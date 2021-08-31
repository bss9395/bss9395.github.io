/* sort.cpp
Author: BSS9395
Update: 2020-08-31T11:14:00+08@China-Guangdong-Zhanjiang+08
Design: sort
Original: https://cplusplus.com/reference/algorithm/sort/?kw=sort
*/

/*
#include <algorithm>

default (1)
template <class RandomAccessIterator>
void sort (RandomAccessIterator first, RandomAccessIterator last);

custom (2)
template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool compare(string &lhs, string &rhs) {
    return (lhs < rhs);
}

int main(int argc, char *argv[]) {
    long arr[] = {
        9, 0, 8, 2, 6, 1, 3, 4, 5, 7
    };
    int n = sizeof(arr) / sizeof(*arr);

    sort(&arr[0], &arr[n]);
    for (int i = 0; i < n; i += 1) {
        fprintf(stdout, "%d ", arr[i]);
    }
    fprintf(stdout, "\n");

    ////////////////////////////////////

    string str = "9082613457";
    sort(str.begin(), str.end());
    cout << str << endl;
    cout << endl;

    ////////////////////////////////////

    vector<string> vec;
    vec.push_back("abc");
    vec.push_back("cba");
    vec.push_back("adb");
    vec.push_back("bbgg");

    sort(vec.begin(), vec.end(), compare);
    sort(vec.begin(), vec.end());

    //for (int i = 0; i < (int)vec.size(); i += 1) {
    //    cout << vec[i] << endl;
    //}
    for (auto it = vec.begin(); it != vec.end(); it += 1) {
        cout << *it << endl;
    }
    cout << endl;
}