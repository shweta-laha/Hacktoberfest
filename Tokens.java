import java.io.*;
import java.util.*;

public class Count {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        s=s.trim();
        if(s.length()==0)
        {
            System.out.println("0");
        }
        else
        {
            String arr[]=s.split("[!,?._'@ ]+");
            System.out.println(arr.length);
            for(String i:arr)
            System.out.println(i);
        }
        scan.close();
    }
}
