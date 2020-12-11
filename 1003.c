/*
1003 Emergency (25 point(s))
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.
Input Specification:
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (¡Ü500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.
Output Specification:
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
Sample Input:
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output:
2 4
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
	int i; int j; int cities; int roads; int start; int destination;
	//input start
	scanf("%d %d %d %d", &cities, &roads, &start, &destination);
	//C99
	int rescue[cities]; int map[cities][cities]; int dist[cities]; int s[cities]; int rescuenum[cities]; int num[cities]; 
	//C90
	//int rescue[500]; int map[500][500]; int dist[500]; int s[500]; int rescuenum[500];
	//initdata 
	for (i = 0; i < cities; i++)
	{
		dist[i] = INT_MAX;
		s[i] = 0;
		num[i] = 0;
		for (j = 0; j < cities; j++)
		{
			map[i][j] = INT_MAX;
		}
	}
	for (i = 0; i < cities; i++)
	{
		scanf("%d", &rescue[i]);
	}
	int m = 0; int n = 0; int o = 0;
	for (i = 0; i < roads; i++)
	{
		scanf("%d %d %d", &m, &n, &o);
		map[m][n] = o;
		map[n][m] = o;
	}
	//input end
	int current; int min; int temp;
	dist[start] = 0; rescuenum[start] = rescue[start]; num[start] = 1;
	for (i = 0; i < cities; i++)
	{
		current = -1; min = INT_MAX;
		for (j = 0; j < cities; j++)
		{
			if (s[j] == 0 && dist[j] < min)
			{
				current = j;
				min = dist[j];
			}
		}
		if (current == -1)
			break;
		s[current] = 1;
		for (temp = 0; temp < cities; temp++)
		{
			if (s[temp] == 0 && map[current][temp] != INT_MAX)
			{
				if (dist[current] + map[current][temp] < dist[temp])
				{
					dist[temp] = dist[current] + map[current][temp];
					rescuenum[temp] = rescuenum[current] + rescue[temp];
					num[temp] = num[current];
				}
				else if (dist[current] + map[current][temp] == dist[temp])
				{
					num[temp] = num[current] + num[temp];
					if (rescuenum[temp] < rescuenum[current] + rescue[temp])
					{
						rescuenum[temp] = rescuenum[current] + rescue[temp];
					}
				}
			}
		}
	}
	printf("%d %d", num[destination], rescuenum[destination]);
	return 0;
}
