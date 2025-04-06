/*<------------------------------------RIZZ CLUB----------------------------------->*/

/*iftikar hussain  2312040*/
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣆⢀⣶⡶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣿⢸⠟⣠⣶⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⢀⣀⠀⢀⣠⠴⠴⠶⠚⠿⠿⠾⠭⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⢀⠴⢋⡽⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠢⣀⠀⠀⠀⠀⠀⠀
// ⠀⠀⢀⡔⠁⡰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠚⠛⣖⠀⠀⠀⠀
// ⠀⢀⡏⠀⡼⢡⠚⡛⠒⣄⠀⠀⠀⠀⣠⠖⠛⠛⠲⡄⠐⢯⠁⠀⠀⠹⡧⠀⠀⠀
// ⠀⣸⠀⠀⡇⠘⠦⣭⡤⢟⡤⠤⣀⠀⠣⣀⡉⢁⣀⠟⠀⠀⢷⠀⠀⠀⠙⣗⠀⠀
// ⠁⢻⠀⠀⢷⢀⡔⠉⢻⡅⣀⣤⡈⠙⠒⠺⠯⡍⠁⠀⠀⠀⢸⡆⠀⠀⠀⠘⡶⠄
// ⠀⣈⣧⠴⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⠃⠀⠀⠀⠀⣸⡇⠀⠀⠀⠀⠸⣔
// ⣾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣧⣤⡤⠴⠖⠋⢹⠃⠀⠀⠀⠀⠀⣷
// ⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣻⠁⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⣼
// ⠙⠑⣤⣀⠀⠀⠀⠀⠀⢀⠀⠀⢄⣐⠴⠋⠀⠀⠀⠀⠀⠀⠘⢆⠀⠀⠀⠀⣰⠟
// ⠀⠀⠀⣑⡟⠛⠛⠛⠛⠛⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢴⡾⠋⠀
// ⠀⠀⠀⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡇⠀⠀
// ⠀⠀⣰⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀
// ⠀⠀⠸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠃⠀⠃
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_pbds;
/*<----------------------------template starts--------------------------------->*/
#define itsiftikar02     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define yes           cout<<"YES"<<endl;
#define no           cout<<"NO"<<endl;
#define fr(i,s,n)     for(int i=s;i<n;i++)
#define int         long long
#define ld         long double
#define get(a)      for(auto &e : a) cin>>e;
#define put(a)      for(int e : a) cout << e << " "; cout << endl;
#define all(v)      v.begin(),v.end()
#define allEqual(a) *max_element(all(a))==*min_element(all(a))
#define lsort(v)    sort(all(v))
#define rsort(v)    sort(v.rbegin(),v.rend())
#define mod         1000000007
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define endl        "\n" 
int max(int a,int b) {return (a>=b)?a:b;}
int min(int a,int b) {return (a<=b)?a:b;}
int max(int a,int b,int c) {return max(a,max(b,c));}
int min(int a,int b,int c) {return min(a,min(b,c));}
int power(int x,int y){int res=1;x=x%mod;while(y>0){if(y&1) res=(res*x)%mod;y=y>>1;x=(x*x) % mod;}return res;}
int modInverse(int n){return power(n, mod - 2);}
int ceil(int a,int b){return (a+b-1)/b;}
/*<----------------------------template ends--------------------------------->*/
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>v1(n),v2(n);
    get(v1);
    get(v2);
    vector<int>suffix(n+1,0);
    for(int i=n-1;i>=0;i--)
    suffix[i]+=suffix[i+1]+v2[i];
    map<int,int>mp;
    fr(i,0,n)
    mp[v1[i]]=i;
    fr(i,0,n)
    v2[i]=mp[v2[i]];
    vector<int>temp;
    int ans=suffix[0];
    fr(i,0,n){
        int x=lower_bound(all(temp),v2[i])-temp.begin();
        if(x==temp.size()){
            temp.push_back(v2[i]);
        }
        else
        temp[x]=v2[i];
        ans=max(ans,temp.size()*k+suffix[i+1]);
    }
    cout<<ans<<endl;
}
int32_t main()
{
    itsiftikar02;
    int _=1;
    cin>>_;
    while(_--)
    {
        solve();
    }

    return 0;
}