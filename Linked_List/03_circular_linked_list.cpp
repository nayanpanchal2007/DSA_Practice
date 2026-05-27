#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

class LinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void insert_at_front(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = tail = new_node;
            tail->next = head;
            return;
        }

        new_node->next = head;
        head = new_node;
        tail->next = head;
    }

    void insert_at_back(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = tail = new_node;
            tail->next = head;
            return;
        }

        tail->next = new_node;
        tail = new_node;
        tail->next = head;
    }

    void delete_front() {
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            Node* temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
            return;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void delete_back() {
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            Node* temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        temp->next = head;
        delete tail;
        tail = temp;
    }

    void print_ll() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* ptr = head;
        do {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != head);
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insert_at_front(10);
    ll.insert_at_front(20);
    ll.insert_at_front(30);
    ll.insert_at_back(40);
    ll.insert_at_back(50);
    ll.delete_front();
    ll.delete_front();
    ll.insert_at_back(60);
    ll.delete_back();
    ll.delete_back();
    ll.print_ll();
    return 0;
}