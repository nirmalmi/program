#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void rule(int a[][4]);
void display(int a[][4]);
void game(int b[][4],int a[][4],int c[][4],char name[]);
int main()
{
    int i,j,a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,' '},b[4][4]={7,11,15,10,8,6,4,12,5,9,13,1,2,3,14,' '},c[4][4]={7,11,15,10,8,6,4,12,5,9,13,1,2,3,14,' '};
    char name[10],ch;
    printf("\n enter your name");
    scanf("%s",name);
    do{
        system("cls");
        rule(a);
        game(b,a,c,name);
        printf("\n want to more  to play game:y/n");
        scanf(" %c",&ch);
    }while(ch=='y');
    return 0;
}
void rule(int a[][4])
{
    int i,j;
printf("       RULE OF THIS GAME\n\n");
printf("\n1.you can move 1 step at a time by arrow key.\n");
printf("move up   : by 5 key\n");
printf("move down : by 7 key\n");
printf("move left : by 8 key\n");
printf("move right: by 9 key\n");
printf("2.you can move number at empty position only\n");
printf("3.For each valid move : your total no of move will decreased by 1\n");
printf("4.Winning situation: number in a 4x4 matrix should be in order from 1 to 15\n");

printf("      WINNING SITUATION:");
printf("\n-------------\n");
for(i=0;i<4;i++)
{
printf("|");
for(j=0;j<4;j++)
{
if(j!=0)
printf("|");
if(a[i][j]!=32)
printf("%2d",a[i][j]);
}
if(i!=3)
printf("|");
if(i==3)
printf("  |");
printf("\n");
}
printf("-------------\n");
printf("5.you can exit the game at any time pressing 20 key");
printf("\n so try to win in minimum no of moves");
printf("\n\n       HAPPY GAMING ,GOOD LUCK\n");
printf("\n enter any key to start game......");
getch();
}
void game(int b[][4],int a[][4],int c[][4],char name[])
{
	int move=7,flag=0,k=1,i,j,arrow;
	while(k<=move)
	{
	system("cls");
	printf("\n HELLO %s",name);
	printf("\tmove remaining: %d",move);
	display(b);
	printf("\n enter key");
	scanf("%d",&arrow);
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	{
		if(b[i][j]==' ')
		{
			if(arrow==8)
			{
				b[i][j]=b[i][j+1];
				b[i][j+1]=' ';
				move--;
				break;
			}
	       	else if(arrow==9)
			{
				b[i][j]=b[i][j-1];
				b[i][j-1]=' ';
				move--;
				break;
			}	
			else if(arrow==7)
			{
				b[i][j]=b[i-1][j];
				b[i-1][j]=' ';
				move--;
				break;
			}
			else if(arrow==5)
			{
				b[i][j]=b[i+1][j];
				b[i+1][j]=' ';
				move--;
				break;
			}
			else if(arrow==20)
			exit(0);
			else
			printf("\n invalid option");
	   }
	}	
	}
}
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
	if(a[i][j]!=b[i][j])
	{
		flag=1;
		break;
	}
}
}
if(flag==0)
printf("\n you won!");
else
printf("\n you lose!");
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
b[i][j]=c[i][j];
}
}
void display(int a[][4])
{
	int i,j;
printf("\n-----------------\n");
for(i=0;i<4;i++)
{
printf("|");
for(j=0;j<4;j++)
{
if(j!=0)
printf("|");
if(a[i][j]!=' ')
printf("%2d ",a[i][j]);
if(a[i][j]==' ')
printf("%3c",a[i][j]);
}
if(i!=3)
printf("|");
if(i==3)
printf("|");
printf("\n");
}
printf("-----------------\n");	

}
