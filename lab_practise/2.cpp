#include <iostream>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    // Calculate and display the factorial
    int result = factorial(num);
    std::cout << "Factorial of " << num << " is: " << result << std::endl;

    return 0;
}
