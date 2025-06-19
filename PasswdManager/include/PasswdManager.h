#pragma once
#include <vector>
#include <string>
#include <cstdlib>

struct Entry {
    std::string service;
    std::string username;
    std::string password;
};

inline void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class PasswdManager {
public:
    PasswdManager();
    void addEntry();
    void viewEntries() const;
    void deleteEntry();
    void editEntry();
    void saveEntries() const;
    void loadEntries();
private:
    std::vector<Entry> entries;
    const std::string filename = "entries.txt";
};