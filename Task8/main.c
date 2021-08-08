#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "qsort.h"


int main(){
    FILE *fp;
    FILE *fp2;
    FILE *fc;
    int c;
    int line=0;
    char* row;
    ssize_t read;
    ssize_t len =0;


    fp = fopen("data.txt","r");
    if(fp == NULL) {
        perror("Error in opening file");
        return(-1);
    }
        while(1) {
        c = fgetc(fp);
        if((char)c == (char)'\n')line++;
        if( feof(fp))break ;
    } 
    //printf("line : %d\n", line);
    int arr[line];
    fclose(fp);


    fp2 =fopen("data.txt","r");
    int round=0;
        while (((read = getline(&row, &len, fp2)) != -1)&& (round<line)) {
            arr[round]=atoi(row);
            round++;
        }
    fclose(fp2);


    int srr[7] ={10,7,12,8,3,2,6};
    QuickSort(srr,0,6);
    fc=fopen("data_stored.txt","w");
    for(int i =0;i<6;i++)
    {
        printf("%d ",srr[i]);
        fprintf(fc,"%d\n",srr[i]);
    }
    fclose(fc);
    return 0;
}