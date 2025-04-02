#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCoins(vector<int>& denominations, int amount) {
    sort(denominations.rbegin(), denominations.rend()); // Sort in descending order
    int count = 0;
    
    for (int coin : denominations) {
        if (amount >= coin) {
            count += amount / coin;
            amount %= coin;
        }
    }
    
    return (amount == 0) ? count : -1;
}

int main() {
    int n, amount;
    
    // Taking input
    cin >> n;
    vector<int> denominations(n);
    
    for (int i = 0; i < n; i++) {
        cin >> denominations[i];
    }
    
    cin >> amount;
    
    // Handling invalid input
    if (amount < 0) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    int result = minCoins(denominations, amount);
    cout << result << endl;
    
    return 0;
}

