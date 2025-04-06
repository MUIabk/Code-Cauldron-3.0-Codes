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
    string s; cin>>s;
    if(is_sorted(s.begin(), s.end())) {
        cout << "YES\n";
        return;
    } 
    bool pair = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) pair = 1;
    }
    if(!pair) {
        cout << "NO\n";
        return;
    }
    if(n == 4) {
        if(s == "0100" || s == "1101") {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    int one = count(s.begin(), s.end(), '1');
    int zero = n-one;
    if(n == 5) {
        if(one == 1 || zero == 1) cout << "YES\n";
        else if(s == "01001" || s == "01101") cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    cout << "YES" << "\n";


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

 