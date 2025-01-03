#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <Lmcons.h>
#include <conio.h>

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

void showMainMenu(int role);
void ChangeandAdd();
void SuggestFriends();
void ShowasGraph();
void ShowList();
void CLI(int role);
int chooseUser();
void printSystemInfo();

int main() {
    int role = chooseUser();
    if (role != 0) {
        CLI(role);
    } else {
        std::cout << GREEN << "Exiting... Goodbye!\n" << RESET;
    }
    return 0;
}
typedef LONG(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

void printSystemInfo() {
    // Lấy tên máy tính
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    if (GetComputerNameA(computerName, &size)) {
        std::cout << YELLOW << "COMPUTER NAME: " << computerName << "\n";
    } else {
        std::cerr << "Failed to get computer name.\n";
    }

    // Lấy tên người dùng
    char userName[UNLEN + 1]; // UNLEN được định nghĩa trong <Lmcons.h>
    size = sizeof(userName);
    if (GetUserNameA(userName, &size)) {
        std::cout << CYAN << "USER NAME: " << userName << "\n";
    } else {
        std::cerr << "Failed to get user name.\n";
    }

    // Lấy thông tin hệ điều hành
    RTL_OSVERSIONINFOEXW osvi;
    ZeroMemory(&osvi, sizeof(osvi));
    osvi.dwOSVersionInfoSize = sizeof(osvi);

    RtlGetVersionPtr fnRtlGetVersion = (RtlGetVersionPtr)GetProcAddress(
        GetModuleHandleA("ntdll.dll"), "RtlGetVersion");

    if (fnRtlGetVersion != nullptr) {
        if (fnRtlGetVersion((PRTL_OSVERSIONINFOW)&osvi) == 0) {
            std::cout << BLUE << "OS VERSION: " << osvi.dwMajorVersion << "."
                      << osvi.dwMinorVersion << " (Build " << osvi.dwBuildNumber << ")\n";
        } else {
            std::cerr << "Failed to get OS version.\n";
        }
    } else {
        std::cerr << "RtlGetVersion not available.\n";
    }

    // Lấy thông tin múi giờ
    TIME_ZONE_INFORMATION tzInfo;
    if (GetTimeZoneInformation(&tzInfo) != TIME_ZONE_ID_INVALID) {
        std::wcout << RED << L"TIME ZONE: " << tzInfo.StandardName << L" (UTC "
                   << tzInfo.Bias / -60 << L")\n";
    } else {
        std::cerr << "Failed to get time zone information.\n";
    }
}

// --- Choose User Role ---
int chooseUser() {
    int option;
    std::cout << MAGENTA << "Who are you?\n";
    std::cout << CYAN << "1. Admin\n";
    std::cout << "2. User\n";
    std::cout << "0. Exit\n";
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {
        case 1:
            return 1; // Admin
        case 2:
            return 2; // User
        case 0:
            return 0; // Exit
        default:
            std::cout << RED << "Invalid option. Try again.\n" << RESET;
            return chooseUser();
    }
}

// --- Show Main Menu ---
void showMainMenu(int role) {
    system("cls"); // Clear screen
    printSystemInfo();
    std::cout << GREEN << "FOLLOW US ON FACEBOOK\n\n";
    std::cout << WHITE << "Trinh | Hiep | Hai | Binh\n";
    std::cout << "---------------------------------------------\n";
    std::cout << BLUE << "\n--- Main Menu ---\n" << RESET;

    if (role == 2) { // Normal User Menu
        std::cout << CYAN << "0. Exit\n";
        std::cout << "1. Change | Add | Delete\n";
        std::cout << "2. Suggest Friends\n";
    } else if (role == 1) { // Admin Menu
        std::cout << CYAN << "0. Exit\n";
        std::cout << "1. Show as Graph\n";
        std::cout << "2. Print List\n";
    }

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
            std::cout << GREEN << "Change operation selected.\n" << RESET;
            break;
        case 2:
            std::cout << GREEN << "Add operation selected.\n" << RESET;
            break;
        case 3:
            std::cout << GREEN << "Delete operation selected.\n" << RESET;
            break;
        case 0:
            break;
        default:
            std::cout << RED << "Invalid option.\n" << RESET;
    }
}

// --- Suggest Friends Options ---
void SuggestFriends() {
    int option;
    std::cout << MAGENTA << "\n--- Suggest Friends Options ---\n" << RESET;
    std::cout << CYAN << "1. Suggest as Hobby\n";
    std::cout << "2. Suggest as Habit\n";
    std::cout << "3. Suggest as Other\n";
    std::cout << "0. Back\n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {
        case 1:
            std::cout << GREEN << "Suggesting friends by Hobby...\n" << RESET;
            break;
        case 2:
            std::cout << GREEN << "Suggesting friends by Habit...\n" << RESET;
            break;
        case 3:
            std::cout << GREEN << "Suggesting friends by Other criteria...\n" << RESET;
            break;
        case 0:
            break;
        default:
            std::cout << RED << "Invalid option.\n" << RESET;
    }
}

// --- Show as Graph ---
void ShowasGraph() {
    int option;
    std::cout << MAGENTA << "\n--- Show as Graph ---\n" << RESET;
    std::cout << CYAN << "1. Show as adjacency matrix\n";
    std::cout << "2.Show as png\n";
    std::cout << "0. Back\n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {
        case 1:
            system("");
            std::cout << GREEN << "\n" << RESET;
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        case 2:
            system("");
            std::cout << GREEN << "\n" << RESET;
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        case 0:
            break;
        default:
            std::cout << RED << "Invalid option.\n" << RESET;
    }

}

// --- Show List ---
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
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        case 2:
            system("");
            std::cout << GREEN << "\n" << RESET;
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        case 3:
            system("");
            std::cout << GREEN << "n" << RESET;
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        case 0:
            break;
        default:
            std::cout << RED << "Invalid option.\n" << RESET;
    }
}

// --- Command Line Interface ---
void CLI(int role) {
    int option;
    do {
        showMainMenu(role);
        std::cin >> option;

        if (role == 2) { // Normal User
            switch (option) {
                case 1: ChangeandAdd(); break;
                case 2: SuggestFriends(); break;
                case 0: std::cout << GREEN << "Exiting... Goodbye!\n" << RESET; break;
                default: std::cout << RED << "Invalid option. Try again.\n" << RESET;
            }
        } else if (role == 1) { // Admin
            switch (option) {
                case 1: ShowasGraph(); break;
                case 2: ShowList(); break;
                case 0: std::cout << GREEN << "Exiting... Goodbye!\n" << RESET; break;
                default: std::cout << RED << "Invalid option. Try again.\n" << RESET;
            }
        }
    } while (option != 0);
}
