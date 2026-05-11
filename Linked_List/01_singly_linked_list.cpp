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
    Node* head = nullptr;
    
public:
    void insert_at_back(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = new_node;
            return;            
        }

        Node* ptr = head;

        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        
        ptr->next = new_node;
    }

    void insert_at_front(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = new_node;
            return;
        }

        new_node->next = head;
        head = new_node;
    }

    void delete_front() {
        if (head == nullptr) {
            cout << "List is empty! Can't delete from front.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    void delete_back() {
        if (head == nullptr) {
            cout << "List is empty! Can't delete from back.\n";
            return;
        }

        Node* ptr = head;
        Node* preptr = nullptr;

        while (ptr->next != nullptr) {
            preptr = ptr;
            ptr = ptr->next;
        }

        preptr->next = nullptr;
        delete ptr;
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
    LinkedList ll;

    ll.insert_at_back(10);
    ll.insert_at_back(20);
    ll.insert_at_back(30);
    ll.insert_at_back(40);
    ll.insert_at_front(50);
    ll.insert_at_front(60);
    ll.delete_front();
    ll.delete_front();
    ll.delete_back();
    ll.delete_back();
    

    ll.print_list();
    return 0;
}