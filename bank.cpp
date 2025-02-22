#include <iostream> // For inputs and outputs
#include <string> // For strings
#include <bits/stdc++.h> // For all libraries

using namespace std;

int n = 0; // Structure to store client informations
bool q = 0; // To control validation

// Structure to store client informations
struct clients {
    string firstname, lastname; // client's first and last name
    string password1, password2; // passwords
    string email; // client's email
    string id; // client's national ID
    string balance; // client's account balance
};

clients client[100];

void Process() {
    string choice3, index, password0;
    int u = 1, x; // u: password attempts, x: converted client number
    long long balance, withdraw, deposit;
    bool s = 0, fg = 0,er = 0; //  for loop control and error handling

    // Display options
    cout << "\033[1m1: \033[0mCheck your balance.\n";
    cout << "\033[1m2: \033[0mWithdraw.\n";
    cout << "\033[1m3: \033[0mDeposit.\n";
    cout << "\033[1m4: \033[0mExit\n\n";
    cout << "--------------\n";

    // Loop up to 3 attempts
    for (int c = 1; c <= 3; c++) {
        cout << endl;
        cout << "Enter your choice: ";
        s = 0;
        u = 1;
        fg = 0;

        while (s == 0) {
            getline(cin,choice3);

            // Check Balance
            if (choice3 == "1") {
                cout << endl;
                cout << "Enter your client number.\n";
                getline(cin, index);
                
                // Validation client number
                while (fg == 0) {
                    for (int g = 0; g < index.size(); g++) {
                        if (!isdigit(index[g])) {
                            fg = 0;
                            cout << "Incorrect data.\n";
                            cout << endl;
                            cout << "Please enter your client number.\n";
                            getline(cin,index);
                            break;
                        } else {
                            fg = 1;
                        }
                    }
                }
                
                x = stoi(index); // Converts client number to integer

                // Check user logging
                if(client[x - 1].password1==" "){
                    cout<<"Please login first (Enter 4 to exit).\n";
                    cout << endl;
                    break;
                }
                
                cout << "Enter your password: ";
                getline(cin, password0);
                
                // Allow 3 attempts for password verification
                while (u <= 3) {
                    if (password0 == client[x - 1].password1) {
                        cout << "Your balance is: " << client[x - 1].balance <<"$"<< endl;
                        cout << "*****\n";
                        er=1;
                        break;
                    } else {
                        cout << "Incorrect password.\n";
                        getline(cin,password0);
                        er=0;
                    }
                    u++;
                }
                
                // If user attemts failed
                if (er == 0) {
                    cout << "You have reached the limit, please check your data.\n";
                }
                s = 1;
            }
            
            // Withdraw
            else if (choice3 == "2") {
                cout << "Enter client number.\n";
                getline( cin, index);
                
                // Validation client number
                while (fg == 0) {
                    for (int g = 0; g < index.size(); g++) {
                        if (!isdigit(index[g])) {
                            fg = 0;
                            cout << "Please enter numerical value.\n";
                            getline(cin,index);
                            break;
                        } else {
                            fg = 1;
                        }
                    }
                }
                
                x = stoi(index); // Converts client number to integer

                // Check user logging
                if (client[x - 1].password1 == " ") {
                    cout<<"Please login first (Enter 4 to exit).\n";
                    break;
                }
                
                cout << "Enter your password: ";
                getline(cin , password0);
                er = 0;

                // Password verification (3 attempts)
                while (u <= 3) {
                    if (password0 == client[x - 1].password1) {
                        cout << endl;
                        cout << "Your current balance is: " << client[x - 1].balance<<" $" << endl;
                        cout << "Enter your Amount: ";
                        cin >> withdraw;
                        
                        balance = stoi(client[x - 1].balance);
                        
                        // Check withdrawal validation
                        if (withdraw > balance) {
                            cout << endl;
                            cout << "Sorry, you can't withdraw this amount.\n";
                            er = 1;
                        } else {
                            balance -= withdraw;
                            client[x - 1].balance = to_string(balance);
                            cout << endl;
                            cout << "Your new balance is: " << client[x - 1].balance<<" $" << endl;
                            cout << "-----------------\n";
                            er = 1;
                            break;
                        }
                    } else {
                        cout << "Incorrect password.\n";
                        getline(cin, password0);
                        er = 0;
                    }
                    u++;
                }
                
                // If user attemts failed
                if (er == 0) {
                    cout << "You have reached the limit, please check your data.\n";
                    cout << endl;
                }
                s = 1;
                break;
            }
            
            // Deposit
            else if (choice3 == "3") {
                cout << "Enter your client number.\n";
                getline(cin, index);
                
                // Validation client number
                while (fg == 0) {
                    for (int g = 0; g < index.size(); g++) {
                        if (!isdigit(index[g])) {
                            fg = 0;
                            cout << "Please enter numerical value.\n";
                            getline(cin,index);
                            break;
                        } else {
                            fg = 1;
                        }
                    }
                }
                
                x = stoi(index); // Converts client number to integer
                
                // Check user logging
                if (client[x - 1].password1 == " ") {
                    cout<<"Please login first (Enter 4 to exit).\n";
                    break;
                }
                
                cout << "Enter your password: ";
                getline(cin, password0);
                er = 0;

                // Password verification (3 attempts)
                while (u <= 3) {
                    if (password0 == client[x - 1].password1) {
                        cout << "Your current balance is: " << client[x - 1].balance<<"$" << endl;
                        cout << "Enter your deposit amount: ";
                        cin >> deposit;
                        
                        balance = stoi(client[x - 1].balance);
                        balance += deposit;
                        client[x - 1].balance = to_string(balance);
                        
                        cout << "Your new balance is: " << client[x - 1].balance << "$" << endl;
                        cout << "******\n";
                        er = 1;
                        break;
                    } else {
                        cout << "Incorrect password.\n";
                        getline(cin, password0);
                        er = 0;
                    }
                    u++;
                }
                
                // If user attemts failed
                if (er == 0) {
                    cout << "You have reached the limit, please check your data.\n";
                }
                s =1;
                break;
            }
            
            // Option 4: Exit
            else if (choice3 == "4") {
                cout << endl;
                cout << "Thank you" << endl;
                cout << "****\n";
                cout << endl;
                s = 1;
                break;
            }
            
            // For invalid option
            else {
                cout << "Please enter a valid number .\n";
                s = 0;
            }
        }
        
        // The exit for the loop
        if (choice3 == "4") {
            break;
        }
    }
}

