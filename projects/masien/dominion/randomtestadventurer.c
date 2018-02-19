/*
 * ADVENTURER CARD TEST
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

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int curPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
			
	int i, j, m;
	
	// generate seed for rand()
	srand(time(NULL));
	
	for (i = 0; i < numIterations; i++)
	{
		oldTreasureCount = 0;
		newTreasureCount = 0;
		testPassed = 1;
		allTestsPassed = 1;

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		// generate a random hand with adventurer in it
		testG.hand[curPlayer][0] = adventurer;
		testG.hand[curPlayer][1] = -99;
		testG.hand[curPlayer][2] = -99;
		testG.hand[curPlayer][3] = -99;
		testG.hand[curPlayer][4] = -99;
		
		for (j = 1; j <= 4; j++)
		{
			// generate random # 0-26 to generate random starting hands with NO DUPLICATES
			randNum = rand() % 27;
			
			while (randNum == 7 || randNum == testG.hand[curPlayer][1] || randNum == testG.hand[curPlayer][2] || randNum == testG.hand[curPlayer][3] || randNum == testG.hand[curPlayer][4])
			{
				randNum = rand() % 27;
			}
			
			testG.hand[curPlayer][j] = randNum;
		}
		
		int ii = 0;
		
		for (ii = 0; ii < testG.handCount[curPlayer]; ii++)
		{
			printf("testG.hand[0][%d] = (%d)\n", ii, testG.hand[curPlayer][ii]);
			if ((testG.hand[curPlayer][ii] == copper) || (testG.hand[curPlayer][ii] == silver) || (testG.hand[curPlayer][ii] == gold))
			{
				oldTreasureCount++;
			}
		}
		
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		// TEST 1: check that there is a net gain of 1 in handcount
		printf("TEST 1: check that there is a net gain of 1 in handcount\n");
		
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
		
		//put played card in played card pile
		//discardCard(handpos, curPlayer, &testG, 0);
			
		if ((testG.handCount[curPlayer] - G.handCount[curPlayer]) == 1)
		{
			printf("*****TEST PASSED***** there was a net gain of 1 in handcount\n\n");
		}
		else
		{
			printf("*****TEST FAILED***** there was NOT a net gain of 1 in handcount\n\n");
			allTestsPassed = 0;
		}
		
		// TEST 2: check that we actually discarded adventurer and gained 2 treasure cards
		printf("TEST 2: check that we actually discarded adventurer and gained 2 treasure cards\n");
		
		for (ii = 0; ii < testG.handCount[curPlayer]; ii++)
		{
			printf("testG.hand[0][%d] = (%d)\n", ii, testG.hand[curPlayer][ii]);
			if (testG.hand[curPlayer][ii] == adventurer)
			{
				testPassed = 0;
			}
			
			if ((testG.hand[curPlayer][ii] == copper) || (testG.hand[curPlayer][ii] == silver) || (testG.hand[curPlayer][ii] == gold))
			{
				newTreasureCount++;
			}
		}
		
		if (newTreasureCount - oldTreasureCount == 2)
		{
			printf("*****TEST PASSED***** player gained 2 treasure cards\n\n");
		}
		else
		{
			printf("*****TEST FAILED***** player did NOT gain 2 treasure cards\n\n");
			allTestsPassed = 0;
		}
		
		// TEST 3: check that we passed all of the tests
		printf("TEST 3: check that we passed all of the tests\n");
		if (allTestsPassed == 1)
		{
			printf("*****TEST PASSED***** all tests passed\n\n");
		}
		else
		{
			printf("*****TEST FAILED***** at least one test failed, refer to individual results above\n\n");
		}
	}
	
}
