#include<iostream>
using namespace std;

int main(){
    
    cout<<"Enter the value of a: "<<endl;
    int a;
    cin>>a;

    cout<<"Enter the value of b: "<<endl;
    int b;
    cin>>b;

    cout<<"Enter the operation you want to perform:" << endl;
    char op;
    cin>>op;
    

    switch( op ){
        
        case '+':
        cout<<(a+b)<<endl;
        break;

        case '-':
        cout<<(a-b)<<endl;
        break;

        case '*':
        cout<<(a*b)<<endl;
        break;

        case '/':
        cout<<(a/b)<<endl;
        break;

        case '%':
        cout<<(a%b)<<endl;
        break;

        default: 
        cout<<"Please enter he valid operator: "<<endl;
        break;



    }





}