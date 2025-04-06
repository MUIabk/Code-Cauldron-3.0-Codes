#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector <ll> arr(n);
    for(auto &it : arr) cin >> it;
    cout << "YES" << '\n';
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}