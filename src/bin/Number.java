package bin;

import java.util.Random;
public class Number {
	int numa=0;
	int numb=0;
	int numc=0;
	int numd=0;
	Random random=new Random();
	Number(){
		do {
			numa=random.nextInt(10);
			numb=random.nextInt(10);
			numc=random.nextInt(10);
			numd=random.nextInt(10);
		}while(judge(numa,numb,numc,numd)==false);
	}
	
	private boolean judge(int a,int b,int c,int d) {
		if(a==b || a==c || a==d || b==c || b==d || c==d)
			return false;
		else return true;
	}
	
	
//	public static void main(String[] args) {
//		new CreateNumber();
//		System.out.println(numa);
//		System.out.println(numb);
//		System.out.println(numc);
//		System.out.println(numd);
//	}
}
