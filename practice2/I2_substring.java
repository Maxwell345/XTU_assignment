import java.util.Scanner;
public class Main {
	public static int my_int_min(int x,int y)
	{
		return x<y?x:y;
	}
	public static int my_min_of_array(int[] array,int size)
	{
		int res,i;
		res=1000000;
		for(i=0;i<size;++i) {
			if(array[i]<res) res=array[i];
		}
		return res;
	}
	public static boolean alloccured(int[] arr,int size)
	{
		int i;
		for(i=0;i<size;++i) {
			if(arr[i]<=-1) return false;
		}
		return true;
	}

	public static void main(String[] args) {
		Scanner reader=new Scanner(System.in);
		String alphabet="abcdefghijklmnopqrstuvwxyz";
		String s;
		int i,j,srclen,t;
		int start,end,ans;
		int[] lastpos=new int[26];
		while(reader.hasNext()) {
			s=reader.nextLine();
			ans=5000;srclen=s.length();
			for(i=0;i<26;++i) lastpos[i]=-1;
			for(i=0;i<srclen;++i) {
				for(j=0;j<26;++j) {
					if(s.charAt(i)==alphabet.charAt(j)) lastpos[j]=i;
				}
				if(alloccured(lastpos, 26))
				{
					start=my_min_of_array(lastpos, 26);
					ans=my_int_min(ans, i-start+1);
				}
			}
			if(ans!=5000) {
				
				System.out.println(ans);
			}
			else System.out.println("0");
		}
		
	}

}
