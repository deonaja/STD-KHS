#include <iostream>
#include "tubes.h"

using namespace std;

int main()
{
    listGudang lG;
    listPenitip lP;
    lG.first = NULL;
    lP.first = NULL;
    lP.last = NULL;
    menu(lG,lP);
    return 0;
}
