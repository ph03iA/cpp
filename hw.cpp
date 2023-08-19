#include <iostream>
using namespace std;

int main()
{

    int rupees;
    cout << "Enter the amount: ";
    cin >> rupees;

    switch (1)
    {

    case 1:
        cout << "Number 100 rupees notes required is: " << (rupees / 100) << endl;
        rupees = rupees % 100;

        cout << "Number 50 rupees notes required is: " << (rupees / 50) << endl;
        rupees = rupees % 50;

        cout << "Number 20 rupees notes required is: " << (rupees / 20) << endl;
        rupees = rupees % 20;

        cout << "Number 1 rupee notes required is: " << (rupees / 1) << endl;
        rupees = rupees % 1;
        break;
    }
}