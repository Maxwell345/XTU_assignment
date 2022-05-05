#include <iostream>
#include <queue>
using namespace std;
typedef struct{
	int fish;
	int decline;
}pond;
bool operator <(const pond& a,const pond& b){
    return a.fish < b.fish;
}
int my_max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int T,n,m,i;
	pond pd,tmp;
	priority_queue <pond> pq;
	int x,ans;
	scanf("%d",&T);
	while(T--){
		while(!pq.empty()) pq.pop();
		scanf("%d%d",&n,&m);
		for(i=0;i<n;++i){
			scanf("%d%d",&pd.fish,&pd.decline);
			pq.push(pd);
		}
		ans=0;
		while(m--){
			if(pq.empty()||pq.top().fish<=0) break;
			tmp=pq.top();
			pq.pop();
			x=tmp.fish;
			ans+=x;
			x=my_max(0,x-tmp.decline);
			tmp.fish=x;
			pq.push(tmp);
		}
		cout<<ans<<endl;
	}
	return 0;
}
