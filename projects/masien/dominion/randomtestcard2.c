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
#include <time.h>

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
	int randNum = -99;
	int numIterations = 100;

    int i, j, m;
    int handpos = 0, choice1 = smithy, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int curPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	for (i = 0; i < numIterations; i++)
	{
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);
		
		// generate a random hand with smithy in it
		testG.hand[curPlayer][0] = smithy;
		testG.hand[curPlayer][1] = -99;
		testG.hand[curPlayer][2] = -99;
		testG.hand[curPlayer][3] = -99;
		testG.hand[curPlayer][4] = -99;
		
		for (j = 1; j <= 4; j++)
		{
			// generate random # 0-26 to generate random starting hands with NO DUPLICATES
			randNum = rand() % 27;
			
			while (randNum == 13 || randNum == testG.hand[curPlayer][1] || randNum == testG.hand[curPlayer][2] || randNum == testG.hand[curPlayer][3] || randNum == testG.hand[curPlayer][4])
			{
				randNum = rand() % 27;
			}
			
			testG.hand[curPlayer][j] = randNum;
		}
		
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		// TEST 1: check that we discarded the smithy card
		printf("TEST 1: check that we discarded the smithy card\n");
		
		int ii = 0;
		
		for (ii = 0; ii < testG.handCount[curPlayer]; ii++)
		{
			printf("testG.hand[0][%d] = (%d)\n", ii, testG.hand[curPlayer][ii]);
		}
		
		cardEffect(smithy, 0, 0, 0, &testG, 0, 0);
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
}
