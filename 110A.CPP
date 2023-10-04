#include<bits/stdc++.h>
using namespace std;
                    
bool isLuckyDigit(char digit) {
    return digit == '4' || digit == '7';
}

int countLuckyDigits(long long number) {
    int count = 0;
    while (number > 0) {
        char digit = static_cast<char>(number % 10 + '0');  //static_cast<char> isko use kiya number%10 + 0 ko char me convert krne ke liye 
        if (isLuckyDigit(digit)) {
            count++;
        }
        number /= 10;
    }
    return count;
}

bool isNearlyLuckyNumber(long long n) {
    int luckyCount = countLuckyDigits(n);
    return luckyCount > 0 && (luckyCount == 4 || luckyCount == 7);
}


int main() {
    long long n;
    cin >> n;
    if (isNearlyLuckyNumber(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}






