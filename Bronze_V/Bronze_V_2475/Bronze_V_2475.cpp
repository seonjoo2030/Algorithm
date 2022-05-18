#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>

int main()
{
	int iNum = 0;
	int iRet = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &iNum);
		iRet = iRet + iNum * iNum;
	}

	printf("%d\n", iRet % 10);

	return 0;
}