import java.util.Scanner;
public class Main {
	public static int nextpos(int p,int size)
	{
		int res;
		res=p+1;
		if(res>size) res-=size;
		return res;
	}

	public static void main(String[] args) {
		Scanner reader=new Scanner(System.in);
		int T,i,j,repeat;
		int n,a1,a2,ans;
		int[] circle=new int[1001];
		int[] f=new int[1001];
		T=reader.nextInt();
		while(T>0) {
			n=reader.nextInt();
			a1=reader.nextInt();
			a2=reader.nextInt();
			for(i=0;i<=n;++i) circle[i]=i;
			f[1]=a1;f[2]=a2;
			for(i=3;i<n;++i) f[i]=(f[i-1]+f[i-2])%n+1;
			j=0;
			for(i=1;i<n;++i) {
				repeat=f[i];
				while(repeat>0)
				{
					do {
						j=nextpos(j,n);
					}while(circle[j]==0);
					repeat--;
				}
				circle[j]=0;
			}
			do {
				j=nextpos(j,n);
			}while(circle[j]==0);
			ans=j;
			System.out.println(ans);
			T--;
		}
	}

}
