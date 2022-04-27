#include <stdio.h>
typedef struct{
	long long value;
	int cnt;
}card;
void clearcard(card *array,int size)
{
	int idx;
	for(idx=0;idx<size;++idx){
		array[idx].value=-1;
		array[idx].cnt=-1;
	}
}
int hasfound(card *array,long long x,int p)
{
	int j;
	for(j=0;j<=p;++j){
		if(array[j].value==x) return j;
	}
	return -1;
}
int main()
{
    int T,i,top;
    int t;
    long long n,p,ans,balls;
    card color[10005];
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        ans=n*(n-1)*(n-2)/6;
        clearcard(color,n);top=-1;
        for(i=0;i<n;++i){
            scanf("%lld",&balls);
            t=hasfound(color,balls,top);
            if(t!=-1) color[t].cnt++;
            else
			{
				++top;
				color[top].value=balls;
				color[top].cnt=1;
			}
        }
        for(i=0;i<=top;++i)
        {
            p=color[i].cnt;
            if(p>=3) ans-=( (p*(p-1)*(p-2))/6 );
            if(p>=2) ans-=( ((n-p)*p*(p-1))/2 );
        }
        printf("%lld\n",ans);
    }
    return 0;
}
