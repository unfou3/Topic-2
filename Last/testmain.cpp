#include "CLI.cpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include "hobbycode.cpp"
#include "dataprocess.cpp"
#include "habitc.cpp"

int main(){
    system("cls"); // Clear screen
    int role = chooseUser();
    if (role != 0) {
        CLI(role);
    } else {
        std::cout << GREEN << "Exiting... Goodbye!\n" << RESET;
    }
}