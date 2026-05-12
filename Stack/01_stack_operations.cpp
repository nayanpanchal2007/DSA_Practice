#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> arr;
    int top = -1;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arr.resize(size);
    }

    bool is_empty() {
        return top < 0;
    }

    bool is_full() {
        return top >= size-1;
    }

    void push(int val) {
        if (is_full()) {
            cout << "Stack overflow!\n";
            return;
        }

        top++;
        arr[top] = val;
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack underflow!\n";
            return -1;
        }

        int popped_val = arr[top];
        top--;
        return popped_val;
    }

    int peek() {
        if (is_empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }

        return arr[top];
    }

    void display() {
        if (is_empty()) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack (bottom to top): ";

        for (int x : arr) {
            cout << x << " ";
        }

        cout << endl;
    }
};

int main() {
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    st.display();

    cout << st.peek();
    return 0;
}