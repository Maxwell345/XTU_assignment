#include <stdio.h>
typedef struct{
	int begin;
	int end;
	int weight;
}Edge;
void myswap(Edge *x,Edge *y)
{
    Edge temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int partition(Edge *arr,int left,int right)
{
    int i,j;
    Edge key;
    i=left;j=right;key=arr[left];
    while(i!=j){
        while(i<j&&arr[j].weight>=key.weight) --j;
        myswap(&arr[i],&arr[j]);
        while(i<j&&arr[i].weight<=key.weight) ++i;
        myswap(&arr[i],&arr[j]);
    }
    return i;
}
void Qsort(Edge *arr,int left,int right)
{
    int v;
    if(left<right){
        v=partition(arr,left,right);
        Qsort(arr,left,v-1);
        Qsort(arr,v+1,right);
    }
}
int Find(int *parent,int f)
{
	while(parent[f]>0){
		f=parent[f];
	}
	return f;
}
void my_fill_zero(int *arr,int size)
{
	int idx;
	for(idx=0;idx<size;++idx) arr[idx]=0;
}
int main()
{
	int numvtx,numedg,i,price;
	int j,emax,n,m;
	int K,MAXVER=1008,MAXEDG=10006;
	int parent[MAXVER];
	Edge edges[MAXEDG];
	Edge t;
	scanf("%d",&K);
	while(K--){
		my_fill_zero(parent,MAXVER);
		scanf("%d %d",&numvtx,&numedg);
		for(i=1;i<=numedg;++i)
		{
			scanf("%d %d %d",&edges[i].begin,&edges[i].end,&edges[i].weight);
		}
		Qsort(edges,1,numedg);
		price=0;
		for(i=numedg;i>=1;--i)
		{
			n=Find(parent,edges[i].begin);
			m=Find(parent,edges[i].end);
			if(n!=m)
			{
				parent[n]=m;
				price+=edges[i].weight;
			}
		}
		printf("%d\n",price);
	}
}
