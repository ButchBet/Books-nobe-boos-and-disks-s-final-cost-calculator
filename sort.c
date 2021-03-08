#include <stdio.h>

int main(){
  int n=0, c=0, i=0, j=0, k=0, p=1; // number of elements, counter, j, k and i carible for the loops and finally p to add it in a variable loop 
  printf("Enter the number of elements: "); scanf("%i", &n);
  float num[n], comp[1], x=0; // numbers, compare and x to show the lowest number
  
  // reading number loop
  for (i=0; i<n; i++){
      printf("Enter the real number: "); scanf("%f", &num[i]); printf("\n");
  }
  
  
  for (i=0; i<n; i++){
    for (j=0; j<n-i; j++){ // n represent the number of iterations to find the lower number 
        if(c != 2 && n-i == 1){
            if (num[0]<=num[1]){
                x = num[0];
                num[0]  = num[1]; 
                num[1] = x;
                c = 0; // don't repit the loop and chenge the index position
                break;
            }else{
                c = 0; // here too
                break;
            }
        }
        else if(c !=2){ // condition to stop the iteration "the max number that get j is 2 when complete
            // all positive comparations
            
            for (k=0; k<n-p; k++){ // we asign the value num[i] to comp[0] to can begin always since the 
                            // fisrt value and if the value is not the lower then the second will continue
                            // the comparation with itself and the rest of the array          
                comp[0] = num[0]; 
                if(comp[0] <= num[k+1]){
                    x = comp[0];
                    c = k;
                    continue;
                }
                else{
                    c = 0;
                    break;
                }
            }
        }
    }

    
    for (k=0; k<n-p; k++){ // asign to the last index the lower number to don't manipulate it 
        
        if (num[k] == x){
            num[k]  = num[k+1]; 
            num[k+1] = x;
        }
        else{
            continue;
        }
    }
    p++;
    c = 0;
  }
  
  for (i=n-1; i>=0; i--){
      printf("--> %.1f.\n", num[i]);
  }
    
  return 0;
}
