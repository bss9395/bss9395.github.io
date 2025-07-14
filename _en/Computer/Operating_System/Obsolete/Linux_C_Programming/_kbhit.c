#include <sys/ioctl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>


void enable_raw_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void disable_raw_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int _kbhit() {
    enable_raw_mode();

    int fl = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, fl | O_NONBLOCK);
    int ch = getchar();
    fcntl(STDIN_FILENO, F_SETFL, fl);

    if(EOF != ch) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int _getch() {
    enable_raw_mode();
    int ch = getchar();
    disable_raw_mode();
    return ch;
}

int main(int argc, char *argv[]) {
    int kb = '\0';
    for (int i = 0; i < 10; ++i) {
        while (_kbhit()) {
            kb = _getch();
            printf("getch: %d\n", kb);
        }
        printf("getpid = %d, getppid = %d\n", getpid(), getppid());
        sleep(1);
    }
    disable_raw_mode();

    int ch = _getch();
    printf("%c\n", ch);
    return 0;
}