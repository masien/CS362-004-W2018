/*
 * STEWARD CARD TEST
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

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 100;
    int numPlayers = 2;
    int curPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int numIterations = 100;
	int randNum = -99;
	
	// generate seed for rand()
	srand(time(NULL));
	
	for (i = 0; i < numIterations; i++)
	{
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		// generate a random hand with steward in it
		testG.hand[curPlayer][0] = steward;
		testG.hand[curPlayer][1] = -99;
		testG.hand[curPlayer][2] = -99;
		testG.hand[curPlayer][3] = -99;
		testG.hand[curPlayer][4] = -99;
		
		for (j = 1; j <= 4; j++)
		{
			// generate random # 0-26 to generate random starting hands with NO DUPLICATES
			randNum = rand() % 27;
			
			while (randNum == 18 || randNum == testG.hand[curPlayer][1] || randNum == testG.hand[curPlayer][2] || randNum == testG.hand[curPlayer][3] || randNum == testG.hand[curPlayer][4])
			{
				randNum = rand() % 27;
			}
			
			testG.hand[curPlayer][j] = randNum;
		}
		
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		// TEST 1: choice1 = 1 (+2 cards)
		printf("TEST 1: +2 cards...\n");
		
		choice1 = 1;
		
		cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);
		
		if ((testG.handCount[curPlayer] == G.handCount[curPlayer] + 2 - 1) && (testG.deckCount[curPlayer] == G.deckCount[curPlayer] - 2))
		{
			printf("*****TEST PASSED***** hand count = %d, expected = %d\n", testG.handCount[curPlayer], G.handCount[curPlayer] + 2 - 1);	// handcount + 2 cards drawn - steward card
			printf("                      deck count = %d, expected = %d\n\n", testG.deckCount[curPlayer], G.deckCount[curPlayer] - 2);	// deckcount - 2 cards drawn
		}
		else
		{
			printf("*****TEST FAILED***** hand count = %d, expected = %d\n", testG.handCount[curPlayer], G.handCount[curPlayer] + 2 - 1);	// handcount + 2 cards drawn - steward card
			printf("                      deck count = %d, expected = %d\n\n", testG.deckCount[curPlayer], G.deckCount[curPlayer] - 2);	// deckcount - 2 cards drawn 
		}
		
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));

		// TEST 2: choice1 = 2 (+2 coins)
		printf("TEST 2: +2 coins...\n");
		
		choice1 = 2;
		
		cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);
		
		if ((testG.handCount[curPlayer] == G.handCount[curPlayer] - 1) && (testG.coins == G.coins + 2))
		{
			printf("*****TEST PASSED***** hand count = %d, expected = %d\n", testG.handCount[curPlayer], G.handCount[curPlayer] - 1);	// handcount - steward card
			printf("                      coins = %d, expected = %d\n", testG.coins, G.coins + 2);	// coins + 2 coins chosen
		}
		else
		{
			printf("*****TEST FAILED***** hand count = %d, expected = %d\n", testG.handCount[curPlayer], G.handCount[curPlayer] - 1);	// handcount - steward card
			printf("                      coins = %d, expected = %d\n\n", testG.coins, G.coins + 2);	// coins + 2 coins chosen
		}

		// TEST 3: choice1 = 3 (trash 2 cards)
		printf("TEST 3: trash 2 cards...\n");
		
		choice1 = 3;
		
		// generate a random hand with steward in it
		G.hand[curPlayer][0] = steward;
		G.hand[curPlayer][1] = -99;
		G.hand[curPlayer][2] = -99;
		G.hand[curPlayer][3] = -99;
		G.hand[curPlayer][4] = -99;
		
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		for (j = 1; j <= testG.handCount[curPlayer]; j++)
		{
			// generate random # 0-26 to generate random starting hands with NO DUPLICATES
			randNum = rand() % 27;
			
			while (randNum == 18 || randNum == testG.hand[curPlayer][1] || randNum == testG.hand[curPlayer][2] || randNum == testG.hand[curPlayer][3] || randNum == testG.hand[curPlayer][4] || randNum == testG.hand[curPlayer][5] || randNum == testG.hand[curPlayer][6])
			{
				randNum = rand() % 27;
			}
			
			testG.hand[curPlayer][j] = randNum;
		}
		
		cardEffect(steward, 0, 0, 0, &testG, 1, 0);
		
		// generate random # 1-4 to generate random value for choice2
		choice2 = (rand() % 4) + 1;
		
		// generate random # 1-4 to generate random value for choice3
		choice3 = (rand() % 4) + 1;
		while (choice3 == choice2)
		{
			// generate random # 1-4 to generate random value for choice3
			choice3 = (rand() % 4) + 1;
		}
		
		cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);
		
		int ii = 0;
		
		for (ii = 0; ii < testG.handCount[curPlayer]; ii++)
		{
			printf("testG.hand[0][%d] = (%d)\n", ii, testG.hand[curPlayer][ii]);
			if (testG.hand[curPlayer][ii] != steward && testG.hand[curPlayer][ii] != choice2 && testG.hand[curPlayer][ii] != choice3)
			{
				printf("GOOD CARD\n");
			}
			else
			{
				testPassed = 0;
			}
		}
		
		if (testPassed == 1)
		{
			printf("*****TEST PASSED***** appropriate cards were trashed\n\n");
		}
		else
		{
			printf("*****TEST FAILED***** inappropriate cards were trashed\n\n");
		}
		
	}
}
