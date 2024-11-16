#include <bits/stdc++.h>
#define f(i,a,b) for (int i=a;i<=b;i++)
using namespace std;

const int maxn = 100005;

list <int> a[maxn];
int n,m;
int low[maxn],num[maxn];
bool vi[maxn];
int timef =0 ;
vector <pair <int,int > > res;

void dfs(int x,int pX) {
    vi[x] =1;
    num[x] = low[x] = ++timef;
    for (auto y:a[x]) {
        if (y==pX) continue;
        if (!num[y]) {
            dfs(y,x);
            if (num[y]) low[x] = min(low[x],low[y]);
            if (low[y] >= num[y])
            {
                if (x<=y) res.push_back({x,y});else res.push_back({y,x});
            }
        }
        else {
            low[x] = min (low[x],num[y]);

        }

    }
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
        if (!vi[i]) dfs(i,0);
    }
    sort (res.begin(),res.end());
    cout<<res.size()<<endl;
    for (auto x:res) cout<<x.first<<" "<<x.second<<endl;
    return 0;
}
