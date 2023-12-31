// Private members:
//   Attribute: Money currently available amount
//   Attribute: ID User Account
// Public members:
//   Method: login login
//   Method: logout log out
//   Method: store stored value
//   Method: Pay consumption (reminder: need to judge whether the current eCash has enough amount to consume)
//   Method: display Query the current balance
// Main program
//   Enter the account to log in and perform the following functions
//    Enter 's': stored value
//    Type 'p': consume
//    Enter 'd': query balance
//    Type 'q': log out, and leave the program
//    The program will save each account and its balance to the hard disk

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class UserAccount {
private:
    int moneyAvailable = 0;
    string userID;

public:
    // Constructor
    UserAccount(string id) : userID(id), moneyAvailable(0.0) {}

    // Login method
    void login() {
        // Implement your login logic here
        cout << userID;
    }

    // Logout method
    void logout() {
        // Implement your logout logic here
        cout << "eCash: Logged out! Saved files already!" << endl;
        cout << "Thank you! ByeBye!" << endl;
    }

    // Store money method
    void store(double amount) {
        if (amount >= 0){
        moneyAvailable += amount;
        cout << "eCash: You Stored $" << amount << endl;
        } 
        else {
        cout << "eCash: Please enter an amount greater than 0" << endl;
        }
    }

    // Pay consumption method
    bool pay(double amount) {
        if (amount < 0) {
            cout << "eCash: Please enter an amount greater than 0" << endl;
            return false;
        }
        else if (moneyAvailable >= amount) {
            moneyAvailable -= amount;
            cout << "eCash: You Paid $" << amount << endl;
            return true;
        } else {
            cout << "eCash: Insufficient Balance" << endl;
            return false;
        }
    }

    // Display balance method
    double display() {
        cout << "eCash: Current balance: " << moneyAvailable << endl;
        return moneyAvailable;
    }

    // Save account information to a file
    void saveToFile() {
        ofstream outFile(userID + ".txt");
        outFile << userID << " " << moneyAvailable << endl;
        outFile.close();
    }
};

int main() {
    string userID;
    cout << "=== Welcome eCash ===" << endl;
    cout << "eCash: Please Enter your user ID: ";
    cin >> userID;

    // Create a UserAccount object for the logged-in user
    UserAccount account(userID);

    // Load user account data from file if it exists
    ifstream inFile(userID + ".txt");
    if (inFile) {
        double balance;
        inFile >> userID >> balance;
        account = UserAccount(userID);
        // account.login();
        // account.display();
    } else {
        account.login();
    }

    char choice;
    while(true) {
        cout << endl;
        cout << "Hello " << userID << "! Please select choices:" << endl;
        cout << "s: Store" << endl;
        cout << "p: Purchase" << endl; 
        cout << "d: Display balance" << endl;
        cout << "q: Quit" << endl;
        cin >> choice;

        switch (choice) {
            case 's':
                double amount;
                cout << "Enter the amount to store: ";
                cin >> amount;
                account.store(amount);
                break;
            case 'p':
                double cost;
                cout << "Enter the amount to pay: ";
                cin >> cost;
                account.pay(cost);
                break;
            case 'd':
                account.display();
                break;
            case 'q':
                account.saveToFile();
                account.logout();
                return 0;
                break;
        }
        system("pause");
        system("cls");
    } 

    return 0;
}



