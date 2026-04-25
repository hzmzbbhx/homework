#include <iostream>
#include <string>
#include <iomanip>
#include "evaluator.h"

using namespace std;

void print(const string& expression, int n) 
{
    try 
    {
        double result = evaluate(expression);
        cout << expression << " = " << fixed << setprecision(n) << result << endl;
    } 
    catch (const runtime_error& e) 
    {
        cout << expression << " - " << e.what() << endl; 
    }
}

int main() 
{
    string expressions[] = 
    {
        "((3.14 + 2.71) * (1.41 - 0.41)) + (5.0 / 2.0)",
        "(10.0 - (3.5 * 4.2)) + (15.6 / 2.1)",
        "((8.0 / 2.0) * (3.0 + 2.0)) - (7.2 - 4.5)",
        "(5.5 + (3.3 * 2.2)) / (1.1 * 9.0)",
        "((2.0 * (1.0 + 5.0)) / (3.0 - 2.0)) + (9.9 * 0.1)",
        "(4.5 * (3.3 - 2.2)) + ((5.5 - 1.5) / 2.6)",
        "((2.5 + 3.0) * (5.0 - 1.0)) + (0.5 * 7.5)",
        "((9.9 / 3.3) - 1.0) * (2.0 + 4.0)",
        "(((8.0 + 2.5) / 2.5) * (3.0 - 0.9)) + 5.0",
        "(10.0 - (2.0 * (3.0 + 7.0))) / (2.0 * 2.0)",
        "1e5 + 1",
        "1 + - 1",
        "-1 + 2",
        "1 / 0",
        "1 + + 1",
        "1 + 2)",
        "?"
    };

    for (const auto& expr : expressions) 
    {
        print(expr, 4); 
    }

    return 0;
}