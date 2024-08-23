#include<bits/stdc++.h>
using namespace std;

class Customer{
    private:
    public:
    int account_number,account_balance;
    bool isActive;
    string name;

    Customer(){
        name = "user";
        account_number = 0;
        account_balance = 0;
        isActive = false;    
    }

    Customer(string name,int account_number,int account_balance){
        this->name = name;
        this->account_number = account_number;
        this->account_balance = account_balance;
        this->isActive = true;
    }

    inline Customer(string name,int account_number):name(name),account_number(account_number),account_balance(0),isActive(true){}

    void deposit(int amount){
        account_balance += amount;
        cout<<"Rupees "<<amount<<" added to account "<<account_number<<". Current balance - "<<account_balance<<endl;
    }

    void withdraw(int amount){
        if(account_balance>=amount){
        account_balance -= amount;
        cout<<"Rupees "<<amount<<" withdrawn from account "<<account_number<<". Current balance - "<<account_balance<<endl;
        }
        else{
        cout<<"Balance insufficient\n";
        }
    }

    void transfer(int amount,Customer targetCustomer){
        if(this->account_balance >= amount){
        this->account_balance -= amount;
        targetCustomer.account_balance += amount;
        cout<<"Rupees "<<amount<<" transferred from account "<<account_number<<" to "<<targetCustomer.account_number<<endl;
        }
        else{
            cout<<"Balance insufficient\n";
        }
    }

    void printDetails(){
        cout<<"Customer Details ->\n";
        cout<<"name- "<<name<<"\n";
        cout<<"account number - "<<account_number<<"\n";
        cout<<"account balance - "<<account_balance<<"\n";
        cout<<"active:"<<(isActive ? "yes\n" : "no\n");
    }

};


int main(){
    Customer c1("Vishal",1,1000);
    // cout<<sizeof(c1.account_number)<<" "<<int(&c1.account_number)<<"\n";
    // cout<<sizeof(c1.account_balance)<<" "<<int(&c1.account_balance)<<"\n";
    // cout<<sizeof(c1.isActive)<<" "<<int(&c1.isActive)<<"\n";
    // cout<<sizeof(c1.name)<<" "<<int(&c1.name)<<"\n";
    // cout<<sizeof(c1);

    // c1.printDetails();
    c1.deposit(1000);
    c1.withdraw(5000);
    c1.deposit(10000);
    c1.withdraw(8000);

}