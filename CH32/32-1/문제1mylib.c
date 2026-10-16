#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mylib.h"
int input() {
	int x;
	printf("정수 입력: ");
	scanf("%d", &x);
	return x;
}
int bigger(int a, int b) {
	if (a > b)return a;
	else return b;
}
void print(int big) {
	printf("더 큰수 %d", big);
}
