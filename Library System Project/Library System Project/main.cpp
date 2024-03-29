//
//  main.cpp
//  Library System Project
//
//  Created by Yousef Emad on 29/03/2024.
//

#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;
// Main Menu
void mainMenu(string name) {
    cout << "==========================\n";
    cout << "  Welcome to "<< name << "\n";
    cout << "==========================\n\n";
    cout << "Please choose an option from below\n\n";
    cout << "1. Add a book\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Delete a book\n";
    cout << "5. List all books info\n";
    cout << "6. How many books in library\n";
    cout << "7. Exit\n\n";
    cout << "Your choice : ";
}


int Book::iD_Helper = 10000;
int Library::bookCount = 0;
Library* Library::instance = nullptr;

int main(){
    Library* AlexLibrary = Library::getinstance("AlexLibrary");
        string title, authorName, authorEmail;
        bool flag = true;
        int choice, bookId;

    while(flag){
        mainMenu(AlexLibrary->getName());
        cin >> choice;
        cout << endl;
        switch (choice){
            case 1://add
                cout << "Please enter book title\n";
                cin.ignore();
                getline(cin, title);
                cout << "\nPlease enter book author name\n";
                getline(cin, authorName);
                cout << "\nPlease enter book author email\n";
                getline(cin, authorEmail);
                AlexLibrary->addBook(Book(title,authorName,authorEmail));
                    break;
            case 2://borrow
                cout << "Please enter id of the book you want to borrow\n";
                cin >> bookId;
                AlexLibrary->borrowBook(bookId);
                    break;
            case 3://return
                cout << "Please enter id of the book you want to return\n";
                cin >> bookId;
                AlexLibrary->returnBook(bookId);
                    break;
            case 4://delete
                cout << "Please enter id of the book you want to delete\n";
                cin >> bookId;
                AlexLibrary->removeBook(bookId);
                    break;
            case 5://list
                    AlexLibrary->dispalyBooks();
                    break;
            case 6://booksCount
                AlexLibrary->getBookCount();
                    break;
            case 7://exit
                cout << "Bye Bye\n";
                flag = false;
                break;
            default:cout<<"ivalid choice\n";
                break;
        }
        
    }

    delete AlexLibrary;

    return 0;

}
