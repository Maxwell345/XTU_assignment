import java.util.Scanner;
public class Main {
	public static int gcd_2(int x,int y)
	{
		return y>0?gcd_2(y, x%y):x;
	}
	public static int gcd_3(int n1,int n2,int n3)
	{
		return gcd_2(gcd_2(n1, n2), n3);
	}
	public static void main(String[] args) {
		Scanner sr=new Scanner(System.in);
		int t;
		t=sr.nextInt();
		while(t>0) {
			int p,q;
			int a,b,c,factor;
			p=sr.nextInt();
			q=sr.nextInt();
			a=p*(p+q);
			b=q*q;
			c=2*(p+q)*q-p*(p+q)-q*q;
			factor=gcd_3(a, b, c);
			a/=factor;b/=factor;c/=factor;
			System.out.println(a+" "+b+" "+c);
			t--;
		}
	}

}
