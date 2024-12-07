// COMSC 210 | Lab 37 | Niko Dittmar
#include <iostream>
using namespace std;

int sum_ascii(const string&);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    cout << sum_ascii("Hello World") << endl;
    cout << sum_ascii("Hello World!") << endl;
    cout << sum_ascii("A") << endl;

    return 0;
}

// sum_ascii() calculates the sum of the ASCII values of a strings characters.
// arguments: str - the string to calculate ASCII sum.
// returns: sum of ASCII values in str.
int sum_ascii(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += (int)c;
    }
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
