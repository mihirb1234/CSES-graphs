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
char dirs[]={'U','D','L','R'};
bool inrange(ll nrow,ll ncol,ll n,ll m){
    if((nrow>=0 && ncol>=0 && nrow<n && ncol<m)){
        return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    // queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0)); // Changed the name of the vector to avoid naming conflicts
    
     pair<int,int>st;   
     pair<int,int>en;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='A'){
                st={i,j};
            }
            if(v[i][j]=='B'){
                en={i,j};
            }

        }
     }   
     vis[st.first][st.second]=1;
     queue<pair<int,int>>q;
     q.push(st);
     vector<vector<pair<int,int>>>prev(n,vector<pair<int,int>>(m,{-1,-1}));
     while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(inrange(nrow,ncol,n,m) && vis[nrow][ncol]==0 && v[nrow][ncol]!='#'){
                prev[nrow][ncol]={row,col};
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
     }
     bool fg=1;
     if(vis[en.first][en.second]==0){
        cout<<"NO"<<endl;
        // return 0;
        // cout<<"0"<<endl;
        // break;
        fg=0;
        return;

     }
     else cout<<"YES"<<endl;
     vector<pair<int,int>>ps;
     pair<int,int>curr=en;
     while(curr!=st){
        ps.push_back({curr.first,curr.second});
        curr={prev[curr.first][curr.second]};
     }
     ps.push_back(st);
     reverse(ps.begin(),ps.end());
    //  for(auto it:ps){
    //     cout<<it.first<<" "<<it.second<<endl;
    //  }
     if(fg==1)cout<<ps.size()-1<<endl;
    string ans="";
    for(int i=0;i<ps.size()-1;i++){
        if(((ps[i].first)+1==ps[i+1].first) && (ps[i].second==ps[i+1].second)){
            ans+="D";//row increase
        }
        else if((ps[i].first==ps[i+1].first) && ((ps[i].second)+1==ps[i+1].second)){
            ans+="R";//column increase
        }
        else if(((ps[i].first)-1==ps[i+1].first) && (ps[i].second==ps[i+1].second)){
            ans+="U";
        }
        else{
            ans+="L";
        }
    }
    cout<<ans<<endl;
}
 

    int main() {
    
        // Your code goes here
        solve();

        return 0;
    }
