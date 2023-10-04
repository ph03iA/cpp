#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cin >> word;

    int uppercase_count = 0;
    int lowercase_count = 0;

    for (char letter : word)
    {
        if (isupper(letter))
        {
            uppercase_count++;
        }
        else
        {
            lowercase_count++;
        }
    }

    if (uppercase_count > lowercase_count)
    {
        for (char &letter : word)
        {
            letter = toupper(letter);
        }
    }
    else
    {
        for (char &letter : word)
        {
            letter = tolower(letter);
        }
    }

    cout << word << endl;

    return 0;
}
