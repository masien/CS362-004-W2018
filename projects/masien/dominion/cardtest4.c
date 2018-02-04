/*
 * SMITHY CARD TEST
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
	
	G.hand[curPlayer][0] = smithy;
	G.hand[curPlayer][1] = copper;
	G.hand[curPlayer][2] = gardens;
	G.hand[curPlayer][3] = adventurer;
	G.hand[curPlayer][4] = remodel;
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// TEST 1: check that we discarded the smithy card
	printf("TEST 1: check that we discarded the smithy card\n");
	
	int ii = 0;
	
	for (ii = 0; ii < testG.handCount[curPlayer]; ii++)
	{
		printf("testG.hand[0][%d] = (%d)\n", ii, testG.hand[curPlayer][ii]);
	}
	
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
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
		printf("*****TEST PASSED***** smithy was successfully discarded from the player's hand\n\n");
	}
	else
	{
		printf("*****TEST FAILED***** smithy was NOT discarded and is still in the player's hand\n\n");
	}
	
	// TEST 2: check that we have a net gain of 2 cards (-1 for the smithy discard, and +3 for the draw 3 cards)
	printf("TEST 2: check that we have a net gain of 2 cards\n");
	
	if (testG.handCount[curPlayer] - G.handCount[curPlayer] == 2)
	{
		printf("*****TEST PASSED***** there was a net gain of 2 cards\n\n");
	}
	else
	{
		printf("*****TEST FAILED***** there was NOT a net gain of 2 cards\n\n");
	}
	
}
