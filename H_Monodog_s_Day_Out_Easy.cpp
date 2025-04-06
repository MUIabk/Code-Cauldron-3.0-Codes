#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class T>using ind_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T>using ind_mset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vl> vll;
template<class T> using maxpq = priority_queue<T>;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> using vec1 = vector<T>;
template<class T> using vec2 = vector<vector<T>>;
template<class T> using vec3 = vector<vector<vector<T>>>;

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i,b,a)  for(ll i =((b)-1);i>=(a);i--)
#define mem(a,x)   memset(a,x,sizeof(a))
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(v) v.begin(), v.end()
#define rall(v) (v).rbegin(),(v).rend()
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fbo(a) find_by_order(a) //will give a-th largest element
#define ook(a) order_of_key(a) //will give no. of elements strictly lesser than a
#define sz(x) ((int)(x).size())
#define nzl(x) __builtin_clzll(x)
#define nzr(x) __builtin_ctzll(x)
#define setbits(x) __builtin_popcountll(x)
#define setbitsParity(x) __builtin_parityll(x) // 1 -> odd else 0 if even
#define umap unordered_map
#define uset unordered_set
#define nl "\n"
#define PI atan(1)*4
#define E 2.71828
#define yes {cout << "Yes" << endl; return;}
#define no {cout << "No" << endl; return;}
#define YES {cout << "Yes" << endl;}
#define NO {cout << "No" << endl;}
#define nyet {cout<<"-1"<<endl;return;}
#define mxe(v)  (*max_element(v.begin(),v.end()))
#define mne(v)  (*min_element(v.begin(),v.end()))
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define ub upper_bound
#define lb lower_bound
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define outt(a) \
      FOR(i,1,sz(a))            \
      cout << a[i] << " "; \
      cout << endl;
#define inn(a) \
      FOR(i,1,sz(a))            \
      cin>>a[i];
#define FAST_AF_BOI                \
    ios_base ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
      x += 0x9e3779b97f4a7c15;//abk
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }
};
typedef gp_hash_table<long long,long long,custom_hash> fast_map;
typedef unordered_map<long long,long long,custom_hash> safe_map;

