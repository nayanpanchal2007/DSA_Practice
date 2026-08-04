#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int num = 5324;
    string str;

    stringstream ss;
    ss << num;
    ss >> str;

    cout << str << endl;
    return 0;
}