#include <iostream>
using namespace std;

int sum_of_digits(int n) {
    if (n < 0) n *= -1;    
    int sum = 0;

    while (n != 0) {
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }

    return sum;
}

int main() {
    cout << sum_of_digits(102) << endl;
    cout << sum_of_digits(-91) << endl;
    cout << sum_of_digits(1234) << endl;
    cout << sum_of_digits(834) << endl;
    return 0;
}