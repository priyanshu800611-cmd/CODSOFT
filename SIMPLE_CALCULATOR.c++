#include <iostream>
using namespace std;

int main()
{
    double a, b, res;
    char op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter operator (+,-,*,/): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> b;

    switch(op)
    {
        case '+': res = a + b; cout << "Result = " << res; break;
        case '-': res = a - b; cout << "Result = " << res; break;
        case '*': res = a * b; cout << "Result = " << res; break;
        case '/': if(b!=0) { res = a / b; cout << "Result = " << res; }
                  else cout << "Division by zero not possible"; 
                  break;
        default: cout << "Invalid operator";
    }

    return 0;
}
