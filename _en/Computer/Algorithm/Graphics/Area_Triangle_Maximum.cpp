/* Area_Triangle_Maximum.cpp
Author: BSS9395
Update: 2023-06-14T22:39:00+08@China-Beijing
Design: Area Triangle Maximum
Credit: https://leetcode.cn/problems/largest-triangle-area/solutions/1490629/zui-da-san-jiao-xing-mian-ji-by-leetcode-yefh/
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Area_Triangle {
public:
    struct Point {
        double _x    = 0.0;
        double _y    = 0.0;
        bool   _used = false;
        Point(double x, double y) {
            _x = x;
            _y = y;
        }
    };

public:
    static auto _Area_Triangle_Maximum_Brute_Force(vector<Point *> &points) -> double {
        static auto _Area_Triangle = [](Point* o, Point* v, Point* w) -> double {
            /* determinant represented in matrix endianess.
                         || 1 x2 y2 ||
            area = 0.5 * || 1 x1 y1 ||; 
                         || 1 x0 y0 ||
            */
            return 0.5 * abs(o->_x * v->_y + v->_x * w->_y + w->_x * o->_y - o->_y * v->_x - v->_y * w->_x - w->_y * o->_x);
        };

        auto area_maxi = 0.0;
        auto size = (int)points.size();
        for (auto i = 0; i < size; i += 1) {
            for (auto j = i + 1; j < size; j += 1) {
                for (auto k = j + 1; k < size; k += 1) {
                    auto area = _Area_Triangle(points[i], points[j], points[k]);
                    (area < area_maxi) ? area_maxi : (area_maxi = area);
                }
            }
        }
        return area_maxi;
    }

    static auto _Area_Triangle_Monotonous_Chain(vector<Point*>& points) -> double {
        static auto _Cross_Product = [](Point* o, Point* v, Point* w) -> double {
            /*
                          ||  x   y   z  ||
            cross(v, w) = || v_x v_y v_z || = x ， (v_y ， w_z - v_z ， w_y) - y ，(v_x ，w_z - v_z ， w_x) + z ， (v_x ， w_y - v_y ， w_x);
                          || w_x w_y w_z ||
                        = z ， (v_x ， w_y - v_y ， w_x) = z ， [(vx - ox) ， (wy - oy) - (vy - oy) ， (wx - ox)];
            */
            return (v->_x - o->_x) * (w->_y - o->_y) - (v->_y - o->_y) * (w->_x - o->_x);
        };

        static auto _Area_Triangle = [](Point* o, Point* v, Point* w) -> double {
            /* determinant represented in matrix endianess.
                         || 1 x2 y2 ||
            area = 0.5 * || 1 x1 y1 ||;
                         || 1 x0 y0 ||
            */
            return 0.5 * abs(o->_x * v->_y + v->_x * w->_y + w->_x * o->_y - o->_y * v->_x - v->_y * w->_x - w->_y * o->_x);
        };

        ////////////////////////////////////////////////////////////////////////

        if (false == (2 < points.size())) {
            return 0.0;
        }

        sort(points.begin(), points.end(), [](const Point* lhs, const Point* rhs) -> bool {
            return (lhs->_x == rhs->_x) ? (lhs->_y < rhs->_y) : (lhs->_x < rhs->_x);
            });

        ////////////////////////////////////////////////////////////////////////

        vector<Point*> convex = vector<Point*>{};
        for (int i = 0, size = (int)points.size(); i < size; i += 1) {  // note: convex hull bottom peripheral line.
            while (2 <= (int)convex.size() && false == (0 < _Cross_Product(convex[(int)convex.size() - 2], convex[(int)convex.size() - 1], points[i]))) {
                convex[(int)convex.size() - 1]->_used = false, convex.pop_back();
            }
            points[i]->_used = true, convex.emplace_back(points[i]);
        }
        int stage = (int)convex.size();
        convex[0]->_used = false;                                       // note: the zeroth element should be reconsidered.
        for (int i = (int)points.size() - 2; 0 <= i; i -= 1) {          // note: convex hull top    peripheral line.
            if (points[i]->_used == false) {
                while (stage < (int)convex.size() && false == (0 < _Cross_Product(convex[(int)convex.size() - 2], convex[(int)convex.size() - 1], points[i]))) {
                    convex[(int)convex.size() - 1]->_used = false, convex.pop_back();
                }
                points[i]->_used = true, convex.emplace_back(points[i]);
            }
        }
        convex.pop_back();                                              // note: the zeroth element is duplicated.

        ////////////////////////////////////////////////////////////////////////

        auto area_maxi = 0.0;
        auto size = (int)convex.size();
        for (int i = 0; i < size; i += 1) {
            for (int j = i + 1; j < size; j += 1) {
                for (int k = j + 1; k < size; k += 1) {
                    auto area = _Area_Triangle(convex[i], convex[j], convex[k]);
                    (area < area_maxi) ? area_maxi : (area_maxi = area);
                }
            }
        }
        return area_maxi;
    }

public:
    static auto _Test_Area_Triangle_Maximum_Brute_Force() {
        vector<Point *> points = vector<Point *>{};
        points.push_back(new Point(0.0, 0.0));
        points.push_back(new Point(0.0, 1.0));
        points.push_back(new Point(1.0, 0.0));
        points.push_back(new Point(0.0, 2.0));
        points.push_back(new Point(2.0, 0.0));
        auto area = Area_Triangle::_Area_Triangle_Maximum_Brute_Force(points);
        fwprintf(stdout, L"maximum area = %lf\n", area);

        for (int i = 0, size = (int)points.size(); i < size; i += 1) {
            delete points[i], points[i] = nullptr;
        }
    }

    static auto _Test_Area_Triangle_Maximum_Monotonous_Chain() -> void {
        vector<Point*> points = vector<Point*>{};
        points.push_back(new Point(0.0, 0.0));
        points.push_back(new Point(0.0, 1.0));
        points.push_back(new Point(1.0, 0.0));
        points.push_back(new Point(0.0, 2.0));
        points.push_back(new Point(2.0, 0.0));
        auto area = Area_Triangle::_Area_Triangle_Monotonous_Chain(points);
        fwprintf(stdout, L"maximum area = %lf\n", area);

        for (int i = 0, size = (int)points.size(); i < size; i += 1) {
            delete points[i], points[i] = nullptr;
        }
    }
};

int main(int argc, char* argv[]) {
    // Area::_Test_Area_Triangle_Maximum_Brute_Force();
    Area_Triangle::_Test_Area_Triangle_Maximum_Monotonous_Chain();

    return 0;
}
