/*
1006 Sign In and Sign Out (25 point(s))
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:
Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.

Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int compare(char a[8], char b[8])
{
	int ha, ma, sa, hb, mb, sb, ta, tb, diff = 0;
	ha = 10 * (a[0] - '0') + (a[1] - '0');
	hb = 10 * (b[0] - '0') + (b[1] - '0');
	ma = 10 * (a[3] - '0') + (a[4] - '0');
	mb = 10 * (b[3] - '0') + (b[4] - '0');
	sa = 10 * (a[6] - '0') + (a[7] - '0');
	sb = 10 * (b[6] - '0') + (a[7] - '0');
	ta = ha * 3600 + ma * 60 + sa;
	tb = hb * 3600 + mb * 60 + sb;
	if(ta > tb)
		diff = 1;
	else if(ta < tb)
		diff = -1;
	else
		diff = 0;
	return diff;
}

int main()
{
	int i, j, m;
	scanf("%d", &m);
	struct node
	{
		char number[16];
		char unlockt[8];
		char lockt[8];
	}ID[m];
	for(i = 0;i < m; i++)
	{
		for(j = 0; j < 15; j++)
		{
			ID[i].number[j] = 0;
		}
		for(j = 0; j < 8; j++)
		{
			ID[i].unlockt[j] = 0;
			ID[i].lockt[j] = 0;
		}
	}
	for(i = 0; i < m; i++)
	{
		scanf("%s %s %s", ID[i].number, ID[i].unlockt, ID[i].lockt);
	}
	int unlock = 0, lock = 0;
	for(i = 0;i < m; i++)
	{
		if(compare(ID[unlock].unlockt, ID[i].unlockt) == 1)
			unlock = i;
		if(compare(ID[lock].lockt, ID[i].lockt) == -1)
			lock = i;
	}
	printf("%s %s", ID[unlock].number, ID[lock].number);
	return 0;
}
