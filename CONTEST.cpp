#include <iostream>

int nearestMultipleOf10(int purchaseAmount) {
    // Find the nearest multiple of 10
    return ((purchaseAmount + 9) / 10) * 10;
}

int accountBalanceAfterPurchase(int purchaseAmount) {
    // Initial account balance
    int initial_balance = 100;
    
    // Find the nearest multiple of 10 to the purchaseAmount
    int roundedAmount = nearestMultipleOf10(purchaseAmount);
    
    // Calculate the account balance after the purchase
    int account_balance = initial_balance - roundedAmount;
    
    return account_balance;
}

int main() {
    // Test cases
    int purchaseAmount1 = 9;
    int purchaseAmount2 = 15;

    std::cout << "Example 1: Account balance after $" << purchaseAmount1 << " purchase: " << accountBalanceAfterPurchase(purchaseAmount1) << std::endl;
    std::cout << "Example 2: Account balance after $" << purchaseAmount2 << " purchase: " << accountBalanceAfterPurchase(purchaseAmount2) << std::endl;

    return 0;
}
