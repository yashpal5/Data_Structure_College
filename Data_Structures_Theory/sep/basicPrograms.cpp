#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits
#include <algorithm> // Required for reverse

// --- Function Prototypes ---
// It's good practice to declare functions before main, even if defined later,
// or just define them before main. For this single-file structure, we'll define them here.

void printMenu() {
    std::cout << "\n===== C++ Multi-Tool Menu =====\n";
    std::cout << "1. Fibonacci Series Generator\n";
    std::cout << "2. Palindrome Checker\n";
    std::cout << "3. Factorial Calculator\n";
    std::cout << "4. Basic Calculator\n";
    std::cout << "5. Temperature Converter\n";
    std::cout << "6. Exit\n";
    std::cout << "===============================\n";
    std::cout << "Enter your choice: ";
}

void fibonacciSeries() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    std::cout << "\n--- Fibonacci Series ---\n";
    std::cout << "Enter the number of terms: ";
    std::cin >> n;

    // Input validation for non-integer or negative inputs
    if (std::cin.fail() || n < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer.\n";
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
        return;
    }

    std::cout << "Fibonacci Series: ";
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            std::cout << t1 << " ";
            continue;
        }
        if (i == 2) {
            std::cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        std::cout << nextTerm << " ";
    }
    std::cout << std::endl;
}

// Updated Palindrome Checker without using std::reverse
void palindromeChecker() {
    std::string text;
    std::cout << "\n--- Palindrome Checker ---\n";
    std::cout << "Enter a word or number: ";
    std::cin >> text;

    bool isPalindrome = true;
    int left = 0;
    int right = text.length() - 1;

    // Loop from both ends of the string towards the center
    while (left < right) {
        // If characters at the pointers do not match, it's not a palindrome
        if (text[left] != text[right]) {
            isPalindrome = false;
            break; // Exit the loop early
        }
        // Move pointers inward
        left++;
        right--;
    }

    if (isPalindrome) {
        std::cout << "'" << text << "' is a palindrome.\n";
    } else {
        std::cout << "'" << text << "' is not a palindrome.\n";
    }
}

void factorialCalculator() {
    int n;
    long long factorial = 1; // Use long long for larger factorial values
    std::cout << "\n--- Factorial Calculator ---\n";
    std::cout << "Enter a non-negative integer: ";
    std::cin >> n;

    if (std::cin.fail() || n < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (n > 20) {
        std::cout << "Input is too large. Factorial for numbers > 20 exceeds the long long range.\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    std::cout << "Factorial of " << n << " = " << factorial << std::endl;
}

void basicCalculator() {
    char op;
    double num1, num2;
    std::cout << "\n--- Basic Calculator ---\n";
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter two operands: ";
    std::cin >> num1 >> num2;
    
    if (std::cin.fail()) {
        std::cout << "Invalid number input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (op) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error! Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Error! Operator is not correct.\n";
            break;
    }
}

void temperatureConverter() {
    int choice;
    double temp, convertedTemp;
    std::cout << "\n--- Temperature Converter ---\n";
    std::cout << "1. Celsius to Fahrenheit\n";
    std::cout << "2. Fahrenheit to Celsius\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if (std::cin.fail()) {
        std::cout << "Invalid choice.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (choice) {
        case 1:
            std::cout << "Enter temperature in Celsius: ";
            std::cin >> temp;
            convertedTemp = (temp * 9.0 / 5.0) + 32;
            std::cout << temp << " C is " << convertedTemp << " F\n";
            break;
        case 2:
            std::cout << "Enter temperature in Fahrenheit: ";
            std::cin >> temp;
            convertedTemp = (temp - 32) * 5.0 / 9.0;
            std::cout << temp << " F is " << convertedTemp << " C\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }
}


int main() {
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        // Input validation for the menu choice
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
            std::cin.clear(); // Clear the error flag
            // Discard the rest of the line to prevent an infinite loop
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0; // Set choice to a value that won't exit but will trigger the default case
        }


        switch (choice) {
            case 1:
                fibonacciSeries();
                break;
            case 2:
                palindromeChecker();
                break;
            case 3:
                factorialCalculator();
                break;
            case 4:
                basicCalculator();
                break;
            case 5:
                temperatureConverter();
                break;
            case 6:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}