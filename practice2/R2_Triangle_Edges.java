import java.util.Scanner;
public class Main {
	public static void swaparr(int[] arr,int x,int y)
	{
		int temp;
		temp=arr[x];
		arr[x]=arr[y];
		arr[y]=temp;
	}
	public static int partition(int[] a,int left,int right)
	{
		int i,j,key;
		i=left;j=right;key=a[left];
		while(i!=j) {
			while(i<j&&a[j]>=key) j--;
			swaparr(a, i, j);
			while(i<j&&a[i]<=key) i++;
			swaparr(a, i, j);
		}
		return i;
	}
	public static void my_qsort(int[] a,int left,int right)
	{
		int v;
		if(left<right)
		{
			v=partition(a,left, right);
			my_qsort(a, left, v-1);
			my_qsort(a, v+1, right);
		}
	}
	public static void main(String[] args) {
		Scanner reader=new Scanner(System.in);
		int T,n,ans,s;
		int i,j,low,high,mid;
		int[] edges=new int[1008];
		T=reader.nextInt();
		while(T>0) {
			T--;
			n=reader.nextInt();
			for(i=1;i<=n;++i) edges[i]=reader.nextInt();
			my_qsort(edges,1,n);
			ans=0;
			for(i=1;i<=n-2;++i) {
				for(j=i+1;j<=n-1;++j) {
					low=j+1;high=n;s=edges[i]+edges[j];
					if(edges[low]<s&&edges[high]<s) ans+=(n-j);
					else if(edges[low]<s&&edges[high]>=s)
					{
						while(high-low>1) {
							mid=(low+high)/2;
							if(edges[mid]<s) low=mid;
							else high=mid;
						}
						ans+=(low-j);
					}
				}
			}
			System.out.println(ans);
		}
	}

}