#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define fo(i, n) for (int i = 0; i < n; i++)
#define cfo(i, n) for (int i = 1; i <= n; i++)
#define rfo(i, n) for (int i = n-1; i >= 0; i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define mod 1000000007
#define pi 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/* clang-format on */

/* Main()  function */

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

int cond(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int n, int m, vector<string> &a, vector<vi> &deg, vector<vi> &vis)
{
    queue<pii> q;

    fo(i, n)
    {
        fo(j, m)
        {
            if (deg[i][j] == 0)
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        fo(d, 4)
        {
            int nx = x - dx[d], ny = y - dy[d];
            if (cond(nx, ny, n, m) && vis[nx][ny] == 0)
            {
                char e = dir[d];
                if (a[nx][ny] == e || a[nx][ny] == '?')
                {
                    deg[nx][ny]--;
                    if (deg[nx][ny] == 0)
                    {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        fo(i, n)
            cin >> a[i];

        vector<vi> deg(n, vi(m, 0)), vis(n, vi(m, 0));

        fo(i, n)
        {
            fo(j, m)
            {
                if (a[i][j] == '?')
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int nx = i + dx[d], ny = j + dy[d];
                        if (cond(nx, ny, n, m))
                        {
                            deg[i][j]++;
                        }
                    }
                }
                else
                {
                    int d = string("UDLR").find(a[i][j]);
                    int nx = i + dx[d], ny = j + dy[d];
                    if (cond(nx, ny, n, m))
                    {
                        deg[i][j]++;
                    }
                }
            }
        }

        bfs(n, m, a, deg, vis);

        int tc = 0;
        fo(i, n)
        {
            fo(j, m)
            {
                if (vis[i][j] == 0)
                {
                    tc++;
                }
            }
        }

        cout << tc << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
 