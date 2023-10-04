#include <bits/stdc++.h>
using namespace std;


int main()
{
    string que;
    cin >> que;

    vector<int> numbers;

    size_t pos = 0;

    while ((pos = que.find("+")) != string::npos) //+ ko dhund raha hai que ke end tak
    {
        int num = stoi(que.substr(0, pos));  //obtain integers from strings
        numbers.push_back(num);
        que.erase(0, pos + 1);
    }

    numbers.push_back(stoi(que));

    sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i];
        if (i < numbers.size() - 1)
        {
            cout << "+";
        }
    }

    cout << endl;

    return 0;
}
