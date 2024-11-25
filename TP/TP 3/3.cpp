#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int* p_a = &a;
    cout << a << endl;
    cout << p_a << endl;
    cout << *p_a << endl;
}
