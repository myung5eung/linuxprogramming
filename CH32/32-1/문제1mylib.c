#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mylib.h"
int input() {
	int x;
	printf("정수 입력: ");
	scanf("%d", &x);
	return x;
}
double cal(int x) {
	return 1.5 * SQUARE(x) - 3 * x + 0.7;
}
void print(double y) {
	printf("y = %lf", y);
}
