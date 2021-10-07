import java.util.Scanner;
import java.lang.Math;

public class strange{    
 public static void main(String args[])
 {
	
	int max_prime=largestPrimeFactor(n);
	if(max_prime>Math.sqrt(n)) {
		System.out.print("Strange");
	}
	else
	{
		System.out.print("Not Strange");
	}
	
 }
public static int largestPrimeFactor(int n) {  
	  if (n <= 1) {  
	   return 0;  
	  } else {  
	   int div = 2;  
	   while (div < n) {  
	    if (n % div != 0) {  
	     div++;  
	    } else {  
	     n = n / div;  
	     div = 2;  
	    }  
	   }  
	   return n;  
	  }  
	  
	}   
}
