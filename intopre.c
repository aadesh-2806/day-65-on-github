#include<stdio.h>
#include<string.h>
#define N 80
void initstack(int *t)
{
	*t=-1;
}
void push(char *a,char x,int *t)
{
	*t=*t+1;
	a[*t]=x;
}
void pop(char *a,char *x,int *t)
{
	*x=a[*t];
	*t=*t-1;
}
char peek(char *a,int t)
{
	return a[t];
}

int emptystack(int t)
{
	if (t==-1)
	return 1;
	else 
    return 0;
}
int fullstack(int t)
{
	if (t==N-1)
	return 1;
	else
	return 0;
}
int prio(char x)
{
	if (x=='=') return 0;
	if (x=='+' || x=='-') return 1;
	if (x=='*' || x=='/') return 2;
	if (x=='^') return 3;
}
int main()
{
	char s[N],a[N],b[N];
	int topa,topb,i,j,k;
	char c;
	initstack(&topa);
	initstack(&topb);
	printf("give the input expression: ");
	scanf("%s",s);
	i=strlen(s);
	while(i>=0)
	{
		if (s[i]>='a' && s[i]<='z')
		push(b,s[i],&topb);
		else if (s[i]==')')
		push(a,s[i],&topa);
		else if (s[i]=='(')
		{
			pop(a,&c,&topa);
			while(c!=')')
			{
				push(b,c,&topb);
				pop(a,&c,&topa);
			}
		}
		else
		{
			while(!emptystack(topa) && peek(a,topa)!=')' && prio(peek(a,topa))>prio(s[i]))
			{	pop(a,&c,&topa);
				push(b,c,&topb);
			}
			push(a,s[i],&topa);	
		}
		i--;
	}
	while (!emptystack(topa))
	{
		pop(a,&c,&topa);
		push(b,c,&topb);
	}
	while(!emptystack(topb))
	{
		pop(b,&c,&topb);
		printf("%c",c);
	}
	printf("\n");
}
