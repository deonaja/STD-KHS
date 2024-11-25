#include <iostream>
#include <cmath>

using namespace std;

float kerucut(float r, float t) {
    return (M_PI * r * r * t) / 3;
}

int main() {
    float r, t,hasil;
    r = 10;
    t = 10;
    hasil = kerucut(r, t);
    cout << r << t << endl;
    cout << hasil << endl;
    return 0;
}
