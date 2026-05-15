#include <iostream>
#include <vector>
using namespace std;

void sum_and_average(vector<int>& arr, int& sum, int& average) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    average = sum / n;
}

int main() {
    vector<int> arr = {3, 4, 5, 6, 2, 10};
    int sum = 0;
    int average = 0;

    sum_and_average(arr, sum, average);
    
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;
    
    return 0;
}