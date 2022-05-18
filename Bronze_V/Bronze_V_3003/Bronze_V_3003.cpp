#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int iNum = 0;
	int iRetArr[7] = { 0 };

	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &iNum);

		switch (i)
		{
		case 0:
			iRetArr[i] = 1 - iNum;
			break;
		case 1:
			iRetArr[i] = 1 - iNum;
			break;
		case 2:
			iRetArr[i] = 2 - iNum;
			break;
		case 3:
			iRetArr[i] = 2 - iNum;
			break;
		case 4:
			iRetArr[i] = 2 - iNum;
			break;
		case 5:
			iRetArr[i] = 8 - iNum;
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < sizeof(iRetArr) / sizeof(int) - 1; i++)
		printf("%d ", iRetArr[i]);

	return 0;
}