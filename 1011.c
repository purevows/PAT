/**
1011 World Cup Betting (20 point(s))
With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:

 W    T    L
1.1  2.5  1.7
1.2  3.1  1.6
4.1  1.2  1.1
To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1×3.1×2.5×65%-1)×2=39.31 yuans (accurate up to 2 decimal places).

Input Specification:
Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.

Output Specification:
For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

Sample Input:
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1
Sample Output:
T T W 39.31
**/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char writelog(int num)
{
	if(num == 0)
		return 'W';
	else if(num == 1)
		return 'T';
	else if(num == 2)
		return 'L';
}

int main()
{
	double games[3][3], temp = 0, max = 0;
	char record[3];
	int i, j, k;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			scanf("%lf", &games[i][j]);
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 3; k++)
			{
				temp = (games[0][i] * games[1][j] * games[2][k] * 0.65 - 1) * 2;
				if(temp > max)
				{
					max = temp;
					record[0] = writelog(i);
					record[1] = writelog(j);
					record[2] = writelog(k);
				}
			}
		}
	}
	for(i = 0; i < 3; i++)
		printf("%c ", record[i]);
	printf("%.2f", max);
	return 0;
}
