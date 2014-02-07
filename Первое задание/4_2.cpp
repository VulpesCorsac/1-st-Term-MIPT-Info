#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

#define all(c) c.begin(), c.end()
#define MAX 100

using namespace std;

struct segment
{
    int st, fn, n;
};

bool comparator(segment s1, segment s2)
{
    return ((s1.st < s2.st) || ((s1.st == s2.st) && (s1.fn > s2.fn)));
}

int main()
{
//    freopen("r+", "input.txt", stdin);

    int n;

    cin >> n;
    vector <segment> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i].st >> s[i].fn;

        s[i].n = i + 1;

        if (s[i].st > s[i].fn)
            swap(s[i].st, s[i].fn);
    }

    sort(all(s), comparator);

    vector <int> answer;

    int st = s[0].st;
    int fn = s[0].fn;
    int temp_fn = fn;
    int temp_fn_n = 0;

    answer.push_back(s[0].n);

    for (int i = 1; i < n; i++)
    {
        if (s[i].fn < 0)
            continue;
        if (s[i].st >= MAX)
            break;

        if (s[i].st < fn)
        {
            if (s[i].fn >= temp_fn)
            {
                temp_fn = s[i].fn;
                temp_fn_n = s[i].n;
            }
        }
        else
        {
            answer.push_back(temp_fn_n);
            temp_fn_n = s[i].n;
            temp_fn = s[i].fn;
            fn = temp_fn;
        }
    }

    if ((fn < MAX) && (answer[answer.size() - 1] != s[n-1].n))
        answer.push_back(s[n-1].n);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    return 0;
}
