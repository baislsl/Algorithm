#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,flag;
	char name[11],password[11];
	char put[1001][2][11];
	int put_ind=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",name);
		scanf("%s",password);
		j=0;
		flag=0;
		while(password[j])
		{
			switch(password[j])
			{
				case '1':password[j]='@';flag=1;break;
				case '0':password[j]='%';flag=1;break;
				case 'l':password[j]='L';flag=1;break;
				case 'O':password[j]='o';flag=1;break;
			}
			j++;
		}
		if(flag)
		{
			strcpy(put[put_ind][0],name);
			strcpy(put[put_ind++][1],password);
		}
	}
	if(put_ind)
	{
		printf("%d\n",put_ind);
		for(i=0;i<put_ind;i++)
		{
			printf("%s %s\n",put[i][0],put[i][1]);
		}
	}
	else if(n==1) printf("There is 1 account and no account is modified");
	else printf("There are %d accounts and no account is modified",n);
}




