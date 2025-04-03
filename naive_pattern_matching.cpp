#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, pattern;
    getline(cin, str);
    getline(cin, pattern);


    int n = str.size();
    int m = pattern.size();

    bool found = false;

    for (int i = 0; i <= n - m; i++) {  // Ensure valid range
        int j;
        for (j = 0; j < m; j++) {
            if (str[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {  // If full pattern matched
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Not matched" << endl;
    }

    return 0;
}
