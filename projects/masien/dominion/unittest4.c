/********************************************
 *** unit test for updateCoins()
 *******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() 
{
	int curPlayer = 0;
	int players = 2;
	int seed = 1000;
	int kingdom[10] = {adventurer, smithy, cutpurse, estate, ambassador, outpost, salvager, treasure_map, mine, remodel};
	int initializedGame = -99;
	int gameOver = -99;
	int allTestsPassed = 1;
	struct gameState gameStateStruct;
	int initValue = 0;
	int testValue = 0;
	int testPass = 1;
	int bonus = 2;
	int oldCoins;
	int newCoins;
	
	
	// initialize the game state
	initializedGame = initializeGame(players, kingdom, seed, &gameStateStruct);
	
	gameStateStruct.hand[curPlayer][0] = steward;
	gameStateStruct.hand[curPlayer][1] = copper;
	gameStateStruct.hand[curPlayer][2] = silver;
	gameStateStruct.hand[curPlayer][3] = gold;
	gameStateStruct.hand[curPlayer][4] = remodel;
	
	printf("Player 1's hand count = %d\n", gameStateStruct.handCount[curPlayer]);
	printf("gameStateStruct.coins = %d\n", gameStateStruct.coins);
	oldCoins = gameStateStruct.coins;
	
	int i = 0;
	int j = 0;
	
	for (i = 0; i < gameStateStruct.handCount[curPlayer]; i++)
	{
		if (gameStateStruct.hand[curPlayer][i] == copper)
		{
			printf("gameStateStruct.hand[0][%d] = copper\n", i);
		}
		else if (gameStateStruct.hand[curPlayer][i] == silver)
		{
			printf("gameStateStruct.hand[0][%d] = silver\n", i);
		}
		else if (gameStateStruct.hand[curPlayer][i] == gold)
		{
			printf("gameStateStruct.hand[0][%d] = gold\n", i);
		}
	}
	
	updateCoins(0, &gameStateStruct, bonus);
	newCoins = gameStateStruct.coins;
	
	printf("gameStateStruct.coins = %d\n", gameStateStruct.coins);
	
	for (i = 0; i < gameStateStruct.handCount[curPlayer]; i++)
	{
		if (gameStateStruct.hand[curPlayer][i] == copper)
		{
			printf("gameStateStruct.hand[0][%d] = copper\n", i);
		}
		else if (gameStateStruct.hand[curPlayer][i] == silver)
		{
			printf("gameStateStruct.hand[0][%d] = silver\n", i);
		}
		else if (gameStateStruct.hand[curPlayer][i] == gold)
		{
			printf("gameStateStruct.hand[0][%d] = gold\n", i);
		}
	}
	
	if (gameStateStruct.coins == 8)
	{
		printf("*****TEST PASSED***** change in coins is accurately reflected\n\n");
	}
	else
	{
		printf("*****TEST FAILED***** change in coins is NOT accurately reflected\n\n");
	}
	
	// initialize the game state
	initializedGame = initializeGame(players, kingdom, seed, &gameStateStruct);
	
	gameStateStruct.hand[curPlayer][0] = steward;
	gameStateStruct.hand[curPlayer][1] = adventurer;
	gameStateStruct.hand[curPlayer][2] = smithy;
	gameStateStruct.hand[curPlayer][3] = gardens;
	gameStateStruct.hand[curPlayer][4] = remodel;
	gameStateStruct.coins = 0;
	
	printf("Player 1's hand count = %d\n", gameStateStruct.handCount[curPlayer]);
	printf("gameStateStruct.coins = %d\n", gameStateStruct.coins);
	
	updateCoins(0, &gameStateStruct, 0);
	
	printf("Player 1's hand count = %d\n", gameStateStruct.handCount[curPlayer]);
	printf("gameStateStruct.coins = %d\n", gameStateStruct.coins);
	
	if (gameStateStruct.coins == 0)
	{
		printf("*****TEST PASSED***** change in coins is accurately reflected\n\n");
	}
	else
	{
		printf("*****TEST FAILED***** change in coins is NOT accurately reflected\n\n");
	}
	
	
	// initialize the game state
	initializedGame = initializeGame(players, kingdom, seed, &gameStateStruct);
	
	gameStateStruct.hand[curPlayer][0] = steward;
	gameStateStruct.hand[curPlayer][1] = adventurer;
	gameStateStruct.hand[curPlayer][2] = smithy;
	gameStateStruct.hand[curPlayer][3] = gardens;
	gameStateStruct.hand[curPlayer][4] = remodel;
	gameStateStruct.coins = 5;
	
	printf("Player 1's hand count = %d\n", gameStateStruct.handCount[curPlayer]);
	printf("gameStateStruct.coins = %d\n", gameStateStruct.coins);
	
	updateCoins(0, &gameStateStruct, 0);
	
	printf("Player 1's hand count = %d\n", gameStateStruct.handCount[curPlayer]);
	printf("gameStateStruct.coins = %d\n", gameStateStruct.coins);
	
	if (gameStateStruct.coins == 0)
	{
		printf("*****TEST PASSED***** change in coins is accurately reflected\n\n");
	}
	else
	{
		printf("*****TEST FAILED***** change in coins is NOT accurately reflected\n\n");
	}
}
