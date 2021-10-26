import java.util.*;
public class prime_in_range{
	static void pin(int min,int max){
	int a=min,b=max,flag,i,j;
		for (i = a; i <= b; i++) {
 
            if (i == 1 || i == 0)
                continue;
 
            flag = 1;
 
            for (j = 2; j <= i / 2; ++j) {
                if (i % j == 0) {
                    flag = 0;
                    break;
                }
            }
 
            if (flag == 1)
                System.out.println(i);
        }

	}
	public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	System.out.println("enter max");
	int max=sc.nextInt();
	System.out.println("enter min");
	int min=sc.nextInt();
	pin(min,max);

	}
}
