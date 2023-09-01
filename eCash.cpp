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
    double moneyAvailable;
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
        moneyAvailable += amount;
        cout << "eCash: You Stored $" << amount << endl;
    }

    // Pay consumption method
    bool pay(double amount) {
        if (moneyAvailable >= amount) {
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
    do {
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
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 'q');

    return 0;
}



// #include <iostream>
// #include <string>
// #include <fstream>
// using namespace std;

// class User {
//     // Attribute
//     private:
//         double balance;
//         string username;
//     public:
//         User(string username) {
//             this->username = username;
//             this->balance = 0.0;
//         }
//         bool login(string username) {
//             if (this->username == username) {
//                 return true;
//             }
//             return false;
//         }
//         void logout() {
//             cout << "Logged out successfully." << endl;
//         }
//         void store(double amount) {
//             this->balance += amount;
//             cout << "Stored $" << amount << " successfully." << endl;
//         }
//         bool pay(double amount) {
//             if (this->balance >= amount) {
//                 this->balance -= amount;
//                 cout << "Paid $" << amount << " successfully." << endl;
//                 return true;
//             }
//             cout << "Insufficient balance." << endl;
//             return false;
//         }
//         void display() {
//             cout << "Current balance: $" << this->balance << endl;
//         }
// };

// int main() {
//     string username;
//     char choice;

//     cout << "Enter the account to log in and perform the following functions:" << endl;
//     cout << "Enter 's': stored value" << endl;
//     cout << "Type 'p': consume" << endl;
//     cout << "Enter 'd': query balance" << endl;
//     cout << "Type 'q': log out, and leave the program" << endl;

//     User user("user");

//     while (true) {
//         cin >> choice;

//         switch (choice) {
//             case 's':
//                 double amount;
//                 cout << "Enter the amount to store: ";
//                 cin >> amount;
//                 user.store(amount);
//                 break;

//             case 'p':
//                 double pay_amount;
//                 cout << "Enter the amount to pay: ";
//                 cin >> pay_amount;

//                 if (user.pay(pay_amount)) {
//                     break;
//                 }

//                 break;

//             case 'd':
//                 user.display();
//                 break;

//             case 'q':
//                 user.logout();
//                 return 0;

//             default:
//                 cout << "Invalid choice." << endl;
//         }
//     }

//     return 0;
// }

