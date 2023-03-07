#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include "LibraySystem.h"
#include <sstream>

using namespace std;

void LibraySystem::basiclibray(){
    bookname.emplace_back("Harry Potter");
    bookname.emplace_back("Alice In Wonderland");
    bookname.emplace_back("Matilda");
    bookname.emplace_back("Stella in Underworld");
    author.emplace_back("J.K Rowling");
    author.emplace_back("C.S Lewis");
    author.emplace_back("Ronald Dahl");
    author.emplace_back("Nikki");
    type.emplace_back("Fantasy");
    type.emplace_back("Fiction");
    type.emplace_back("Children's Book");
    type.emplace_back("Non- Fiction");

    viewbooks();
}

void LibraySystem::login(int choice) {
    char buff[16];
    int pass = 0;

    cin.clear();

    printf("Is it bug, or is it a feature? \n");
    cin >> buff;

    if(strcmp(buff, "feature"))
    {
        printf ("Wrong Password \n");
    }
    else
    {
        printf ("Correct Password \n");
        pass = 1;
    }

    if(pass)
    {
        printf ("Access Granted: \n\n");
        
        if(choice ==1){
        deletebook();
        }

    }
}

void LibraySystem::addBook(){
	string book, writer, genre;
	std::stringstream ss;
	
	cin.clear();
	cin.sync();
	
	cout << "Input Book Name: " << endl;
	cin.ignore();
	getline(cin, book);
	ss << book;
	
	cout << "Input Writer: " << endl;
	getline(cin, writer);
	ss << writer;
	
	cout  << "Input Genre: " << endl;
	getline(cin, genre);
	ss << genre;
	
	bookname.emplace_back(book);
	author.emplace_back(writer);
	type.emplace_back(genre);
	
    	viewbooks();
    	std::cout <<" Thank you for returning a book! Bye now" ;
	
}

void LibraySystem :: viewbooks(){

  	cout << "Books in Collection: " << std::endl << std::endl;

    for(int i =0; i < bookname.size(); i++){
        cout << i+1 << ". " <<bookname[i] << ", " << author[i] << ", " << type[i] << endl;
    }
    
    cout << endl;
}

void LibraySystem :: deletebook(){
	int num;
	
	cout << "What Book do you want to borrow? \nInput the Number: " << endl;
	cin >> num;
	
	bookname.erase(bookname.begin()+num-1);
	author.erase(author.begin()+num-1);
	type.erase(type.begin()+num-1);
	
	viewbooks();
	showmenu();
}

void LibraySystem :: showmenu(){
	std:: cout << "----Service Menu ----- " << std::endl << "1. Borrow a book" << std::endl << "2. Add to Collection " << std::endl << "3. End Session " << std::endl;
    int choice;
    
    std::cin >> choice;
    
    if(choice == 1){
    	deletebook();
    }
    
    if(choice == 2){
    	addBook();
    }
    
    if (choice == 3){
    	cout << "Thank you for visiting! Come again soon";
    
    }


}
