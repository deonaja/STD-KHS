#include "stack.h"

using namespace std;

void createStack_103032300101(Stack &s){
    s.top = -1;
}

bool isEmpty_103032300101(Stack s) {
    if (s.top == -1) {
        return true;
    } else {
        return false;
    }
}

bool isFull_103032300101(Stack s) {
    if (s.top == 15) {
        return true;
    } else {
        return false;
    }
}

void push_103032300101(Stack &s, infotype x) {
    if (s.top != 15) {
        s.top++;
        s.info[s.top] = x;
    } else {
        cout << "Stack Full" << endl;
    }
}

infotype pop_103032300101(Stack &s) {
    if (s.top != -1) {
        infotype x = s.info[s.top];
        s.top--;
        return x;
    } else {
        cout << "Stack kosong" << endl;
        return 0;
    }
}

void printInfo_103032300101(Stack s) {
    int i;
    if (s.top != -1) {
        for (i = s.top; i > -1; i--) {
            cout << s.info[i];
        }
    } else {
        cout << "Stack Kosong" << endl;
    }
    cout << endl;
}
