#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
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
#define read(type) readInt<type>() // Fast read

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

pair<int, vector<int>> processCycle(int start, const vector<int> &p, const vector<char> &s, vector<bool> &visited)
{
    int currentNode = start;
    int blaclC = 0;
    vector<int> cycle;

    while (true)
    {
        if (visited[currentNode])
        {
            break;
        }

        visited[currentNode] = true;
        cycle.pb(currentNode);

        if (s[currentNode] == '0')
        {
            blaclC++;
        }

        currentNode = p[currentNode];

        if (currentNode < 0 || currentNode >= p.size())
        {
            break;
        }
    }

    return {blaclC, cycle};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p(n);
        vector<char> s(n);
        vector<int> F(n, 0);
        vector<bool> visited(n, false);

        fo(i, n)
        {
            cin >> p[i];
            p[i]--;
        }

        fo(i, n)
        {
            cin >> s[i];
        }

        fo(i, n)
        {
            if (!visited[i])
            {
                pair<int, vector<int>> result = processCycle(i, p, s, visited);
                int blaclC = result.first;
                vector<int> cycle = result.second;

                for (int index : cycle)
                {
                    F[index] = blaclC;
                }
            }
        }

        fo(i, n)
        {
            cout << F[i] << " ";
        }
        cout << endl;
    }
    return 0;
}