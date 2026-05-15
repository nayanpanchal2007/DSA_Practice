#include <iostream>
#include <vector>
using namespace std;

void count_even_and_odd(vector<int>& arr, int& even_count, int& odd_count) {
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int even = 0;
    int odd = 0;

    count_even_and_odd(arr, even, odd);

    cout << "Even count = " << even << endl;
    cout << "Odd count = " << odd << endl;

    return 0;
}