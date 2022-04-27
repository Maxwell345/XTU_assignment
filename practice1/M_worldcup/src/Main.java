import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner reader=new Scanner(System.in);
		int T,n,i;
		float w_max,d_max,l_max,cost;
		T=reader.nextInt();
		while(T>0) {
			T--;w_max=d_max=l_max=0;
			n=reader.nextInt();
			float[] win=new float[n];
			float[] draw=new float[n];
			float[] lose=new float[n];
			for(i=0;i<n;++i) {
				win[i]=reader.nextFloat();
				draw[i]=reader.nextFloat();
				lose[i]=reader.nextFloat();
			}
			for(i=0;i<n;++i) {
				if(win[i]>w_max) w_max=win[i];
				if(draw[i]>d_max) d_max=draw[i];
				if(lose[i]>l_max) l_max=lose[i];
			}
			cost=1/w_max+1/d_max+1/l_max;
			if(cost<1) System.out.println("Yes");
			else       System.out.println("No");
		}
	}

}
