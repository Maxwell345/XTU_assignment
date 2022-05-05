#include <stdio.h>
long long a[1005];
long long b[1005];
long long my_max(long long x,long long y)
{
	return x>y?x:y;
}
long long batch_min(long long *d1,long long *d2,int size)
{
	int i;
	long long res;
	res=b[0]/a[0];
	for(i=1;i<size;++i){
		if(b[i]/a[i]<res) res=b[i]/a[i];
	}
	return res;
}
long long f(long long *arr1,long long *arr2,int size,long long x)
{
	int i;
	long long sum=0;
	for(i=0;i<size;++i){
		sum+=my_max(x*arr1[i]-arr2[i],0);
	}
	return sum;
}
int main()
{
	int T,n,i,j;
	long long low,mid,high;
	long long k,g,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&k);
		for(i=0;i<n;++i) scanf("%d",&a[i]);
		for(i=0;i<n;++i) scanf("%d",&b[i]);
		low=batch_min(a,b,n);high=low+k;
		while(high>low){
            mid=(low+high+1)/2;
            g=f(a,b,n,mid);
            if(g<=k) low=mid;
            else if(g>k) high=mid-1;
        }
        printf("%lld\n",low);
	}
	return 0;
}
