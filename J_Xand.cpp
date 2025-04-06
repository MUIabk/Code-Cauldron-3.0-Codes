#include <bits/stdc++.h>

using namespace std;


#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

#define int long long
 
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto &e : a) cin>>e;
    sort(a.begin(), a.end());
    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
        int msb = 63 - __builtin_clzll(a[i]);
        int temp = 1ll<<msb+1;
        int idx = upper_bound(a.begin(), a.end(), temp-1) - a.begin();
        debug(i, a[i], temp, idx)
        cnt1 += (n-idx);
    }  
    int cnt2 = (n*(n-1)>>1) - cnt1;
    cout << abs(cnt1-cnt2) << "\n";


}   



int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("./files/input.txt", "r", stdin);
    freopen("./files/output.txt", "w", stdout);
    freopen("./files/error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _TEST = 1;
    cin>>_TEST;
    for(int _ = 1; _ <= _TEST; _++) {
        solve();
    }
    return 0;
        
}

