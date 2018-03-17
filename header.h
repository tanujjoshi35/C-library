#include<stdio.h>
#include<math.h>

/*
  Toom-Cook-3-way Algorithm
*/


// Calculating length of the numbers entered
int num_length(long long int number){         

        int l=0;

	do{
	     l++;
             number=number/10;
	}while(number) ;

       return l;
}

//ToomCook Algorithm starts
void ToomCook(){
  
	int base=1, index1, index2, index;
	long int Base=base*base, temp; 	
	long long int num1, num2,result; 
	long long int px0, px1, px2, qx0, qx1, qx2;   // for step 1
	long long int p0,p1,pn1,pn2,pinfinity,q0,q1,qn1,qn2,qinfinity; // for step2
        long long int r0,r1,rn1,rn2,rinfinity; // for step3
	long long int r[5]; // for step4
	
        int l_num1=0, l_num2=0;

	printf("\n\n\t\t\t*****Lets test ToomCook Algorithm*****");
	printf("\n\nEnter the two integers A & B to multiply \n\n");
	scanf("%lld %lld",&num1, &num2);

        l_num1=num_length(num1);
        l_num2=num_length(num2);

        index1=(log10(num1)/3)+1;
        index2=(log10(num2)/3)+1;

	index=(index1>index2 ? index1 : index2);

        for(int i=0; i<index;i++){

               base=base*10;

	 }


	printf("\n\nvalue of Base for splitting = %d\n\n",base);

	// Step1- Splitting

	px0=num1%base;
	temp=num1/base;
	px1=temp%base;
        px2=temp/base;
	
	qx0=num2%base;
	temp=num2/base;
	qx1=temp%base;
        qx2=temp/base;
	
	printf("\nPolynomial becomes : \n\n");
	printf("\t p(x)=%lld x^2 + %lld x + %lld",px2,px1,px0);
	printf("\t q(x)=%lld x^2 + %lld x + %lld",qx2,qx1,qx0);

	// Step2- Evaluation   --checks the polynomial for different values (i.e, 0,1,-1,-2, infinity)
	
	p0=px0; p1=px0+px1+px2;
	pn1=px0-px1+px2; pn2=px0-2*px1+4*px2;
	pinfinity=px2;
		
	q0=qx0; q1=qx0+qx1+qx2;
	qn1=qx0-qx1+qx2; qn2=qx0-2*qx1+4*qx2;
	qinfinity=qx2;
	
	
	// Step3- PointWise Multiplication----this is the most expensive step, the only step that is not linear in the sizes of p and q.

	r0=p0*q0; 				   // 1st multiplication
	r1=p1*q1; 				   // 2nd multiplication
	rn1=pn1*qn1;				   // 3rd multiplication
	rn2=pn2*qn2; 				   // 4th multiplication
        rinfinity=pinfinity*qinfinity;  	   //5th multiplication

	
	//Step4- Interpolation
	
	r[0]=r0;
	r[4]=rinfinity;
	r[3]=(rn2 -r1)/3;
	r[1]=(r1-rn1)/2;
	r[2]=rn1-r0;
	r[3]=(r[2]-r[3])/2 +2*rinfinity;
	r[2]=r[2]+r[1]-r[4];
	r[1]=r[1]-r[3];

	
	//Step5- Recomposition
	
	result=r[4]*base*base*base*base+r[3]*base*base*base+r[2]*base*base+r[1]*base+r[0];
	 
        printf("\n\nUsing Toom-Cook-3-way Multiplication....\n\nResult ( A*B ) = %lld \n\n",result);
 
  }

/*
  Newton Division Algorithm starts
*/

// Calculate length of a number
int number_length(long double number){         

        int l=0;

	do{
	    l++;
        number=number/10;
	  }while(number>1) ;
	  
       return l;             //length
}

// calculate value of x0
double assumed_num(int l)
{
	int i;
	long double xn=1.0;
	
	for(i=0;i<l;i++){

		xn=xn*0.1;
	}
	
	return xn;
}

// Newton Division Algorithm starts
double NewtonDivision()
{
	int i, length;
	long double finalval,temp,flag, x0, a ,b;
	long double result[10];

	printf("\n\n\t\t*****Let's test Newton-Raphson Division Algorithm*****");

	printf("\n\nEnter the dividend\n");
	scanf("%Lf",&a);
	printf("Enter the divisor\n");
	scanf("%Lf",&b);

	length=number_length(b);
	x0=assumed_num(length);

	printf("\nInitial assumed value i.e, X0 = %.15Lf\n",x0);

	temp=2-(b*x0);

	result[0] = x0*temp;

	printf("\nValue of reciprocal of %Lf after: ",b);
	printf("\n\tIteration[1] = %.15Lf\n",result[0]);

	for(i=1;i<9;i++)
	{
		flag=2-(b*result[i-1]);

		result[i] = result[i-1]*flag;

			printf("\tIteration[%d] = %.15Lf\n",i+1,result[i]);
	}

	finalval=a*result[8];

	printf("\n Result = %.15Lf\n\n",finalval);
}



/*
  Nth root Algorithm 
*/


//Power Calculation
long double power1(long double p, int q){

	long double temp;
	if( q == 0)
        return 1;
	else{
	    temp = power1(p, q/2);
	    if (q%2 == 0)
	        return temp*temp;
	    else

      	      return p*temp*temp;
 	 }
}

// Newton-Raphson Nth root algorithm starts
void NthRoot(){

	int c,i;
	int n,r;
	long double a;
	long double x[101];

	printf("\n\n\t\t*****Let's test Newton-Raphson nth root Algorithm*****");

	printf("\n\nEnter the Number\n");
	scanf("%Lf",&a);
	printf("Enter numerator  of root \n");
	printf("Enter denominator of root \n");
	scanf("%d",&n);
	scanf("%d",&r);

	for(c=0;c<200;c++){

		if(power1(c,n)>a){

			x[1]=c-1;
			break;

			}
	}


	for(i=2;i<=100;i++){

	x[i]=(((n-1)*x[i-1]) + (a/(power1(x[i-1],n-1))))/n;

	}

	long double result=power1(x[100],r);
	printf("\n\nDesired Root value=%Lf\n\n",result);

}


