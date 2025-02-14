#include<stdio.h>
#include<stdlib.h>

char A[4] = {'j','k','l','m'};

char Hex2Char(int x){
	switch(x){
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
		default:
			return 0;
	}
}

char *Bytes2Hex(char *A){
	int i, j;
	int sum, temp;
	char *Out;
	
	Out = malloc( 8 * sizeof(char) );
	for (j = 0; j< 4; j++){
    	for( i = 0, sum = 0, temp = 1; i < 8; i++){
            if( A[j]&(1u<<i) ) sum += temp;
            temp *= 2;
    	}
		Out[ 2*j] = Hex2Char(sum / 16);
		Out[ 2*j+1] = Hex2Char(sum % 16);

	}

	//for (i = 0; i < 8; i++)
	//	printf(" %c",Out[i] );

	//printf("\n");
	return Out;
}

int main()
{
	char *C;
	C = Bytes2Hex(A);
	int i;

	for (i = 0; i < 8; i++)
		printf(" %c",C[i] );
	return 0;
}

