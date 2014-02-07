#include <algorithm>
#include <iostream>
#include <vector>

#define all(c) c.begin(), c.end()

using namespace std;

struct man
{
    int m, f, n;
};

bool comparator(man m1, man m2)
{
    if ((m1.f > m2.f) || ((m1.f == m2.f) && (m1.m < m2.f)))
        return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    vector <man> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].m >> a[i].f;
        a[i].n = i + 1;
    }


    sort(all(a), comparator);
/*
    cout << endl;
    cout << a[0].f << " " << a[0].m << endl;
    cout << a[n-1].f << " " << a[n-1].m;
*/
    vector <int> answer;
    int temp_sum_mass = 0;
    for (int i = 0; i < n; i++)
        if (a[i].f >= temp_sum_mass)
        {
            temp_sum_mass += a[i].m;
            answer.push_back(a[i].n);
        }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    return 0;
}
