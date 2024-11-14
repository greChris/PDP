#include <stdio.h>

int abs(int x)
{
    if (x >= 0)
    {
        return x;
    } 
    else
    {
        return -x;
    }
}

int main(void)
{
    FILE * in = fopen("polybox.in", "r");
    FILE * out = fopen("polybox.out", "w");

    int result;
    int N;
    int iporpovlima;
    fscanf(in, "%d", &iporpovlima); //axristo akoma
    fscanf(in, "%d", &N);

    int boxes[N][2];
    for(int i = 0; i < N; i++)
    {
        fscanf(in,"%d" "%d", &boxes[i][0], &boxes[i][1]);
    }
    result+=boxes[0][0];
    result+=boxes[N-1][0];
    for(int i = 0; i < N; i++)
    {
        result+=boxes[i][1] * 2;
    }
    
    for(int i = 0; i < N - 1; i++)
    {
        result += abs(boxes[i][0] - boxes[i + 1][0]);
    }
    
    fprintf(out, "%d", result);

    fclose(in);
    fclose(out);
}