#include <iostream>
using namespace std;
typedef struct{
	int data;
	int lchild,rchild;
}treenode;
treenode BSTstandard[123];
bool isSameTree(treenode *p,int root1,treenode *q,int root2)
{
	if(p[root1].data==0&&q[root2].data==0) return true;
	else if(p[root1].data==0||q[root2].data==0) return false;
	else if(p[root1].data != q[root2].data) return false;
	else return isSameTree(p,p[root1].lchild,q,q[root2].lchild) && isSameTree(p,p[root1].rchild,q,q[root2].rchild);
}
void cleartree(treenode *tree)
{
	int i;
	for(i=0;i<123;i++){
		tree[i].data=0;tree[i].lchild=0;tree[i].rchild=0;
	}
}
int treetop;
int main()
{
	int T,n,m,b;
	int i,j,branch;
	treenode BSTtest[123];
	scanf("%d",&T);
	while(T--){
		cleartree(BSTstandard);
		scanf("%d%d",&n,&m);
		
		scanf("%d",&b);
		BSTstandard[1].data=b;treetop=1;
		for(j=2;j<=n;++j){
			scanf("%d",&b);
			BSTstandard[++treetop].data=b;
			branch=1;
			while(1){
				if(b<BSTstandard[branch].data)
				{
					if(BSTstandard[branch].lchild!=0) branch=BSTstandard[branch].lchild;
					else {BSTstandard[branch].lchild=treetop;break;}
				}
				else{
					if(BSTstandard[branch].rchild!=0) branch=BSTstandard[branch].rchild;
					else {BSTstandard[branch].rchild=treetop;break;}
				}
			}
		}
		for(i=1;i<=m;++i){
			cleartree(BSTtest);
			scanf("%d",&b);
			BSTtest[1].data=b;treetop=1;
			for(j=2;j<=n;++j){
				scanf("%d",&b);
				BSTtest[++treetop].data=b;
				branch=1;
				while(1){
					if(b<BSTtest[branch].data)
					{
						if(BSTtest[branch].lchild!=0) branch=BSTtest[branch].lchild;
						else {BSTtest[branch].lchild=treetop;break;}
					}
					else{
						if(BSTtest[branch].rchild!=0) branch=BSTtest[branch].rchild;
						else {BSTtest[branch].rchild=treetop;break;}
					}
				}
			}
			if(isSameTree(BSTstandard,1,BSTtest,1)) cout<<i<<": Yes"<<endl;
			else                                    cout<<i<<": No"<<endl;
		}
		cout<<endl;
	}
}
