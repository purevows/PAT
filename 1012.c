#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long int transcript[2001][5] = { 0 }, ranks[2001][5] = { 0 };
int n, m;

void findmin(int c, int m, int e, int a)
{
	int min;
	min = ((e >= m) ? ((m >= c) ? ((c >= a) ? (a) : (c)) : ((m >= a) ? (a) : (m))) : ((e >= c) ? ((c >= a) ? (a) : (c)) : (e >= a) ? (a) : (e)));
	printf("%d", min);
	if (min == a)
		printf(" A\n");
	else if (min == c)
		printf(" C\n");
	else if (min == m)
		printf(" M\n");
	else if (min == e)
		printf(" E\n");
}

void sort(long int rankstemp[2001][3], int course)
{
	long int tempid, tempr;
	int i, j, flag;
	for (i = 0; i < n; i++)
	{
		flag = 0;
		for (j = 0; j < n - 1; j++)
		{
			if (rankstemp[j][1] < rankstemp[j + 1][1])
			{
				tempr = rankstemp[j][1];
				tempid = rankstemp[j][0];
				rankstemp[j][1] = rankstemp[j + 1][1];
				rankstemp[j][0] = rankstemp[j + 1][0];
				rankstemp[j + 1][1] = tempr;
				rankstemp[j + 1][0] = tempid;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	for (i = 0; i < n; i++)
	{
		if (rankstemp[i][1] != rankstemp[i - 1][1])
			rankstemp[i][2] = i + 1;
		else if(rankstemp[i][1] == rankstemp[i - 1][1])
			rankstemp[i][2] = rankstemp[i - 1][2];
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (ranks[i][0] == rankstemp[j][0])
			{
				ranks[i][course] = rankstemp[j][2];
			}
		}
	}
}

int main()
{
	long int rankstemp[2001][3] = { 0 };
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
			scanf("%ld", &transcript[i][j]);
		transcript[i][4] = ((transcript[i][1] + transcript[i][2] + transcript[i][3]) / 3.0) + 0.5;
	}
	for (i = 0; i < m; i++)
		scanf("%ld", &ranks[i][0]);
	for (i = 1; i < 5; i++)
	{
		for (j = 0; j < n; j++)
		{
			rankstemp[j][0] = transcript[j][0];
			rankstemp[j][1] = transcript[j][i];
		}
		sort(rankstemp, i);
	}
	for (i = 0; i < m; i++)
	{
		if (ranks[i][1] == 0)
			printf("N/A\n");
		else
			findmin(ranks[i][1], ranks[i][2], ranks[i][3], ranks[i][4]);
	}
}
