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
	
	// TEST 1: +2 cards
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
	
	// TEST 2: + 2 coins
	printf("TEST 2: +2 coins...\n");
	choice1 = 2;
	cardEffect(steward, 0, 0, 0, &testG, 0, 0);
	
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
	
	// TEST 3: trash 2 cards
	printf("TEST 3: trash 2 cards...\n");
	choice1 = 3;
	cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	G.hand[curPlayer][0] = steward;
	G.hand[curPlayer][1] = copper;
	G.hand[curPlayer][2] = gardens;
	G.hand[curPlayer][3] = adventurer;
	G.hand[curPlayer][4] = remodel;
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	choice2 = 3;
	choice3 = 4;
	
	cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	int ii = 0;
	
	for (ii = 0; ii < testG.handCount[curPlayer]; ii++)
	{
		printf("testG.hand[0][%d] = (%d)\n", ii, testG.hand[curPlayer][ii]);
		if (testG.hand[curPlayer][ii] != steward && testG.hand[curPlayer][ii] != adventurer && testG.hand[curPlayer][ii] != remodel)
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
