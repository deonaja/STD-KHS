#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack s;
    infotype input;
    int i = 4;
    createStack_103032300101(s);
    cin >> input;
    while (input != '.') {
        push_103032300101(s, input);
        cin >> input;
    }
    cout << endl << "isi stack awal" << endl;
    printInfo_103032300101(s);
    while (i > 0) {
        input = pop_103032300101(s);
        i--;
    }
    cout << endl << "isi stack sesudah di pop" << endl;
    printInfo_103032300101(s);
    return 0;
}
