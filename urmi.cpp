///131111129..........
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
#define ll         long long int
#define pi          acos(-1)
#define pb          push_back
#define mp          make_pair
#define fi          first
#define se          second
#define nl          '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define orderedmultiset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
//Chess moves.........
 int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right//
int dy[] = {+1, -1, +0, +0};
///int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};
//Constants........
const ll mod = 1e9+7;
const ll Max = 5e5+5;
const ll inf = 1e18+5;
ll fact[Max];
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll bigmod(ll a,ll b, ll mod){b%=(mod-1);ll result=1ll;while(b>0ll){if(b&1ll) result=result*a%mod;a=a*a%mod;b>>=1ll;}return result;}
int mul(int x, int y){return (x  * y) % mod;}
int binpow(int x, int y){int z = 1;while(y){if(y & 1) z = mul(z, x);x = mul(x, x);y >>= 1;}return z;}
int inv(int x){return binpow(x, mod - 2);}
int ncr(int a,int b){if(a<0 || b<0)return 0;if(a<b)return 0;int ans=fact[a];ans=(ans*inv(fact[b]))%mod;ans=(ans*inv(fact[a-b]))%mod;return ans;}
void fac(){fact[0]=fact[1]=1;for(ll i=2;i<Max;i++){fact[i]=(fact[i-1]*i)%mod;}}
void urmi()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
struct less_then_greater {
    template<typename T, typename U>
    bool operator()(T const& lhs, U const& rhs) const {
        if (lhs.first < rhs.first) return true;
        if (rhs.first < lhs.first) return false;
        return lhs.second>rhs.second;
    }
};
vector<pair<int, int>>v[Max];
int main()
{
    //urmi();
    //fac();
    ll test=1;
    cin>>test;
    for(ll i1=1;i1<=test;i1++){
        int n;
        cin >> n;
        string s1;
        cin >> s1;
        for(int i = 0; i <= n;i++) v[i].clear();
        set<int>s,p, r;
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(s1[i] == 'S') s.insert(i);
            if(s1[i] == 'P') p.insert(i);
            if(s1[i] == 'R') r.insert(i);
        }
        for(int i = 0; i < n; i++){
            if(s1[i] == 'S'){
                v[i].pb({i, 0});
                if(r.size() == 0){
                    ans.pb(i);
                }
                else{
                    auto it = r.begin();
                    int c = *it;
                    if(v[c].size() < v[i].size()){
                        swap(v[c], v[i]);

                    }
                    for(auto it : v[i]) v[c].pb(it);
                    vector<pair<int, int>>v2;
                    swap(v2, v[i]);
                }
                s.erase(i);
            }
            else if(s1[i] == 'P'){
                v[i].pb({i, 1});
                if(s.size() == 0){
                    ans.pb(i);
                }
                else{
                    auto it = s.begin();
                    int c = *it;
                    if(v[c].size() < v[i].size()){
                        swap(v[c], v[i]);

                    }
                    for(auto it : v[i]) v[c].pb(it);
                    vector<pair<int, int>>v2;
                    swap(v2, v[i]);
                }
                p.erase(i);
            }
            else{
                v[i].pb({i, 2});
                if(p.size() == 0){
                    ans.pb(i);
                }
                else{
                    auto it = p.begin();
                    int c = *it;
                    if(v[c].size() < v[i].size()){
                        swap(v[c], v[i]);

                    }
                    for(auto it : v[i]) v[c].pb(it);
                    vector<pair<int, int>>v2;
                    swap(v2, v[i]);
                }
                r.erase(i);
            }
//            for(int j = 0; j < n; j++){
//                cout << "J " << j << nl;
//                for(auto k : v[j]){
//                    cout << k.fi << " " << k.se << nl;
//                }
//            }
        }
        string s2 = s1;
        for(int i : ans){
            for(auto j : v[i]){
                //cout << i << " " << j.fi << " "<< j.se << nl;
                if(j.se == 0) s2[j.fi] = s1[i];
                else if(j.se == 1) s2[j.fi] = s1[i];
                else s2[j.fi] = s1[i];
            }
        }
        cout << s2 << nl;
    }
}