void show() {
    cout << "\033[1mServices\033[0m" << endl;
    cout << "\033[1m1: \033[0mCreate new account and login" << endl;
    cout << "\033[1m2: \033[0mProcess in my account." << endl;
    cout << "\033[1m3: \033[0mDelete my account." << endl;
    cout << "*******" << endl;
}

void account() {
    bool test = 0, test2 = 0, z = 0;

    // Prompt user for their first name
    cout << "Enter your first name\n";
    bool p = 0;

    // First name validation
    while (p == 0) {
        getline(cin, client[n].firstname);
        for (int j = 0; j < client[n].firstname.size(); j++) {
            if (!isalpha(client[n].firstname[j]) && client[n].firstname[j] != ' ') {
                cout << "Please enter a valid name (letters only, no numbers or symbols).\n";
                p = 0;
                break;
            } else {
                p = 1; // Name validation
            }
        }
    }

    cout << "------------------------------\n";
    cout << endl;

    // Prompt user for their last name
    cout << "Enter your last name\n";
    bool r = 0;

    // Last name validation
    while (r == 0) {
        getline(cin, client[n].lastname);
        for (int j = 0; j < client[n].lastname.size(); j++) {
            if (!isalpha(client[n].lastname[j]) && client[n].lastname[j] != ' ') {
                cout << "Please enter a valid name (letters only, no numbers or symbols).\n";
                r = 0;
                break;
            } else {
                r = 1; // Name validation
            }
        }
    }

    cout << "-----------------------------\n";
    cout << endl;

    // Prompt user for their ID (must be exactly 14 digits)
    cout << "Enter your ID\n";
    getline(cin, client[n].id);

    while (z == 0) {
        if (client[n].id.size() != 14) {
            cout << "Enter your ID, it must be 14 digits\n";
            getline(cin, client[n].id);
            z = 0;
        } else {
            z = 1; // ID validation
        }
    }

    // Validation ID for only numbers
    bool k = 0;
    while (k == 0) {
        for (int i = 0; i < client[n].id.size(); i++) {
            if (isdigit(client[n].id[i])) {
                k = 1;
            } else {
                cout << "Please enter only numbers\n";
                getline(cin, client[n].id);
                k = 0;
            }
        }
    }

    cout << "---------------------------\n";
    cout << endl;

    // Prompt user for their email address
    cout << "Enter your email\n";
    getline(cin, client[n].email);

    // Email validation
    while (test2 == 0) {
        if (client[n].email.find("@") != string::npos && client[n].email.find(".com") != string::npos &&
            client[n].email.find("@") < client[n].email.find(".com") &&
            (client[n].email.find("gmail") != string::npos || client[n].email.find("yahoo") != string::npos ||
             client[n].email.find("outlook") != string::npos || client[n].email.find("hotmail") != string::npos ||
             client[n].email.find("icloud") != string::npos || client[n].email.find("zoho") != string::npos) &&
            client[n].email.find(" ") == string::npos) {
            test2 = 1; // Email validation
        } else {
            test2 = 0;
            cout << "The email should contain @, .com, and without spaces. \n";
            getline(cin, client[n].email);
        }
    }

    cout << "--------------------------\n";
    cout << endl;

    // Validation of pass for only numbers
    cout << "Enter your password\n";
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
            getline(cin, client[n].password1);
        }
    }

    cout << "-------------------------\n";
    cout << endl;

    // Confirmation of password by re-enter it
    cout << "Enter your password again\n";
    getline(cin, client[n].password2);

    bool s = 0;
    while (s == 0) {
        if (client[n].password1 == client[n].password2) {
            s = 1;
        } else {
            s = 0;
            cout << "Incorrect password.\n";
            getline(cin, client[n].password2);
        }
    }

    cout << "--------------------------\n";
    cout << endl;

    // Prompt user for for intering initial balance
    cout << "Enter your initial balance. \n";
    bool l = 0;

    // Validation of the balance for only numbers
    while (l == 0) {
        getline(cin, client[n].balance);
        for (int i = 0; i < client[n].balance.size(); i++) {
             if (isdigit(client[n].balance[i])) {
                 l = 1;
             } else {
                 l = 0;
                 cout << "Please enter numerical value. Without spaces \n";
                 break;
                }
            }
        }

        // Displajng client number to the user
        int client_number=n;
        cout << endl;
        cout << "\033[1;33m Your client number is: \033[0m" <<client_number+1 << '\n';
        cout<< endl;
    }

