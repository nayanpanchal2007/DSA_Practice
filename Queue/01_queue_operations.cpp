#include <iostream>
#include <vector>
using namespace std;

class Queue {
public:
    vector<int> arr;
    int size;
    int front;
    int rear;

    Queue(int size) : arr(size), size(size), front(-1), rear(-1) {}

    void insert(int val) {
        if (rear >= size - 1) {
            cout << "Queue is overflow!\n";
            return;
        }

        if (front == -1 || rear == -1) {
            front = 0;
            rear = 0;
            arr[rear] = val;
            return;
        }

        rear++;
        arr[rear] = val;
    }

    void remove() {
        if (front == -1) {
            cout << "Queue is underflow!\n";
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
            return;
        }

        front++;
    }

    int peek() {
        if (front == -1) {
            return -1;
        }
        
        return arr[front];
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue: ";
        
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    
    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.remove();

    q.insert(40);
    q.insert(50);

    q.remove();

    q.display();

    cout << "First element is: " << q.peek() << endl;
    return 0;
}