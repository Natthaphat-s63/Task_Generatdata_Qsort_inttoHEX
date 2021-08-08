#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE * f;
    int N;
    printf("number of integers: ");
    scanf("%d",&N);
    f = fopen("data.txt","w");
    for(int i;i<N;i++){
        fprintf(f,"%d\n",rand()%100);
    }
    fclose(f);
    return 0;

}