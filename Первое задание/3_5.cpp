#include <iostream>

using namespace std;

bool prime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i*i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    prime(n) ? cout << "YES" : cout << "NO";

    return 0;
}
