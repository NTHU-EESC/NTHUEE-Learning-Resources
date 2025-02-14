/*EE231002 Lab08. Blackjack
  104061212,Li-Yu,Feng
  Date:2015/11/16
*/

#include<stdio.h>
#include<stdlib.h>

#define N 10000

int main(void)
{
	int point,i,j,k,Nbust;
	int sum;
	/***Task 1***/
	printf("Points	E(hit)	% Busted\n");
	for(point=2;point<21;point++){				//2~20 point already at hand
		sum=0;									//
		Nbust=0;								//(re)initializing
		for(j=0;j<N;j++){
			k=rand()%13+1;						//randomly choose k
			if( k==11 || k==12 || k==13 )k=10;	// J.Q.K equals 10
			if(k==1 && point+11 <= 21)k=11;		//Convert A to 11 if not busted
			i=point+k;
			if(i>21)Nbust++;					//busting counter
			sum += i;							//sum up for expected vulue
		}										//calculation
		printf("  %2d	%6.2f	%7.4g\n",point,(double)sum/N,100.0*Nbust/N);
		/***print ,conforming to assigned format***/
	}
	/***Task 2***/
	sum=0;
	for(j=0;j<N;j++){
		point=0;
		for( ; point < 21 ; ){					//keep hitting until point >= 21
			k=rand() % 13 + 1 ;					//
			if( k==11 || k==12 || k==13 )k=10;	//
			if(k==1 && point+11 <= 21)k=11;		//
			point += k;							//hit & calculate points
		}
		if(point==21)sum++;						//21 or busted?
	}
	printf("Probability of getting 21 points is %.4g%\n",100.0*sum/N);
	return 0;
}
