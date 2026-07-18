/**
 * Array inverter
 * 
 * In integer array, every element invert means 
 * if element[i] >= 0 -> ans[i] = 9 - element[i]
 * else               -> ans[i] = 9 + element[i]
 * 
 * Example 1 : [1, 2, 3, 4, 5]
 * Output    : [8, 7, 6, 5, 4]
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> array_inverter(vector<int> nums) {
    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        if (nums[i] >= 0) {
            ans[i] = 9 - nums[i];
        } else {
            ans[i] = 9 + nums[i];
        }
    }

    return ans;
}

void print_array(vector<int> arr) {
    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    print_array(array_inverter({1, 2, 3, 4, 5}));
    print_array(array_inverter({9, 3, 7, 5, 8, 2}));
    print_array(array_inverter({-1, 9, 8, 4, -3, -2}));
    print_array(array_inverter({0, 0, 2, 1, -9, -7}));
    print_array(array_inverter({-1}));

    return 0;
}