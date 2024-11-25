#include <iostream>

using namespace std;

int a, b;

void Tukar1(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Tukar2(int a, int *b) {
    int temp;
    temp = a;
    a = *b;
    *b = temp;
}

int main() {
    a = 10;
    b = 5;
    Tukar1(&b,&a);
    Tukar2(a,&b);
    Tukar1(&a,&b);
    cout << a << b;
}
