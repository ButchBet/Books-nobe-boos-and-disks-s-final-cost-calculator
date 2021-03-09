#include <stdio.h>
#include <math.h>

/* n = the number of bits
   max_num = the max value for the first bit (ex: 8 bits = 256 the first bit
   has the value 128
   sum = the addition of each calculation
   calc = the calculation (8th bit is 0 then 0*max_num(128) = 0)
   nums[n] = the value to each bit
*/
int main(){ 
  int n = 0, sum = 0, calc = 0;

  printf("Enter the number of bits to this number: ");scanf("%i",&n);
  printf("\n\nEnter the value to each bit, since the 8th to the 1th\n");

  int nums[n],  max_num = pow(2,n)/2;
  

  // reading the valiu to each index location
  for (int i=0; i<n; i++){
    printf("--> ");scanf("%i", &nums[i]);printf("\n");
    calc = max_num * nums[i];
    sum += calc;
    max_num /= 2;
  }

  printf("The decimal number is: %i.\n\n", sum);

  return 0;
}
