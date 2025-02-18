#include <iostream>
using namespace std;

// **variable**//
double balance = 1000;
int deposit = 0;
int withdDraw = 0;
int password =1234;
int choice = 0;
// **end of variable**//

// show is a function to show the menu of ATM //
void show(){
    cout<<"**menu**"<<endl;
    cout<<"1:balance"<<endl;
    cout<<"2:withdDraw"<<endl;
    cout<<"3:password"<<endl;
    cout<<"4:Exit"<<endl;
    cout<<"******"<<endl;
    
}

void Process(){
   do{ 
    cout<<"Enter your choice : ";
    cin>>choice;
    
    switch(choice){
        case 1:
            cout<<"your balance is"<<balance<<endl;
            break;
    
        case 2:
            cout<<"Note : your balance is"<<balance<<endl;
            cout<<"Enter your Amount"<<endl;
            cin>>withdDraw;
    
            if(withdDraw>balance){
        
                cout<<"Sorry you can't withdDraw this Amount " <<endl;
            }
            else{
                balance -= withdDraw;   // balance = balance - withdDraw
                cout<<"Now : your balance is "<<balance<<endl;
            }    
            break;
    
        case 3:
            cout<<"Your current balance is"<<balance<<endl;
            cout<<"Enter your deposit money : "<<endl;
            cin>>deposit;
            balance += deposit;  // balance = balance + deposit
    
            cout<<"Your new balance is "<<balance<<endl;
            break;
    
    
        case 4:
             cout<<"Thank you"<<endl;
            break;
    } // end of switch
  }while(choice < 4);
} // end of Process

    
      

int main()
{
   show(); 
   Process();

   
}
