#include <stdio.h>

long long abs1(long long x)
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

    long long result = 0;
    int N;
    int iporpovlima;
    fscanf(in, "%d", &iporpovlima); //axristo akoma
    fscanf(in, "%d", &N);

    long long boxes[N][2];
    for(int i = 0; i < N; i++)
    {
        fscanf(in,"%lld" "%lld", &boxes[i][0], &boxes[i][1]);
    }
    result+=boxes[0][0];
    result+=boxes[N-1][0];
    for(int i = 0; i < N; i++)
    {
        result+=boxes[i][1] * 2;
    }
    
    for(int i = 0; i < N - 1; i++)
    {
        result += abs1(boxes[i][0] - boxes[i + 1][0]);
    }
    
    fprintf(out, "%d", result);

    fclose(in);
    fclose(out);
}
