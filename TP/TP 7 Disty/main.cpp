#include <iostream>

using namespace std;

int main()
{
    Stack s;
    infotype x;
    createStack_103032300015(s);
    int i;

    do {
        cin >> x;
        push_103032300015(s, x);
    } while (x == '.');
    cout << endl << "isi stack awal" << endl;
    printInfo_103032300015(s);
    do {
        x = pop_103032300015(s);
    } while (x != 'B');

    cout << endl << "isi stack sesudah pop" << endl;
    printInfo_103032300015(s);

    return 0;
}
