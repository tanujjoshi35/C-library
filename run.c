#include <stdio.h>
#include "header.h"

int main(){

	int choice,temp; 

	printf("\n\n Which Algorithm you want to test?\n\n\tPress:\n");
	printf("\t1--ToomCook-3-way Algorithm\n");
	printf("\t2--Newton Division Algorithm\n");
	printf("\t3--Newton's nth root Algorithm\n");

	scanf("%d", &choice);

	switch(choice){
 
		case 1:

		{ ToomCook();  break;  }

		case 2: 

		 { NewtonDivision(); break;  }

		case 3: 

		 { NthRoot(); break; }

  	   }
	
	printf("\t*****Want to test again or exit:*****\n\t\tTo test again press 1 and to exit press 0     ");
	scanf("%d",&temp);

	if(temp==1){
	
	   main();
	}

	return 0;

 }

