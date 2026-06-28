#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longest_common_multiple(int a, int b) {
    int x = a;
    int y = b;
    
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return x * y / a;
}

int main() {
    cout << longest_common_multiple(1, 10) << endl;
    cout << longest_common_multiple(2, 15) << endl;
    cout << longest_common_multiple(3, 60) << endl;
    cout << longest_common_multiple(50, 60) << endl;
    cout << longest_common_multiple(20, 50) << endl;
    return 0;
}