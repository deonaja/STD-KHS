#include "stack.h"

using namespace std;

void createStack_103032300015(Stack &s){
    s.top = -1;
}

bool isEmpty_103032300015(Stack s) {
    return s.top == -1;
}

bool isFull_103032300015(Stack s) {
    return s.top == 15;
}

void push_103032300015(Stack &s, infotype x) {
    if (!isEmpty_103032300015(s)) {
        s.top++;
        s.info[s.top] = x;
    } else {
        cout << "Stack Full" << endl;
    }
}

infotype pop_103032300015(Stack &s) {
    if (!isFull_103032300015(s)) {
        infotype x = s.info[s.top];
        s.top--;
        return x;
    } else {
        cout << "Stack kosong" << endl;
        return 0;
    }
}

void printInfo_103032300015(Stack s) {
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
