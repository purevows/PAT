/*
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 … NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, …, K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < … < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node
{
	int exp;
	float coef;
}a[10],b[10],c[100];

int main()
{
	int k1, k2, i, j, m, exptemp, n = 0;
	float coeftemp;
	for(i = 0;i < 10; i++)
	{
		a[i].exp = 0;
		a[i].coef = 0;
		b[i].exp = 0;
		b[i].coef = 0;
	}
	for(i = 0; i < 100; i++)
	{
		c[i].exp = -1;
		c[i].coef = 0;
	}
	scanf("%d", &k1);
	for(i = 0; i < k1; i++)
		scanf("%d %f", &a[i].exp, &a[i].coef);
	scanf("%d", &k2);
	for(i = 0; i < k2; i++)
		scanf("%d %f", &b[i].exp, &b[i].coef);
	for(i = 0; i < k1; i++)
	{
		for(j = 0; j < k2; j++)
		{
			exptemp = a[i].exp + b[j].exp;
			coeftemp = a[i].coef * b[j].coef;
			for(m = 0; m < 100; m++)
			{
				if((c[m].exp == exptemp) || (c[m].exp == -1))
				{
					if(c[m].exp == -1)
						n++;
					c[m].exp = exptemp;
					c[m].coef = c[m].coef + coeftemp;
					break;
				}
			}
		}
	}
	int num = n; 
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(c[j].exp < c[j + 1].exp)
			{
				exptemp = c[j].exp;
				coeftemp = c[j].coef;
				c[j].exp = c[j + 1].exp;
				c[j].coef = c[j + 1].coef;
				c[j + 1].exp = exptemp;
				c[j + 1].coef = coeftemp;
			}
		}
	}
	for(i = 0; i < n; i++)
		if(c[i].coef == 0)
			num--; 
	printf("%d", num);
	for(i = 0; i < n; i++)
	{
		if(c[i].coef != 0)
			printf(" %d %.1f", c[i].exp, c[i].coef);
	}
	return 0;
}
