#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int smallest_number(int n, int t) {
    for (int i = 0; i < 10; i++) {
        int product = 1;
        int num = n;
    
        while (num != 0) {
            int digit = num % 10;
            product *= digit;
            num /= 10;
        }

        if (product % t == 0) return n;
        n++;
    }
    
    return n;
}

int main() {
    cout << smallest_number(10, 2) << endl;
    cout << smallest_number(15, 3) << endl;
    return 0;
}