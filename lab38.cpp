// COMSC 210 | Lab 38 | Niko Dittmar
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

    int choice = 0;
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

        string key;
        string old_key;
        string new_key;

        switch (choice) {
            case 1: {
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
            }
            case 2: {
                cout << "Enter the key to search: ";
                cin >> key;
                int hash_index = gen_hash_index(key);
                auto it = hash_table.find(hash_index);
            
                if (it != hash_table.end() && find(it->second.begin(), it->second.end(), key) != it->second.end()) {
                    cout << "Key '" << key << "' found at hash index " << hash_index << endl;
                } else {
                    cout << "Key '" << key << "' not found." << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter the key to add: ";
                cin >> key;
                int hash_index = gen_hash_index(key);
                hash_table[hash_index].push_back(key);
                cout << "Key '" << key << "' added at hash index " << hash_index << endl;
                break;
            }
            case 4: {
                cout << "Enter the key to remove: ";
                cin >> key;
                int hash_index = gen_hash_index(key);
                auto it = hash_table.find(hash_index);
            
                if (it != hash_table.end()) {
                    auto& code_list = it->second;
                    auto code_it = find(code_list.begin(), code_list.end(), key);
                    if (code_it != code_list.end()) {
                        code_list.erase(code_it);
                        cout << "Key '" << key << "' removed." << endl;
                        if (code_list.empty()) {
                            hash_table.erase(it); // Remove empty hash index
                        }
                    } else {
                        cout << "Key '" << key << "' not found in hash index " << hash_index << endl;
                    }
                } else {
                    cout << "Key '" << key << "' not found." << endl;
                }
                break;
            }
            case 5: {
                cout << "Enter the key to modify: ";
                cin >> old_key;
            
                int old_hash_index = gen_hash_index(old_key);
                auto it = hash_table.find(old_hash_index);
            
                if (it != hash_table.end() && find(it->second.begin(), it->second.end(), old_key) != it->second.end()) {
                    cout << "Enter the new key: ";
                    cin >> new_key;
            
                    auto& code_list = it->second;
                    code_list.remove(old_key);
                    if (code_list.empty()) {
                        hash_table.erase(it);
                    }
            
                    int new_hash_index = gen_hash_index(new_key);
                    hash_table[new_hash_index].push_back(new_key);
                    cout << "Key '" << old_key << "' modified to '" << new_key << "'." << endl;
                } else {
                    cout << "Key '" << old_key << "' not found." << endl;
                }
                break;
            }
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


