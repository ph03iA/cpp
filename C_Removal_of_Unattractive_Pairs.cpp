#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        vector<char> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back() != c) {
                stack.pop_back(); // Remove the last element as it forms a pair
            } else {
                stack.push_back(c); // Otherwise, push the current character
            }
        }
        
        cout << stack.size() << endl; // Final size is the remaining length of string
    }
    
    return 0;
}
