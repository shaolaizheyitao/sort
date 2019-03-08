#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char * argv[])
{
	int i,j;
	int len = argc - 1;
	char * temp = malloc(50*sizeof(char));
	memset(temp,0,50);
	if (  0 == len )
	{
		fprintf(stderr,"请输入至少2个参数\n");
		exit(-1);
	}
	else if ( len < 2)
	{
		printf("%s\n",argv[1]);
		return 0;
	}
	else 
	{
		for (i = 0 ;i <len - 1; i++)
		{
			for(j = 0 ; j<len - 1 - i ; j++)
			{
				if((strcmp(argv[j+1] , argv[j+2])) > 0)
				{
					strcpy(temp,argv[j+1]);
					strcpy(argv[j+1],argv[j+2]);
				    strcpy(argv[j+2],temp);
				    memset(temp,0,50);
				}
			}
		}
		free(temp);
		for(i = 0;i < len ;i++)
		{
			printf("%s\t",argv[i+1]);		
		}
		printf("\n");
	}
	
	
	return 0;
}