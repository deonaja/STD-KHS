#include <iostream>

using namespace std;

int main() {
    int in,i;
    float total;
    total = 0;
    cin >> in;
    while (in != -999) {
        total += float(in);
        cin >> in;
        i++;
    }
    cout << total / i << endl;
    return 0;
}
