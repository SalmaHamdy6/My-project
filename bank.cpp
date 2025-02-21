#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int n = 0;

struct clients {
    string firstname, lastname;
    string password1, password2;
    string email;
    string id;
    string balance;
};

clients client[100];

void Process() {
    string choice3, index, password0;
    int u = 1, x;
    long long balance, withdraw, deposit;
    bool s = 0, fg = 0;
    
    cout << "1: Check your balance.\n";
    cout << "2: Withdraw.\n";
    cout << "3: Deposit.\n";
    cout << "4: Exit\n\n";
    cout << "--------------\n";

    int c = 1;

    do {
        cout << "Enter your choice: ";
        s = 0;
        
        while (s == 0) {
            cin >> choice3;
            switch (choice3[0]) {
                case '1': // Check Balance
                    cout << "Enter your client number.\nPlease enter only numerical values.\n";
                    cin >> index;

                    while (!fg) {
                        for (char ch : index) {
                            if (!isdigit(ch)) {
                                fg = 0;
                                cout << "Please enter numerical value.\n";
                                cin >> index;
                                break;
                            }
                            fg = 1;
                        }
                    }

                    x = stoi(index);
                    cout << "Enter your password: ";
                    cin >> password0;

                    while (u <= 3) {
                        if (password0 == client[x - 1].password1) {
                            cout << "Your balance is: " << client[x - 1].balance << endl;
                            cout << "****\n";
                            break;
                        } else {
                            cout << "Please enter correct password.\n";
                            cin >> password0;
                        }
                        u++;
                    }

                    cout << "You have reached the limit, please check your data.\n";
                    u = 1;
                    s = 1;
                    break;

                case '2': // Withdraw
                    cout << "Enter client number.\nPlease enter only numerical values.\n";
                    cin >> index;

                    while (!fg) {
                        for (char ch : index) {
                            if (!isdigit(ch)) {
                                fg = 0;
                                cout << "Please enter numerical value.\n";
                                cin >> index;
                                break;
                            }
                            fg = 1;
                        }
                    }

                    x = stoi(index);
                    cout << "Enter your password: ";
                    cin >> password0;

                    while (u <= 3) {
                        if (password0 == client[x - 1].password1) {
                            cout << "Note: Your balance is: " << client[x - 1].balance << endl;
                            cout << "Enter your Amount: ";
                            cin >> withdraw;

                            balance = stoi(client[x - 1].balance);
                            if (withdraw > balance) {
                                cout << "Sorry, you can't withdraw this amount.\n";
                                cout << "Your current balance is: " << balance << endl;
                            } else {
                                balance -= withdraw;
                                client[x - 1].balance = to_string(balance);
                                cout << "Now, your balance is: " << client[x - 1].balance << endl;
                                cout << "*****\n";
                                break;
                            }
                        } else {
                            cout << "Please enter correct password.\n";
                            cin >> password0;
                        }
                        u++;
                    }

                    cout << "You have reached the limit, please check your data.\n";
                    u = 1;
                    s = 1;
                    fg = 0;
                    break;

                case '3': // Deposit
                    cout << "Enter your client number.\nPlease enter only numerical values.\n";
                    cin >> index;

                    while (!fg) {
                        for (char ch : index) {
                            if (!isdigit(ch)) {
                                fg = 0;
                                cout << "Please enter numerical value.\n";
                                cin >> index;
                                break;
                            }
                            fg = 1;
                        }
                    }

                    x = stoi(index);
                    cout << "Enter your password: ";
                    cin >> password0;

                    while (u <= 3) {
                        if (password0 == client[x - 1].password1) {
                            cout << "Your current balance is: " << client[x - 1].balance << endl;
                            cout << "Enter your deposit amount: ";
                            cin >> deposit;

                            balance = stoi(client[x - 1].balance);
                            balance += deposit;
                            client[x - 1].balance = to_string(balance);

                            cout << "Your new balance is: " << client[x - 1].balance << endl;
                            cout << "****\n";
                            break;
                        } else {
                            cout << "Please enter correct password.\n";
                            cin >> password0;
                        }
                        u++;
                    }

                    cout << "You have reached the limit, please check your data.\n";
                    u = 1;
                    s = 1;
                    fg = 0;
                    break;

                case '4': // Exit
                    cout << "Thank you" << endl;
                    cout << "***\n";
                    s = 1;
                    break;

                default:
                    cout << "Please enter a valid number.\n";
                    s = 0;
            }
        }

        if (choice3[0] == '4') {
            break;
        }

        c++; // End of switch
    } while (c <= 4);
}

