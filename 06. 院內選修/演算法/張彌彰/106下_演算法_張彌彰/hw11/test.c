#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int foo(arg){

	printf("%d\n", arg++);
	printf("%d\n", arg++);
	printf("%d\n", arg++);

	return arg +3;
}



int main(){
	int a = 5;
	int i,j;
	int *b;
	int c[3][3],d[3][3];
	int N = 3;

	b = calloc(5, sizeof(int));
	for (i = 0 ; i < 5; i++)
		printf("%d ",b[i]);
	
	printf("-----------\n");
	
	printf("%d\n", foo(a) );
	

	for( i = 0; i < 3; i++)
		for( j = 0; j < 3 ; j++)
			c[i][j] = i;
	for(i = 0; i< N; i++){
		for(j = 0; j < N; j++){
			printf("%5d ", c[i][j]);
		}
		printf("\n");
	}

	memcpy( d,c,9 * sizeof(int) );


	for(i = 0; i< N; i++){
		for(j = 0; j < N; j++){
			printf("%5d ", d[i][j]);
		}
		printf("\n");
	}

	c[1][1] = 87;
	for(i = 0; i< N; i++){
		for(j = 0; j < N; j++){
			printf("%5d ", d[i][j]);
		}
		printf("\n");
	}
		
	return 0;


}
