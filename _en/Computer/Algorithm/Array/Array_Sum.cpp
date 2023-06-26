/* Array_Sum.cpp
Author: BSS9395
Update: 2023-06-23T22:03:00+08@China-Beijing+08
Design: Array Info
Credit: https://leetcode.cn/problems/maximum-subarray/
*/

#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

/*
��Ŀ������һ���������� data �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
����������ʹ��f(i)�����Ե�i������β�ġ���������������͡�����ô����Ȼ����Ҫ��Ĵ𰸾���max_{0��i��n-1}{f(i)}���������ֻ��Ҫ���ÿ��λ�õ�f(i)��Ȼ�󷵻�{f(i)}�����е����ֵ���ɡ�
*/
class Array_Sum {
    template<typename Type_>
    static auto _Maxi(Type_ lhs, Type_ rhs) -> Type_ {
        Type_ maxi = lhs;
        (rhs < maxi) ? maxi : (maxi = rhs);
        return maxi;
    }

    template<typename Type_>
    static auto _Maxi(Type_ lhs, Type_ mid, Type_ rhs) -> Type_ {
        Type_ maxi = lhs;
        (mid < maxi) ? maxi : (maxi = mid);
        (rhs < maxi) ? maxi : (maxi = rhs);
        return maxi;
    }

public:
    template<typename Type_>
    static auto _SubArray_Sum_Maximum_Segmentation(vector<Type_>& data) -> vector<Type_> {
        struct Info {
            Type_ _sum_full = 0;
            Type_ _sum_head = 0;
            Type_ _sum_tail = 0;
            Type_ _sum_maxi = 0;
            Info(Type_ sum_full, Type_ sum_head, Type_ sum_tail, Type_ sum_maxi) {
                _sum_full = sum_full;
                _sum_head = sum_head;
                _sum_tail = sum_tail;
                _sum_maxi = sum_maxi;
            }
        };

        static function<Info(vector<Type_>&, int, int)> _Array_Sum_Maximum_Segmentation = [](vector<Type_>& data, int head, int tail) -> Info {
            static auto _Update = [](Info pref, Info suff) -> Info {
                auto sum_full = pref._sum_full + suff._sum_full;
                auto sum_head = _Maxi(pref._sum_head, pref._sum_full + suff._sum_head);
                auto sum_tail = _Maxi(suff._sum_tail, suff._sum_full + pref._sum_tail);
                auto sum_maxi = max(max(pref._sum_maxi, suff._sum_maxi), pref._sum_tail + suff._sum_head);
                return Info(sum_full, sum_head, sum_tail, sum_maxi);
            };

            if (head == tail) {
                return Info(data[head], data[head], data[head], data[head]);
            }
            auto midd = (int)((head + tail) / 2);
            auto pref = _Array_Sum_Maximum_Segmentation(data, head    , midd);
            auto suff = _Array_Sum_Maximum_Segmentation(data, midd + 1, tail);
            return _Update(pref, suff);
        };

        auto retu = vector<Type_>();
        if (false == (1 <= data.size())) {
            return retu;
        }

        auto sum = _Array_Sum_Maximum_Segmentation(data, 0, (int)data.size() - 1);
        retu.push_back(sum._sum_maxi);
        return retu;

    }
    
    template<typename Type_>
    static auto _SubArray_Sum_Maximum(vector<Type_>& data) -> vector<Type_> {
        auto retu = vector<Type_>();
        if (false == (1 <= data.size())) {
            return retu;
        }

        Type_ summ = data[0];
        Type_ maxi = summ;
        for (int i = 1, size = (int)data.size(); i < size; i += 1) {
            summ += data[i];
            (data[i] <= summ) ? summ : (summ = data[i]);
            (summ <= maxi) ? maxi : (maxi = summ);
        }
        retu.push_back(maxi);
        return retu;
    }

public:
    static auto _Test_SubArray_Sum_Maximum_Segmentation() -> void {
        auto data = vector<int> {
            -2, 1, -3, 4, -1, 2, 1, -5, 4
        };
        auto maxi = _SubArray_Sum_Maximum_Segmentation(data);
        fwprintf(stdout, L"maxi = %d\n", maxi[0]);
    }

    static auto _Test_SubArray_Sum_Maximum() -> void {
        auto data = vector<int> {
            -2, 1, -3, 4, -1, 2, 1, -5, 4
        };
        auto maxi = _SubArray_Sum_Maximum_Segmentation(data);
        fwprintf(stdout, L"maxi = %d\n", maxi[0]);
    }   
};


int main(int argc, char* argv[]) {
    Array_Sum::_Test_SubArray_Sum_Maximum_Segmentation();
    Array_Sum::_Test_SubArray_Sum_Maximum();

    return 0;
}
