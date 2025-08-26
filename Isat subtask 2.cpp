#include <iostream>
#include <bitset>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <regex>  // For input validation

using namespace std;

// Convert decimal to 16-bit binary
string decimalToBinary(int decimal) {
    return bitset<16>(decimal).to_string();
}

// Convert binary string to decimal
int binaryToDecimal(const string& binary) {
    if (!regex_match(binary, regex("^[01]+$"))) {
        throw invalid_argument("Invalid binary input.");
    }
    return static_cast<int>(stoul(binary, nullptr, 2));
}

// Convert decimal to hexadecimal (uppercase)
string decimalToHexadecimal(int decimal) {
    stringstream ss;
    ss << hex << uppercase << decimal;
    return ss.str();
}

// Convert hexadecimal string to decimal
int hexadecimalToDecimal(const string& hexValue) {
    if (!regex_match(hexValue, regex("^[0-9A-Fa-f]+$"))) {
        throw invalid_argument("Invalid hexadecimal input.");
    }
    return static_cast<int>(stoul(hexValue, nullptr, 16));
}

// Demo: generate random number and show binary
void demo() {
    srand(static_cast<unsigned>(time(0)));
    int randomNumber = rand() % 100;
    cout << "Random number: " << randomNumber << "\n";
    cout << "Binary: " << decimalToBinary(randomNumber) << "\n";
}

// Display menu
void showMenu() {  
    cout << "\n=== Conversion Menu ===\n";
    cout << "1. Decimal to Binary\n";
    cout << "2. Binary to Decimal\n";
    cout << "3. Decimal to Hexadecimal\n";
    cout << "4. Hexadecimal to Decimal\n";
    cout << "5. Demo (Random Binary Conversion)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        try {
            switch (choice) {
                // If choice == 1, run this block
                case 1: {
                    int decimal;
                    cout << "Enter a decimal number: ";
                    cin >> decimal;
                    cout << "Binary: " << decimalToBinary(decimal) << "\n";
                    break;
                }
                // If choice  == 2, run this block
                case 2: {
                    string binary;
                    cout << "Enter a binary number: ";
                    cin >> binary;
                    cout << "Decimal: " << binaryToDecimal(binary) << "\n";
                    break;
                }
                // If choice == 3, run this block
                case 3: {
                    int decimal;
                    cout << "Enter a decimal number: ";
                    cin >> decimal;
                    cout << "Hexadecimal: " << decimalToHexadecimal(decimal) << "\n";
                    break;
                }
                // If choice == 4, run this block
                case 4: {
                    string hexValue;
                    cout << "Enter a hexadecimal number: ";
                    cin >> hexValue;
                    cout << "Decimal: " << hexadecimalToDecimal(hexValue) << "\n";
                    break;
                }
                // If choice == 5, run this code
                case 5: {
                    demo();
                    break;
                }
                // If choice == 6, run this code
                case 6:
                    cout << "Exiting program. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please select between 1 and 6.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }

    } while (choice != 6);

    return 0;
}