void show() {
    cout << "Services" << endl;
    cout << "1: Create account and login" << endl;
    cout << "2: Process in your account." << endl;
    cout << "3: Delete account.\n" << endl;
    cout << "**" << endl;
}

void account() {
    bool test = 0, test2 = 0, z = 0;
    cout << "Enter your first name\n";
    
    bool p = 0;
    while (p == 0) {
        getline(cin, client[n].firstname);
        for (int j = 0; j < client[n].firstname.size(); j++) {
            if (!isalpha(client[n].firstname[j]) && client[n].firstname[j] != ' ') {
                cout << "Please enter a valid name (letters only, no numbers or symbols).\n";
                p = 0;
                break;
            } else {
                p = 1;
            }
        }
    }

    cout << "------------------------------\n";
    cout << "Enter your last name\n";
    
    bool r = 0;
    while (r == 0) {
        getline(cin, client[n].lastname);
        for (int j = 0; j < client[n].lastname.size(); j++) {
            if (!isalpha(client[n].lastname[j]) && client[n].lastname[j] != ' ') {
                cout << "Please enter a valid name (letters only, no numbers or symbols).\n";
                r = 0;
                break;
            } else {
                r = 1;
            }
        }
    }
    
    cout << "-----------------------------\n";
    cout << "Enter your ID\n";
    cin.ignore();
    getline(cin, client[n].id);
    while (z == 0) {
        if (client[n].id.size() != 14) {
            cout << "Enter your ID again\n";
            cin >> client[n].id;
            z = 0;
        } else {
            z = 1;
        }
    }
    
    bool k = 0;
    while (k == 0) {
        for (int i = 0; i < client[n].id.size(); i++) {
            if (isdigit(client[n].id[i])) {
                k = 1;
            } else {
                cout << "Please enter only numbers\n";
                cin.ignore();
                getline(cin, client[n].id);
                k = 0;
            }
        }
    }
    
    cout << "---------------------------\n";
    cout << "Enter your email\n";
    cin.ignore();
    getline(cin, client[n].email);

    while (test2 == 0) {
        if (client[n].email.find("@") != string::npos && client[n].email.find(".com") != string::npos &&
            client[n].email.find("@") < client[n].email.find(".com") &&
            (client[n].email.find("gmail") != string::npos || client[n].email.find("yahoo") != string::npos ||
             client[n].email.find("outlook") != string::npos || client[n].email.find("hotmail") != string::npos ||
             client[n].email.find("icloud") != string::npos || client[n].email.find("zoho") != string::npos)) {
            test2 = 1;
        } else {
            test2 = 0;
            cout << "The email should contain '@' and '.com'.\n";
            getline(cin, client[n].email);
        }
    }
    
    cout << "--------------------------\n";
    cout << "Enter your password\n";
    cin.ignore();
    getline(cin, client[n].password1);
    
    while (test == 0) {
        for (int i = 0; i < client[n].password1.size(); i++) {
            if (isdigit(client[n].password1[i])) {
                test = 1;
            } else {
                test = 0;
                break;
            }
        }
        if (test == 0) {
            cout << "Enter only numerical values. Without spaces\n";
            cin.ignore();
            getline(cin, client[n].password1);
        }
    }
    
    cout << "-------------------------\n";
    cout << "Enter your password again\n";
    cin.ignore();
    getline(cin, client[n].password2);
    
    bool s = 0;
    while (s == 0) {
        if (client[n].password1 == client[n].password2) {
            s = 1;
        } else {
            s = 0;
            cout << "Please enter your password again\n";
            cin.ignore();
            getline(cin, client[n].password2);
        }
    }
    
    cout << "--------------------------\n";
    cout << "Enter your initial balance. \n";
    bool l = 0;
    while (l == 0) {
        getline(cin, client[n].balance);
        for (int i = 0; i < client[n].balance.size(); i++) {
            if (isdigit(client[n].balance[i])) {
                l = 1;
            } else {
                l = 0;
                cout << "Please enter numerical value.\n";
                break;
            }
        }
    }
    
    cout << "******\n";
    cout << "Your client number is: " << n + 1 << '\n';
}

