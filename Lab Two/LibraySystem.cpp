//
// Created by Nicole Sood on 26/02/2023.
//
#include <iostream>
#include <vector>
#include <fstream>
#include "LibraySystem.h"
using namespace std;

void LibrayManagementSystem::basiclibray(){
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

    for(int i =0; i < bookname.size(); i++){
        cout << bookname[i] << " " << author[i] << " " << type[i] << endl;
    }
}

void LibrayManagementSystem::login() {
    char buff[10];
    int pass = 0;

    cin.clear();

    printf("Is it bug, or is it a feature? \n");
    //gets(buff);
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
        /* Now Give root or admin rights to user*/
        printf ("\n Root privileges given to the user \n");
    }
}

void LibrayManagementSystem::addBook(){

}