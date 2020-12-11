/***
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
Input
Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.
Output
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
Sample Input
-1000000 9
Sample Output
-999,991
***/ 

#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,sum;int i;int j;int temp;int num=0;int flag=0;int nagetive=0;
    scanf("%d %d",&a,&b);
	while(a<-1000000 || a>1000000 || b<-1000000 || b>1000000)
	{
		printf("Overflow,input again");
		scanf("%d %d",&a,&b);
	}
	sum=a+b;
	if(sum<0)
	{
		nagetive=1;
		sum=abs(sum);
	}
	char result[10]={'0'};
	temp=sum;
	if(temp==0)
	{
		num=1;
	}
	else
	{
		while(temp)
		{
			temp=temp/10;
			num++;
		}
	}
	sprintf(result,"%d",sum);
	for(i=num;i>=0;i--)
	{
		if(flag%3==0&&i!=num&&i!=0)
		{
			for(j=num;j>i;j--)
			{
				result[j]=result[j-1];
			}
			result[j]=',';
			num++;
		}
		flag++;
	}
	if(nagetive==1)
	{
		for(i=num;i>0;i--)
		{
			result[i]=result[i-1];
		}
		result[i]='-';
		num++;
	}
	for(i=0;i<num;i++)
	{
		printf("%c",result[i]);
	}
    return 0;
}
