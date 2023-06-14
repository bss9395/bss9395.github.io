/* Convex_Hull.cpp
Author: BSS9395
Update: 2023-06-14T22:09:00+08@China-Beijing+08
Design: Convex Hull
Credit: https://leetcode.cn/problems/erect-the-fence/solutions/1440879/an-zhuang-zha-lan-by-leetcode-solution-75s3/
*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Convex_Hull {
public:
    struct Point {
        double _x    = 0.0;
        double _y    = 0.0;
        bool   _used = false;
        Point(double x, double y) {
            _x = x;
            _y = y;
        }

        auto _Into_WString() -> wstring {
            wstring str = wstring{};
            str.resize(64);
            // int count = swprintf(&str[0], L"[%.1lf, %.1lf, %ls]", _x, _y, (_used == true) ? L"true" : L"false");
            int count = swprintf(&str[0], L"[%.1lf, %.1lf]", _x, _y);
            str.resize(count);
            return str;
        }
    };

public:
    static auto _Convex_Hull_Brute_Force(vector<Point*>& points, vector<Point*>& hull) -> void {
        static auto _Cross_Product = [](Point* o, Point* v, Point* w) -> double {
            /*
                          ||  x   y   z  ||
            cross(v, w) = || v_x v_y v_z || = x ， (v_y ， w_z - v_z ， w_y) - y ，(v_x ，w_z - v_z ， w_x) + z ， (v_x ， w_y - v_y ， w_x);
                          || w_x w_y w_z ||
                        = z ， (v_x ， w_y - v_y ， w_x) = z ， [(vx - ox) ， (wy - oy) - (vy - oy) ， (wx - ox)];
            */
            return (v->_x - o->_x) * (w->_y - o->_y) - (v->_y - o->_y) * (w->_x - o->_x);
        };

        ////////////////////////////////////////////////////////////////////////

        if (false == (2 < points.size())) {
            return;
        }

        sort(points.begin(), points.end(), [](const Point* lhs, const Point* rhs) -> bool {
            return (lhs->_x == rhs->_x) ? (lhs->_y < rhs->_y) : (lhs->_x < rhs->_x);
            });

        ////////////////////////////////////////////////////////////////////////

        vector<Point*> convex = vector<Point*>{};
        auto size = (int)points.size();
        points[0]->_used = false, convex.push_back(points[0]);  // note: the zeroth element should be reconsidered.
        auto o = (int)0;
        while (true) {                                          // note: convex hull bottom peripheral line.
            auto v = o + 1;
            if (false == (v < size)) {
                break;
            }
            for (auto w = v + 1; w < size; w += 1) {
                if (_Cross_Product(points[o], points[v], points[w]) <= 0.0) {
                    v = w;
                }
            }
            o = v;
            points[o]->_used = true, convex.push_back(points[o]);
        }
        while (true) {                                          // note: convex hull top    peripheral line.
            auto v = o - 1;
            while (0 <= v && points[v]->_used == true) {
                v -= 1;
            }
            if (false == (0 <= v)) {
                break;
            }
            for (auto w = v - 1; 0 <= w; w -= 1) {
                if (points[w]->_used == false && _Cross_Product(points[o], points[v], points[w]) <= 0.0) {
                    v = w;
                }
            }
            o = v;
            points[o]->_used = true, convex.push_back(points[o]);
        }
        convex.pop_back();                                      // note: the zeroth element is duplicated.

        ////////////////////////////////////////////////////////////////////////

        for (int i = 0, size = (int)hull.size(); i < size; i += 1) {
            delete hull[i], hull[i] = nullptr;
        }
        hull.clear();
        for (int i = 0, size = (int)convex.size(); i < size; i += 1) {
            hull.emplace_back(new Point(convex[i]->_x, convex[i]->_y));
        }
    }

    static auto _Convex_Hull_Monotonous_Chain(vector<Point *>& points, vector<Point *>& hull) -> void {
        static auto _Cross_Product = [](Point* o, Point* v, Point* w) -> double {
            /*
                          ||  x   y   z  ||
            cross(v, w) = || v_x v_y v_z || = x ， (v_y ， w_z - v_z ， w_y) - y ，(v_x ，w_z - v_z ， w_x) + z ， (v_x ， w_y - v_y ， w_x);
                          || w_x w_y w_z ||
                        = z ， (v_x ， w_y - v_y ， w_x) = z ， [(vx - ox) ， (wy - oy) - (vy - oy) ， (wx - ox)];
            */
            return (v->_x - o->_x) * (w->_y - o->_y) - (v->_y - o->_y) * (w->_x - o->_x);
        };

        ////////////////////////////////////////////////////////////////////////

        if (false == (2 < points.size())) {
            return;
        }

        sort(points.begin(), points.end(), [](const Point *lhs, const Point *rhs) -> bool {
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

        for (int i = 0, size = (int)hull.size(); i < size; i += 1) {
            delete hull[i], hull[i] = nullptr;
        }
        hull.clear();
        for (int i = 0, size = (int)convex.size(); i < size; i += 1) {
            hull.emplace_back(new Point(convex[i]->_x, convex[i]->_y));
        }
    }

public:
    static auto _Test_Convex_Hull_Brute_Force() -> void {
        vector<Point*> points = vector<Point*>{};
        points.push_back(new Point(0.0, 0.0));
        points.push_back(new Point(0.0, 1.0));
        points.push_back(new Point(1.0, 0.0));
        points.push_back(new Point(0.0, 2.0));
        points.push_back(new Point(2.0, 0.0));
        vector<Point*> hull = vector<Point*>{};
        _Convex_Hull_Brute_Force(points, hull);

        ////////////////////////////////

        for (int i = 0, size = (int)hull.size(); i < size; i += 1) {
            if (i == 0) {
                fwprintf(stdout, L"%ls", hull[i]->_Into_WString().c_str());
            }
            else {
                fwprintf(stdout, L", %ls", hull[i]->_Into_WString().c_str());
            }
        }

        for (int i = 0, size = (int)points.size(); i < size; i += 1) {
            delete points[i], points[i] = nullptr;
        }
        for (int i = 0, size = (int)hull.size(); i < size; i += 1) {
            delete hull[i], hull[i] = nullptr;
        }
    }

    static auto _Test_Convex_Hull_Monotonous_Chain() -> void {
        vector<Point*> points = vector<Point*>{};
        points.push_back(new Point(0.0, 0.0));
        points.push_back(new Point(0.0, 1.0));
        points.push_back(new Point(1.0, 0.0));
        points.push_back(new Point(0.0, 2.0));
        points.push_back(new Point(2.0, 0.0));
        vector<Point*> hull = vector<Point*>{};
        _Convex_Hull_Monotonous_Chain(points, hull);

        ////////////////////////////////

        for (int i = 0, size = (int)hull.size(); i < size; i += 1) {
            if (i == 0) {
                fwprintf(stdout, L"%ls", &(hull[i]->_Into_WString())[0]);
            }
            else {
                fwprintf(stdout, L", %ls", hull[i]->_Into_WString().c_str());
            }
        }

        for (int i = 0, size = (int)points.size(); i < size; i += 1) {
            delete points[i], points[i] = nullptr;
        }
        for (int i = 0, size = (int)hull.size(); i < size; i += 1) {
            delete hull[i], hull[i] = nullptr;
        }
    }
};

int main(int argc, char* argv[]) {
    // Convex::_Test_Convex_Hull_Brute_Force();
    Convex_Hull::_Test_Convex_Hull_Monotonous_Chain();

    return 0;
}
