// C_{n}^{k}

#include <iostream>

using namespace std;

int C(int k, int n) {
    if (n == k || k == 0)
        return 1;
    return C(k, n-1) + C(k-1, n-1);
}

int main() {
    int n;
    cin >> n;
	
    for (int i = 0; i <= n; i++)
        cout << C(i, n) << " ";

    return 0;
}
