import java.util.Scanner;
public class my_multiplier {
	public static int my_multiply(int x,int y) {
		int stair,product,tempx,tempy;
		product=0;tempx=x;tempy=y;
		do {
			stair=(tempy&1)>0?tempx:0;
			product+=stair;
			tempy>>=1;tempx<<=1;
		} while (tempy>0);
		return product;
	}

	public static void main(String[] args) {
		Scanner sr=new Scanner(System.in);
		int a,b,myans;
		a=sr.nextInt();
		b=sr.nextInt();
		sr.close();
		myans=my_multiply(a,b);
		System.out.println(myans);
	}

}
