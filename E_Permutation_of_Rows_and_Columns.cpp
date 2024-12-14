#include <bits/stdc++.h>
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007

using namespace std;

vector<int> splitToInt(const string &s)
{
    vector<int> result;
    stringstream ss(s);
    int num;
    while (ss >> num)
    {
        result.push_back(num);
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string s;
        getline(cin, s);
        vector<int> nm = splitToInt(s);
        int n = nm[0];
        int m = nm[1];

        vector<vector<int>> grid1(n, vector<int>(m));
        fo(i, n)
        {
            string row;
            getline(cin, row);
            grid1[i] = splitToInt(row);
        }

        vector<vector<int>> grid2(n, vector<int>(m));
        fo(i, n)
        {
            string row;
            getline(cin, row);
            grid2[i] = splitToInt(row);
        }

        set<set<int>> rowSets1;
        for (const auto &row : grid1)
        {
            rowSets1.insert(set<int>(row.begin(), row.end()));
        }

        bool rowCheck = true;
        for (const auto &row : grid2)
        {
            if (rowSets1.find(set<int>(row.begin(), row.end())) == rowSets1.end())
            {
                cout << "NO" << endl;
                rowCheck = false;
                break;
            }
        }

        if (!rowCheck)
        {
            continue;
        }

        set<set<int>> colSets1;
        for (int j = 0; j < m; ++j)
        {
            set<int> colSet;
            for (int i = 0; i < n; i++)
            {
                colSet.insert(grid1[i][j]);
            }
            colSets1.insert(colSet);
        }

        bool colCheck = true;
        for (int j = 0; j < m; j++)
        {
            set<int> colSet;
            fo(i, n)
            {
                colSet.insert(grid2[i][j]);
            }
            if (colSets1.find(colSet) == colSets1.end())
            {
                cout << "NO" << endl;
                colCheck = false;
                break;
            }
        }

        if (colCheck)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}