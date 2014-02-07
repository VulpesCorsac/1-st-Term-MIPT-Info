#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <int> a (n), b;

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    for (int q = 0; q < n; q++)
    {
        for (int i = 0; i < a.size(); i++)
            if (a.size() % m != i)
                b.push_back(a[i]);

        cout << a[a.size() % m] << " ";

        a.clear();
        for (int i = 0; i < b.size(); i++)
            a.push_back(b[i]);
        b.clear();
    }

    return 0;
}
