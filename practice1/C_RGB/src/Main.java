import java.util.Scanner;
public class Main {
	public static int my_min(int x,int y)
	{
		return x<y?x:y;
	}
	public static void main(String[] args) {
		Scanner reader=new Scanner(System.in);
		String s;int i,res,t,remain;
		int n_r,n_g,n_b,size;
		int rg,rb,gr,gb,br,bg;
		int[] d=new int[6];
		while(reader.hasNext()) {
			s=reader.nextLine();size=s.length();
			n_r=n_g=n_b=0;
			for(i=0;i<6;i++) d[i]=0;
			res=0;
			for(i=0;i<size;i++) {
				if(s.charAt(i)=='R')      n_r++;
				else if(s.charAt(i)=='G') n_g++;
				else                      n_b++;
			}
			for(i=0;i<=n_r-1;i++) {
				if(s.charAt(i)=='G')      d[0]++;
				else if(s.charAt(i)=='B') d[1]++;
			}
			for(i=n_r;i<=n_r+n_g-1;i++) {
				if(s.charAt(i)=='R')      d[2]++;
				else if(s.charAt(i)=='B') d[3]++;
			}
			for(i=n_r+n_g;i<=size-1;i++) {
				if(s.charAt(i)=='R')      d[4]++;
				else if(s.charAt(i)=='G') d[5]++;
			}
			t=my_min(d[0], d[2]);
			res+=t;d[0]-=t;d[2]-=t;
			t=my_min(d[1], d[4]);
			res+=t;d[1]-=t;d[4]-=t;
			t=my_min(d[5], d[3]);
			res+=t;d[5]-=t;d[3]-=t;
			remain=0;
			for(i=0;i<6;i++) {
				if(d[i]!=0) remain=d[i];
			}
			res+=2*remain;
			System.out.println(res);
		}
	}

}
