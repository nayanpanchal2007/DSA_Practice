#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node* prev, Node* next) : data(val), prev(prev), next(next) {}
};

class DoublyLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void insert_at_front(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void insert_at_back(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void delete_front() {
        if (head == nullptr) {
            cout << "List is empty! Nothing to delete.\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        head = head->next;
        head->prev = nullptr;

        delete temp;
    }

    void delete_back() {
        if (head == nullptr) {
            cout << "List is empty! Nothing to delete.\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;

        delete temp;
    }

    void print_list() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* ptr = head;
        
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insert_at_front(10);
    dll.insert_at_front(20);
    dll.insert_at_front(30);
    dll.insert_at_back(40);
    dll.insert_at_back(50);

    dll.delete_front();
    dll.delete_front();

    dll.insert_at_front(60);
    dll.insert_at_back(70);
    dll.insert_at_back(80);

    dll.delete_back();

    dll.insert_at_back(90);
    
    dll.print_list();
    return 0;
}