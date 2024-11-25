#include "stack.h"

void createStack_103032300035(stack &S){
    S.top = 0;
};
bool isEmpty_103032300035(stack S){
    if (S.top == 0){
        return true;
    }else{
        return false;
    }
};
bool isFull_103032300035(stack S){
    if (S.top == 15){
        return true;
    }else{
        return false;
    }
};
void push_103032300035(stack &S, infotype x){
    if(!isFull_103032300035(S)){
        S.top = S.top + 1;
        S.info[S.top]=x;
    }
};
infotype pop_103032300035(stack &S){
    infotype x;
    if (!isEmpty_103032300035(S)){
        x = S.info[S.top];
        S.top = S.top - 1;

    }
     return x;
};
void printinfo_103032300035(stack S){
    for ( int i = S.top;i >= 1;i--){
        cout << S.info[i] << " ";
    }
    cout << endl;
};