void login() {
    bool ghj = 0; // Track  for successful login
    string pass, id2;
    int test = 1; // for login attempts

    // Allow up to 3 login attempts
    while (test <= 3) {
        cout << endl;

        // Prompt user to enter their ID
        cout << "Enter your ID\n";
        getline(cin, id2);

        // Prompt user to enter their password
        cout << "Enter your password\n";
        getline(cin ,pass);

        // Check if entered credentials match stored credentials
        if (pass == client[n].password1 && id2 == client[n].id) {
            cout << endl;
            cout << "\033[34mYour login has been successfully completed\033[0m\n";
            cout << endl;

            // Displaing user information
            cout << "Hello " << client[n].firstname << endl;
            cout << "\033[1mYour FULL NAME: \033[0m" << client[n].firstname << " " << client[n].lastname << "\n";
            cout << "\033[1mYour EMAIL: \033[0m" << client[n].email << "\n";
            cout << "\033[1mYour ID: \033[0m" << client[n].id << "\n";
            cout << "\033[1mYour BALANCE: \033[0m" << client[n].balance<<" $" << "\n";
            cout << endl;

            ghj = 1;
            break; // Exit loop true
        } else {
            // If credentials incorrect, display an erro
            cout << "Incorrect data.\n";
            cout << endl;
            ghj = 0;
        }

        test+=1;
    }

    // If user logging failed after 3 attempts only
    if (ghj == 0) {
        cout<<"You have reached the limit, please check your data.\n";
    }
}

void choice() {
    cout << "\033[1mEnter 1: \033[0mTo login.\n\033[1mEnter 2:  \033[0mTo exit.\n"; // login or not.

    string  choice;
    bool jk = 0; // Input validation

    // Loop until user enters valid choice
    while (jk == 0) {
        getline(cin, choice);
        
        if (choice == "1") {
            login(); // Call login function
            jk = 1; // Exit loop after successful selection
        }

        else if (choice == "2") {
            cout << endl;
            cout << "Thank you for dealing with us.\n";
            cout << "*********\n";
            cout << endl;
            jk = 1; // Exit loop
            q = 1; // To indicate program exit (global)
        }
        // Prompt user to enter a valid number
        else {
            cout << "please enter valid number.\n";
            jk = 0; // // Keep loop running until valid input
        }
    }
}

