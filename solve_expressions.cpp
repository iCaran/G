#include <iostream>
#include <fstream>
#include <cmath> // For pow() function
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ifstream inputFile("output.txt");
    ofstream outputFile("solved.cpp");

    if (!inputFile || !outputFile) {
        cout << "Error opening files." << endl;
        return 1;
    }

    string value;

    while (getline(inputFile, value)) {
    	// cout<<value<<endl;
        value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
