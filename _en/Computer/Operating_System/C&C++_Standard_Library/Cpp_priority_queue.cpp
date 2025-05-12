/* Cpp_priority_queue.cpp
Author: BSS9395
Update: 2025-05-11T09:26:00+08@China-Guangdong-Zhanjiang+08
*/

#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		return a < b; // 这里定义了最小堆
	}
};

int main(int argc, char *argv[]) {
	priority_queue<int> pq_max;
	priority_queue<int, vector<int>, compare> pq_min;

	pq_max.push(3);
	pq_max.push(4);
	cout << pq_max.top() << endl;

	pq_min.push(3);
	pq_min.push(4);
	cout << pq_min.top() << endl;

	return 0;
}