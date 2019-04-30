
/* Smithy code in dominion.c
int _smithy(struct gameState *state, int currentPlayer, int handPos){
    for (int i = 1; i < 3; i++) drawCard(currentPlayer, state);     // +3 Cards
    discardCard(handPos, currentPlayer, state, 0);                  // discard card from hand
    return 0;
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
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, pass = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, great_hall};

	printf("----------------- Testing Card: Smithy ----------------\n");
	initializeGame(2, k, 1000, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("Hand Count = %d, Expected = %d\n", testG.handCount[testG.whoseTurn], G.handCount[G.whoseTurn] + 2);
	pass += asserttrue(testG.handCount[testG.whoseTurn] == G.handCount[G.whoseTurn] + 3);

	printf("Played count = %d, Expected = %d\n", testG.playedCardCount, G.playedCardCount + 1);
	pass += asserttrue(testG.playedCardCount == G.playedCardCount + 1);

	printf("\n >>>>> Smithy testing complete passed [%d of %d] tests <<<<<\n", pass, 2);
	return 0;
}