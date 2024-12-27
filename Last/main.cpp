#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include "CLI.cpp"


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