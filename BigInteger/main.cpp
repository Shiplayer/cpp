#include <iostream>
#include <string>
#include "BigInteger.h"

using namespace std;

int main(int argc, char const* argv[]){
	const BigInteger big("12341");
	const BigInteger big2(15);
	cout<< big + big2 <<endl;
	cout<< big - big2 <<endl;
	cout<< big * big2 <<endl;
	return 0;
}
