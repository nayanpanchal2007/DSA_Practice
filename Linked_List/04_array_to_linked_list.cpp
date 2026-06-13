#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

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
        return;
    }

    void convert_array_to_ll(vector<int>& arr) {
        head = nullptr;
        for (int i = 0; i < arr.size(); i++) {
            insert_back(arr[i]);
        }
    }

    void print_list() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }

        cout << "NULL\n";
    }
};

int main() {
    LinkedList ll;
    
    vector<int> arr = {10, 20, 30, 40};
    ll.convert_array_to_ll(arr);

    ll.print_list();
    return 0;
}