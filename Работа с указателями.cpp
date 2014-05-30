#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int b = 5;
    cout << "Value ( b): " <<  b << ", Address: " << &b << endl;
    int* c = &b;
    cout << "Value (*c): " << *c << ", Address: " <<  c << endl;
    *c = 6;
    cout << "Value (*c): " << *c << ", Address: " <<  c << endl;
    cout << "Value ( b): " <<  b << ", Address: " << &b << endl;
    b = 9;
    cout << "Value (*c): " << *c << ", Address: " <<  c << endl;
    cout << "Value ( b): " <<  b << ", Address: " << &b << endl;
    int** d = &c;
    **d = 7;
    cout << "Value (*c): " << *c << ", Address: " <<  c << endl;
    cout << "Value ( b): " <<  b << ", Address: " << &b << endl;
    cout << endl;
    cout << "**d    *d         d" << endl;
    cout << **d << "      " << *d << "   " << d << endl;
    cout << endl;
    int arr[10];
    int i;
    for (i = 0; i < 10; i++) {
        arr[i] = i;
        cout << "a[" << i << "] = " << arr[i] << ", address: " << &arr[i] << endl;
    }
    cout << endl;
    cout << "arr = " << arr << endl;
    for (i = 0; i < 10; i++)
        cout << "a[" << i << "] = " << *(arr+i) << endl;
    cout << endl;
    int* p = (int*) malloc(10000*sizeof(int));
    cout << "Pointer: " << p << endl;
    for (i = 0; i < 10000; i++)
        *(p+i) = i;
    realloc(p, 20000*sizeof(int));
    free(p);
    return 0;
}