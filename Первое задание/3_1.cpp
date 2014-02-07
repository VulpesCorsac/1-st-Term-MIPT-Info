// max of array

#include <iostream>

using namespace std;

int main() {
    int n, m, temp;
    cin >> n >> m;
	
    for (int i = 1; i < n; i++) {
        cin >> temp;
        if (temp > m)
            m = temp;
    }
    cout << m;

    return 0;
}