void Delete() {
    int x; // Variable for client number
    bool fg = 0; // Input validation
    int nm = 1; // Counter for password attemption
    string position4, pass2;

    // Prompt user for their client number
    cout << "Enter your client number.\n";
    getline(cin, position4);

    while (fg == 0) {
        for (int i = 0; i < position4.size(); i++) {
            if (isdigit(position4[i])) {
                fg = 1; // If all characters are digits, set true
            } else {
                fg = 0; // Re enter If any character is not digit
                cout << "Please enter numerical value.\n";
                getline(cin, position4);
                break;
            }
        }
    }

    x = stoi(position4); // Convert client number from string to integer

    // Password for account deleetion
    cout<<"please enter your password.\n";

    // Password verification (3 attempts)
    while (nm <= 3) {
        cin >> pass2;
        
        // Account deleetion if entered password matched the client password
        if (pass2 == client[x - 1].password1) {
            // Reset all user account data
            client[x - 1].firstname = " ";
            client[x - 1].id = " ";
            client[x - 1].password2 = " ";
            client[x - 1].password1 = " ";
            client[x - 1].lastname = " ";
            client[x - 1].email = " ";
            client[x - 1].balance = "0";

            cout << "This account is currently unavailable.\n";
            cout << "\n***\n";
            break; // Exit the loop
        } 
        else {
            cout << "Please enter the correct password.\n";
        }

        nm += 1; // Increasing the attempt counter
    }
}

int main() { 
    // OOOH WAW PATTERN :)
    cout << "\033[32m               *****         \033[0m" << endl;
    cout << "\033[32m         ****         ****     \033[0m" << endl;
    cout << "\033[32m      ***        \033[33m$\033[0m        \033[32m***   \033[0m" << endl;
    cout << "\033[32m    **         \033[33m$$$$$\033[0m         \033[32m**  \033[0m" << endl;
    cout << "\033[32m   *        \033[33m$$   $   $\033[0m         \033[32m* \033[0m" << endl;
    cout << "\033[32m  *           \033[33m$  $\033[0m              \033[32m*\033[0m" << endl;
    cout << "\033[32m  *             \033[33m$$$\033[0m             \033[32m*\033[0m" << endl;
    cout << "\033[32m  *              \033[33m$  $\033[0m           \033[32m*\033[0m" << endl;
    cout << "\033[32m   *         \033[33m$   $   $$\033[0m        \033[32m* \033[0m" << endl;
    cout << "\033[32m    **         \033[33m$$$$$\033[0m         \033[32m**\033[0m" << endl;
    cout << "\033[32m      ***        \033[33m$\033[0m        \033[32m***   \033[0m" << endl;
    cout << "\033[32m         ****         ****    \033[0m " << endl;
    cout << "\033[32m               *****         \033[0m" << endl;
    cout << endl;


    string yourchoice;
    bool s = 0; // Input validation

    // Loop to allow multiple accounts until 100
    while (n < 100) {
        for (int i = 1; i <= 4; i++) {
            show(); // Showing available services

            getline(cin, yourchoice);
            s = 0; // Input validation
            
            while (s == 0) {
                if (yourchoice == "1") {
                    // If user selects option 1, create an account and show choices
                    account();
                    choice();
                    s = 1; // Exit loop
                }
                else if (yourchoice == "2") {
                    // If user selects option 2, process the account
                    Process();
                    s = 1; // Exit loop
                }
                else if (yourchoice == "3") {
                    // If user selects option 3, delete the account
                    Delete();
                    s = 1; // Exit loop
                }
                else if (yourchoice != "1" || yourchoice != "2" || yourchoice != "3") {
                    // If input is invalid, prompt the user again
                    cout << "Please enter valid number .\n";
                    s = 0;
                    getline(cin, yourchoice);
                }
            }

            // Break out of the loop, if user chooses to exit
            if (q == 1) {
                break; // Increment loop counter
            }
        }
        n++;
    }
}
