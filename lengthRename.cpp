#include <bits/stdc++.h>
using namespace std;

void getReverse(char name[], int n)
{

    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[])
{ // isme char ki lenght pass nhi karni padti arrya jaise
    int count = 0;

    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{

    char name[20];

    cout << "Enter your name: " << endl;
    cin >> name;

    cout << "Your name is: " << endl;
    cout << name << endl;

    int len = getLength(name);

    cout << "Length: " << getLength(name) << endl;
    getReverse(name, len);

    cout << "Your name is: " << endl;
    cout << name << endl;

    return 0;
}