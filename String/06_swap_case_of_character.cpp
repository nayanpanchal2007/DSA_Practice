#include <iostream>
using namespace std;

string swap_case(string s) {
    string ans = "";
    
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            ans += toupper(c);
        } else if (c >= 'A' && c <= 'Z') {
            ans += tolower(c);
        } else {
            ans += c;
        }
    }

    return ans;
}

int main() {
    cout << swap_case("Hello World") << endl;
    cout << swap_case("C++ is high level language.") << endl;
    cout << swap_case("C++ and Java both are Object Oriented languages.") << endl;
    
    return 0;
}