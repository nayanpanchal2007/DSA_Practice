#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
    vector<int> arr = {5, 1, 6};
    int n = arr.size();

    function<int()> sum_xor_subsets = [&]() {
        int orr = 0;
        
        for (int& x : arr) {
            orr |= x;
        }

        return orr * (1 << (n - 1));
    };

    cout << "XOR sum of Subsets = " << sum_xor_subsets() << endl;
    
    return 0;
}