// ================================== i/o module ==================================
template <class T> void print(T x){cerr<<x;};
template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T, class V> void print(map <T, V> v);
template <class T> void print(multiset <T> v);
template <class T, class V> void print(pair <T, V> p) {cerr << "{"; print(p.ff); cerr << ","; print(p.ss); cerr << "}";}
template <class T> void print(vector <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <class T> void print(set <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <class T> void print(multiset <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void print(map <T, V> v) {cerr << "[ "; for (auto i : v) {print(i); cerr << " ";} cerr << "]";}
void print(__int128 x) {if (x < 0) {putchar('-');x = -x;}if (x > 9) print(x / 10);putchar(x % 10 + '0');}
template<class T>void read(T &x){x=0;int f=0;char ch=getchar();while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();x=f? -x:x;return ;}
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template <class T> inline vector<T>& operator--(vector<T>& v) { for(auto &x:v) --x; return v; }
template <class T> inline vector<T>& operator++(vector<T>& v) { for(auto &x:v) ++x; return v; }
template <class T> inline vector<T>& operator^=(vector<T>& v,int y) { for(auto &x:v) x^=y; return v; }
inline string& operator^=(string& s,int y) { for(auto &x:s)x=((x-'0')^y)+'0' ; return s; }

void dgb_out () { cerr << endl; }
template < typename Head, typename... Tail >
void dgb_out ( Head H, Tail... T) { cerr <<' ' << H; dgb_out (T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dgb_out(__VA_ARGS__) 
#else
#define dbg(...)
#endif

// ================================================================================

//`````````````````````````````````````````````IMP FUNCTIONS``````````````````````````````````````````````````````
ll ceil(ll a,ll b){return (a+b-1)/b;}
int log_2(ull i){return i?nzl(1)-nzl(i):-1;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll bin_expo(ll a, ll b, ll mod) {ll res = 1;a%=mod;if(a==0)return 0;while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll bin_mul(ll a, ll b, ll mod) {ll res = 0; while (b > 0) {if (b & 1)res = (res + a) % mod; a = (a + a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return bin_expo(a, b - 2, b);}
ll ncr(ll n, ll r, ll m, ll *fact, ll *ifact) {if(n<r)return 0;ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r];if(n < r) return 0;if(n == r || r == 0) return 1;if(r<0) return 0; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vl sieve(int n) {int*arr = new int[n + 1](); vl vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i*i <= n; i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll large_expo(ll a,ll b,ll c,ll m) {return bin_expo(a,bin_expo(b,c,phin(m)),m);} //(a^b^c)%M 
ll large_expo_prime(ll a,ll b,ll c,ll m) {return bin_expo(a,bin_expo(b,c,m-1),m);} //(a^b^c)%M when m is prime
template<class T>vector<T> prefixSum(vector<T> v, bool flag){vector<T> ans;T sum = 0;if (flag){for (auto &e : v){sum += e;ans.eb(sum);}}else{ans.pb(0);REP(i, v.size(), 0){sum += v[i];ans.eb(sum);}reverse(all(ans));}return ans;}
ll ffs(ll n){if(n==0)return -1;return log2(n & -n);}
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll uid(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
//````````````````````````````````````````````````````````````````````````````````````````````````````````````

const ll INF = 1e18 + 10;
const ll inf = 1e9 + 10;
const ll N = 1e5 + 10;
const ld EPS = 1e-15;
const ll mod1 = (1e9 + 7);
const ll mod2 = (998244353);

/*
Self notes cause I need it :
1. dumbfk read the question properly ... I m fed up with this lack of presence of mind
2. dont assume that something is given in question ,like the input is sorted or stuff
   if some step needs the input to be sorted , either check question or sort , dont assume
3. in case you have less time to debug : 
    Common errors :
      -> Wrote wrong variable names at places cause ur stupid	
     -> For debugging u hard coded small values and submitted that solution right away
     -> Your thinking is never wrong ... Most of the time, typing the code is bugged (maybe a letter or two)
*/
ll myRand(ll B) {
    return (ull)rng() % B;
}
 
 
ll MOD = mod1;
struct Mint { // 1000000007  1000000009
    ll x;
 
    Mint() : x(0) {}
    Mint(ll _x) {
        _x %= MOD;
        if (_x < 0) _x += MOD;
        x = _x;
    }
 
    Mint& operator += (const Mint &a) {
        x += a.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    Mint& operator -= (const Mint &a) {
        x += MOD - a.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    Mint& operator *= (const Mint &a) {
        x = (ull)x * a.x % MOD;
        return *this;
    }
    Mint pow(ll pw) const {
        Mint res = 1;
        Mint cur = *this;
        while(pw) {
            if (pw & 1) res *= cur;
            cur *= cur;
            pw >>= 1;
        }
        return res;
    }
    Mint inv() const {
        assert(x != 0);
        ll t = x;
        ll res = 1;
        while(t != 1) {
            ll z = MOD / t;
            res = (ull)res * (MOD - z) % MOD;
            t = MOD - t * z;
        }
        return res;
    }
    Mint& operator /= (const Mint &a) {
        return *this *= a.inv();
    }
    Mint operator + (const Mint &a) const {
        return Mint(*this) += a;
    }
    Mint operator - (const Mint &a) const {
        return Mint(*this) -= a;
    }
    Mint operator * (const Mint &a) const {
        return Mint(*this) *= a;
    }
    Mint operator / (const Mint &a) const {
        return Mint(*this) /= a;
    }
 
    bool sqrt(Mint &res) const {
        if (MOD == 2 || x == 0) {
            res = *this;
            return true;
        }
        if (pow((MOD - 1) / 2) != 1) return false;
        if (MOD % 4 == 3) {
            res = pow((MOD + 1) / 4);
            return true;
        }
        int pw = (MOD - 1) / 2;
        int K = 30;
        while((1 << K) > pw) K--;
        while(true) {
            Mint t = myRand(MOD);
            Mint a = 0, b = 0, c = 1;
            for (int k = K; k >= 0; k--) {
                a = b * b;
                b = b * c * 2;
                c = c * c + a * *this;
                if (((pw >> k) & 1) == 0) continue;
                a = b;
                b = b * t + c;
                c = c * t + a * *this;
            }
            if (b == 0) continue;
            c -= 1;
            c *= Mint() - b.inv();
            if (c * c == *this) {
                res = c;
                return true;
            }
        }
        assert(false);
    }
 
    bool operator == (const Mint &a) const {
        return x == a.x;
    }
    bool operator != (const Mint &a) const {
        return x != a.x;
    }
    bool operator < (const Mint &a) const {
        return x < a.x;
    }
};
struct Factorials {
    vector<Mint> f, fi;
 
    Factorials() : f(), fi() {}
    Factorials(int n) {
        n += 10;
        f = vector<Mint>(n);
        fi = vector<Mint>(n);
        f[0] = 1;
        for (int i = 1; i < n; i++)
            f[i] = f[i - 1] * i;
        fi[n - 1] = f[n - 1].inv();
        for (int i = n - 1; i > 0; i--)
            fi[i - 1] = fi[i] * i;
    }
 
    Mint C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return f[n] * fi[k] * fi[n - k];
    }
};
struct Powers {
    vector<Mint> p, pi;
 
    Powers() : p(), pi() {}
    Powers(int n, Mint x) {
        n += 10;
        if (x == 0) {
            p = vector<Mint>(n);
            p[0] = 1;
        } else {
            p = vector<Mint>(n);
            pi = vector<Mint>(n);
            p[0] = pi[0] = 1;
            Mint xi = x.inv();
            for (int i = 1; i < n; i++) {
                p[i] = p[i - 1] * x;
                pi[i] = pi[i - 1] * xi;
            }
        }
    }
 
    Mint pow(int n) {
        if (n >= 0)
            return p[n];
        else
            return pi[-n];
    }
};
struct Inverses {
    vector<Mint> ii;
 
    Inverses() : ii() {}
    Inverses(int n) {
        n += 10;
        ii = vector<Mint>(n);
        ii[1] = 1;
        for (int x = 2; x < n; x++)
            ii[x] = Mint() - ii[MOD % x] * (MOD / x);
    }
 
    Mint inv(Mint x) {
        assert(x != 0);
        ll t = x.x;
        ll res = 1;
        while(t >= (int)ii.size()) {
            ll z = MOD / t;
            res = (ull)res * (MOD - z) % MOD;
            t = MOD - t * z;
        }
        return ii[t] * res;
    }
};
#define int long long
void transcendent(int tc)
{
    int n, m; cin >> n >> m;
    vec1<array<int, 2>> cord(n); 
    FOR(i, 0, n) FOR(j, 0, 2) cin >> cord[i][j];
    vec2<int> adj(n);
    vec1<int> deg(n);
    FOR(_, 0, m) {
        int u, v; cin >> u >> v;
        -- u, -- v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u] ++;
        deg[v] ++;
    }
    FOR(i, 0, n) sort(all(adj[i]));
    vec3<int> pos(n, vec2<int>(2));
    FOR(i, 0, n) {
        int m = sz(adj[i]);
        FOR(j, 0, m) {
            int v = adj[i][j];
            pos[v][j & 1].pb(i);
        }
    }
    int SQ = sqrtl(m);
    vec1<int> hvy(n, -1);
    vec1<int> hv;
    FOR(i, 0, n) {
        if(deg[i] > SQ) {
            hvy[i] = sz(hv);
            hv.pb(i);
        }
    }
    auto chk = [&] (int x) { return hvy[x] != -1; };
    vec2<int> go(sz(hv), vec1<int>(sz(hv)));
    for(auto &u: hv) {
        int m = sz(adj[u]);
        FOR(j, 0, m) {
            int v = adj[u][j];
            if(chk(v)) go[hvy[v]][hvy[u]] = 1 + (j & 1);
        }
    }
    vec1<Mint> op(sz(hv));
    FOR(i, 0, n) {
        for(auto &v: pos[i][0]) {
            if(chk(v)) {
                op[hvy[v]] += cord[i][0] + cord[i][1];
            }
        }
        for(auto &v: pos[i][1]) {
            if(chk(v)) {
                op[hvy[v]] -= cord[i][0] + cord[i][1];
            }
        }
    }
    auto pull = [&] (int x) {
        if(chk(x)) {
            for(auto &v: hv) {
                if(go[hvy[x]][hvy[v]]) {
                    if(go[hvy[x]][hvy[v]] == 1) op[hvy[v]] -= cord[x][0] + cord[x][1];
                    else op[hvy[v]] += cord[x][0] + cord[x][1];
                }
            }
        } else {
            for(auto &v: pos[x][0]) {
                if(chk(v)) {
                    op[hvy[v]] -= cord[x][0] + cord[x][1];
                }
            }
            for(auto &v: pos[x][1]) {
                if(chk(v)) {
                    op[hvy[v]] += cord[x][0] + cord[x][1];
                }
            }
        }
    };
    auto push = [&] (int x) {
        if(chk(x)) {
            for(auto &v: hv) {
                if(go[hvy[x]][hvy[v]]) {
                    if(go[hvy[x]][hvy[v]] == 1) op[hvy[v]] += cord[x][0] + cord[x][1];
                    else op[hvy[v]] -= cord[x][0] + cord[x][1];
                }
            }
        } else {
            for(auto &v: pos[x][0]) {
                if(chk(v)) {
                    op[hvy[v]] += cord[x][0] + cord[x][1];
                }
            }
            for(auto &v: pos[x][1]) {
                if(chk(v)) {
                    op[hvy[v]] -= cord[x][0] + cord[x][1];
                }
            }
        }
    };
    auto upd = [&] (int x, int d) {
        Mint sm = 0;
        if(chk(x)) {
            sm = op[hvy[x]];
        } else {
            FOR(k, 0, sz(adj[x])) {
                int v = adj[x][k];
                if(k & 1) sm -= cord[v][0] + cord[v][1];
                else sm += cord[v][0] + cord[v][1];
            } 
        }
        if(sz(adj[x]) & 1) swap(cord[x][0], cord[x][1]);
        FOR(t, 0, 2) {
            if(sz(adj[x]) & 1) {
                cord[x][t] = - cord[x][t];
                cord[x][t] = (sm + cord[x][t]).x;
            } else {
                cord[x][t] = ((d? sm: sm * (-1)) + cord[x][t]).x;
            }
        }
    };
    int q; cin >> q;
    FOR(_, 0, q) {
        int t, u; cin >> t >> u;
        -- t, -- u;
        if(t <= 1) {
            pull(u);
            upd(u, t);
            push(u);
        } else {
            int pt = u + 1;
            cout << pt << " " << cord[pt - 1][0] << " " << cord[pt - 1][1] << "\n";
        }
    }
}

static void read(){
    freopen("gen","r",stdin);
    freopen("output","w",stdout);
}

int32_t main()
{
    // read();
    FAST_AF_BOI
     auto begin = std::chrono::high_resolution_clock::now();
    //cout << fixed << setprecision(12);
    //cerr << fixed << setprecision(0);
    //clock_t timer;
    //timer = clock();
    //PreComp();
    int test = 1;
    // cin >> test;
    FOR(tc, 1, test + 1)
    {
            //cerr << endl << "----Test:" << tc << "----" <<endl;
            transcendent(tc);
    }
    auto end = std::chrono::high_resolution_clock::now();
     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //  cerr << "Time measured: Opt " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}