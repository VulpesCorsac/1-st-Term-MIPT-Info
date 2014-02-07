#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define all(c) c.begin(), c.end()
#define MAX 1000

typedef unsigned long long ull;
typedef long double ld;
typedef double type;

using namespace std;

class hash
{
public:
    int size;
    vector <bool> table;

    hash(int _sz = 257)
    {
        table.resize(_sz, false);
        size = _sz;
    }

    int h1(int i)
    {
        return (i*i) % size;
    }

    int h2(int i)
    {
        return (7*i + 64 + i*i) % size;
    }

    int h3(int i)
    {
        return i % size;
    }

    int h4(int i)
    {
        int k = i;
        for (int j = 2; j <= i; j++)
            k = (k * i) % size;
        return k;
    }

    int h5(int i)
    {
        return (i ^ (i >> 4)) % size;
    }

    int h6(int i)
    {
        return (i*i ^ i) % size;
    }

    int h7(int i)
    {
        return (i << 5 ^ i >> 2) % size;
    }

    void add(int i)
    {
        table[h1(i)] = true;
		table[h2(i)] = true;
		table[h3(i)] = true;
		table[h4(i)] = true;
		table[h5(i)] = true;
		table[h6(i)] = true;
		table[h7(i)] = true;
    }

    bool search(int i)
    {
        if (table[h1(i)])
        if (table[h2(i)])
        if (table[h3(i)])
        if (table[h4(i)])
        if (table[h5(i)])
        if (table[h6(i)])
        if (table[h7(i)])
            return true;
        return false;
    }

};

int main()
{
//    freopen("in.txt", "r+", stdin);
//    freopen("out.txt", "w+", stdout);

    hash h(10007);
    int n, k = 0, q;
    set <int> s;
    s.clear();

    n = h.size / 2;
    for (int i = 0; i <= n; i++)
    {
        do
            q = rand();
        while (s.find(q) != s.end());

        if (h.search(q))
        {
            k++;
            cout << "error on " << q << " iter = " << i <<endl;
        }

        h.add(q);
        s.insert(q);
    }
    cout << "fails - " << k << endl;

//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
