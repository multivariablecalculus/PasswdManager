#include "PasswdManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

PasswdManager::PasswdManager() {
    loadEntries();
}

void PasswdManager::addEntry() {
    Entry entry;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Service: ";
    std::getline(std::cin, entry.service);
    std::cout << "Username: ";
    std::getline(std::cin, entry.username);
    std::cout << "Password: ";
    std::getline(std::cin, entry.password);
    entries.push_back(entry);
    saveEntries();
    std::cout << "Entry added!\n";
}

void PasswdManager::viewEntries() const {
    if (entries.empty()) {
        std::cout << "No entries.\n";
        return;
    }
    for (size_t i = 0; i < entries.size(); ++i) {
        std::cout << i + 1 << ".\n";
        std::cout << "  Service: " << entries[i].service << "\n";
        std::cout << "  Username: " << entries[i].username << "\n";
        std::cout << "  Password: " << entries[i].password << "\n";
        std::cout << "---------------------\n";
    }
}

void PasswdManager::deleteEntry() {
    if (entries.empty()) {
        std::cout << "No entries to delete.\n";
        return;
    }
    viewEntries();
    std::cout << "Enter the number of the entry to delete: ";
    size_t idx;
    std::cin >> idx;
    if (std::cin.fail() || idx < 1 || idx > entries.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid entry number.\n";
        return;
    }
    entries.erase(entries.begin() + idx - 1);
    saveEntries();
    std::cout << "Entry deleted!\n";
}

void PasswdManager::editEntry() {
    if (entries.empty()) {
        std::cout << "No entries to edit.\n";
        return;
    }
    viewEntries();
    std::cout << "Enter the number of the entry to edit: ";
    size_t idx;
    std::cin >> idx;
    if (std::cin.fail() || idx < 1 || idx > entries.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid entry number.\n";
        return;
    }
    Entry& entry = entries[idx - 1];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Edit Service (current: " << entry.service << "): ";
    std::string newService;
    std::getline(std::cin, newService);
    if (!newService.empty()) entry.service = newService;
    std::cout << "Edit Username (current: " << entry.username << "): ";
    std::string newUsername;
    std::getline(std::cin, newUsername);
    if (!newUsername.empty()) entry.username = newUsername;
    std::cout << "Edit Password (current: " << entry.password << "): ";
    std::string newPassword;
    std::getline(std::cin, newPassword);
    if (!newPassword.empty()) entry.password = newPassword;
    saveEntries();
    std::cout << "Entry updated!\n";
}

void PasswdManager::saveEntries() const {
    std::ofstream ofs(filename);
    for (const auto& entry : entries) {
        ofs << entry.service << '\n'
            << entry.username << '\n'
            << entry.password << '\n';
    }
}

void PasswdManager::loadEntries() {
    entries.clear();
    std::ifstream ifs(filename);
    std::string service, username, password;
    while (std::getline(ifs, service) &&
        std::getline(ifs, username) &&
        std::getline(ifs, password)) {
        entries.push_back({ service, username, password });
    }
}