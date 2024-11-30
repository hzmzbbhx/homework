#ifndef _EVALUATOR_H
#define _EVALUATOR_H

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

int youxianji(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double Operation(double a, double b, char op) 
{
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) 
            {
                throw runtime_error("IILEGAL: Division by zero!");
            }
            return a / b;
        default:
            throw runtime_error("IILEGAL: Illegal operation!");//理论上会先报错Error: Invalid character，但是不写这行编译器会警告
    }
}

double transformer(const string& str) 
{
    stringstream ss(str);
    double value;
    ss >> value;
    return value;
}

double evaluate(const string& expression) 
{
    stack<double> values; 
    stack<char> ops;      

    char lastChar = ' ';

    for (int i = 0; i < expression.length(); i++) 
    {
        if (expression[i] == ' ')  continue;

        if (isdigit(expression[i]) || expression[i] == '.') 
        {
            string number;
            while (i < expression.length() &&
                   (isdigit(expression[i]) || expression[i] == '.' || expression[i] == 'e' || expression[i] == 'E')) 
            {
                number += expression[i++];
            }
            i--; 
            values.push(transformer(number)); 
            lastChar = 'n'; 
        }

        else if (expression[i] == '(') 
        {
            ops.push(expression[i]);
            lastChar = '('; 
        }

        else if (expression[i] == ')') 
        {
            while (!ops.empty() && ops.top() != '(') 
            {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(Operation(val1, val2, op));
            }
            if (ops.empty() || ops.top() != '(') 
            {
                throw runtime_error("IILEGAL: Mismatched parentheses!");
            }
            ops.pop(); 
            lastChar = ')'; 
        }

        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') 
        {
            if (expression[i] == '-') 
            {
                if (lastChar == ' ' || lastChar == '(' || lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/') 
                {
                    i++; 
                    string number;
                    while (i < expression.length() &&
                           (isdigit(expression[i]) || expression[i] == '.' || expression[i] == 'e' || expression[i] == 'E')) 
                    {
                        number += expression[i++];
                    }
                    i--; 
                    values.push(-transformer(number)); 
                    lastChar = 'n'; 
                    continue; 
                }
            }

            if (lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/') 
            {
                throw runtime_error("IILEGAL: Invalid expression! Operator cannot follow operator.");
            }

            while (!ops.empty() && youxianji(ops.top()) >= youxianji(expression[i])) 
            {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(Operation(val1, val2, op));
            }
            ops.push(expression[i]); 
            lastChar = expression[i]; 
        } 
        else 
        {
            throw runtime_error("IILEGAL: Invalid character");
        }
    }

    while (!ops.empty()) 
    {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(Operation(val1, val2, op));
    }

    return values.top(); 
}

#endif