#include <stdio.h>
#include <string.h>
typedef struct{
	long long value;
	int cnt;
}card;
card freq[70];
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
	int T,i,k;
	int cardtop,t,flag;
	long long n,base,ans,q_n;
	long long digit[70];
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		if(n<=2) ans=2;
		else
		{
			for(base=2;base<=n-1;base++){
				memset(digit,-1,sizeof(digit));
				k=0;q_n=n;
				do{
					digit[k++]=q_n%base;
					q_n/=base;
				}while(q_n>0);
				clearcard(freq,70);
				freq[0].value=digit[0];freq[0].cnt=1;
				cardtop=0;
				for(i=1;digit[i]!=-1;++i){
					t=hasfound(freq,digit[i],cardtop);
					if(t!=-1) freq[t].cnt++;
					else
					{
						++cardtop;
						freq[cardtop].value=digit[i];
						freq[cardtop].cnt=1;
					}
				}
				flag=1;
				for(i=0;i<=cardtop;++i){
					if(freq[i].cnt!=freq[0].cnt)
					{
						flag=0;break;
					}
				}
				if(flag==1)
				{
					ans=base;
					break;
				}
				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
