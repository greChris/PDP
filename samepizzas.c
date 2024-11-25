/* USER: user5.37pdp
LANG: C
TASK: hiring*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int x = *a;
    *a= *b; 
    *b = x;
}

int xorism(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] > pivot) {  
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high) 
    {   
        int pi = xorism(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    
    int N;
    int K;
    int ipoprovlima; //den to xrisimopoio kapou
    int result;
    
    FILE * in = fopen("samepizzas.in", "r");
    FILE * out = fopen("samepizzas.out", "w");

    fscanf(in, "%d", &ipoprovlima);
    fscanf(in, "%d", &N);
    fscanf(in, "%d", &K);
    
    int arr[N]; 
    
    for (int i = 0; i < N; i++)
    {
        fscanf(in, "%d ", &arr[i]);
    }
    
    quicksort(arr, 0, N - 1);
    
    result = arr[K - 1];
    fprintf(out,"%d",result);
    
    fclose(in);
    fclose(out);

    return 0;
}
