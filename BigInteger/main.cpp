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
	cout<< "result sub: " << big - big2<<endl;
	cout<<"big: ";
	cin>>big;
	cout<<"big2: ";
	cin>>big2;
	cout<<"result add: " << big + big2 <<endl;
	return 0;
}
