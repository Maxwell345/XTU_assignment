#include <stdio.h>
int my_min(int x,int y)
{
	return x<y?x:y;
}
void myswap(long long *x,long long *y)
{
	long long temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int partition(long long *arr,int left,int right)
{
	int i,j;
	long long key;
	i=left;j=right;key=arr[left];
	while(i!=j){
		while(i<j&&arr[j]>=key) --j;
		myswap(&arr[i],&arr[j]);
		while(i<j&&arr[i]<=key) ++i;
		myswap(&arr[i],&arr[j]);
	}
	return i;
}
void Qsort(long long *arr,int left,int right)
{
	int v;
	if(left<right){
		v=partition(arr,left,right);
		Qsort(arr,left,v-1);
		Qsort(arr,v+1,right);
	}
}
int binSearchSup(long long *arr,long long value,int left,int right)
{
	int low,mid,high;
	low=left;high=right;
	if(arr[left]<=value&&arr[right]<=value) return 0;
	if(arr[left]>value&&arr[right]>value) return right-left+1;
	while(high-low>1){
		mid=(low+high)/2;
		if(arr[mid]<=value) low=mid;
		else high=mid;
	}
	return right-high+1;
}
int main()
{
	int T,i,n,c;
	int low,high,remove_num,res;
	long long x;
	long long a[10007];
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&c);
		for(i=1;i<=n;++i) scanf("%lld",&a[i]);
		Qsort(a,1,n);res=15000;
		for(i=0;i<=n-1;++i){
			remove_num=i;
			x=c*a[i+1];
			remove_num+=binSearchSup(a,x,i+1,n);
			res=my_min(remove_num,res);
		}
		printf("%d\n",res);
	}
	return 0;
}
