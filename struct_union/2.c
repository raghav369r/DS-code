#include<stdio.h>
struct player{
	int jno;
	char name[20];
	int hscore;
	float bat_avg;
	int s1;
	int s2;
	int s3;
};
int main(){
	struct player p1,p2;
	/*printf("%d %s %d %f %d %d %d",p1.jno,p1.name,p1.hscore,p1.bat_avg,p1.s1,p1.s2,p1.s3);*/
	printf("Enter details of 1st player: ");
	scanf("%d%s%d%f%d%d%d",&p1.jno,p1.name,
	&p1.hscore,&p1.bat_avg,&p1.s1,&p1.s2,&p1.s3);
	printf("%d %s %d %f %d %d %d",p1.jno,p1.name,p1.hscore,p1.bat_avg,p1.s1,p1.s2,p1.s3);
}
