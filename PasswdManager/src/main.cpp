#include <iostream>
#include "PasswdManager.h"

int main() {
    PasswdManager manager;

    std::cout << "Welcome to PasswdManager CLI!\n";
    while (true) {
        std::cout << "\n1. Add Entry\n2. View Entries\n3. Exit\n4. Delete Entry\n5. Edit Entry\n";
        int choice;
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::string dummy;
            std::getline(std::cin, dummy);
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        switch (choice) {
        case 1:
            manager.addEntry();
            clearScreen();
            break;
        case 2:
            manager.viewEntries();
            std::cout << "Press enter to continue...";
            std::cin.ignore();
            std::cin.get();
            clearScreen();
            break;
        case 3:
            std::cout << "Goodbye!\n";
            return 0;
        case 4:
            manager.deleteEntry();
            clearScreen();
            break;
        case 5:
            manager.editEntry();
            clearScreen();
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}