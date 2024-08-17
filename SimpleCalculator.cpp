#include<iostream>
using namespace std;

void calculator(){
    double a,b;
    char o;
    cout<<"Enter number 1: ";
    cin>>a;
    cout<<"Enter number 2: ";
    cin>>b;
    cout<<"Enter operation to perform (+,-,*,/): ";
    cin>>o;
    switch(o) {
        case '+':
            cout<<a+b;
            break;
        case '-':
            cout<<a-b;
            break;
        case '*':
            cout<<a*b;
            break;
        case '/':
            if (b!=0) {cout<<a/b;}
            else{cout<<"Can't perform diviison by 0";}
            break;

    }
}

int main(){
    cout<<"\n----WELCOME TO SIMPLE CALCULATOR----"<<endl;
    bool running = true;
    while (running == true){
        calculator();
        int res;
        cout<<"\n\nCalculate Again? \n 1. Yes \n 2. No\n";
        cin>>res;
        if (res!=1){running = false;}
    }
    return 0;
}