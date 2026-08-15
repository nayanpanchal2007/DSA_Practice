#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int>& st, int element) {
    if (st.empty()) {
        st.push(element);
        return;
    }
    
    int top = st.top();
    st.pop();

    insert_at_bottom(st, element);
    st.push(top);
}

void reverse_stack(stack<int>& st) {
    if (st.empty()) {
        return;
    }

    int top = st.top();
    st.pop();

    reverse_stack(st);
    insert_at_bottom(st, top);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    stack<int> temp = st;

    cout << "Before reversal: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverse_stack(st);

    temp = st;
    
    cout << "After reversal: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;


    return 0;
}