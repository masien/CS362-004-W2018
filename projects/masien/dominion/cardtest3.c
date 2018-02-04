/*
 * FEAST CARD TEST
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() 
{
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
	int testPassed = 1;
	int oldTreasureCount = 0;
	int newTreasureCount = 0;
	int allTestsPassed = 1;

    int i, j, m;
    int handpos = 0, choice1 = smithy, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int curPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	testG.hand[curPlayer][0] = feast;
	testG.hand[curPlayer][1] = copper;
	testG.hand[curPlayer][2] = gardens;
	testG.hand[curPlayer][3] = adventurer;
	testG.hand[curPlayer][4] = silver;
	
	// TEST 1: check that we discarded the feast card
	
	int ii = 0;
	
	for (ii = 0; ii < testG.handCount[curPlayer]; ii++)
	{
		printf("testG.hand[0][%d] = (%d)\n", ii, testG.hand[curPlayer][ii]);
	}
	
	cardEffect(feast, smithy, choice2, choice3, &testG, handpos, &bonus);
	//put played card in played card pile
    //discardCard(handpos, curPlayer, &testG, 0);
	
	for (ii = 0; ii < testG.handCount[curPlayer]; ii++)
	{
		printf("testG.hand[0][%d] = (%d)\n", ii, testG.hand[curPlayer][ii]);
		if (testG.hand[0][ii] == feast)
		{
			testPassed = 0;
		}
	}
	
	if (testPassed == 1)
	{
		printf("*****TEST PASSED***** feast was successfully discarded from the player's hand\n\n");
	}
	else
	{
		printf("*****TEST FAILED***** feast was NOT discarded and is still in the player's hand\n\n");
	}
	
	// reset testPassed (we will start as false this time since we are looking for a smithy in discard)
	testPassed = 0;
	
	// TEST 2: check that we gained a smithy in the deck
	for (ii = 0; ii < testG.deckCount[curPlayer]; ii++)
	{
		if (testG.discard[curPlayer][ii] == smithy)
		{
			testPassed = 1;
		}
	}
	
	if (testPassed == 1)
	{
		printf("*****TEST PASSED***** feast was successfully discarded from the player's hand\n\n");
	}
	else
	{
		printf("*****TEST FAILED***** feast was NOT discarded and is still in the player's hand\n\n");
	}
	
}
