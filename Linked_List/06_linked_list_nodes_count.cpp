#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

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
        while (ptr->next) {
            ptr = ptr->next;
        }

        ptr->next = new_node;
    }

    void insert_array(vector<int> arr) {
        for (int i = 0; i < arr.size(); i++) {
            insert(arr[i]);
        }
    }

    int count_nodes() {
        if (head == nullptr) {
            return 0;
        }

        int n = 0;

        for (Node* ptr = head; ptr; ptr = ptr->next) {
            n++;
        }

        return n;
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
};

int main() {
    LinkedList ll;

    ll.insert_array({10, 20, 30, 40, 50});
    ll.print_list();

    cout << "Total nodes = " << ll.count_nodes() << endl;
    return 0;
}