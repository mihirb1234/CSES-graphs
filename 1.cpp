    #include<bits/stdc++.h>
    using namespace std;

    // Macros
    #define ll long long
    #define vi vector<int>
    #define vll vector<ll>
    #define pii pair<int, int>
    #define pll pair<ll, ll>
    #define rep(i, a, b) for(int i = (a); i <= (b); ++i)
    #define repr(i, a, b) for(int i = (a); i >= (b); --i)
    #define all(avg) (avg).begin(), (avg).end()
    #define rall(avg) (avg).rbegin(), (avg).rend()
    #define sz(avg) ((int)(avg).size())
    #define fi first
    #define se second
    #define pb push_back
    #define eb emplace_back
    #define mp make_pair
    using namespace std;
    const int INF = 1e9 + 7;
    const ll LLINF = 1e18 + 7;
    const double EPS = 1e-9;

    // Functions
    ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
    ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
    ll mod_pow(ll base, ll eavgp, ll mod) {
        ll result = 1;
        while (eavgp > 0) {
            if (eavgp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            eavgp /= 2;
        }
        return result;
    }
const int N=3e4+5;
// int n,t;
// vi a(n);

ll drow[]={1,0,-1,0};
ll dcol[]={0,1,0,-1};
bool inrange(ll nrow,ll ncol,ll n,ll m){
    if((nrow>=0 && ncol>=0 && nrow<n && ncol<m)){
        return true;
    }
    return false;
}
void solve() {
    // vector<int>adj(N);
    int n,m;
    cin>>n>>m;
    vector<string>v(n);
    for(auto &i:v){
        cin>>i;
    }
    vector<vector<ll>>vis(n,vector<ll>(m,0));
    queue<pair<ll,ll>>q;
    int count=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(vis[i][j]==1){
                continue;
            }           
            if(v[i][j]=='#'){
                continue;
            }
            q.push({i,j});
            vis[i][j]=1;
            count++;
            while(!q.empty()){
                ll row=q.front().first;
                ll col=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    ll nrow=row+drow[k];
                    ll ncol=col+dcol[k];
                    if((inrange(nrow,ncol,n,m) && vis[nrow][ncol]==0) && v[nrow][ncol]!='#'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }

        }
    }
    cout<<count<<endl;
}  

    int main() {
    
        // Your code goes here
        solve();

        return 0;
    }
