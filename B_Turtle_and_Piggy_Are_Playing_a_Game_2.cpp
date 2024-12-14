#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string reorder_string(string s) {
    vector<int> char_count(26, 0);
    
    // Count character frequencies
    for (char c : s) {
        char_count[c - 'a']++;
    }
    
    // Find the most frequent character
    int most_common_idx = max_element(char_count.begin(), char_count.end()) - char_count.begin();
    char most_common = 'a' + most_common_idx;
    
    // Remove the most frequent character from the count
    char_count[most_common_idx] -= 2;
    
    // Create the middle part of the string
    string middle;
    bool continue_loop = true;
    while (continue_loop) {
        continue_loop = false;
        for (int i = 0; i < 26; i++) {
            if (char_count[i] > 0) {
                middle += ('a' + i);
                char_count[i]--;
                continue_loop = true;
            }
        }
    }
    
    // Combine the parts
    return most_common + middle + most_common;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << reorder_string(s) << endl;
    }
    
    return 0;
}