#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// --- FUNCTION DECLARATIONS ---
void writetoFile(const string &filename);
void readfromFile(const string &filename);
void appendtoFile(const string & filename);

// --- MAIN FUNCTION ---
int main() {
    string filename = "notes.txt"; 
    int choice;

    do {
        cout << "------ SIMPLE NOTEPAD ------" << endl;
        cout << "1. Write File" << endl;
        cout << "2. Read File" << endl;
        cout << "3. Append File" << endl;
        cout << "4. Exit" << endl;
        cout << "\nEnter choice: ";
        
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                writetoFile(filename);
                break;
            case 2:
                readfromFile(filename);
                break;
            case 3:
                appendtoFile(filename);
                break;
            case 4:
                cout << "\nExiting notepad. Goodbye!" << endl;
                break;
            default:
                cout << "\n[Invalid Option] Please choose a number between 1 and 4.\n" << endl;
        }
    } while (choice != 4); 

    return 0;
}

// --- FUNCTION DEFINITIONS ---

// 1. Write File
void writeToFile(const string& filename) {
    ofstream outFile(filename); 
    if (!outFile) {
        cout << "\n[Error] Could not create or open the file!" << endl;
        return;
    }
    cout << "\n--- Writing to File ---" << endl;
    cout << "Enter text (Type 'END' on a new line to stop):" << endl;
    
    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        outFile << line << endl; 
    }
    outFile.close(); 
    cout << "[Success] File saved successfully.\n" << endl;
}

// 2. Read File
void readFromFile(const string& filename) {
    ifstream inFile(filename); 
    if (!inFile) {
        cout << "\n[Error] File '" << filename << "' not found! Please write to it first." << endl;
        return;
    }
    cout << "\n--- Displaying File Contents ---" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    cout << "--------------------------------\n" << endl;
    inFile.close(); 
}

// 3. Append File
void appendToFile(const string& filename) {
    fstream file;
    file.open(filename, ios::out | ios::app); 
    if (!file.is_open()) {
        cout << "\n[Error] Could not open file for appending." << endl;
        return;
    }
    cout << "\n--- Appending to File ---" << endl;
    cout << "Enter text to add (Type 'END' on a new line to stop):" << endl;
    
    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        file << line << endl; 
    }
    file.close(); 
    cout << "[Success] Content appended successfully.\n" << endl;
    return;
}
