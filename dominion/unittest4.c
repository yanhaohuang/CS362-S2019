/* whoseTurn code in dominion.c
int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
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

	printf("----------------- Unit Test: whoseTurn ----------------\n");
	initializeGame(4, k, 1000, &G);

    for (int i = 0 ; i < 4 ; i++) {
    	G.whoseTurn = i;
		printf("Player turn = %d, Expected = %d\n", whoseTurn(&G), G.whoseTurn);
		pass += asserttrue(whoseTurn(&G) == G.whoseTurn);	
	}	
	printf("\n >>>>> whoseTurn testing complete passed [%d of %d] tests <<<<<\n", pass, 4);
	return 0;
}