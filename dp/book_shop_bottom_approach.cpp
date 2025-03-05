#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n, x;
int price[1005];
int pages[1005];
int dp[100005];  
void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    // Initialize dp array
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    
    cout << dp[x] << endl;  // Maximum number of pages
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
