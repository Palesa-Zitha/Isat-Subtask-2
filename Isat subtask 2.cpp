#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    string binary = "";
    while (decimal > 0) {
        binary = char((decimal % 2) + '0') + binary;
        decimal /= 2;
    }
    return binary;
}

// Function 2: Binary to Decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    for (char digit : binary) {
        decimal = decimal * 2 + (digit - '0');
    }
    return decimal;
}

// Function 3: Decimal to Hexadecimal
string decimalToHexadecimal(int decimal) {
    if (decimal == 0) return "0";
    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";
    while (decimal > 0) {
        hex = hexDigits[decimal % 16] + hex;
        decimal /= 16;
    }
    return hex;
}

// Function 4: Hexadecimal to Decimal
int hexadecimalToDecimal(string hex) {
    int decimal = 0;
    for (char digit : hex) {
        if (digit >= '0' && digit <= '9')
            decimal = decimal * 16 + (digit - '0');
        else if (digit >= 'A' && digit <= 'F')
            decimal = decimal * 16 + (digit - 'A' + 10);
        else if (digit >= 'a' && digit <= 'f')
            decimal = decimal * 16 + (digit - 'a' + 10);
    }
    return decimal;
}

// Function to show menu
void showMenu() {
    cout << "\nConversion Menu:\n";
    cout << "1. Convert Decimal to Binary\n";
    cout << "2. Convert Binary to Decimal\n";
    cout << "3. Convert Hexadecimal to Decimal\n";
    cout << "4. Convert Decimal to Hexadecimal\n";
    cout << "5. Demo (Generate and convert random integers to binary)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
}

int main() {
    srand(time(0)); // seed random generator
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            int decimal;
            cout << "Enter a decimal number: ";
            cin >> decimal;
            cout << "Binary representation: " << decimalToBinary(decimal) << endl;
        }
        else if (choice == 2) {
            string binary;
            cout << "Enter a binary number: ";
            cin >> binary;
            cout << "Decimal representation: " << binaryToDecimal(binary) << endl;
        }
        else if (choice == 3) {
            string hex;
            cout << "Enter a hexadecimal number: ";
            cin >> hex;
            cout << "Decimal representation: " << hexadecimalToDecimal(hex) << endl;
        }
        else if (choice == 4) {
            int decimal;
            cout << "Enter a decimal number: ";
            cin >> decimal;
            cout << "Hexadecimal representation: " << decimalToHexadecimal(decimal) << endl;
        }
        else if (choice == 5) {
            int randomNum = rand() % 100; // 0–99
            cout << "Generated random integer: " << randomNum << endl;
            cout << "Binary representation: " << decimalToBinary(randomNum) << endl;
        }
        else if (choice == 6) {
            cout << "Exiting the program.\n";
        }
        else {
            cout << "Invalid choice. Please select between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
