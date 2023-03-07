#include <iostream>
#include "LibraySystem.h"
int main() {
    LibraySystem l;

    std:: cout << "Welcome to the Virtual Library! " << std::endl;

    l.basiclibray();

    std:: cout << "----Service Menu ----- " << std::endl << "1. Borrow a book" << std::endl << "2. Add to Collection " << std::endl << "3. End Session " << std::endl;
    int choice;
    std::cin >> choice;

    if(choice == 1){
        std::cout << "REAL COMPUTER SCIENCER CHECK: \n" << std::endl;
        l.login(choice);
    }

    else if (choice ==2 ) {
    	l.addBook();
    }
    
    else {
   	std::cout <<"Thank you! " <<std::endl;;
    }

    return 0;
}
