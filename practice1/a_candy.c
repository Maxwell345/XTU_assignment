#include <stdio.h>
long long M=1000000007;
int main()
{
	long long n,s0,s1,s2;
	long long t0,t1,t2,t3,ans;
	while(1){
		scanf("%lld",&n);
		if(n==0) break;
		t0=t1=t2=0;
		if(n%3==0)
		{
			s0=s1=s2=n/3;
		}
		else if(n%3==1)
		{
			s1=n/3+1;
			s0=s2=n/3;
		}
		else
		{
			s1=s2=n/3+1;
			s0=n/3;
		}
		t0=(s0*(s0-1)*(s0-2))/6;
		t1=(s1*(s1-1)*(s1-2))/6;
		t2=(s2*(s2-1)*(s2-2))/6;
		t3=s0*s1*s2;t3%=M;
		ans=(t0+t1+t2+t3)%M;
		printf("%lld\n",ans);
	}
}
