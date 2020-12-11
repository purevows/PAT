/*
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ¡­ ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID¡¯s of its children. For the sake of simplicity, let us fix the root ID to be 01.

Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output ¡°0 1¡± in a line.

Sample Input

2 1
01 1 02

Sample Output

0 1
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node
{
	int child[100];
	int childnumber;
}node[100];

int m, n;
int maxdepth = -1; 
int leafnumber[100] = {0};

void dfs(int current, int depth)
{
	int a;
	if(node[current].childnumber == 0)
	{
		leafnumber[depth]++;
		if(depth > maxdepth)
			maxdepth = depth;
		return;
	}
	for(a = 0; a < node[current].childnumber; a++)
	{
		dfs(node[current].child[a], depth + 1);
	}
}
int main()
{
	int i, j, ID, k, l;
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
		{
			node[i].child[j] = 0;
		}
		node[i].childnumber = 0;
	}
	scanf("%d %d", &n, &m);
	for(i = 0;i < m; i++)
	{
		scanf("%d %d", &ID, &k);
		for(j = 0; j < k; j++)
		{
			scanf("%d", &l);
			node[ID].child[j] = l;
			node[ID].childnumber++;
		}
	}
	dfs(1,0);
	printf("%d", leafnumber[0]);
	for(i = 1; i <= maxdepth; i++)
	{
		printf(" %d", leafnumber[i]);
	}
	return 0;
}
