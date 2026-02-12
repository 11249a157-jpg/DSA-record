#include<stdio.h>
void towerofhanoi(int n,char s,char d,char t)
{
	if(n==1)
	{
		printf(" move the disk %d from %c to %c ",n,s,d);
		return ;
	}
	towerofhanoi(n-1,s,t,d);
	printf("\n move disk %d from %c to %c",n,s,d);
	towerofhanoi(n,s, d, t);
	printf("\n move disk %d from %c to %c",n,d,s);
	towerofhanoi(n-1,t,d,s);

}
int main()
{
	int n;
	char s,d,t;
	printf("enter no.of disks: ");
	scanf("%d",&n);
	towerofhanoi(n,'s','d','t');
	
	
}
