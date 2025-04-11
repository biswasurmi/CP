https://codeforces.com/contest/1811/submission/200828725

///131111129..........
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
#define ll          long long int
#define pi          acos(-1)
#define pb          push_back
#define mp          make_pair
#define fi          first
#define se          second
#define nl          '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define orderedmultiset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
///Chess moves.........
 int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right//
int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};
///Constants........
const ll mod = 1e9+7;
const ll Max = 1e6+5;
const ll inf = 1e18+5;
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll bigmod(ll a,ll b, ll mod){b%=(mod-1);ll result=1ll;while(b>0ll){if(b&1ll) result=result*a%mod;a=a*a%mod;b>>=1ll;}return result;}
ll inverse(ll a, ll M){if(gcd(a, M)==1) return bigmod(a, M-2, M) % M;return 1;}
ll ncr(ll a, ll b, ll mod){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K % mod; ans = ans * inverse(L, mod) % mod;} return ans;}
ll ncrwithk(ll n,ll k){if(k>n-k) k=n-k;ll p=1,pp=1;if(k!=0){while(k){p*=n;pp*=k;ll m=__gcd(p,pp);p/=m;pp/=m;n--;k--;}}else p=1;return p;}
ll mul(ll a,ll b){ll ans=0ll;while(b){if(b&1) ans+=a;b>>=1;a+=a;if(a>inf) a=inf;if(ans>inf) ans=inf;}return ans;}
void urmi()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll dp[20][2];
ll solve(string& r,ll n,ll tight)
{
    //cout<<n<<" "<<lead<<" "<<tight<<nl;
    if(n<=0){
        return 1;
    }
    //cout<<n<<" "<<lead<<" "<<dp[n][lead][tight]<<nl;
    if(dp[n][tight]!=-1) return dp[n][tight];
    ll ub=tight ? (r[r.size()-n])-'0' : 9;
    ll ans=0;
    //cout<<n<<" "<<ub<<nl;
    for(ll i=0;i<=ub;i++){
        if(i==4) continue;
        ans+=solve(r,n-1,tight&(i==ub));
    }
    return dp[n][tight]=ans;
}
int main()
{
    //urmi();
    ll test=1;
    cin>>test;
    while(test--){
        ll n,ans=0;
        cin>>n;
        n++;
        string s=to_string(n);
        ll l=1,r=inf;
        while(l<=r){
            ll mid=(l+r)/2ll;
            //cout<<"l "<<l<<" "<<r<<" "<<mid<<nl;
            memset(dp,-1,sizeof(dp));
            string s=to_string(mid);
            ll c=solve(s,s.size(),1);
            //cout<<mid<<" "<<c<<nl;
            ll ok=0;
            for(ll i=0;i<s.size();i++){
                if(s[i]=='4'){
                    ok=1;
                    break;
                }
            }
            if(c==n){
                ll ok1=0;
                for(ll i=0;i<s.size();i++){
                    if(ok1){
                        s[i]='9';
                    }
                    else{
                        if(s[i]=='4'){
                            s[i]='3';
                            ok1=1;
                        }
                    }
                }
                if(ok1){
                    ll d=0,mid=0;
                    while(d<s.size()){
                        ll c=s[d]-'0';
                        mid=(mid*10)+c;
                        d++;
                    }
                    ans=mid;
                }
                else ans=mid;
                break;
            }
            else if(c>n){
                r=mid-1;
            }
            else l=mid+1;
            memset(dp,-1,sizeof(dp));
        }
        cout<<ans<<nl;
    }
}
