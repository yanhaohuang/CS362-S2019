/* numHandCards code in dominion.c
int numHandCards(struct gameState *state) {
  return state->handCount[ whoseTurn(state) ];
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int asserttrue(int t) {
	if (t) {printf("SUCCESS\n"); return 1;}
	else {printf("FAIL\n"); return 0;}
}

int main() {
	int pass = 0;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, great_hall};

	printf("----------------- Unit Test: numHandCards ----------------\n");
	initializeGame(2, k, 1000, &G);

    for (int i = 0 ; i < 11 ; i++) {
    	G.handCount[G.whoseTurn] = i;
		printf("Number of hand cards = %d, Expected = %d\n", numHandCards(&G), G.handCount[G.whoseTurn]);
		pass += asserttrue(numHandCards(&G) == G.handCount[G.whoseTurn]);	
	}	
	printf("\n >>>>> numHandCards testing complete passed [%d of %d] tests <<<<<\n", pass, 11);
	return 0;
}