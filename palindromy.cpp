#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string reverseString(string str) {
    string reversed;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed.push_back(str[i]);
    }
    return reversed;
}

bool isPalindrome(string line) {
    string reversed = reverseString(line);
    return line == reversed;
}

int main() {
    ifstream inputFile("text.txt");
    if (!inputFile) {
        cerr << "Plik nie istnieje." << endl;
        return 1;
    }

    int palindromeCount = 0;
    string line;
    while (getline(inputFile, line)) {
        if (isPalindrome(line)) {
            cout << "Znaleziono palindrom: " << line << endl;
            palindromeCount++;
        }
    }

    cout << "Znaleziono " << palindromeCount << " palindromow"  << endl;

    inputFile.close();
    return 0;
}
