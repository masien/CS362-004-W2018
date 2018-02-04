/********************************************
 *** unit test for isGameOver()
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
	
	// TEST 1
	
	// initialize the game state
	initializedGame = initializeGame(players, kingdom, seed, &gameStateStruct);
	
	// TEST 1: first check to see that we successfully initialized a valid game state
	printf("TEST 1: Test to see that we successfully initialized a valid game state...\n");
	
	// test isGameOver function
	gameOver = isGameOver(&gameStateStruct);
	
	// print the results
	if(gameOver == 0)
	{
		printf("*****TEST PASSED***** the game is not over.\n\n");
		// allTestPassed still = 1
	} 
	else 
	{
		printf("*****TEST FAILED***** the game terminated.\n\n");
		allTestsPassed = 0;
	}
	
	// TEST 2
	
	// reset the game state
	memset(&gameStateStruct, 23, sizeof(struct gameState)); 
	initializeGame(players, kingdom, seed, &gameStateStruct);
	
	// deplete 1 supply pile
	gameStateStruct.supplyCount[1] = 0;
	
	// TEST 2: check game state when only 1 supply pile is depleted
	printf("TEST 2: Test game state when only 1 supply pile is depleted...\n");
	
	// test isGameOver function
	gameOver = isGameOver(&gameStateStruct);
	
	// print the results
	if(gameOver == 0)
	{
		printf("*****TEST PASSED***** the game is not over.\n\n");
		// allTestPassed still = 1
	} 
	else 
	{
		printf("*****TEST FAILED***** the game terminated.\n\n");
		allTestsPassed = 0;
	}
	
	// TEST 3
	
	// reset the game state
	memset(&gameStateStruct, 23, sizeof(struct gameState)); 
	initializeGame(players, kingdom, seed, &gameStateStruct);
	
	// deplete 2 supply piles
	gameStateStruct.supplyCount[1] = 0;
	gameStateStruct.supplyCount[2] = 0;
	
	// TEST 3: check game state when 2 supply piles are depleted
	printf("TEST 3: Test game state when 2 supply piles are depleted...\n");
	
	// test isGameOver function
	gameOver = isGameOver(&gameStateStruct);
	
	// print the results
	if(gameOver == 0)
	{
		printf("*****TEST PASSED***** the game is not over.\n\n");
		// allTestPassed still = 1
	} 
	else 
	{
		printf("*****TEST FAILED***** the game terminated.\n\n");
		allTestsPassed = 0;
	}
	
	// TEST 4
	
	// reset the game state
	memset(&gameStateStruct, 23, sizeof(struct gameState)); 
	initializeGame(players, kingdom, seed, &gameStateStruct);
	
	// deplete 3 supply piles
	gameStateStruct.supplyCount[1] = 0;
	gameStateStruct.supplyCount[2] = 0;
	gameStateStruct.supplyCount[3] = 0;
	
	// TEST 4: check game state when 3 supply piles are depleted
	printf("TEST 4: Test game state when 3 supply piles are depleted...\n");
	
	// test isGameOver function
	gameOver = isGameOver(&gameStateStruct);
	
	// print the results
	if(gameOver == 1)
	{
		printf("*****TEST PASSED***** the game is not over.\n\n");
		// allTestPassed still = 1
	} 
	else 
	{
		printf("*****TEST FAILED***** the game terminated.\n\n");
		allTestsPassed = 0;
	}
	
	// TEST 5
	
	// reset the game state
	memset(&gameStateStruct, 23, sizeof(struct gameState)); 
	initializeGame(players, kingdom, seed, &gameStateStruct);
	
	// deplete 4 supply piles
	gameStateStruct.supplyCount[1] = 0;
	gameStateStruct.supplyCount[2] = 0;
	gameStateStruct.supplyCount[3] = 0;
	gameStateStruct.supplyCount[4] = 0;
	
	// TEST 5: check game state when more than 3 (4) supply piles are depleted
	printf("TEST 5: Test game state when more than 3 (4) supply piles are depleted...\n");
	
	// test isGameOver function
	gameOver = isGameOver(&gameStateStruct);
	
	// print the results
	if(gameOver == 1)
	{
		printf("*****TEST PASSED***** the game is not over.\n\n");
		// allTestPassed still = 1
	} 
	else 
	{
		printf("*****TEST FAILED***** the game terminated.\n\n");
		allTestsPassed = 0;
	}
	
	// TEST 6
	
	// reset the game state
	memset(&gameStateStruct, 23, sizeof(struct gameState)); 
	initializeGame(players, kingdom, seed, &gameStateStruct);
	
	// deplete 1 province pile
	gameStateStruct.supplyCount[province] = 0;
	
	// TEST 6: check game state when province pile is depleted
	printf("TEST 6: Test game state when province pile is depleted...\n");
	
	// test isGameOver function
	gameOver = isGameOver(&gameStateStruct);
	
	// print the results
	if(gameOver == 1)
	{
		printf("*****TEST PASSED***** the game is not over.\n\n");
		// allTestPassed still = 1
	} 
	else 
	{
		printf("*****TEST FAILED***** the game terminated.\n\n");
		allTestsPassed = 0;
	}
	
	// TEST 7
	
	// TEST 7: check if we passed all of the tests
	printf("TEST 7: Check if we passed all of the tests...\n");
	
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
