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
	value = BigInteger(buf);
	return in;
}

BigInteger BigInteger::operator+(BigInteger const& right) const{
	BigInteger ans = *this;

	int buf = 0;

	if(ans.sign ^ right.sign){
		BigInteger buf_right = right;
		ans = ans - right;
		/*bool sign = false;
		if(ans.number.size() == right.number.size()){
			for(size_t i = ans.number.size(); i > 0; i--){
				if(ans.number[i] > right.number.size())
					sign = (ans.number[i] > right.number[i] ? ans.sign : right.sign);
			}
			for(size_t i = 0; i < ans.number.size(); i++){
				cout<<ans.number[i] << " vs " << right.number[i] <<endl;
				buf += (ans.sign ? -ans.number[i] : ans.number[i]) + (right.sign ? -right.number[i] : right.number[i]);
				cout << "buf1: " << buf;
				if(buf < 0){
					buf = (buf + 10)*(-1);
				}
				cout << "\tbuf2: " << buf;
				ans.number[i] = (buf < 0 ? -buf : buf)  % 10;
				buf /= 10;
				cout << "\tbuf3: " << buf << endl;
			}
			for(size_t i = ans.number.size(); i > 0; i--)
				if(ans.number[i - 1] != 0){
					ans.number.erase(ans.number.begin() + i, ans.number.end());
					break;
				}
			 		
		} //else if(ans.number.size() > right.number.size()){
			
		//}*/
		return ans;
	}
	
	vector<unsigned int> result;
	
	size_t size = ans.number.size() > right.number.size() ? ans.number.size() : right.number.size();


	for(size_t i = 0; i < size; i++){
		buf += (i < ans.number.size() ? ans.number[i] : 0)+ (i < right.number.size() ? right.number[i] : 0);
		cout<<buf<<endl;
		result.push_back(buf % 10);
		buf /= 10;
	}
	if(buf!=0)
		result.push_back(buf);
	
	ans.number = result;
	ans.sign = ans.sign & right.sign;
	return ans;
}

BigInteger BigInteger::operator-(BigInteger const &right) const {
	BigInteger ans = *this;
	int buf = 0;
	if(ans.sign ^ right.sign){
		bool sign = ans.sign & !right.sign; 
		BigInteger buf_right = right;
		ans.sign = false;
		buf_right.sign = false;
		ans = ans + buf_right;
		ans.sign = sign;
		return ans;
	}
	bool flag;
	if(ans.number.size() == right.number.size()){
		for(size_t i = ans.number.size(); i > 0; i--)
			if(ans.number[i-1] != right.number[i-1]){
				flag = ans.number[i-1] > right.number[i-1];
				break;
			}
	} else 
		flag = ans.number.size() > right.number.size();

	cout<<flag<<endl;
	if(!(ans.sign ^ right.sign)){
		int digit = 0;
		if(flag){
			for(size_t i = 0; i < ans.number.size(); i++){
				buf += ans.number[i] - (i < right.number.size() ? right.number[i] : 0) - digit;
				digit = 0;
				if(buf < 0){
					buf = buf + 10;
					digit = 1;
				}
				ans.number[i] = buf % 10;
				buf = 0;
			}
		} else {
			for(size_t i = 0; i < right.number.size(); i++){
				buf += right.number[i] - (i < ans.number.size() ? ans.number[i] : 0) - digit;
				cout<<"buf: " << buf<<endl;
				digit = 0;
				if(buf < 0){
					buf += 10;
					digit = 1;
				}
				if(i < ans.number.size())
					ans.number[i] = buf%10;
				else
					ans.number.push_back(buf%10);
				buf = 0;
			}
			ans.sign = false;
		}
	} else{
		int digit = 0;
	}
	return ans;	
}
