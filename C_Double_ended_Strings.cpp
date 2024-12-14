#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to find the length of the longest common substring
int longest_common_substring(const string& s1, const string& s2) {
    int max_len = 0;

    // Check all substrings of s1
    for (int i = 0; i < s1.length(); ++i) {
        for (int j = i; j < s1.length(); ++j) {
            string sub = s1.substr(i, j - i + 1);
            // Check if this substring is in s2
            if (s2.find(sub) != string::npos) {
                max_len = max(max_len, (int)sub.length());
            }
        }
    }

    return max_len;
}

// Function to find the minimum number of operations needed
int find_min_operations(const string& a, const string& b) {
    int lcs_len = longest_common_substring(a, b);
    return (a.length() - lcs_len) + (b.length() - lcs_len);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << find_min_operations(a, b) << endl;
    }
    return 0;
}
