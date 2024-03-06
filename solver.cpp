#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "muParser.h"

double evaluateExpression(const std::string& expression, double a, double b, double c, double d, double e, double f) {
    mu::Parser parser;
    parser.DefineVar("a", &a);
    parser.DefineVar("b", &b);
    parser.DefineVar("c", &c);
    parser.DefineVar("d", &d);
    parser.DefineVar("e", &e);
    parser.DefineVar("f", &f);

    parser.SetExpr(expression);
    return parser.Eval();
}

int main() {
    std::ifstream inputFile("output.txt");
    if (!inputFile.is_open()) {
        std::cout << "Error opening the file.\n";
        return 1;
    }

    double a, b, c, d, e, f;
    std::string expression;
    while (inputFile >> expression) {
        std::cout << "Enter the values of a, b, c, d, e, and f: ";
        std::cin >> a >> b >> c >> d >> e >> f;

        double result = evaluateExpression(expression, a, b, c, d, e, f);
        std::cout << "Result: " << result << std::endl;
    }

    inputFile.close();
    return 0;
}
