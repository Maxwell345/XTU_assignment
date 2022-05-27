#include <iostream>
#include <cstdio>
#include <queue>
#define LL long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1010;
struct arc {
    int to,next;
};
int head[maxn],mp[maxn][maxn],tot;
int n,m,k,city[5],d[maxn];
bool done[maxn];
arc g[maxn<<10];
priority_queue< pii,vector< pii >,greater< pii > >q;
void add(int u,int v) {
    g[tot].to = v;
    g[tot].next = head[u];
    head[u] = tot++;
}
int MyAddByBit(int x,int y)
{
	if(y==0) return x;
	return MyAddByBit(x^y,(x&y)<<1);
}
void dijkstra(int s,int t) {
    int i,u,v,judge_cond;
    for(i = 0; i <= n; i++) {
        d[i] = INF;
        done[i] = false;
    }
    for(i = 0; i <= k+1; i++)
        if(city[i] != s && city[i] != t)
            done[city[i]] = true;
    while(!q.empty()) q.pop();
    d[s] = 0;
    q.push(make_pair(d[s],s));
    while(!q.empty()) {
        u = q.top().second;
        q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(i = head[u]; i != -1; i = g[i].next) {
        	judge_cond=MyAddByBit(d[u],mp[u][g[i].to]);
            if(d[g[i].to] > judge_cond) {
                d[g[i].to] = judge_cond;
                q.push(make_pair(d[g[i].to],g[i].to));
            }
        }
        if(done[t]) return;
    }
}
void ShowResByJudge(int value,bool condition)
{
	if(condition) printf("%d",value);
	else cout<<"Impossible";
}
int main() {
    int i,j,u,v,w,ans;
    while(scanf("%d %d %d",&n,&m,&k)) {
    	if(n==0&&m==0&&k==0) break;
        for(i = 1; i <= n; i++) {
            head[i] = -1;
            for(j = 1; j <= n; j++)
                mp[i][j] = INF;
        }
        for(tot = i = 0; i < m; i++) {
            scanf("%d %d %d",&u,&v,&w);
             if(mp[u][v] == INF) {
                mp[u][v] = mp[v][u] = w;
                add(u,v);
                add(v,u);
            } else if(mp[u][v] > w) {
                mp[u][v] = mp[v][u] = w;
            }
        }
        city[0] = 1;
        for(i = 1; i <= k; i++) scanf("%d",&city[i]);
        city[i] = n;
        bool flag = true;
        for(ans = i = 0; i <= k; i++) {
            dijkstra(city[i],city[i+1]);
            if(d[city[i+1]] == INF) {flag = false;break;}
            ans = MyAddByBit(ans,d[city[i+1]]);
        }
        ShowResByJudge(ans,flag);
        putchar('\n');
    }
    return 0;
}
