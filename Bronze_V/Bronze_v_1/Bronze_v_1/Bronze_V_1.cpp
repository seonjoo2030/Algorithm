#include <stdio.h>
#include <string.h>


// ������ ���̳ʽ��� ������ ���� ������ �ʴ� ���� ������ �����ؾ� �Ѵ�.
// Subtract �Լ��� ������ ù��° ���� ū ���̰�, �ι�° ���� ���� ���� �����Ͽ� �����Ѵ�.
// Subtract �Լ� �ۿ��� ��ȣ�� ����.
// ������ ũ�� ������ ���ϴ� max �Լ� �ʿ�
// ���� ������ ���� max �Լ� ȣ�� ���� ó���Ѵ�.
// �������� ���� ���ϴ� ����� ã�ƾ� �Ѵ�.

int getQuotient(char* pszQuotient, int iQuotientLen)
{
	pszQuotient[iQuotientLen - 1] = pszQuotient[iQuotientLen - 1] + 1;
	if ('9' < pszQuotient[iQuotientLen - 1])
	{
		while ('9' < pszQuotient[iQuotientLen - 1])
		{
			pszQuotient[iQuotientLen - 1] = '0';
			pszQuotient[iQuotientLen - 1 - 1] = pszQuotient[iQuotientLen - 1 - 1] + 1;
			iQuotientLen--;
		}
	}

	return 0;
}

char* Max(char* pszFirstNum, char* pszSecNum)
{
	int iFirstNumLen = 0;
	int iSecNumLen = 0;

	iFirstNumLen = strlen(pszFirstNum);
	iSecNumLen = strlen(pszSecNum);

	if (iSecNumLen < iFirstNumLen)
		return pszFirstNum;
	else if (iSecNumLen > iFirstNumLen)
		return pszSecNum;
	else
	{
		for (int i = 0; i < iFirstNumLen; i++)
		{
			if (pszFirstNum[i] > pszSecNum[i])
				return pszFirstNum;
			else if (pszFirstNum[i] < pszSecNum[i])
				return pszSecNum;
		}
	}
	return pszFirstNum;
}

int Subtract(char* pszFirstNum, char* pszSecNum)
{
	int iFirstNumLen = 0;
	int iSecNumLen = 0;
	int iUpper = 0;
	if (NULL == pszFirstNum || NULL == pszSecNum)
		return -1;

	iFirstNumLen = strlen(pszFirstNum);
	iSecNumLen = strlen(pszSecNum);

	for (int i = iSecNumLen - 1; i >= 0; i--)
	{
		pszFirstNum[iFirstNumLen - 1] = pszFirstNum[iFirstNumLen - 1] - pszSecNum[i] - iUpper + '0';
		if ('0' > pszFirstNum[iFirstNumLen - 1])
		{
			pszFirstNum[iFirstNumLen - 1] = pszFirstNum[iFirstNumLen - 1] + 10;
			iUpper = 1;
		}
		else
		{
			iUpper = 0;
		}
		iFirstNumLen--;
	}

	if (iUpper)
		pszFirstNum[iFirstNumLen - 1] = pszFirstNum[iFirstNumLen - 1] - 1;

	return 0;
}

int Devide(char* pszFirstNum, char* pszSecNum, char* pszQuotient)
{
	int iFirstNumLen = 0;
	int iSecNumLen = 0;
	int iQuotientLen = 0;
	char szTemp[1001] = { 0 };

	iFirstNumLen = strlen(pszFirstNum);
	iSecNumLen = strlen(pszSecNum);

	iQuotientLen = iFirstNumLen - iSecNumLen + 1;

	for (int i = 0; i < iQuotientLen; i++)
	{
		pszQuotient[i] = '0';
	}

	pszQuotient[iQuotientLen] = '\0';

	memset(szTemp, '0', iFirstNumLen);

	for (int i = iSecNumLen - 1; i >= 0; i--)
	{
		szTemp[iFirstNumLen - 1] = szTemp[iFirstNumLen - 1] + pszSecNum[i] - '0';
		iFirstNumLen--;
	}

	while (Max(pszFirstNum, szTemp) == pszFirstNum)
	{
		Subtract(pszFirstNum, szTemp);
		getQuotient(pszQuotient, iQuotientLen);
	}

	return 0;
}

int main()
{
	char szMoney[1001] = { 0 };
	char szNum[1001] = { 0 };
	char szQuotient[1001] = { 0 };
	int iIndex = 0;
	int iQindex = 0;

	scanf("%s %s", szMoney, szNum);

	if (!strcmp(szMoney, szNum))
		printf("1\n0\n");
	else if (!strcmp(szNum, "1"))
		printf("%s\n0\n", szMoney);
	else
	{
		Devide(szMoney, szNum, szQuotient);

		while ('0' == szMoney[iIndex])
			iIndex++;

		if ('\0' == szMoney[iIndex])
			iIndex--;

		while ('0' == szQuotient[iQindex])
			iQindex++;

		if ('\0' == szQuotient[iQindex])
			iQindex--;


		printf("%s\n%s\n", szQuotient + iQindex, szMoney + iIndex);
	}

	return 0;
}