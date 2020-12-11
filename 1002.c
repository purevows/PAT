/*
1002 A+B for Polynomials(25 point(s))
This time, you are supposed to find A+B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:
K N1 aN1 N2 aN2 ... Nk aNk
where K is the number of nonzero terms in the polynomial,Ni adn aNi(i=1,2,...,K) are the exponents and coefficients, respectively. It is given that 1<=K<=10,0<=NK<...<N2<N1<=1000.
Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 2 1.5 1 2.9 0 3.2
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int exponents;
	double coefficients;
}a[10], b[10];
double result[1000];
int main()
{
	int k; int k1; int k2; int i; int j;
	scanf("%d", &k1);
	for (i = 0; i < k1; i++)
	{
		scanf("%d %lf", &a[i].exponents, &a[i].coefficients);
		result[a[i].exponents] = a[i].coefficients;
	}
	scanf("%d", &k2);
	k = k1 + k2;
	for (i = 0; i < k2; i++)
	{
		scanf("%d %lf", &b[i].exponents, &b[i].coefficients);
		result[b[i].exponents] += b[i].coefficients;
	}
	for(i = 0; i < k1; i++)
	{
		for(j = 0; j < k2; j++)
		{
			if(a[i].exponents == b[j].exponents)
			{
				k--;
				if((a[i].coefficients + b[j].coefficients) == 0)
				{
					k--;
				}
			}
		}
	}
	printf("%d", k);
	for(i = 1000; i >= 0; i--)
	{
		if(abs(result[i]) > 1e-15)
			printf(" %d %.1lf", i, result[i]);
	}
	return 0;
}
