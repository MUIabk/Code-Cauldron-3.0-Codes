#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define int long long
#define private public


void solve() {
    int n, m; cin>>n>>m;
    vector<set<int>> adj(n);
    vector<pair<int, int>> edges(m);
    for(auto &[u, v] : edges) {
        cin>>u>>v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int q, k; cin>>q>>k;
    vector<int> p(q);
    for(auto &e : p) cin>>e;
    vector<int> pos(m, 1e9);
    for(int i = 0; i < q; i ++) pos[p[i] - 1] = i;
    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (int l, int r) {return pos[l] < pos[r];});
    auto chk = [&] (int mid) -> bool {
        vector<vector<int>> adj(n);
        for(int i = mid; i < m; i++) {
            auto &[u, v] = edges[ord[i]];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> h(n), up(n);
        vector<bool> vis(n);

        //for finding the bridges
        set<pair<int, int>> bridges;
        auto dfs = [&] (auto self, int v, int p = -1) -> void {
            vis[v] = 1;
            up[v] = h[v];
            for(auto u : adj[v]) {
                if(u == p) continue;
                if(vis[u]) up[v] = min(up[v], h[u]);
                else {
                    h[u] = h[v]+1;
                    self(self, u, v);
                    up[v] = min(up[v], up[u]);
                    if(up[u] > h[v]) {
                        bridges.insert({u, v});
                    }
                }
            }
        };
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(dfs, i);
            }
        }
        vis.assign(n, false);
        vector<int> ids(n);
        //converting all the scc to a single node 
        auto dfs2 = [&] (auto self, int v, int p = -1, int id) -> void {
            ids[v] = id;
            vis[v] = 1;
            for(auto &u : adj[v]) {
                if(!vis[u] && !bridges.count({u, v}) && !bridges.count({v, u})) {
                    self(self, u, v, id);
                }
            }
        };
        int id = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs2(dfs2, i, -1, id);
                id++;
            }
        }

        vector<vector<int>> dfs_tree(id);
        vector<pair<int, int>> dfs_tree_edges;
        for(auto &[u, v] : bridges) {
            dfs_tree[ids[u]].push_back(ids[v]);
            dfs_tree[ids[v]].push_back(ids[u]);
            dfs_tree_edges.emplace_back(ids[u], ids[v]);
        }
        vis.assign(n, false);
        int cnt = 0;
        auto dfs3 = [&] (auto self, int v) -> void {
            if(dfs_tree[v].empty()) cnt += 2;
            if(dfs_tree[v].size() == 1) cnt++;
            vis[v] = 1;
            for(auto &u : dfs_tree[v]) {
                if(!vis[u]) self(self, u);
            }
        };

        vector<int> leaves;
        for(int i = 0; i < id; i++) {
            cnt = 0;
            if(!vis[i]) {
                dfs3(dfs3, i);
                leaves.push_back(cnt);
            }
        }        

        sort(leaves.begin(), leaves.end());
        int ans = 0;
        for(int i = 0; i < leaves.size()-1; i++) {
            ans += leaves[i];
            leaves[i+1] -= leaves[i];
        }
        ans += leaves.back()+1>>1;
        return ans <= k;
    };

    int l = 0, r = q;
    int ans = -1;
    while(l <= r) {
        int mid = l+r>>1;
        if(chk(mid)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << ans << "\n";

}   



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _TEST = 1;
    // cin>>_TEST;
    for(int _ = 1; _ <= _TEST; _++) {
        solve();
    }
    return 0;
        
}
