/* Adventurer code in dominion.c
int _adventurer(struct gameState *state, int currentPlayer, int drawntreasure, int z, int temphand[]){
    while (drawntreasure < 1) {
        if (state->deckCount[currentPlayer] < 1) shuffle(currentPlayer, state);             // if the deck is empty we need to shuffle discard and add to deck
        drawCard(currentPlayer, state);
        int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];    // top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) drawntreasure++;
        else {
            temphand[z] = cardDrawn;
            state->handCount[currentPlayer]--;                                              // this should just remove the top card (the most recently drawn one).
            z++;
        }
    }
    while (z - 1 >= 0) {
        state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z-1]; // discard all cards in play that have been drawn
        z--;
    }
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
	int temp[MAX_HAND];
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, pass = 0, i = 0;
	int treasure = 0, t1 = 0, t2 = 0;
	int numPlayers, seed;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, great_hall};

	for (int j = 1; j <= 10; j++) {
		pass = 0;
		printf("----------------- Testing Card: Adventurer [%d of 10] ----------------\n", j);
		numPlayers = (rand() % 10);
		seed = (rand() % 1000);
		initializeGame(numPlayers, k, seed, &G);
		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

		while (treasure < 2) {
			drawCard(G.whoseTurn, &G);
			int draw = G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1];
			if (draw == copper || draw == silver || draw == gold) treasure++;
			else {temp[i] = draw; G.handCount[G.whoseTurn]--; i++;}
	    }
		printf("Discard count = %d, Expected = %d\n", testG.discardCount[testG.whoseTurn], G.discardCount[G.whoseTurn] + i);
		pass += asserttrue(testG.discardCount[testG.whoseTurn] == G.discardCount[G.whoseTurn] + i);
		
		for (int i = 0; i < G.handCount[G.whoseTurn]; i++){ 
			if (G.hand[G.whoseTurn][i] == copper || G.hand[G.whoseTurn][i] == silver || G.hand[G.whoseTurn][i] == gold) t1++;
		}
		for(int i = 0; i < testG.handCount[testG.whoseTurn]; i++){
			if (testG.hand[testG.whoseTurn][i] == copper || testG.hand[testG.whoseTurn][i] == silver || testG.hand[testG.whoseTurn][i] == gold) t2++;
		}
		printf("Treasure count = %d, Expected = %d\n", t2, t1);
		pass += asserttrue(t2 == t1);
		
		printf("\n >>>>> Adventurer testing complete passed [%d of 2] tests <<<<<\n", pass);
	}
	return 0;
}