import java.util.Scanner;
public class adder_calc {
	public static int my_todec(int[] rb) {
		return ( ((rb[3]*2+rb[2])*2+rb[1])*2+rb[0]);
	}

	public static void main(String[] args) {
		Scanner reader=new Scanner(System.in);
		int a,b,overflow,ans;
		int[] bintempa=new int[4];
		int[] bintempb=new int[4];
		int[] add_res=new int[4];
		a=reader.nextInt();b=reader.nextInt();
		if(a>15||a<0||b>15||a<0) System.out.println("error input");
		else {
			bintempa[0]=a%2;bintempa[1]=(a/2)%2;bintempa[2]=((a/2)/2)%2;bintempa[3]=((a/2)/2)/2;
			bintempb[0]=b%2;bintempb[1]=(b/2)%2;bintempb[2]=((b/2)/2)%2;bintempb[3]=((b/2)/2)/2;
			my_full_adder FA0=new my_full_adder(bintempa[0],bintempb[0],0);
			add_res[0]=FA0.my_full_sum();
			my_full_adder FA1=new my_full_adder(bintempa[1],bintempb[1],FA0.my_full_cout());
			add_res[1]=FA1.my_full_sum();
			my_full_adder FA2=new my_full_adder(bintempa[2],bintempb[2],FA1.my_full_cout());
			add_res[2]=FA2.my_full_sum();
			my_full_adder FA3=new my_full_adder(bintempa[3],bintempb[3],FA2.my_full_cout());
			add_res[3]=FA3.my_full_sum();
			overflow=FA3.my_full_cout();
			ans=my_todec(add_res);
			System.out.println(ans);
			if(overflow>0) System.out.println("OVERFLOW!");
			else System.out.println("not overflow");
		}
	}

}
