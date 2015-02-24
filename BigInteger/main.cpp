#include <iostream>
#include <string>
#include "BigInteger.h"

using namespace std;

int main(int argc, char const* argv[]){
	BigInteger big;
	cout<< "big: ";
	cin>>big;
	BigInteger big2;
	cout<< "big2: ";
	cin>> big2;
	cout<< "result: " << big + big2<<endl;
	return 0;
}
