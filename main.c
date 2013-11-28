#include <stdlib.h>
#include <stdio.h>
#include <string.h>



struct coins {
	int quarters;
	int dimes;
	int nickels;
	int pennies;
};
typedef struct coins coins_t;

int calc_change(int iVal, coins_t *pCoins);
void dump_coins(coins_t *pCoins);

int main(int argc, char *argv[]) {

	int iRC;
	int iGiven;
	coins_t sCoins;

	iRC=EXIT_SUCCESS;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <given amount>\n", argv[0]);
		iRC=EXIT_FAILURE;
		exit(iRC);
	}

	
	iGiven = atoi(argv[1]);
	bzero(&sCoins,sizeof(coins_t));

	printf("Amount given %d\n",iGiven);

	while (0 != iGiven) {
		iGiven = calc_change(iGiven,&sCoins);
	} 
	
	dump_coins(&sCoins);
	
	exit(iRC);

}


int calc_change(int iVal, coins_t *pCoins) {

	int tmp;

	printf("iVal =  %d\n", iVal);
	if (NULL == pCoins) {
		return -1;
	}

	tmp = iVal/25;

	if ( tmp > 0) {
		pCoins->quarters += tmp;
		iVal -= tmp*25;
	}

	tmp = iVal/10;

	if ( tmp > 0) {
		pCoins->dimes += tmp;
		iVal -= tmp*10;
	}

	tmp = iVal/5;

	if ( tmp > 0) {
		pCoins->nickels += tmp;
		iVal -= tmp*5;
	}


	if ( iVal > 0) {
		pCoins->pennies += iVal;
		iVal = 0;
	}
	return iVal;
}

void dump_coins(coins_t *pCoins) {
	if (NULL == pCoins) {
		return;
	}

	printf("Quarters = %d\n", pCoins->quarters);
	printf("Dimes = %d\n", pCoins->dimes);
	printf("Nickels = %d\n", pCoins->nickels);
	printf("Pennies = %d\n", pCoins->pennies);

}








