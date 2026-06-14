#include <iostream>
#include <vector>
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

    void insert(int val) {
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

    void insert_array(vector<int> arr) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            insert(arr[i]);
        }
    }

    void print_list() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* ptr = head;
        while (ptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }

        cout << endl;
    }

    void reverse() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

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
};

int main() {
    LinkedList ll;
    ll.insert_array({1, 2, 3, 4, 5});

    ll.reverse();
    
    ll.print_list();
    return 0;
}