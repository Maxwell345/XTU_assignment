#include <stdio.h>
#include <math.h>
int numcir[16];
int temp[16];
int nextpos(int x,int size)
{
	int pos=x+1;
	if(pos>=size) pos%=size;
	return pos;
}
int all_zeros(int *arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]!=0) return 0;
	}
	return 1;
}
int main()
{
	int T,n;
	int cnt,flag,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&numcir[i]);
		}
		
		flag=0;cnt=0;
		while(cnt<=1000)
		{
			if(all_zeros(numcir,n)){
				flag=1;
				break;
			}
			for(i=0;i<n;i++){
				temp[i]=numcir[i];
			}
			
			for(i=0;i<n;i++){
				temp[i]=numcir[i];
			}
			for(i=0;i<n;i++){
				numcir[i]=abs(temp[i]-temp[nextpos(i,n)]);
			}
			cnt++;
		}
		if(!flag) printf("Impossible\n");
		else      printf("%d\n",cnt);
	}
	return 0;
}
