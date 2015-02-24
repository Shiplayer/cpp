#include <iostream>
#include <string>
#include <algorithm>
#include "BigInteger.h"

using namespace std;

BigInteger::BigInteger(){
	number.push_back(0);
	sign=false;
}

BigInteger::BigInteger(int value){
	if(value < 0){
		sign = true;
		value = -value;
	} else sign = false;

	while(value != 0){
		number.push_back(value % 10);
		value /= 10;
	}
	//reverse(number.begin(), number.end());
	
}

BigInteger::BigInteger(string const value){
	if(value[0] == '-'){
		sign = true;
		//value.erase(value.begin());
	} else sign = false;
	for(size_t i = 0; i < value.size(); i++){
		if(value[i] == '-') continue;
		if(value[i] >= '0' && value[i] <= '9')
			number.push_back(value[i] - '0');
		//else throw invalid_argument("Only numbers!");
	}
	reverse(number.begin(), number.end());
}

BigInteger::BigInteger(BigInteger const &other){
	number = other.number;
	sign = other.sign;
}

void BigInteger::print_numbers(){
	for(size_t i = 0; i < number.size(); i++){
		cout<<number[i];
	}
	cout<<endl;
}

/*BigInteger& BigInteger::operator+(BigIntger const &right){
	
}*/

string to_string(BigInteger const& value){
	string buf = "";
	for(size_t i = 0; i < value.number.size() ; i++){
		buf += to_string(value.number[i]);
	}
	if(value.sign)
		buf += "-";
	reverse(buf.begin(), buf.end());
	return buf;
}

ostream &operator<<(ostream& out, BigInteger const& value){
	out << to_string(value);
	return out;
}

istream &operator>>(istream& in, BigInteger &value){
	string buf;
	in >> buf;
	cout<<"istream " << buf << endl;
	value = BigInteger(buf);
	return in;
}

BigInteger BigInteger::operator+(BigInteger const& right) const{
	BigInteger ans = *this;

	if(ans.sign ^ right.sign){
			int buf = 0;
		if(ans.number.size() == right.number.size()){
			for(size_t i = 0; i < ans.number.size(); i++){
				cout<<ans.number[i] << " vs " << right.number[i] <<endl;
				buf += (ans.sign ? -ans.number[i] : ans.number[i]) + (right.sign ? -right.number[i] : right.number[i]);
				if(buf < 0){
					buf = (buf + 10)*(-1);
				}
				ans.number[i] = (buf < 0 ? -buf : buf)  % 10;
				buf /= 10;
			}
			for(size_t i = ans.number.size(); i > 0; i--)
				if(ans.number[i] != 0){
					ans.number.erase(ans.number.end() - (i - 1 - ans.number.size()), ans.number.end());
					break;
				}
			 		
		}
		return ans;
	}
	
	vector<unsigned int> result;
	
	size_t size = ans.number.size() > right.number.size() ? ans.number.size() : right.number.size();
	int buf = 0;

	for(size_t i = 0; i < size; i++){
		buf += (i < ans.number.size() ? ans.number[i] : 0)+ (i < right.number.size() ? right.number[i] : 0);
		result.push_back(buf % 10);
		buf /= 10;
	}
	
	ans.number = result;
	ans.sign = !(ans.sign & right.sign);
	return ans;
}

BigInteger BigInteger::add(BigInteger left, const BigInteger right){
}
