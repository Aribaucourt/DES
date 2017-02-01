#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "DES_data.h"
#include "DES_Troussis.c"


int main()
{

	uint64_t A;
	uint64_t B;
	uint32_t C;
	A = expansion(2);
	B = xor(1, 2);
	C = permutation_p(1);

	printf("debut du prog test.c\n");
	printf("expansion(2) = %ld \n", A);
	printf("exp de 6 \n \n \n");
	printf("expansion(6) = %ld \n", expansion(6));
	//printf("xor(A,K) = %ld \n", B);
	//printf("permutation_p(1) = %d \n", C);
	//printf("permutation_p(26) = %d \n", permutation_p(26));
	return(0);
}
