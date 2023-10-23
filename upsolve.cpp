#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;

    string mostFrequentSubstr;
    int maxCount = 0;

    for (int i = 0; i < n - 1; i++) {
        string t = s.substr(i, 2);
        int count = 1;
        for (int j = i + 1; j < n - 1; j++) {
            string tt = s.substr(j, 2);
            if (tt == t) {
                count++;
            }
        }
        if (count > maxCount) {
            mostFrequentSubstr = t;
            maxCount = count;
        }
    }
    cout << mostFrequentSubstr << endl;
    return 0;
}
