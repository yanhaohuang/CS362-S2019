/* getCost code in dominion.c
int getCost(int cardNumber) {
	switch (cardNumber) {
		case curse:
			return 0;
		case estate:
			return 2;
		case duchy:
			return 5;
		case province:
			return 8;
		case copper:
			return 0;
		case silver:
			return 3;
		case gold:
			return 6;
		case adventurer:
			return 6;
		case council_room:
			return 5;
		case feast:
			return 4;
		case gardens:
			return 4;
		case mine:
			return 5;
		case remodel:
			return 4;
		case smithy:
			return 4;
		case village:
			return 3;
		case baron:
			return 4;
		case great_hall:
			return 3;
		case minion:
			return 5;
		case steward:
			return 3;
		case tribute:
			return 5;
		case ambassador:
			return 3;
		case cutpurse:
			return 4;
		case embargo: 
			return 2;
		case outpost:
			return 5;
		case salvager:
			return 4;
		case sea_hag:
			return 4;
		case treasure_map:
			return 4;
	}
	return -1;
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
	printf("----------------- Unit Test: getCost ----------------\n");
	printf("Cost = %d, Expected = %d\n", getCost(-1), -1);
	pass += asserttrue(getCost(-1) == -1);	

	printf("Cost = %d, Expected = %d\n", getCost(curse), 0);
	pass += asserttrue(getCost(curse) == 0);	

	printf("Cost = %d, Expected = %d\n", getCost(estate), 2);
	pass += asserttrue(getCost(estate) == 2);

	printf("Cost = %d, Expected = %d\n", getCost(duchy), 5);
	pass += asserttrue(getCost(duchy) == 5);

	printf("Cost = %d, Expected = %d\n", getCost(province), 8);
	pass += asserttrue(getCost(province) == 8);

	printf("Cost = %d, Expected = %d\n", getCost(copper), 0);
	pass += asserttrue(getCost(copper) == 0);

	printf("Cost = %d, Expected = %d\n", getCost(silver), 3);
	pass += asserttrue(getCost(silver) == 3);

	printf("Cost = %d, Expected = %d\n", getCost(gold), 6);
	pass += asserttrue(getCost(gold) == 6);	

	printf("Cost = %d, Expected = %d\n", getCost(adventurer), 6);
	pass += asserttrue(getCost(adventurer) == 6);

	printf("Cost = %d, Expected = %d\n", getCost(council_room), 5);
	pass += asserttrue(getCost(council_room) == 5);

	printf("Cost = %d, Expected = %d\n", getCost(feast), 4);
	pass += asserttrue(getCost(feast) == 4);

	printf("Cost = %d, Expected = %d\n", getCost(gardens), 4);
	pass += asserttrue(getCost(gardens) == 4);

	printf("Cost = %d, Expected = %d\n", getCost(mine), 5);
	pass += asserttrue(getCost(mine) == 5);

	printf("Cost = %d, Expected = %d\n", getCost(remodel), 4);
	pass += asserttrue(getCost(remodel) == 4);	

	printf("Cost = %d, Expected = %d\n", getCost(smithy), 4);
	pass += asserttrue(getCost(smithy) == 4);

	printf("Cost = %d, Expected = %d\n", getCost(village), 3);
	pass += asserttrue(getCost(village) == 3);

	printf("Cost = %d, Expected = %d\n", getCost(baron), 4);
	pass += asserttrue(getCost(baron) == 4);

	printf("Cost = %d, Expected = %d\n", getCost(great_hall), 3);
	pass += asserttrue(getCost(great_hall) == 3);

	printf("Cost = %d, Expected = %d\n", getCost(minion), 5);
	pass += asserttrue(getCost(minion) == 5);

	printf("Cost = %d, Expected = %d\n", getCost(steward), 3);
	pass += asserttrue(getCost(steward) == 3);

	printf("Cost = %d, Expected = %d\n", getCost(tribute), 5);
	pass += asserttrue(getCost(tribute) == 5);

	printf("Cost = %d, Expected = %d\n", getCost(ambassador), 3);
	pass += asserttrue(getCost(ambassador) == 3);

	printf("Cost = %d, Expected = %d\n", getCost(cutpurse), 4);
	pass += asserttrue(getCost(cutpurse) == 4);

	printf("Cost = %d, Expected = %d\n", getCost(embargo), 2);
	pass += asserttrue(getCost(embargo) == 2);

	printf("Cost = %d, Expected = %d\n", getCost(outpost), 5);
	pass += asserttrue(getCost(outpost) == 5);

	printf("Cost = %d, Expected = %d\n", getCost(salvager), 4);
	pass += asserttrue(getCost(salvager) == 4);

	printf("Cost = %d, Expected = %d\n", getCost(sea_hag), 4);
	pass += asserttrue(getCost(sea_hag) == 4);

	printf("Cost = %d, Expected = %d\n", getCost(treasure_map), 4);
	pass += asserttrue(getCost(treasure_map) == 4);
	printf("\n >>>>> getCost testing complete passed [%d of %d] tests <<<<<\n", pass, 28);
	return 0;
}

