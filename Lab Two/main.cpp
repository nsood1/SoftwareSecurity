#include <iostream>
#include "LibraySystem.h"
int main() {
    LibrayManagementSystem l;

    std:: cout << "Welcome to the Virtual Library! " << std::endl << std::endl << "Currently in our collection we have: " << std::endl << std::endl;

    l.basiclibray();

    std:: cout << "----Service Menu ----- " << std::endl << "1. Borrow a book" << std::endl << "2. Add to Collection " << std::endl << "3. End Session " << std::endl;
    int choice;
    std::cin >> choice;

    if(choice == 1 || choice == 2){
        std::cout << "REAL COMPUTER SCIENCER CHECK: " << std::endl;
        l.login();
    }

    else {

    }

    return 0;
}
