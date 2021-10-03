class node{
    int min, max;
}
public class minMax {
    public static node getMinMax(int[] numbers){
        int maxValue = numbers[0];
        int minValue = numbers[0];
        for(int i=1;i < numbers.length;i++){
          if(numbers[i] > maxValue){
            maxValue = numbers[i];
          }
          if(numbers[i] < minValue){
            minValue = numbers[i];
          }
        }
        node ans=new node();
        ans.max=maxValue;
        ans.min=minValue;
        return ans;
    }
    public static void main(String []args){
        int [] arr={1, 2, 3, 4, 5};

        node ans=getMinMax(arr);
        System.out.println("Minimum element in array arr is: "+ans.min);
        System.out.println("Maximum element in array arr is: "+ans.max);
    }
}
