// COMSC 210 | Lab 37 | Niko Dittmar
#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(const string&);

int main() {
    ifstream infile("lab-37-data.txt");

    string line;
    long long total = 0;

    while (getline(infile, line)) {
        total += sum_ascii(line);
    }

    infile.close();

    cout << "Total Sum:" << total << endl;

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
