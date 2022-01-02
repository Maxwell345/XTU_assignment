public class my_half_adder {
	int a,b;
	public my_half_adder() {
		a=0;
		b=0;
	}
	public my_half_adder(int ia,int ib) {
		a=ia;
		b=ib;
	}
	public int my_half_sum() {
		return a^b;
	}
	public int my_co() {
		return a&b;
	}
}
