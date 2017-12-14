// 14th December 2017
// Paul Beomcheol Kim
// This is a basic version calculating a bond price, including coupon and its amortizing types.
// later on, I will put day convention and other critical calculator that may essential to make a strategies -duration and -convexity
#include <iostream>
#include "Bond.h"
using namespace std;

int main(int argc, const char * argv[]) {



	Bond complexBond(1000, 0.1, 0.12, 10, 'S');
	
	complexBond.getBondPrice();
	return 0;
}

