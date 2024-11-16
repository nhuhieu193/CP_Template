#include <bits/stdc++.h>
#define f(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
list <int> a[100005];
int b[100005];
int c[100005];
int n,m,i,j,k,s,res=0;
void dfs(int V,int pV)
{
    vector <int> f;
    for (auto y:a[V])
    {

        if (y==pV) continue;

        dfs(y,V);
        f.push_back(b[y]);
    }
    sort (f.begin(),f.end());
    b[V]=1;
    if (!f.empty()) b[V]+=f.back();
    if ((int)f.size() >1) c[V] = 1+ f.back() +f[f.size()-2];
    res= max(res,max(b[V],c[V]));
}
int main()
{
    cin>>m;n=m;
    while (--m)
    {
        cin>>i>>j;
        a[i].push_back(j);
        a[j].push_back(i);
    }
    dfs(1,0);
//    f(i,1,n) cout<<b[i]<<" ";
//    cout<<endl;
    cout<<res-1;
    return 0;
}
