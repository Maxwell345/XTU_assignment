#include <stdio.h>
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;
}
long long lcm(long long p,long long q)
{
	return (p*q)/gcd(p,q);
}
int P[108];
int main()
{
	int K,n,i,t;
	long long cnt,ans;
	scanf("%d",&K);
	while(K--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&P[i]);
		ans=1;
		for(i=1;i<=n;i++)
		{
			cnt=1;t=i;
			while(P[t]!=i)
			{
				t=P[t];
				cnt++;
			} 
			ans=lcm(ans,cnt);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
