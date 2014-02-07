#include <algorithm>
#include <iostream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

#define all(c) c.begin(), c.end()
#define MAX 100

using namespace std;

struct point
{
    long double x, y;
};

long double sqr(long double a)
{
    return a*a;
}

long double dist (point A, point B)
{
    return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}

int main()
{
//    freopen("r+", "input.txt", stdin);

    int n;
    cin >> n;

    vector <point> points (n);
    vector <int> ans;
    vector <int> v (n, 0);

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    int st = 0, temp_st = 0;
    long double l = dist(points[0], points[1]);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dist(points[i], points[j]) < l)
            {
                l = dist(points[i], points[j]);
                st = i;
            }

    v[st] = 1;
    ans.push_back(st);

    while (st != -1)
    {
        l = temp_st = -1;
        for (int i = 0; i < n; i++)
            if (!v[i])
                if (l == -1 || dist(points[st], points[i]) < l)
                {
                    l = dist(points[st], points[i]);
                    temp_st = i;
                }

        if (temp_st != -1)
        {
            v[temp_st] = 1;
            ans.push_back(temp_st);
        }

        st = temp_st;
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";

    return 0;
}
