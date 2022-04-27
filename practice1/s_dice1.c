#include <stdio.h>
int main()
{
	char instruct[205];
	int i,temp;
	int pose[3];
	while(scanf("%s",instruct)!=EOF){
		pose[0]=1;pose[1]=5;pose[2]=3;
		for(i=0;instruct[i];++i)
		{
			if(instruct[i]=='U'){
				temp=7-pose[0];
				pose[0]=pose[1];
				pose[1]=temp;
			}
			else if(instruct[i]=='D'){
				temp=7-pose[1];
				pose[1]=pose[0];
				pose[0]=temp;
			}
			else if(instruct[i]=='L'){
				temp=7-pose[2];
				pose[2]=pose[0];
				pose[0]=temp;
			}
			else if(instruct[i]=='R'){
				temp=7-pose[0];
				pose[0]=pose[2];
				pose[2]=temp;
			}
			else if(instruct[i]=='X'){
				temp=7-pose[2];
				pose[2]=pose[1];
				pose[1]=temp;
			}
			else if(instruct[i]=='Y'){
				temp=7-pose[1];
				pose[1]=pose[2];
				pose[2]=temp;
			}
		}
		printf("%d\n",pose[0]);
	}
	return 0;
}
