/******************************************************
  EE3980 Algorithms HW12 Longest Path Problem
  Li-Yu Feng 104061212
  Date:2018/6/2
*******************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 999

int maxCost;
int *maxRoute;
int **CostMat;
int N;
int *rowlist;

int rowMax(int row, int *Perm, int traveled);	//for finding bound
void printResult(char **city);
void InsertionSort(int *list,int n);	//sort to decreasing order
int Pandita(void);						//generate permutation and check

int rowMax(int row, int *Perm, int traveled){
	int max = 0;
	int i;

	memcpy( rowlist, CostMat[row], N * sizeof(int) );
	
	for (i = 0; i < traveled; i++)
		rowlist[ Perm[i] ] = 0 ;

	for (i = 0; i < N; i++){
		if ( rowlist[i] > max ) max = rowlist[i];
	}

	return max;
}


void printResult(char **city){			//print min path and cost
	int i;

	printf("Minimum distance route:\n");
	for (i = 0; i < N-1 ;i++){
		printf("  %s -> %s\n",city[ maxRoute[i] ], city[ maxRoute[i+1] ]);
	}
	printf("  %s -> %s\n",city[ maxRoute[N-1] ], city[ maxRoute[0] ]);
	printf("Total distance : %d \n", maxCost );
}

void InsertionSort(int *list,int n){
    int i,j;
    int temp;

    for(j = 1; j < n; j++){
        temp = list[j];
        
        i = j-1;
        while((i>=0) && (temp > list[i] ) ){
            list[i+1] = list[i];
            i--;
        }
        list[i+1] = temp;

    }

}

int Pandita(void){
	int *A;//A[N]={};
	int i,j=0,k=0,value;
	int m,n;
	int M = N-1;
	int cost;
	int bound;

	A = malloc( M * sizeof(int) );
	
	for(i=1;i<= M;i++)						//
		A[i-1]=i;							//initialize A to be 1,2,3...N
	for(;;){

		/////////////////////////////////////  calculate cost and bound
		cost = CostMat[0][ A[0] ];		  //   
		for (m = 0; m < M-1; m++)
			cost += CostMat[ A[m] ][ A[m+1] ];
		cost += CostMat[ A[M-1] ][0];
		
		if(cost > maxCost){
			maxCost = cost;
			memcpy(maxRoute + 1, A, M *sizeof(int));
		}

		cost = CostMat[0][ A[0] ];
		for(m = 0; m < M-1; m++ ){
			cost += CostMat[ A[m] ][ A[m+1] ];
			for (n = m+1, bound = cost; n < M; n++)
				bound += rowMax( A[n], A, m+1 );
			bound += CostMat[ A[M-1] ][0];
			if(bound < maxCost) { InsertionSort(A+m+2, N-m-3); //skip 
									m = M-1; 
			}
		}

		

		////////////////////////////////////
		for(i=M-2;i>=0 && A[i]>=A[i+1];i--){}
			j=i;							//find largest j, A[j]<A[j+1]
		if(i==-1){							//if j is not found
			return 0;						//that's the last permutation
		}
		for(i=M-1;i>=0 && A[i]<=A[j];i--){}	//
			k=i;							//find largest k A[k]>A[j]
		value=A[j];							//
		A[j]=A[k];							//
		A[k]=value;							//swap A[j] and A[k]
		for(i=1; j+1 < M-i ; j++,i++){		//
			value=A[j+1];					//
			A[j+1]=A[M-i];					//reverse the value
			A[M-i]=value;					//from A[j+1] to  A[N-1]
		}
	}	
}


int main(){

	int i,j; 

	char **city;
	int *visitlst;
	int *sollst;


	scanf(" %d", &N);

	maxCost = 0;
	maxRoute = malloc(N * sizeof(int));
	maxRoute[0] = 0;
	rowlist = malloc( N * sizeof(int) );

	city = malloc(N * sizeof(char *));
	CostMat = malloc(N * sizeof(int *));

	for(i = 0; i< N; i++){
		city[i] = malloc(sizeof(char*));
		CostMat[i] = malloc(N * sizeof(int) );
	}

	visitlst = calloc(N, sizeof(int));
	sollst = calloc(N, sizeof(int));


	for(i = 0; i <N; i++){
		scanf(" %[^\n]", city[i]);

		getchar();


	}
	for(i = 0; i< N; i++)
		for(j = 0; j < N; j++)
		    scanf("%d", &CostMat[i][j]);
	
	for( i = 0; i < N; i++)	CostMat[i][i] = 0;


	Pandita();

	printResult(city);
	
	return 0;
}

