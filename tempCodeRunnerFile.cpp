#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> a(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> a[i].first >> a[i].second;
        }

        double lo = 0.0, hi = 1e6;
        bool possible = true;

        for (int i = 1; i <= N; ++i)
        {
            double min_speed = i / static_cast<double>(a[i - 1].second);
            double max_speed = i / static_cast<double>(a[i - 1].first);

            if (min_speed > max_speed)
            {
                possible = false;
                break;
            }

            lo = max(lo, min_speed);
            hi = min(hi, max_speed);
        }

        cout << "Case #" << t << ": ";
        if (!possible || lo > hi)
        {
            cout << "-1" << endl;
        }
        else
        {

            stringstream ss;
            ss << fixed << setprecision(6) << lo;
            string result = ss.str();

            result.erase(result.find_last_not_of('0') + 1, string::npos);
            if (result.back() == '.')
            {
                result.pop_back();
            }

            cout << result << endl;
        }
    }

    return 0;
}
