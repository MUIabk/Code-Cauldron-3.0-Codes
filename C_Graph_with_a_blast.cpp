/*Regarding the K part if there is a point intesection when a line is drawn from point a to point b we can only need 1 point at max, there was even a hint in question
itself there was no MOD otherwise if k would have been greater than 1 we can create a case where value of nodes rises exponentially, now ofcourse if there is a 
point between a and b we will take the value of k as 0 we can check that by seeing the GCD of dx and dy, if it is 1 then k is 0, where dx and dy are the distances 
between points on x-axis and y-axis respectively now if it is not one let's say one point was (a,b) and other was (c,d) we can just take (a+1,d+1) as the stopping point
and it's not hard to see why each time it will work and there will be no points in line segment (a,b) to (a+1,d+1) and (a+1,d+1) to (c,d) rest is just basic dijstra and
implementation*/
// Author and solution by: Yesh Agarwal (Valhalla_RL)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> val(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> val[i];
    }
    vector<vector<ll>> graph(n+1);
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll q;
    cin >> q;
    vector<bool> del(n+1, false);
    while(q--){
        ll x, a, b;
        cin >> x >> a >> b;
        if(!del[x]){
            ll vx = val[x];
            for(auto &u : graph[x]){
                if(del[u]) continue;
                ll oval = val[u];
                ll dx = abs(u-x);
                ll dy = abs(oval-vx);
                ll g = gcd(dx,dy);
                ll k = min(g-1,1ll);
                val[u] = k*max(vx, oval);
            }
            del[x] = true;
        }
        if(del[a] || del[b]){
            cout << -1 << "\n";
            continue;
        }
        ll INF = LLONG_MAX/4;
        vector<ll> dist(n+1, INF);
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        dist[a] = 0;
        pq.push({0,a});
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if(d != dist[node]) continue;
            if(node == b) break;
            for(auto &it : graph[node]){
                if(del[it]) continue;
                ll cost = max(val[node], val[it]);
                if(dist[node]+cost < dist[it]){
                    dist[it] = dist[node]+cost;
                    pq.push({dist[it], it});
                }
            }
        }
        cout <<(dist[b]==INF?-1:dist[b]) << "\n";
    }
    return 0;
}
