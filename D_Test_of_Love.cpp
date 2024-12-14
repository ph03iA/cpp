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
#include <queue>
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

struct State
{
    int pos;
    int swim;
};

class RiverCrossing
{
public:
    RiverCrossing(int n, int m, int k, const string &river)
        : n(n), m(m), k(k), river(river), visited(n + 2, false) {}

    bool canReachRightBank()
    {
        queue<State> statesQueue;
        initializeQueue(statesQueue);

        while (!statesQueue.empty())
        {
            State currentState = statesQueue.front();
            statesQueue.pop();

            if (processCurrentState(currentState, statesQueue))
            {
                return true;
            }
        }
        return false;
    }

private:
    int n, m, k;
    string river;
    vector<bool> visited;

    void initializeQueue(queue<State> &q)
    {
        q.push({0, 0});
        visited[0] = true;
    }

    bool processCurrentState(const State &currentState, queue<State> &q)
    {
        int pos = currentState.pos;
        int swim = currentState.swim;

        if (pos == n + 1)
        {
            return true;
        }

        if (isOnLogOrStart(pos))
        {
            if (attemptJump(pos, swim, q))
            {
                return true;
            }
        }

        if (isSwimming(pos, swim))
        {
            if (attemptSwim(pos, swim, q))
            {
                return true;
            }
        }

        return false;
    }

    bool isOnLogOrStart(int pos) const
    {
        return pos == 0 || river[pos - 1] == 'L';
    }

    bool attemptJump(int pos, int swim, queue<State> &q)
    {
        for (int jump = 1; jump <= m; ++jump)
        {
            int newPos = pos + jump;
            if (newPos == n + 1)
            {
                return true;
            }
            if (isValidPosition(newPos))
            {
                enqueueState(newPos, swim, q);
            }
        }
        return false;
    }

    bool isSwimming(int pos, int swim) const
    {
        return pos > 0 && pos <= n && river[pos - 1] == 'W' && swim < k;
    }

    bool attemptSwim(int pos, int swim, queue<State> &q)
    {
        int newPos = pos + 1;
        if (newPos == n + 1)
        {
            return true;
        }
        if (isValidPosition(newPos))
        {
            enqueueState(newPos, swim + 1, q);
        }
        return false;
    }

    bool isValidPosition(int pos) const
    {
        return pos <= n && river[pos - 1] != 'C' && !visited[pos];
    }

    void enqueueState(int pos, int swim, queue<State> &q)
    {
        visited[pos] = true;
        q.push({pos, swim});
    }
};

void processTestCases(int testCases)
{
    while (testCases--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        string river;
        cin >> river;

        RiverCrossing riverCrossing(n, m, k, river);
        cout << (riverCrossing.canReachRightBank() ? "YES" : "NO") << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    processTestCases(t);

    return 0;
}
