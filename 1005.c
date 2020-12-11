/*
1005 Spell It Right (20 point(s))
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (¡Ü10^100 ).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int i = 0, j = 0, k, sum = 0;
	char input[101] = {0};
	scanf("%s", &input);
	for(i = 0; i < 101; i++)
	{
		if(input[i] != 0)
		{
			sum = sum + (input[i] - '0');
			j++;
		}
	}
	if(sum == 0)
		printf("zero");
	int m[j];
	for(k = 0; k < j; k++)
		m[k] = 0;
	i = 0;
	while(sum)
	{
		m[i] = sum % 10;
		sum = sum / 10;
		i++;
	}
	for(k = i - 1; k >= 0; k--)
	{
		if(k != 0)
		{
			switch(m[k])
			{
				case 0:printf("zero ");break;
				case 1:printf("one ");break;
				case 2:printf("two ");break;
				case 3:printf("three ");break;
				case 4:printf("four ");break;
				case 5:printf("five ");break;
				case 6:printf("six ");break;
				case 7:printf("seven ");break;
				case 8:printf("eight ");break;
				case 9:printf("nine ");break;
			}
		}
		else
		{
			switch(m[k])
			{
				case 0:printf("zero");break;
				case 1:printf("one");break;
				case 2:printf("two");break;
				case 3:printf("three");break;
				case 4:printf("four");break;
				case 5:printf("five");break;
				case 6:printf("six");break;
				case 7:printf("seven");break;
				case 8:printf("eight");break;
				case 9:printf("nine");break;
			}
		}
	}
	return 0;
}
