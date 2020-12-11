/*
1007 Maximum Subsequence Sum (25 point(s))
Given a sequence of K integers { N1, N2, бн, NK }. A continuous subsequence is defined to be { Ni, Ni+1, бн, Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int i, j, k, sum = -1, search;
	scanf("%d", &k);
	int integers[k];
	int start = 0, end = k - 1, current = 0;
	if(k == 0)
	{
		end = 0;
		integers[0] = 0;
	}
	for(i = 0; i < k; i++)
		scanf("%d", &integers[i]);
	for(i = 0; i < k; i++)
	{
		if(integers[i] >= 0)
		{
			search = 0;
			for(j = i; j < k; j++)
			{
				search = search + integers[j];
				if(sum < search)
				{
					sum = search;
					start = i;
					end = j;
				}
			}
		}
	}
	if(sum < 0)
		sum = 0;
	printf("%d %d %d",sum ,integers[start], integers[end]);
	return 0;
}
