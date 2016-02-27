#include<stdio.h>
#include<conio.h>
int main()
{
	//clrscrn();
	int image [8][8]={{12,32,15,48,65,14,81,91}
						,{12,51,84,65,32,15,78,95}
						,{12,32,92,93,18,52,23,84}
						,{12,32,15,65,48,98,12,32}
						,{62,31,81,95,21,32,58,12}
						,{51,78,65,12,91,32,95,12}
						,{75,32,65,98,21,38,98,32}
						,{45,65,21,35,84,6,87,6}},i,j,newimage[8][8],avg=0,arr[200],top=0,savenum,count;
	int negcount=0,final[200],finaltop=0,temp[200],temptop=0;
	printf("Enter 8*8 matrix \n");
	for(i=0;i<8;i++)
	{
		  for(j=0;j<8;j++)
		  {
		  printf("%3d  ",image[i][j]);
		  avg+=image[i][j];
		  } printf("\n");
	}
	avg/=64;
	printf("Average=%d",avg);
	for(i=0;i<8;i++)
	{
		  for(j=0;j<8;j++)
		  {
			newimage[i][j]=image[i][j]-avg;
		  }
	}printf("\n");
	for(i=0;i<8;i++)
	{
		  for(j=0;j<8;j++)
		  {
		  printf("%3d  ",newimage[i][j]);
		  avg+=image[i][j];
		  } printf("\n");
	}
	i=0;j=1;savenum=newimage[0][0];count=0;
	if(newimage[0][1]==savenum)
	{
		count++;
	}
	else
	{
		arr[top]=count+1;top++;
			arr[top]=savenum;top++;count=0;
			savenum=newimage[0][1];
	}i=1;j=0;
	while(i<8)
	{
		while(j>=0&&i<8)
		{
			if(newimage[i][j]==savenum)
			{
				count++;
			}
			else
			{
				arr[top]=count+1;top++;
				arr[top]=savenum;top++;count=0;savenum=newimage[i][j];
			}
		i++;j--;
		}
		if(i>=8)
		{
			j++;j++;i--;
		}
		else
		{
		j++;
		}
		while(i>=0&&j<8)
		{
			if(newimage[i][j]==savenum)
			{
				count++;
			}
			else
			{
				arr[top]=count+1;top++;
				arr[top]=savenum;top++;count=0;savenum=newimage[i][j];
			}
			i--;j++;
		}
		if(j>=8)
		{
			i++;i++;j--;
		}
		else
		{
		i++;
		}


	}
	printf("runlength encoding ");
	for(i=0;i<top;)
	{
		printf("%2d  %3d ",arr[i++],arr[i++]);
	}
	for(i=0;i<top;)
	{
	if(arr[i]==1)
	{
		negcount++;
		temp[temptop]=arr[i+1];temptop++;
	}
	else
	{
		if(negcount==0)
		{
			final[finaltop]=arr[i];finaltop++;
			final[finaltop]=arr[i+1];finaltop++;
		}
		else
		{
			final[finaltop]=negcount-(negcount*2);finaltop++;
			for(j=0;j<temptop;j++)
			{
			final[finaltop]=temp[j];finaltop++;

			}
			final[finaltop]=arr[i];finaltop++;
			final[finaltop]=arr[i+1];finaltop++;
		}
		negcount=0;
	}i+=2;
	}
	printf("negetivelength encoding ");
	for(i=0;i<finaltop;i++)
	{
		printf("%3d  ",final[i]);
	}
	getch();
}