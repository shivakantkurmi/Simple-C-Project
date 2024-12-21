#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <unistd.h>
#include <stdio.h>  

using namespace std;

// Base class for bank accounts
class Account {
protected:
    double balance;
    string id, name, fname, address, pass, mob_no, pin;

public:
    // Virtual functions to be overridden by derived classes
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
    virtual void displayDetails() = 0;
    virtual void editDetails() = 0;
    virtual void deleteAccount() = 0;
};

// Derived class for savings account
class SavingsAccount : public Account {
public:
    // Implementations of virtual functions
    void deposit() override {
            string tempid;
            float amount;
            fstream file,newfile;
            int found=0;
            system("cls");
            cout<<"\n\n\t\t DEPOSITE AMOUNT OPTION ";
            file.open("bank.txt",ios::in);
            if (!file){
                cout<<"\n\nNo data exist for this user ";
            }
            else{
            cout<<"\nEnter your user id :";
            cin>>tempid;
            newfile.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
            }
            while(!file.eof()){
                if (id==tempid){
                    cout<<"\nEnter Amount for Deposite : ";
                    cin>>amount; 
                    balance+=amount;
                    newfile<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
                    found++;
                    cout<<"\n\n\t......successfully " <<amount<<" deposited .... ";
                    cout<<"\n\n Balance after deposit :"<<balance;
        
                }
                else{
                    newfile<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
            }
            if (found==0){
                cout<<"\n\n\tid not found .....";
            }
            file.close();
            newfile.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
    }
    

    void withdraw() override {
        cout << "Withdraw function for Savings Account." << endl;
    }

    void displayDetails() override {
        cout << "Displaying details of Savings Account." << endl;
    }

    void editDetails() override {
        cout << "Editing details of Savings Account." << endl;
    }

    void deleteAccount() override {
        cout << "Deleting Savings Account." << endl;
    }
};

// Derived class for checking account
class CheckingAccount : public Account {
public:
    // Implementations of virtual functions
    void deposit() override {
        cout << "Deposit function for Checking Account." << endl;
    }

    void withdraw() override {
        cout << "Withdraw function for Checking Account." << endl;
    }

    void displayDetails() override {
        cout << "Displaying details of Checking Account." << endl;
    }

    void editDetails() override {
        cout << "Editing details of Checking Account." << endl;
    }

    void deleteAccount() override {
        cout << "Deleting Checking Account." << endl;
    }
};

// Class for bank management
class Bank {
public:
    void menu();
    void bankManagement();
};

// Implementation of bank menu
void Bank::menu() {
    int choice;
    while (true) {
        system("cls");
        cout << "\n\n\t\tControl panel";
        cout << "\n\n 1. Bank management";
        cout << "\n 2. Exit";
        cout << "\n\n Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nPlease wait while redirecting you to bank management system...\n";
                Sleep(3000); // Sleep for 3 seconds
                bankManagement();
                break;
            case 2:
                cout << "Exiting...";
                exit(0);
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    }
}

// Implementation of bank management
void Bank::bankManagement() {
    int choice;
    while (true) {
        system("cls");
        cout << "\n\t\t Bank Management";
        cout << "\n 1. New user";
        cout << "\n 2. Deposit";
        cout << "\n 3. Withdraw";
        cout << "\n 4. Search user record";
        cout << "\n 5. Edit user record";
        cout << "\n 6. Delete user record";
        cout << "\n 7. Show all records";
        cout << "\n 8. Go back to main menu";
        cout << "\n\n Enter Your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Selected: New user" << endl;
                break;
            case 2:
                cout << "Selected: Deposit" << endl;
                break;
            case 3:
                cout << "Selected: Withdraw" << endl;
                break;
            case 4:
                cout << "Selected: Search user record" << endl;
                break;
            case 5:
                cout << "Selected: Edit user record" << endl;
                break;
            case 6:
                cout << "Selected: Delete user record" << endl;
                break;
            case 7:
                cout << "Selected: Show all records" << endl;
                break;
            case 8:
                cout << "\nPlease wait while redirecting you to the main menu...\n";
                Sleep(3000); // Sleep for 3 seconds
                return;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    }
}

int main() {
    Bank bankObj;
    bankObj.menu();
    return 0;
}
