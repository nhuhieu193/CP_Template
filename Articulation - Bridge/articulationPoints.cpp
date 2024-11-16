#include <bits/stdc++.h>
#define f(i,a,b) for (int i=a;i<=b;i++)
using namespace std;

const int maxn = 100005;

list <int> a[maxn];
int n,m;
int low[maxn],num[maxn];
bool vi[maxn];
int par[maxn];
int timef =0 ;
vector <int > res;

void dfs(int x,int pX) {
    int child  = (par[x] != -1);
    num[x] = low[x] = ++timef;
    for (auto y:a[x]) {
        if (y==pX) continue;
        if (!num[y]) {
            par[y] = x;
            dfs(y,x);
            if (num[y]) low[x] = min(low[x],low[y]);
            if (low[y] >= num[x]) child++;
        }
        else {
            low[x] = min (low[x],num[y]);
        }
    }
    if (child>=2) res.push_back(x);
}

int32_t main() {
    cin>>n>>m;
    f(i,1,m) {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(vi,0,sizeof vi);
    f(i,1,n) {
        par[i] = -1;
        if (!vi[i]) dfs(i,-1);
    }
    sort (res.begin(),res.end());
    cout<<res.size()<<endl;
    for (auto x:res) cout<<x<<" ";
    return 0;
}
