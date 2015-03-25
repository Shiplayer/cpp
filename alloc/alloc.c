#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    int num = 5;
    //int** mass = (int **)calloc(num, sizeof(int *));
    int* arr = (int *)calloc(num, sizeof(int));
    int* arr2 = (int *)calloc(num, sizeof(int));
    int i;
    for(i = 0; i < num; i++){
        arr[i] = i + 1;
        arr2[i] = num - i;
    }
   // memcpy(mass, arr, num * sizeof(int *));
    int j;
    for(i = 0; i < num; i++)
        printf("%d", arr[i]);
    printf("\n");
    for(i = 0; i < num; i++)
        printf("%d", arr2[i]);
    printf("\n");
    memcpy(arr, arr2, num * sizeof(int));
    for(i = 0; i < num; i++)
        printf("%d",arr[i]);
    printf("%d\n", arr[6]);
    return 0;
}
