/* USER: user5.37pdp
LANG: C
TASK: hiring*/
#include <stdio.h>

int secondary(int a, int b, int c);
void quicksort(int ipojifii[][4], int low, int high);



int main(void)
{
    FILE *in = fopen("hiring.in", "r");
    FILE *out = fopen("hiring.out", "w");

    int ipoprovlima, N, Xalkina, Asimenia, Xrisa, result = 0;

    fscanf(in, "%d %d %d %d %d", &ipoprovlima, &N, &Xalkina, &Asimenia, &Xrisa);

    int ipojifii[N][4];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(in, "%d", &ipojifii[i][j]);
        }
        ipojifii[i][3] = secondary(ipojifii[i][0], ipojifii[i][1], ipojifii[i][2]);
    }

    quicksort(ipojifii, 0, N - 1);

    for(int i = 0; i < N; i++)
    {
        if(Xrisa != 0)
        {
            result += ipojifii[i][2];
            Xrisa--;
        }
        else if(Asimenia != 0)
        {
            result += ipojifii[i][1];
            Asimenia--;
        }
        else
        {
            result += ipojifii[i][0];
        }
    }
    fprintf(out, "%d", result);

    fclose(in);
    fclose(out);
    return 0;
}
void swap_rows(int row1[], int row2[], int cols)
{
    for (int i = 0; i < cols; i++) {
        int temp = row1[i];
        row1[i] = row2[i];
        row2[i] = temp;
    }
}

int xorism(int ipojifii[][4], int low, int high)
{
    int pivot = ipojifii[high][3]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (ipojifii[j][3] > pivot) 
        { 
            i++;
            swap_rows(ipojifii[i], ipojifii[j], 4);
        }
    }
    swap_rows(ipojifii[i + 1], ipojifii[high], 4);
    return i + 1;
}

void quicksort(int ipojifii[][4], int low, int high)
{
    if (low < high) 
    {   
        int pi = xorism(ipojifii, low, high);

        quicksort(ipojifii, low, pi - 1);
        quicksort(ipojifii, pi + 1, high);
    }
}
int secondary(int a, int b, int c)
{
    int y = (b - a) + (c - b);
    return y;
}
