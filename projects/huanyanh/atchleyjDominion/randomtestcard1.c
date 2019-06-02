/* Village code in dominion.c
int _village(struct gameState *state, int currentPlayer, int handPos){
    drawCard(currentPlayer, state);                     // +1 Card
    state->numActions = state->numActions + 3;          // +2 Actions
    discardCard(handPos, currentPlayer, state, 0);      // discard played card from hand
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
#include <time.h>

int asserttrue(int t) {
	if (t) {printf("SUCCESS\n"); return 1;}
	else {printf("FAIL\n"); return 0;}
}

int main() {
	srand(time(NULL));

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, pass = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, great_hall};
	int numPlayers, seed;

	for (int i = 1; i <= 10; i++) {
		pass = 0;
		printf("----------------- Testing Card: Village [%d of 10] ----------------\n", i);
		numPlayers = (rand() % 10);
		seed = (rand() % 1000);
		initializeGame(numPlayers, k, seed, &G);
		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

		printf("Hand Count = %d, Expected = %d\n", testG.handCount[testG.whoseTurn], G.handCount[G.whoseTurn]);
		pass += asserttrue(testG.handCount[testG.whoseTurn] == G.handCount[G.whoseTurn]);

		printf("Actions = %d, Expected = %d\n", testG.numActions, G.numActions + 2);
		pass += asserttrue(testG.numActions == G.numActions + 2);

		printf("Played count = %d, Expected = %d\n", testG.playedCardCount, G.playedCardCount + 1);
		pass += asserttrue(testG.playedCardCount == G.playedCardCount + 1);
		
		printf("\n >>>>> Village testing complete passed [%d of 3] tests <<<<<\n", pass);
	}
	return 0;
}