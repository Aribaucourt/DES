
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include "DES_data.h"

/*
 * Function of expansion
 * takes in input a word A (according to our notation) of 32 bits
 * turns A into a word of 48 bits according to ei[] in DES_data.h
 */

uint64_t expansion(uint32_t plaintext_blockA) {  
    uint64_t expandedA = 0; //the output of the function, on 48 bits but uint48_t does not exist
    uint32_t troncatedA = 0; 
    int tmp = 0; //index of the bit of A to find
    
    for(int i = 0; i < 48; i++) { //i goes through the table ei[] of 48 bits
		tmp = ei[i];  // tmp is between 1 and 32
		troncatedA = plaintext_blockA >> (tmp-1); //to get the bit of index tmp, we shift A of (tmp-1) bits		
		if (troncatedA%2 == 1){ //so the bit tmp is 1
			expandedA += pow(2, (47-i));//we set the bit (47-i) to 1			
		}
		// or expandedA += 2^i it depends on increm of i and big or little endian of expansion table
    }
    return expandedA;
}


/*
 * XOR function
 * XOR between E(A) and K, both on 48 bits
 */
 
//fonction inutile !!!
uint64_t xor(uint64_t expandedA, uint64_t key) {
	uint64_t xored = expandedA ^ key;
	return xored;
}


/*
 * Permutation function P
 * takes in input a word of 32 bits (the output of the S-boxes) 
 * turns it into a word of 32 bits according to the permutation table p32i[] of DES_data.h 
 */

uint32_t permutation_p(uint32_t sboxes_output){
	uint32_t perm = 0; //the output of this function
	uint32_t troncated_sboxes_output = 0;
	int tmp = 0;
	for(int i = 0; i < 32; i++) {  //i goes through the table p32i[] of 32 bits
		tmp = p32i[i];
		troncated_sboxes_output = sboxes_output >> (tmp-1);
		if (troncated_sboxes_output%2 == 1){ //so the bit tmp is 1
			perm += pow(2, (31-i));  //we set the bit (31-i) to 1
		}
	}
	return perm; // perm = f(A,K)
}

/*
 * Function f(A,K) according to our notation f(A,K) = PoS(E(A)^K)
 * with E expansion function, S sboxes function, P permutation function
 * A plaintext of 32 bits and K key of 48 bits  
 */


/*
uint32_t des_f(uint32_t A, uint64_t K) {
	uint64_t expandedA = expansion(A);
	uint64_t xored = expandedA ^ K; // or uint64_t xored = xor(expandedA,K);
	uint32_t sbox_output = S(xored); // !!!!! remplacer S avec le bon nom de fonction de SAM
	uint32_t output = permutation_p(sbox_output);
	return output;
}

*/

/*
 * DES function with 3 rounds
 * A plaintext of 32 bits and K key of 48 bits  
 */


