#include <iostream>

using namespace std;

int main() {
    int in;
    cin >> in;
    if (in % 3 == 0) {
        cout << in << " adalah bilangan kelipatan 3" << endl;
    } else {
        cout << in << " bukan bilangan kelipatan 3" << endl;
    }
    return 0;
}
