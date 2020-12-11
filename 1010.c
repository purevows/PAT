/**
1010 Radix (25 point(s))
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is yes, if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:

N1 N2 tag radix

Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set { 0-9, a-z } where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.

Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
**/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

long long int transformDec(char N[], int radix)
{
	long long int sum = 0;
	int temp, len = strlen(N), i, exp = 0;
	for(i = len - 1; i >= 0; i--)
	{
		if((97 <= N[i]) && (N[i] <= 122))
		{
			temp = N[i] - 'a' + 10;
			sum = sum + temp * pow(radix, exp++);
		}
		else if((48 <= N[i]) && (N[i] <= 57))
		{
			temp = N[i] - '0';
			sum = sum + temp * pow(radix, exp++);
		}
	}
	return sum;
}

int findmax(char N[])
{
	int tempint, max = 0, i;
	for(i = 0; i < 11; i++)
	{
		if((97 <= N[i]) && (N[i] <= 122))
		{
			tempint = N[i] - 'a' + 10;
		}
		else if((48 <= N[i]) && (N[i] <= 57))
		{
			tempint = N[i] - '0';
		}
		if(tempint > max)
			max = tempint;
	}
	return max + 1;
}

long long int compare(long long int target, char N[])
{
	long long int low = findmax(N), mid, high, result;
	(low >= target) ? (high = low) : (high = target);
	while(low <= high)
	{
		mid = (low + high) / 2;
		result = transformDec(N, mid);
		if(result == target)
			return mid;
		else if(result > target || result < 0)
			high = mid - 1;
		else if(result < target)
			low = mid + 1;
	}
	return -1;
}

int main()
{
	char N1[11], N2[11];
	long long int tag, radix, i, result;
	for(i = 0; i < 11; i++)
	{
		N1[i] = 0;
		N2[i] = 0;
	}
	scanf("%s %s %d %d", &N1, &N2, &tag, &radix);
	result = tag == 1 ? compare(transformDec(N1, radix), N2) : compare(transformDec(N2, radix), N1);
	if(result == -1)
		printf("Impossible");
	else
		printf("%lld", result);
	return 0;
}
