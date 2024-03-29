//
//  Library.h
//  Library System Project
//
//  Created by Yousef Emad on 29/03/2024.
//

#ifndef Library_h
#define Library_h
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Library{
    // attribut
private:
    string name;
    vector<Book>books;
    // Static instance
    static Library* instance;
    // private constructor to privant instance
    Library(string name): name(name){};
    
public:
    static int bookCount;
    void getBookCount(){
        cout << name << " has " << bookCount <<" books. "<<endl;
    }
    // Static member function to get the instance of the class
    static Library*  getinstance(string name){
        // Create the instance if it does not exist
        if (instance == nullptr){
            instance = new Library(name);
        }
        return instance;
    }
    string  getName(){
        return name;
    }
    //  Add Methods
    void addBook(const Book& book){
        books.push_back(book);
        bookCount++;
    }
    
    // Search Methods
    int searchBook(int iD){
        bool found = false;
        int booksize = books.size();
        for (int i = 0; i < booksize; i++){
            if(books[i].getID() == iD){
                found = true;
                cout << books[i].get_Title()<< "is found\n";
                return i;
            }
        }
        if(!found){
            cout << "invaid id \n";
        }
        return -1; // if book not found;
    }
    
    // Remove Methods
    void removeBook(int iD){
        int bookIndex  = searchBook(iD);
        if (bookIndex == -1)return;
        cout<<books[bookIndex].get_Title()<<" is deleted successfully\n";
        books.erase(books.begin()  + bookIndex);
        bookCount --;
    }
    
    // BorrowBook
    void borrowBook(int iD){
        int bookIndex = searchBook(iD);
        if(bookIndex == -1)return;
        if(books[bookIndex].getStatus() == "NotAvaliable"){
            cout << books[bookIndex].get_Title()<<" is not available now for borrowing.\n";
            return;
        }
        books[bookIndex].setStatus("NotAvailable");
        cout<<books[bookIndex].get_Title()<<" is borrowed successfully\n";
    }
    
    // Return Book
    void returnBook(int iD){
        int bookIndex = searchBook(iD);
        if(bookIndex == -1)return;
        if(books[bookIndex].getStatus() == "Available"){
            cout << books[bookIndex].get_Title()<<"is already available\n";
            return;
        }
        books[bookIndex].setStatus("Available");
        cout << books[bookIndex].get_Title()<< "is returned successfully\n";
    }
    
    // display
    void dispalyBooks(){
        if(books.size() == 0){
            cout << "Library is empty\n";
            return;
        }
        for(Book book:books){
            book.displayBookInfo();
        }

    }
};

#endif /* Library_h */
