/********************************************
 *** unit test for supplyCount()
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
	
	
	// initialize the game state
	initializedGame = initializeGame(players, kingdom, seed, &gameStateStruct);
	
	int i = 0;
	int j = 0;
	
	for (i = 0; i < 3; i++)
	{
		testPass = 1;
		if (gameStateStruct.supplyCount[i] != -1)
		{
			initValue = supplyCount(i, &gameStateStruct);
			printf("supplyCount[%d] = %d\n", i, gameStateStruct.supplyCount[i]);
			for (j = 0; j < initValue; j++)
			{
				testValue = supplyCount(i, &gameStateStruct);
				if ((initValue - j) != testValue)
				{
					testPass = 0;
				}
				gameStateStruct.supplyCount[i] -= 1;
				//printf("supplyCount[%d] = %d\n", i, gameStateStruct.supplyCount[i]);
			}
		}
		if (testPass == 0)
		{
			printf("*****TEST FAILED***** supplyCount[%d] failed\n", i);
		}
		else
		{
			printf("*****TEST PASSED***** supplyCount[%d] passed\n", i);
		}
	}
	
	// test value of allTestsPassed (1 = true: all tests were passed, 0 = false: at least one test failed)
	if (allTestsPassed == 1)
	{
		printf("*****ALL TESTS PASSED***** the isGameOver() function passed all of the unit tests\n\n");
	} 
	else 
	{
		printf("*****FAILED***** the isGameOver() function failed at least 1 of the unit tests above (refer to individual test results)\n\n");
	}
}
	
