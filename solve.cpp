#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("output.txt");
    ofstream outputFile("solved.cpp");

    if (!inputFile || !outputFile) {
        cout << "Error opening files." << endl;
        return 1;
    }

    string value;
    short int count = 0;

    if (outputFile.is_open()) {
        outputFile << "#include <iostream>\n";
        outputFile << "#include <cmath>\n";
        outputFile << "using namespace std;\n\n";
        outputFile << "void ikine(float a=0.8, float b=0, float c=0, float d=0, float e=0, float f=0) {\n";
        while (getline(inputFile, value)) {
            value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
            outputFile << "\tfloat th" << ++count << " = " << value << ";\n\n";
            outputFile << "\tcout << th" << count << " << endl;\n\n";
        }

        outputFile << "}\n\n";
        outputFile << "int main(){\n";
        outputFile << "\tikine();\n";
        outputFile << "\treturn 0;\n";
        outputFile << "}\n";

    }

    inputFile.close();
    outputFile.close();

    return 0;
}
