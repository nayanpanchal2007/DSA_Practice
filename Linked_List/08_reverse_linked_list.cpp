#include <bits/stdc++.h>
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

    void insert_at_back(int val) {
        Node* new_node = new Node(val);

        if (!head) {
            head = new_node;
            return;
        }

        Node* ptr = head;

        while (ptr->next) {
            ptr = ptr->next;
        }

        ptr->next = new_node;
    }

    void reverse_list() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void print_list() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* ptr = head;

        while (ptr) {
            if (!ptr->next) {
                cout << ptr->data << " -> NULL\n";
            } else {
                cout << ptr->data << " -> ";
            }

            ptr = ptr->next;
        }
    }
};

int main() {
    LinkedList ll;

    ll.insert_at_back(10);
    ll.insert_at_back(20);
    ll.insert_at_back(30);
    ll.insert_at_back(40);

    ll.print_list();

    ll.reverse_list();

    ll.print_list();
    
    return 0;
}