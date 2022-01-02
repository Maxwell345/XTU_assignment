
public class my_full_adder {
	int x,y,z;
	public my_full_adder(){
		x=0;
		y=0;
		z=0;
	}
	public my_full_adder(int na,int nb,int c) {
		x=na;
		y=nb;
		z=c;
	}
	public int my_full_sum() {
		my_half_adder HA1=new my_half_adder(x,y);
		my_half_adder HA2=new my_half_adder(z,HA1.my_half_sum());
		return HA2.my_half_sum();
	}
	public int my_full_cout() {
		my_half_adder HA_1=new my_half_adder(x,y);
		my_half_adder HA_2=new my_half_adder(z,HA_1.my_half_sum());
		return HA_1.my_co()|HA_2.my_co();
	}
}
