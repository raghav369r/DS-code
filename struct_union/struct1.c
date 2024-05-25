#include<stdio.h>
struct states{
	char name[20];
	int jno,hscore;
	double avg,str;
	struct states *next;
};
typedef struct states state; 
int main(){
	state virat={"King Kohli",18,183,62.87,109.87};
	state dhoni={"Dhoni",7,183,55.87,110.87};
	state abd={"ABD",17,178,59.87,119.87};
	state faf={"faf",18,128,46.87,97.87};
	virat.next=&dhoni;
	dhoni.next=&abd;
	abd.next=&faf;
	faf.next=NULL;

	
}
