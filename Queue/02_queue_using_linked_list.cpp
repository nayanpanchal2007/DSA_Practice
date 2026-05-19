#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

class Queue {
public:
    Node* front = nullptr;
    Node* tail = nullptr;

    void enqueue(int val) {
        Node* new_node = new Node(val);

        if (front == nullptr) {
            front = tail = new_node;
            return;    
        }

        tail->next = new_node;
        tail = new_node;
    }

    void dequeue() {
        if (front == nullptr) {
            return;
        }

        if (front == tail) {
            Node* temp = front;
            front = tail = nullptr;
            delete temp;
            return;
        }
        
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int peek() {
        if (front == nullptr) {
            return -1;
        }
        
        return front->data;
    }

    void print_queue() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* ptr = front;
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);
    // q.enqueue(50);

    q.dequeue();

    q.print_queue();

    cout << "Peek = " << q.peek() << endl;
    
    return 0;
}