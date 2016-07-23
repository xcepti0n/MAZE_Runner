#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 50
#define MAXI 30
char mat[MAXI][MAX];
int m,n,level;
char choice,tchoice;
void create()
{
	int i,j;
	for(i=0;i<MAXI;i++)
	{
		for(j=0;j<MAX;j++)
		{
			if(((i==0)&& j!=0) || i==MAXI-1)
				mat[i][j]='|';
			else if((j==0 && i!=0)|| j==MAX-1)
				mat[i][j]='-';
			else if(i==1 && j==1)
				mat[i][j]='$';
			else if(level==0 || (rand()%(27-2*level)!=0) || (i==0)&& (j==0))
				mat[i][j]='_';
			else	
				mat[i][j]='#';
		}
	}
}
void print()
{
	system("cls");
	printf("WELCOME TO MAZE RUNNER!!!\n\n");
	printf("RULES OF THE GAME ARE AS FOLLOWS\n i. You have to Reach top left corner of THE MAZE\nii. You cannot move behind.\niii. You cannot move over obstacles(i.e. #)\n ");
	printf("\n ******YOU ARE AT LEVEL %d *******\n",level+1);
	int i,j;
	for(i=0;i<MAXI;i++)
	{
		for(j=0;j<MAX;j++)
		{
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}
}
void move()
{
	char option;
	
	if(tchoice==80 || tchoice==75 || tchoice==77 || tchoice==72)
		choice=tchoice;
		switch(choice)
		{
			case (80):{
				if(m!=MAXI-1)
				{
					if(mat[m+1][n]== '#' || mat[m+1][n]=='-' || mat[m+1][n]=='|')
					{
						m=MAXI;
						break;
					}
					else if(mat[m+1][n]==' ')
					{
						m=MAXI;
						printf("YOU CAN'T MOVE BEHIND");
						break;
					}
					mat[m][n]=' ';
					mat[++m][n]=31;
				}
				else
				m++;
				print();
				break;
			}
			case (75):{
				if(n!=0)
				{
					if(mat[m][n-1]== '#' || mat[m][n-1]=='-' || mat[m][n-1]== '|')
					{
						m=MAXI;
						break;
					}
					else if(mat[m][n-1]==' ')
					{
						m=MAXI;
						printf("YOU CAN'T MOVE BEHIND");
						break;
					}
					mat[m][n]=' ';
					mat[m][--n]=17;
				}
				else n--;
				print();
				break;
			}
			case ( 77 ):{
				if(n!=MAX-1)
				{
					if(mat[m][n+1]== '#'||  mat[m][n+1]=='-' || mat[m][n+1]=='|')
					{
						m=MAXI;
						break;
					}
					else if(mat[m][n+1]==' ')
					{
						m=MAXI;
						printf("YOU CAN'T MOVE BEHIND");
						break;
					}
					mat[m][n]=' ';
					mat[m][++n]=16;
				}
				else n++;
				print();
				break;
			}
			case (72):{
				if(m!=0)
				{
					if(mat[m-1][n]== '#' || mat[m-1][n]=='-' || mat[m-1][n]=='|')
					{
						m=MAXI;
						break;
					}
					else if(mat[m-1][n]==' ')
					{
						m=MAXI;
						printf("YOU CAN'T MOVE BEHIND");
						break;
					}
					mat[m][n]=' ';
					mat[--m][n]= 30;
				}
				else m--;
				print();
				break;
			}
			default:{
				print();
				printf("\nIncorrect key pressed\n");
				break;
			}
			
		}
	return;
}
int main()
{
	level=0;
	do
	{
		create();
		m=MAXI-2,n=MAX-2;
		mat[m][n]='*';
		system("cls");
		print();
		char option;
		while(m<MAXI-1 && m>0 && n<MAX-1 && n>0)
		{
			if(n==1 && m==1)
			break;
			if(m==MAXI-2 && n==MAX-2)
			{
				tchoice=getch();
			}
			else if(kbhit())
			{
				tchoice=getch();
			}
			if(!kbhit())
			{
				move();
				 _sleep(350);
			}
	}
		print();
		if(n==1 && m==1)
		{
			printf("-----------YOU WON THE GAME---------------\n\n\n\n\n");
			level++;
			option='n';
		}
		else
		{
				printf("!!!!!!!GAME OVER!!!!!\n\n\n\n");
			printf("Do you want to continue press Y/N\n");
			option=getch();
			if(option=='y' || option=='Y')
				level=0;
			else if(option=='s')
			{
				printf("Congratulations now you have just entered a cheat code\n Now you can jump to any level upto 10\n");
				printf("Enter level :   ");
				scanf("%d",&level);
				level--;
				if(level>9) level=9;
			}
			else
				break;
		}
		
	}while(level<=10);	
	if(level>10)
		printf("CONGRATULATIONS YOU HAVE COMPLETED ALL THE LEVELS!!!");
	getch();	
return 0;
}
