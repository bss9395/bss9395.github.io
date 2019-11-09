#if 0
#include <sys/timerfd.h>
int timerfd_create(int clockid, int flags);
int timerfd_settime(int fd, int flags, const struct itimerspec *new_value, struct itimerspec *old_value);
int timerfd_gettime(int fd, struct itimerspec *curr_value);
#endif

#include <sys/timerfd.h>
#include <unistd.h>

#include <errno.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int checkError(bool failed, const string &file, const long line, const string &func, const string &msg) {
  if(failed) {
    cout << "==" << file << "==" << line << "==" << func << "==[" << errno << "]" << msg << endl;
    if(errno) {
      exit(errno);
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int fd = timerfd_create(CLOCK_MONOTONIC, 0);
  checkError(fd < 0, __FILE__, __LINE__, __FUNCTION__, "CLOCK_MONOTONIC");

  struct itimerspec timeout = { {1, 0}, {1, 0} };
  int err = timerfd_settime(fd, 0, &timeout, NULL);
  checkError(err < 0, __FILE__, __LINE__, __FUNCTION__, "timerfd_settime");

  long tick = 0;
  while(true) {
    long len = read(fd, &tick, sizeof(tick));
    checkError(len != sizeof(tick), __FILE__, __LINE__, __FUNCTION__, "read");
    cout << tick << endl;
  }

  close(fd);
  return 0;
}
