//
//  Book.h
//  Library System Project
//
//  Created by Yousef Emad on 29/03/2024.
//

#ifndef Book_h
#define Book_h
#include <iostream>
#include <string>
using namespace std;

// Create Class
class Author{
    // Attribu
private:
    string name;
    string email;
    
public:
    // Constructor
    Author(){};
    Author(string name){
        this -> name = name;
    }
    Author(string name, string email): name(name), email(email){};
    
    // getter methods
    string get_Email(){
        return email;
    }
    string getName(){
        return name;
    }
    // SetM
    void set_Email(string email){
        this -> email = email;
    }
    // Print Methods
    void print(){
        cout << "Author's Name: "<< name << endl;
        cout << "Author's Email: "<< email << endl;
    }
};

#endif /* Book_h */

class Book{
    // attri
private:
    int iD;
    string title;
    Author writer;
    string status; // Avaliable or Not Avaliable
    
public:
    static int iD_Helper;
    // Constructor
    Book(){};
    Book(string title, const Author &writer) : title(title), status("Available") {
            iD_Helper++;
            iD = iD_Helper;
            this->writer = writer;
        }
    Book(string title, string name, string email) : title(title), writer(name, email), status("Available"){
        iD_Helper++;
        iD = iD_Helper;
    }
    // Getter Methos
    int getID(){
        return iD;
    }
    string get_Title(){
        return title;
    }
    string getWriterName(){
        return writer.getName();
    }
    string getStatus(){
        return status;
    }
    // set
    void setStatus(string status){
        this -> status = status;
    }
    //  Display M
    void displayBookInfo(){
        cout<<"Book id: "<<iD<<endl;
        cout<<"Book title: "<<title<<endl;
        cout<<"Book writer's name: "<<getWriterName()<<endl;
        cout<<"Book writer's email: "<<writer.get_Email()<<endl;
        cout<<"Book status: "<<status<<endl;
        cout<<"==================================\n";
    }
};