void login() {
    string pass, id2;
    int test = 1;

    while (test <= 3) { // in case the client enters invalid values
        cout << "Enter your id\n";
        cin >> id2;
        cout << "Enter your password\n";
        cin >> pass;

        if (pass == client[n].password2 && id2 == client[n].id) {
            cout << "Your login has been successfully completed.\n";
            cout << "******\n";
            cout << "Hello our dear client\n\n";
            cout << "Your full name: " << client[n].firstname << " " << client[n].lastname << "\n";
            cout << "Your email : " << client[n].email << "\n";
            cout << "Your id : " << client[n].id << "\n";
            cout << "Your balance : " << client[n].balance << "\n";
            cout << "****\n";
            break;
        } else {
            cout << "Please enter correct data.\n";
            cout << "-------------------------------\n";
        }
    }
}

void choice() {
    cout << "Enter 1: To login.\nEnter 2: To exit.\n"; // login or not.
    int choice;
    cin >> choice;

    while (true) {
        if (cin.fail()) {  // Detects if input is NOT a number
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input! Please enter a number 1 or 2.\n";
            cin >> choice;
        } else {
            if (choice == 1) {
                login();
            } else if (choice == 2) {
                cout << "Thank you for dealing with us.\n";
                cout << "*****\n";
            }
        }
    }
}

void Delete() {
    int x;
    bool fg = 0;
    string position4;

    cout << "Enter client number.\nPlease enter only numerical values\n";
    cin >> position4;

    while (fg == 0) {
        for (int i = 0; i < position4.size(); i++) {
            if (isdigit(position4[i])) {
                fg = 1;
            } else {
                fg = 0;
                cout << "Please enter numerical value.\n";
                cin >> position4;
                break;
            }
        }
    }
    
    x = stoi(position4);
    client[x - 1].firstname = " ";
    client[x - 1].id = " ";
    client[x - 1].password2 = " ";
    client[x - 1].password1 = " ";
    client[x - 1].lastname = " ";
    client[x - 1].email = " ";
    client[x - 1].balance = "0";
    
    cout << "This account is currently unavailable.\n";
    cout << "*****\n";
}

 int main() {
     cout << "               *****         " << endl;
     cout << "         ****         ****     " << endl;
     cout << "      ***        $         ***   " << endl;
     cout << "    **         $$$$$          **  " << endl;
     cout << "   *        $$   $   $          * " << endl;
     cout << "  *           $  $               *" << endl;
     cout << "  *             $$$              *" << endl;
     cout << "  *              $  $            *" << endl;
     cout << "   *         $   $   $$         * " << endl;
     cout << "    **         $$$$$          **" << endl;
     cout << "      ***        $         ***   " << endl;
     cout << "         ****         ****     " << endl;
     cout << "               *****         " << endl;
     cout << endl;

     
    string yourchoice;
    bool s = 0;

    while (n <= 100) {
        show();
        cin >> yourchoice;
        s = 0;

        while (s == 0) {
            switch (yourchoice[0]) {
                case '1':
                    account();
                    choice();
                    s = 1;
                    break;
                case '2':
                    Process();
                    s = 1;
                    break;
                case '3':
                    Delete();
                    s = 1;
                    break;
                default:
                    cout << "Please enter valid number\n";
                    s = 0;
                    cin >> yourchoice;
            }
        }
        n++;
    }
}
