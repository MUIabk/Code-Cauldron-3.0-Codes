/*The approach during the contest would have been that no counter test case exists where “NO” was an answer so only “YES” will be the answer. But of course there is a proof,
    consider ‘k’ an integer who is the base, suppose k%num = y, where num is any integer which can be made with a combination of the elements of the array and y is the
remainder say we multiply k by k (left shift in bitwise sense) (k^2)%num = (y*k)%num, and we continue to multiply in the same fashion either the new Y(remainder) will
eventually reach zero or start repeating in a loop. If it’s the first case then the remainder is zero and we are all good but if it’s the second case we keep on adding 
bit of k base with xi power say k^(x1)+k^(x2)+... and since it is in a loop we can get infinite number of k^(xi) for which the remainder is Y now, 
    (k^(x1)+k^(x2)+...)%num = (Y+Y+...)%num = (n*Y)%num. Now obviously n can be equal to num, so, (num*Y)%num = 0.
    Thus there always exists a possible combination. So the only answer is “YES”.*/
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
