#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int iNum = 0;
	int iAvg = 0;

	scanf("%d %d", &iNum, &iAvg);

	printf("%d\n", iNum * iAvg - iNum + 1);

	return 0;
}