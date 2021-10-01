
import java.util.*;
class Caesar_Cipher
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        String str,str1="";
        int i,l,a;
        char ch;
        System.out.println("Enter a sentence");
        str=sc.nextLine();
        l=str.length();
        if(l>3&&l<100)
        {
            for(i=0;i<l;i++)
            {
                ch=str.charAt(i);
                a=(int)ch;
                if((a>=97&&a<=109)||(a>=65&&a<=77))
                    a+=13;
                else if((a>=110&&a<=122)||(a>=78&&a<=90))
                    a-=13;
                str1=str1+(char)a;
            }
            System.out.println("the cipher text:\n"+str1);
        }
        else
            System.out.println("Invalid Length");
    }
}