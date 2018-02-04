/********************************************
 *** unit test for getCost()
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
	struct gameState gameStateStruct;
	int returnedCost = -99;
	int allTestsPassed = 1;
	
	// TEST 1: check cost of curse
	printf("TEST 1: check cost of curse...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(curse);
	
	// check for correct value and print results
	if (returnedCost == 0)
	{
		printf("*****TEST PASSED***** cost of curse is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of curse is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 2: check cost of estate
	printf("TEST 2: check cost of estate...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(estate);
	
	// check for correct value and print results
	if (returnedCost == 2)
	{
		printf("*****TEST PASSED***** cost of estate is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of estate is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 3: check cost of duchy
	printf("TEST 3: check cost of duchy...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(duchy);
	
	// check for correct value and print results
	if (returnedCost == 5)
	{
		printf("*****TEST PASSED***** cost of duchy is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of duchy is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 4: check cost of province
	printf("TEST 4: check cost of province...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(province);
	
	// check for correct value and print results
	if (returnedCost == 8)
	{
		printf("*****TEST PASSED***** cost of province is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of province is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 5: check cost of copper
	printf("TEST 5: check cost of copper...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(copper);
	
	// check for correct value and print results
	if (returnedCost == 0)
	{
		printf("*****TEST PASSED***** cost of copper is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of copper is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 6: check cost of silver
	printf("TEST 6: check cost of silver...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(silver);
	
	// check for correct value and print results
	if (returnedCost == 3)
	{
		printf("*****TEST PASSED***** cost of silver is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of silver is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 7: check cost of gold
	printf("TEST 7: check cost of gold...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(gold);
	
	// check for correct value and print results
	if (returnedCost == 6)
	{
		printf("*****TEST PASSED***** cost of gold is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of gold is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 8: check cost of adventurer
	printf("TEST 8: check cost of adventurer...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(adventurer);
	
	// check for correct value and print results
	if (returnedCost == 6)
	{
		printf("*****TEST PASSED***** cost of adventurer is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of adventurer is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 9: check cost of council_room
	printf("TEST 9: check cost of council_room...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(council_room);
	
	// check for correct value and print results
	if (returnedCost == 5)
	{
		printf("*****TEST PASSED***** cost of council_room is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of council_room is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 10: check cost of feast
	printf("TEST 10: check cost of feast...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(feast);
	
	// check for correct value and print results
	if (returnedCost == 4)
	{
		printf("*****TEST PASSED***** cost of feast is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of feast is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 11: check cost of gardens
	printf("TEST 11: check cost of gardens...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(gardens);
	
	// check for correct value and print results
	if (returnedCost == 4)
	{
		printf("*****TEST PASSED***** cost of gardens is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of gardens is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 12: check cost of mine
	printf("TEST 12: check cost of mine...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(mine);
	
	// check for correct value and print results
	if (returnedCost == 5)
	{
		printf("*****TEST PASSED***** cost of mine is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of mine is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 13: check cost of remodel
	printf("TEST 13: check cost of remodel...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(remodel);
	
	// check for correct value and print results
	if (returnedCost == 4)
	{
		printf("*****TEST PASSED***** cost of remodel is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of remodel is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 14: check cost of smithy
	printf("TEST 14: check cost of smithy...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(smithy);
	
	// check for correct value and print results
	if (returnedCost == 4)
	{
		printf("*****TEST PASSED***** cost of smithy is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of smithy is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 15: check cost of village
	printf("TEST 15: check cost of village...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(village);
	
	// check for correct value and print results
	if (returnedCost == 3)
	{
		printf("*****TEST PASSED***** cost of village is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of village is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 16: check cost of baron
	printf("TEST 16: check cost of baron...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(baron);
	
	// check for correct value and print results
	if (returnedCost == 4)
	{
		printf("*****TEST PASSED***** cost of baron is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of baron is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 17: check cost of great_hall
	printf("TEST 17: check cost of great_hall...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(great_hall);
	
	// check for correct value and print results
	if (returnedCost == 3)
	{
		printf("*****TEST PASSED***** cost of great_hall is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of great_hall is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 18: check cost of minion
	printf("TEST 18: check cost of minion...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(minion);
	
	// check for correct value and print results
	if (returnedCost == 5)
	{
		printf("*****TEST PASSED***** cost of minion is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of minion is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 19: check cost of steward
	printf("TEST 19: check cost of steward...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(steward);
	
	// check for correct value and print results
	if (returnedCost == 3)
	{
		printf("*****TEST PASSED***** cost of steward is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of steward is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 20: check cost of tribute
	printf("TEST 20: check cost of tribute...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(tribute);
	
	// check for correct value and print results
	if (returnedCost == 5)
	{
		printf("*****TEST PASSED***** cost of tribute is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of tribute is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 21: check cost of ambassador
	printf("TEST 21: check cost of ambassador...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(ambassador);
	
	// check for correct value and print results
	if (returnedCost == 3)
	{
		printf("*****TEST PASSED***** cost of ambassador is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of ambassador is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 22: check cost of cutpurse
	printf("TEST 22: check cost of cutpurse...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(cutpurse);
	
	// check for correct value and print results
	if (returnedCost == 4)
	{
		printf("*****TEST PASSED***** cost of cutpurse is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of cutpurse is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 23: check cost of embargo
	printf("TEST 23: check cost of embargo...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(embargo);
	
	// check for correct value and print results
	if (returnedCost == 2)
	{
		printf("*****TEST PASSED***** cost of embargo is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of embargo is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 24: check cost of outpost
	printf("TEST 24: check cost of outpost...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(outpost);
	
	// check for correct value and print results
	if (returnedCost == 5)
	{
		printf("*****TEST PASSED***** cost of outpost is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of outpost is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 25: check cost of salvager
	printf("TEST 25: check cost of salvager...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(salvager);
	
	// check for correct value and print results
	if (returnedCost == 4)
	{
		printf("*****TEST PASSED***** cost of salvager is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of salvager is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 26: check cost of sea_hag
	printf("TEST 26: check cost of sea_hag...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(sea_hag);
	
	// check for correct value and print results
	if (returnedCost == 4)
	{
		printf("*****TEST PASSED***** cost of sea_hag is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of sea_hag is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 27: check cost of treasure_map
	printf("TEST 27: check cost of treasure_map...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(treasure_map);
	
	// check for correct value and print results
	if (returnedCost == 4)
	{
		printf("*****TEST PASSED***** cost of treasure_map is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of treasure_map is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 28: check cost of nonexistent_card
	printf("TEST 28: check cost of nonexistent_card...\n");
	
	// call getCost() to get and store the cost of the card in question
	returnedCost = getCost(-1);
	
	// check for correct value and print results
	if (returnedCost == -1)
	{
		printf("*****TEST PASSED***** cost of nonexistent_card is correct (%d)\n\n", returnedCost);
	}
	else
	{
		printf("*****TEST FAILED***** cost of nonexistent_card is incorrect (%d)\n\n", returnedCost);
		allTestsPassed = 0;
	}
	
	// reset returnedCost for next test
	returnedCost = -99;
	
	// TEST 29: check if we passed all of the tests
	printf("TEST 29: Check if we passed all of the tests...\n");
	
	// test value of allTestsPassed (1 = true: all tests were passed, 0 = false: at least one test failed)
	if (allTestsPassed == 1)
	{
		printf("*****ALL TESTS PASSED***** the getCost() function passed all of the unit tests\n\n");
	} 
	else 
	{
		printf("*****FAILED***** the getCost() function failed at least 1 of the unit tests above (refer to individual test results)\n\n");
	}
}
