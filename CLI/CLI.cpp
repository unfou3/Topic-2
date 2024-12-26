#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;
// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void showMainMenu();
void ChangeandAdd();
void SuggestFriends();
void ShowasGraph();
void ShowList();
void CLI();

int main() {
    CLI();
    return 0;
}

void showMainMenu() {
    system("cls"); // Xóa màn hình
    std::cout << YELLOW << "USER: admin      COMPUTERNAME: DESKTOP-XXXXXX    TPM: NONE | MD5: ENABLE\n";
    std::cout << CYAN <<"CURRENT OS: Windows 10 Pro  2024  100H2  19045.4291  64bit  COMPACT + DEF\n";
    std::cout << MAGENTA <<"TIME ZONE: UTC+07:00   |   Bangkok, Hanoi, Jakarta\n";
    std::cout << GREEN <<"FOLLOW US ON FACEBOOK\n\n";

    std::cout << WHITE << "Trinh | Hiep | Hai | Binh\n";
    std::cout << "---------------------------------------------\n";
    std::cout << BLUE << "\n--- Show Menu ---\n" << RESET;
    std::cout << CYAN << "1. Chinh sua | Them | Bot\n";
    std::cout << "2. Goi y tim ban\n";
    std::cout << "3. Bien dien mang bang cau truc do thi\n";
    std::cout << "4. In toan bo danh sach\n";
    std::cout << "0. Exit\n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
}

// --- Change and Add options ---
void ChangeandAdd() {
    int option;
    std::cout << MAGENTA << "\n--- Change and Add options ---\n" << RESET;
    std::cout << CYAN << "1. Change\n";
    std::cout << "2. Add\n";
    std::cout << "3. Delete\n";
    std::cout << "0. Back\n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {
        case 1:
            system("");
            std::cout << GREEN << "\n" << RESET;
            break;
        case 2:
            system("");
            std::cout << GREEN << "\n" << RESET;
            break;
        case 3:
            system("");
            std::cout << GREEN << "\n" << RESET;
            break;
        case 0:
            break;
        default:
            std::cout << RED << "Invalid option.\n" << RESET;
    }
}

// --- Suggest Friends Optiones ---
void SuggestFriends() {
    int option;
    std::cout << MAGENTA << "\n--- Suggest Friends Optiones ---\n" << RESET;
    std::cout << CYAN << "1. Suggest as Hobby\n";
    std::cout << "2. Suggest as Habit\n";
    std::cout << "3. Suggest as \n";
    std::cout << "0. Back\n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {
        case 1:
            system("");
            std::cout << GREEN << "\n" << RESET;
            break;
        case 2:
            system("");
            std::cout << GREEN << "\n" << RESET;
            break;
        case 3:
            system("");
            std::cout << GREEN << "\n" << RESET;
            break;
        case 0:
            break;
        default:
            std::cout << RED << "\n" << RESET;
    }
}

// --- Show as Graph ---
void ShowasGraph() {
    int option;
    std::cout << MAGENTA << "\n--- Show as Graph ---\n" << RESET;
    std::cout << CYAN << "1. Show\n";
    std::cout << "0. Back\n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {
        case 1:
            system("");
            std::cout << GREEN << "\n" << RESET;
            break;
        case 0:
            break;
        default:
            std::cout << RED << "Invalid option.\n" << RESET;
    }
}

// --- Show List ---
void ShowList() {
    int option;
    std::cout << MAGENTA << "\n--- Show List ---\n" << RESET;
    std::cout << CYAN << "1. \n";
    std::cout << "2. \n";
    std::cout << "3. \n";
    std::cout << "0. \n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {
        case 1:
            system("");
            std::cout << GREEN << "\n" << RESET;
            break;
        case 2:
            system("");
            std::cout << GREEN << "\n" << RESET;
            break;
        case 3:
            system("");
            std::cout << GREEN << "n" << RESET;
            break;
        case 0:
            break;
        default:
            std::cout << RED << "Invalid option.\n" << RESET;
    }
}
void CLI(){
    int option;
    do {
        showMainMenu();
        std::cin >> option;

        switch (option) {
            case 1: ChangeandAdd(); break;
            case 2: SuggestFriends(); break;
            case 3: ShowasGraph(); break;
            case 4: ShowList(); break;
            case 0: std::cout << GREEN << "Exiting... Goodbye!\n" << RESET; break;
            default: std::cout << RED << "Invalid option. Try again.\n" << RESET;
        }
    } while (option != 0);

}