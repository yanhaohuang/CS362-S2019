/* isGameOver code in dominion.c
int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0) return 1;

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++) {
      if (state->supplyCount[i] == 0) j++;
  }
  if ( j >= 3) return 1;
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
	int pass = 0;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, great_hall};

	printf("----------------- Unit Test: isGameOver ----------------\n");
	initializeGame(2, k, 1000, &G);

	printf("Game state = %d, Expected = %d\n", isGameOver(&G), 0);
	pass += asserttrue(isGameOver(&G) == 0);

	for (int i = 0; i < 3; i ++) G.supplyCount[i] = 0;
	printf("Game state = %d, Expected = %d\n", isGameOver(&G), 1);
	pass += asserttrue(isGameOver(&G) == 1);

	G.supplyCount[0] = 1;
	printf("Game state = %d, Expected = %d\n", isGameOver(&G), 0);
	pass += asserttrue(isGameOver(&G) == 0);
	
	G.supplyCount[province] = 0;
	printf("Game state = %d, Expected = %d\n", isGameOver(&G), 1);
	pass += asserttrue(isGameOver(&G) == 1);

	printf("\n >>>>> isGameOver testing complete passed [%d of %d] tests <<<<<\n", pass, 4);
	return 0;
}