
//mylib.h
#ifndef _MYLIB_H_
#define _MYLIB_H_
int add(int a, int b);
int data_input();
void data_print(int max);
#endif
//main.c
#include "mylib.h"
int main()
{
    int a, b, max;
    a = data_input();
    b = data_input();
    max = add(a, b);
    data_print(max);
    return 0;
}

//mylib.c
#include <stdio.h>
int data_input()
{
    int a;
    printf("Input:");
    scanf("%d", &a);
    return a;
}
int add(int a, int b)
{ 
    if(a>=b) return a;
    else return b;

 }
void data_print(int max)
{ printf("Max:%d\n", max); }
