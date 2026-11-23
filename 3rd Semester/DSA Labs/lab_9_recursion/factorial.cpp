#include <iostream>
using namespace std;

long FACTORIAL(long FACT, int n) {
    if (n == 0) {
        FACT = 1;
        return FACT;
    }
    
    FACT = n * FACTORIAL(FACT, n - 1); 
    return FACT;
}

long factorial_iterative(int n) {
    if (n < 0) {
        throw invalid_argument("Factorial is undefined for negative numbers.");
    }
    
    long FACT = 1;
    for (int i = 1; i <= n; ++i) {
        FACT *= i;
    }
    
    return FACT;
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << ": " << FACTORIAL(0, n) << endl;
    cout << "Factorial of " << n << ": " << factorial_iterative(n) << endl;
    return 0;
}