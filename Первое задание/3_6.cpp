#include <algorithm>
#include <iostream>
#include <vector>

#define all(c) c.begin(), c.end()

using namespace std;

struct point
{
    long double x, y;
};

bool comparator(point a, point b)
{
    return (a.x < b.x || a.x == b.x && a.y < b.y);
}

long double mul(point a, point b, point c)
{
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

bool cw(point a, point b, point c)
{
    return mul(a, b, c) < 0;
}

bool ccw(point a, point b, point c)
{
    return mul(a, b, c) > 0;
}

void convex_hull (vector <point> &a)
{
    if (a.size() == 1)
        return;

    point p1 = a[0];
    point p2 = a.back();

    vector <point> up, down;

    up.push_back(p1);
    down.push_back(p1);

    for (int i = 1; i < a.size(); i++)
    {
        if (i == a.size() - 1 || cw (p1, a[i], p2))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw (p1, a[i], p2))
        {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);

    return;
}

int main()
{
    vector <point> points (4);

    for (int i = 0; i < 4; i++)
        cin >> points[i].x >> points[i].y;

    sort(all(points), comparator);

    convex_hull(points);

    long double s = mul(points[0], points[1], points[2]) + mul(points[0], points[2], points[3]);

    if (s < 0)
        s *= -1;
    s /= 2.0;
    cout << s;

    return 0;
}
