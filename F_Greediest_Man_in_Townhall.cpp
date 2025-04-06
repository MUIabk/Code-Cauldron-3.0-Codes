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

    auto getTag = [&] (char c) {
        return (c-'a'+1)%26;
    };
    auto getChar = [&] (char id) {
        if(id) return (char)('a'+id-1);
        else return 'z';
    };

    vector<vector<int>> a(26, vector<int>(26, INT_MAX));
    for(int i = 0; i < 26; i++) {
        a[i][i] = 0;
        int id = (i<<1)%26;
        int cnt = 1;
        while(a[i][id] == INT_MAX) {
            a[i][id] = cnt++;
            id = (id<<1)%26;
        }
    }
    vector<int> prev(26), cur(26);
    prev = a[getTag(s[0])];
    for(int i = 1; i < n; i++) {
        int id = getTag(s[i]);
        cur[1] = prev[1]+a[id][1];
        int mn = prev[1];
        for(int j = 2; j != 1; j = (j+1)%26) {
            mn = min(mn, prev[j]);
            cur[j] = mn + a[id][j];
        }
        prev = cur;
    }

    int ans = *min_element(cur.begin(), cur.end());
    if(ans >= INT_MAX) cout << "-1\n";
    else cout << ans << "\n";
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
