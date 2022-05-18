#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int iR1 = 0;
	int iAvg = 0;

	scanf("%d %d", &iR1, &iAvg);
	printf("%d", iAvg * 2 - iR1);

	return 0;
}