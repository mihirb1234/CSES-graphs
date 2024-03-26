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
   int n,m;
   cin>>n>>m;
   vector<vector<int>>adj(n+1);
   while(m--){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);

   }
    vector<int>vis(n+1,0);
    int count=0;
    vector<int>ans;
    //finding the number of connected componenets

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            //naya unvisited means new starting vertex will pose as helpful in connecting all the connected components
            ans.push_back(i);
            queue<int>q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(vis[it]==0){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
            count++;
        }
        
    }
    //no of edges required will be no of connected components-1
    cout<<count-1<<endl;
        for(int i=1;i<ans.size();i++){
            cout<<ans[i-1]<<" "<<ans[i]<<endl;
        }

}  

    int main() {
    
        // Your code goes here
        solve();

        return 0;
    }
