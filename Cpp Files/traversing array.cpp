#include<stdio.h>
 void traversing_array(int*, int , int ); //function declaration
 
 void input_data(int*, int, int);
   
   // function definition
   
   void traversing_array(int linear_array[], int lb, int ub)
   {
   	int counter;
   	 for(counter=lb; counter<=ub; counter++)
   	 {
   	 	printf(" \n element at %d is %d",counter,linear_array[counter]);
   	 	
   	
		}
   }
   
   void input_data(int array[], int lb, int ub)
   {
   	int counter;
   	for(counter=lb; counter<=ub; counter++)
   	{
   		array[counter]=2+counter;
   		printf("\n data value for the: %d: %d",counter, array);
	   }
   	
   }
   
   //function definition
  int main()
  {
  	int lb,ub;
  	int array[100];
  	printf("Enter the lb: %d",lb);
  	scanf("%d",&lb);
  	printf("enter the up: %d", ub);
  	scanf("%d",&ub);
  	
  	input_data(array, lb,ub);
  	
  	traversing_array(array, lb,ub);
  	
  	
  	
  	
  	
  	
  	
  }
