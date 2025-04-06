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