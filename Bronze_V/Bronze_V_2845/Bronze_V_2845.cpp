#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int iPeoPleNum = 0;
	int iSize = 0;
	int iPeopleSum = 0;
	int iNewsNum = 0;
	int iRetArr[6] = { 0 };

	scanf("%d %d", &iPeoPleNum, &iSize);

	iPeopleSum = iPeoPleNum * iSize;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &iNewsNum);
		iRetArr[i] = iNewsNum - iPeopleSum;
	}

	for (int i = 0; i < 5; i++)
		printf("%d ", iRetArr[i]);

	return 0;
}