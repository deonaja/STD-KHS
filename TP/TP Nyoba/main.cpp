#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    char x;
    stack S;

    createStack_103032300035(S);

    while (S.top < 11 ){
        cin >> x;
        push_103032300035(S,x);

    }
    printinfo_103032300035(S);

    cout << endl;

    int i = 4;
    while (i > 0){
        pop_103032300035(S);
        i--;
    }
    printinfo_103032300035(S);
    return 0;
}
