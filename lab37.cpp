// COMSC 210 | Lab 37 | Niko Dittmar
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(const string&);

int main() {
    ifstream infile("lab-37-data.txt");

    map<int, list<string> > hash_table;

    string line;

    while (getline(infile, line)) {
        int hash_index = gen_hash_index(line);
        hash_table[hash_index].push_back(line);
    }

    infile.close();

    int count = 0;
    for (const auto& entry : hash_table) {
        if (count >= 100) break;
        cout << "Hash Index: " << entry.first << ", Codes: ";
        for (const string& code : entry.second) {
            cout << code << " ";
        }
        cout << endl;
        count++;
    }

    return 0;
}

// gen_hash_index() calculates the hash index of a string.
// arguments: str - the string to calculate hash index.
// returns: hash index.
int gen_hash_index(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += (int)c;
    }
    return sum % 97;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
