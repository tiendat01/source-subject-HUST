package bai1_bai2;

public class BigDog extends Dog {
	@Override
	public void greeting() {
		System.out.println("Woow!");
	}
	@Override
	public void greeting(Dog another) {
		System.out.println("Woooooowwww!");
	}
}
