#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i = 1;
    while(i<=n){
        int j = 1;
        char ch = 'A'+j-1;
        while(j<=n){   //agar j ko <= i lenge to triangular pattern banega
            cout<<ch;
            j = j+1;
        }
        cout<<endl;
        i = i+1;
    }
}