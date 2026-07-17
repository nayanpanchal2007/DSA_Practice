#include <iostream>
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

    void insert_back(int val) {
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

    int get_middle() {
        if (head == nullptr) return -1;
        
        Node* slow = head;
        Node* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

int main() {
    LinkedList ll;

    ll.insert_back(10);
    ll.insert_back(20);
    ll.insert_back(30);
    ll.insert_back(40);
    ll.insert_back(50);

    cout << ll.get_middle() << endl;
    return 0;
}