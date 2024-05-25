#include<stdio.h>
struct player{
	int jno;
	char name[20];
	int hscore;
	float bat_avg;
	struct dob{
		int day;
		int month;
		int year;
	}dob;
	int s1;
	int s2;
	int s3;
};

int main(){
	struct player p1[2]={7,"Virat Kohli",258,56.50,8,12,2003,34,78,54};
	//p1[0].dob.day=10;
	printf("%d %s %d %.2f %d %d %d %d %d %d",p1[0].jno,p1[0].name,p1[0].hscore,p1[0].bat_avg,
	p1[0].dob.day,p1[0].dob.month,p1[0].dob.year,p1[0].s1,p1[0].s2,p1[0].s3);
}

