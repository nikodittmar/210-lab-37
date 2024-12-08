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

    int choice;
    do {
        cout << "\n####### LAB 38 MENU #######\n";
        cout << "[1] Print first 100 entries\n";
        cout << "[2] Search for a key\n";
        cout << "[3] Add a key\n";
        cout << "[4] Remove a key\n";
        cout << "[5] Modify a key\n";
        cout << "[6] Exit Program\n";
        cout << "Your choice --> ";
        cin >> choice;

        switch (choice) {
            case 1:
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
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

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


