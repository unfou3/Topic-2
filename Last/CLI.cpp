#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <Lmcons.h>
#include <conio.h>
#include "hobbycode.cpp"
#include "dataprocess.cpp"
#include <vector>
#include "habitc.cpp"

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
void AddStudent();
int check_user(int Sid, vector<Student> list);
void showInforesult(int Sid, vector<Student> list);

int user_id;
vector<Student> list;
vector<string> Habit_list;
vector<string> Hobby_list;

int main() {
    system("cls"); // Clear screen
    Habit_list = output_habit();
    Hobby_list = outputhb();
    list = student_retrieve("student_info.txt");
    int role = chooseUser();
    if (role != 0) {
        CLI(role);
    } else {
        std::cout << GREEN << "Exiting... Goodbye!\n" << RESET;
    }
    return 0;
}
typedef LONG(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

void showInforesult(int Sid, vector<Student> list) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].Sid == Sid) {
            std::cout << GREEN << "Name of Student " << Sid << ": " << list[i].name << "\n" << RESET;
            std::cout << GREEN << "Friends of Student " << Sid << ":\n" << RESET;
            print_vct(list[i].friendcode);
            std::cout << GREEN << "Hobbies of Student " << Sid << ":\n" << RESET;
            print_list_vct(codeToOutput(list[i].hobbies, Hobby_list));
            std::cout << GREEN << "Habits of Student " << Sid << ":\n" << RESET;
            print_list_vct(codeToOutput(list[i].habits, Habit_list));
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            return;
        }
    }

    std::cout << RED << "Student ID " << Sid << " was not found. Try again.\n" << RESET;
}

void AddStudent(){
    Student temp;
    temp.full_userin();
    list.push_back(temp);
    student_save(temp);
}
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
int check_user(int Sid, vector<Student> list) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].Sid == Sid) {
            return 1;
        }
    }
    std::cout << RED << "Student ID " << Sid << " was not found. Try again.\n" << RESET;
    return 0;
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
            std::cout << GREEN << "Enter your Student ID: " << RESET;
            std::cin >> user_id;
            if (check_user(user_id, list) == 1)
            {
                return 2; // User
            }
            else
            {
                return chooseUser();
            }

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
        std::cout << GREEN << "Welcome Student " << user_id << "\n";
        std::cout << CYAN << "0. Exit\n";
        std::cout << "1. Change | Add | Delete\n";
        std::cout << "2. Suggest Friends\n";
        std::cout << "3. Show my Information\n";
    } else if (role == 1) { // Admin Menu
        std::cout << CYAN << "0. Exit\n";
        std::cout << "1. Show as Graph\n";
        std::cout << "2. Print List\n";
        std::cout << "3. Add Student\n";
    }

    std::cout << YELLOW << "Type option: " << RESET;
}

// --- Change and Add options ---
void ChangeandAdd() {
    int option;
    std::cout << MAGENTA << "\n--- Change and Add Friends options ---\n" << RESET;
    std::cout << CYAN << "1. Add Friends\n";
    std::cout << "2. Delete\n";
    std::cout << "3. Add hobbies and habits\n";
    std::cout << "0. Back\n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {

        case 1:
            std::cout << GREEN << "\nAdd operation selected.\n" << RESET;
            std::cout << CYAN << "Enter student ID to add as friends: ";
            int x;
            cin >> x ;
            add_friend(x,user_id, list);
            std::cout << GREEN << "Operation completed \n" << RESET;
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        case 2:
            std::cout << GREEN << "\nDelete operation selected.\n" << RESET;
            std::cout << CYAN << "Enter student ID to delete as friends: ";
            int a;
            cin >> a;
            delete_friend(a,user_id, list);
            std::cout << GREEN << "Operation completed.\n" << RESET;
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        case 3:
        {
            int option2;
            std::cout << GREEN << "\nAdd habits and hobbies operation selected.\n" << RESET;
            std::cout << CYAN << "Select the option you want to change: ";
            std::cout << "1. Add hobby\n";
            std::cout << "2. Add habit\n";
            std::cout<< "0. Back\n" << RESET;
            std::cin >> option2;
            switch (option2)
            {
            case 1:
                cml_input_hobby_tx();
                break;
            
            case 2:
                cml_input_habit_tx();
                break;
            case 0:
                break;
            default:
                std::cout << RED << "Invalid option.\n" << RESET;
                break;
            }
        }
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
    std::cout << CYAN << "1. Suggest as Hobbies and Habits\n";
    std::cout << "0. Back\n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {
        case 1:
            std::cout << GREEN << "\nSuggesting friends by Hobbies and Habits...\n" << RESET;
            int x;
            std::cout << "Enter Student number of friends to suggest: ";
            cin >> x;
            print_vct(probToF(list, user_id , x));
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
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
            DisplayGraph2D(list);
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
void ShowList() {
    int option;
    std::cout << MAGENTA << "\n--- Show List ---\n" << RESET;
    std::cout << CYAN << "1. Show all List of Student \n";
    std::cout << "2. Show the Student had the most friends \n";
    std::cout << "3. Show infor of a Student \n";
    std::cout << "0. Back \n" << RESET;
    std::cout << YELLOW << "Type option: " << RESET;
    std::cin >> option;

    switch (option) {
        case 0:
            break;
        case 1:
            system("");
            std::cout << GREEN << "All of the Student with habis and hobbies\n" << RESET;
            print_full(list, Hobby_list, Habit_list);
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        case 2:
            system("");
            std::cout << GREEN << "The Students have the most numbers of friends is: \n" << RESET;
            print_vct(findLargestVector(list));
            std::cout << "    With number of friends: " << list[getord(findLargestVector(list)[0], list)].friendcode.size();

            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        case 3:
        {
            system("");
            std::cout << GREEN << "Enter Student ID: " << RESET;
            int Sid;
            cin >> Sid;
            showInforesult(Sid, list);
            std::cout << YELLOW << "\nPress any key to comeback and continue the program...\n";
            _getch(); // Chờ người dùng nhấn phím bất kỳ
            break;
        }
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
                case 3: showInforesult(user_id, list); break;
                case 0: std::cout << GREEN << "Exiting... Goodbye!\n" << RESET; break;
                default: std::cout << RED << "Invalid option. Try again.\n" << RESET;
            }
        } else if (role == 1) { // Admin
            switch (option) {
                case 1: ShowasGraph(); break;
                case 2: ShowList(); break;
                case 3: AddStudent(); break;
                case 0: std::cout << GREEN << "Exiting... Goodbye!\n" << RESET; break;
                default: std::cout << RED << "Invalid option. Try again.\n" << RESET;
            }
        }
    } while (option != 0);
}
