#include <stdio.h>

int selectionSortCArray(int array[]);
void swap(int array[], int min, int i);

int main(void){
    int array[6] = {3,2,1,5,4};
    selectionSortCArray(array);
}

int selectionSortCArray(int  array[])
{
    int i, j, min;
    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i + 1; j < 5; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        swap(array, min, i);
        min = i;
    }

    /*Show the changing array */
        printf("{");
        for(int k = 0; k < 5; k++){
            if(k == 4){
                printf("%d}.\n", array[k]);
            }else{
                printf("%d, ", array[k]);
            }
        }
}

void swap(int array[], int min, int i){
    int temp = array[min];
    array[min] = array[i];
    array[i] = temp;
}