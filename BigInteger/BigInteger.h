#ifndef __BIGINTEGER_H__
#define __BIGINTEGER_H__
#include <vector>
#include <string>

using namespace std;

class BigInteger{
private:
	std::vector<unsigned int> number;
	bool sign;
	BigInteger add(BigInteger, const BigInteger);
public:
	BigInteger();
	BigInteger(int);
	BigInteger(string const);
	
	BigInteger(BigInteger const&);
	BigInteger(BigInteger &other) = default;

	void print_numbers();

	friend string to_string(BigInteger const&); //exception
	friend ostream &operator<<(ostream&, BigInteger const&);
	friend istream &operator>>(istream&, BigInteger&); //exception

//	BigInteger operator+(const BigInteger& left, const BigInteger& right);

//	BigInteger &operator+(BigInteger const&);
	BigInteger operator+(BigInteger const&) const; //  :(
//	BigInteger &operator-(BigInteger const&);
//	BigInteget operator-(BigInteger const&) const; //  :(
//	BigInteger &operator*(BigInteger const&);
//	BigInteger operator*(BigInteger const&) const; //  :(
//	BigInteger &operator+=(BigInteger const&);
//	BigInteger &operator-=(BigInteger const&);
//	BigInteger &operator*=(BigInteger const&);
	BigInteger &operator=(BigInteger const &right) = default;
};

string to_string(BigInteger const&);

ostream &operator<<(std::ostream&, BigInteger const&);

istream &operator>>(std::istream&, BigInteger&);

#endif // __BIGINTEGER_H__
