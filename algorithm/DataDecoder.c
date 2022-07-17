#include <stdio.h>
void decoder138(char *s,int *arr)
{
	int i0,i1,i2;
	i0=s[0]-48;i1=s[1]-48;i2=s[2]-48;
	arr[0]=(!i0)&&(!i1)&&(!i2);
	arr[1]=(!i0)&&(!i1)&&(i2);
	arr[2]=(!i0)&&(i1)&&(!i2);
	arr[3]=(!i0)&&(i1)&&(i2);
	arr[4]=(i0)&&(!i1)&&(!i2);
	arr[5]=(i0)&&(!i1)&&(i2);
	arr[6]=(i0)&&(i1)&&(!i2);
	arr[7]=(i0)&&(i1)&&(i2);
}
void showArray(int *a,int size)
{
	int i;
	for(i=0;i<size;i++){
		printf("%d",a[i]);
	}
	putchar('\n');
}
int FindOne(int *group,int count)
{
	int person;
	for(person=0;person<count;person++){
		if(group[person]) return person;
	}
	return -1;
}
int main()
{
	int T,j,ans;
	int outData[8];
	char inputData[3];
	scanf("%d",&T);
	while(T--){
		for(j=0;j<8;j++) outData[j]=0;
		scanf("%s",inputData);
		decoder138(inputData,outData);
		ans=FindOne(outData,8);
		printf("address:%d\nlights:",ans);
		showArray(outData,8);
	}
	return 0;
}
