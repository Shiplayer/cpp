#include <iomanip>
#include <iostream>
#include <functional>
#include <bits/stl_algo.h>
#include "BigInteger.h"

using std::istream;
using std::ostream;

using namespace std;

BigInteger::BigInteger(int x) {
    sign = x < 0 ? true : false;
    x = x < 0 ? -x : x;
    while (x != 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
}

BigInteger::BigInteger() {
    sign = false;
    digits.push_back(0);
}

BigInteger::BigInteger(std::string const &str) {
    if (str[0] == '-')
        sign = true;
    else
        sign = false;
    for (int i = str.length() - 1; i >= 0; i--) {
        if ((i == 0 )& (str[0] == '-')) continue;
        if (str[i] < '0' || str[i] > '9')
            throw invalid_argument("Only digits in number!");
        digits.push_back(str[i] - '0');
    }

}

//sums two positive integers
std::vector<unsigned> add(std::vector<unsigned> a, std::vector<unsigned> b) {
    std::vector<unsigned> result;
    unsigned remain = 0, r = 0;
    unsigned maxSize = a.size() > b.size() ? a.size() : b.size();
    for (unsigned i = 0; i < maxSize; i++) {
        r = (i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0) + remain;
        remain = r / 10;
        result.push_back(r % 10);
    }
    if (remain > 0)
        result.push_back(remain);
    return result;
}

//subtrack  b from a (a >=b)
std::vector<unsigned> sub(std::vector<unsigned> a, std::vector<unsigned> b) {
    vector<unsigned> result;
    int remain = 0, r = 0;
    for (unsigned i = 0; i < a.size(); i++) {
        r = (i < a.size() ? a[i] : 0) - (i < b.size() ? b[i] : 0) - remain;
        remain = 0;
        if (r < 0) {
            remain = 1;
            r = 10 + r;
        }
        result.push_back(r);
    }
    if (remain > 0)
        result.push_back(remain);
    return result;
}

//multiplies vector and int digit,b =0..9
std::vector<unsigned> mul(std::vector<unsigned> a, int b, int n) {
    vector<unsigned> result;
    if (b == 0) return result;
    int remain = 0, r = 0;
    for (unsigned i = 0; i < a.size(); ++i) {
        r = a[i] * b + remain;
        remain = r / 10;
        result.push_back(r % 10);
    }
    if (remain > 0)
        result.push_back(remain);
    for (int i = 0; i < n; ++i) {
        result.insert(result.begin(), 0);
    }
    return result;
}
/*BigInteger& BigInteger::operator+(BigInteger const &right) {
    BigInteger left(this);

    if ((left).sign == right.sign) {
        (left).digits = add((left).digits, right.digits);
        return (left);
    }
    return (left);/*

    vector<unsigned> a = left.digits;
    vector<unsigned> b = right.digits;
    for (unsigned l = 0; l < a.size(); ++l) {
        cout << a[l];
    }
    cout << endl;
    for (unsigned l = 0; l < b.size(); ++l) {
        cout << b[l];
    }
    cout << endl;
    //fill the less number to equal numbers length
    int as = a.size();
    int bs = b.size();
    int t = abs(as - bs);
    for (int j = 0; j < t; ++j) {
        if (as < bs)a.push_back(0);
        if (bs < as)b.push_back(0);
    }
    //find min and max
    int aLessThanB = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            aLessThanB = a[i] < b[i] ? 0 : 2;
            break;
        }
    }
    if (aLessThanB == 1) {
        for (unsigned k = 0; k < left.digits.size(); ++k)
            left.digits[k] = 0;
        left.sign = false;
    }

    else if (aLessThanB == 0) {
        left.digits = sub(b, a);
        left.sign = right.sign;
    }
    else {
        left.digits = sub(a, b);
    }

    //return *this;
    return left;

}*/

BigInteger &BigInteger::operator+(BigInteger const &right) {
    if (sign == right.sign) {
        digits = add(digits, right.digits);
        return *this;
    }
    vector<unsigned> a = digits;
    vector<unsigned> b = right.digits;
    for (int l = 0; l < a.size(); ++l) {
        cout << a[l];
    }
    cout << endl;
    for (int l = 0; l < b.size(); ++l) {
        cout << b[l];
    }
    cout << endl;
    //fill the less number to equal numbers length
    int as = a.size();
    int bs = b.size();
    int t = abs(as - bs);
    for (int j = 0; j < t; ++j) {
        if (as < bs)a.push_back(0);
        if (bs < as)b.push_back(0);
    }
    //find min and max
    int aLessThanB = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            aLessThanB = a[i] < b[i] ? 0 : 2;
            break;
        }
    }
    if (aLessThanB == 1) {
        for (int k = 0; k < digits.size(); ++k)
            digits[k] = 0;
        sign = false;
    }

    else if (aLessThanB == 0) {
        digits = sub(b, a);
        sign = right.sign;
    }
    else {
        digits = sub(a, b);
    }

    return *this;

}

BigInteger& BigInteger::operator-(BigInteger const &right) {
    std::vector<unsigned> a = digits;
    std::vector<unsigned> b = right.digits;
    //fill the less number to equal numbers length
    int as = a.size();
    int bs = b.size();
    int t = abs(as - bs);
    for (int j = 0; j < t; ++j) {
        if (as < bs)a.push_back(0);
        if (bs < as)b.push_back(0);
    }
    //find min and max
    bool aLessThanB = false;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            aLessThanB = a[i] < b[i];
            break;
        }
    }

    if (aLessThanB) {
        vector<unsigned> v = b;
        b = a;
        a = v;
    }
    if (sign & right.sign || (!sign) & (!right.sign)) {
        digits = sub(a, b);
        if (aLessThanB)
            sign = !sign;
    }
    else {
        digits = add(a, b);
    }


    return *this;
}

//multiply two BigInteger "as in school"
BigInteger& BigInteger::operator*(BigInteger const &right) {
    BigInteger left = *this;
    sign = (left.sign ^ right.sign);
    for (unsigned i = 0; i < digits.size(); ++i) {
        digits[i] = 0;
    }

    for (unsigned i = 0; i < right.digits.size(); ++i) {
        digits = add(digits, mul(left.digits, right.digits[i], i));
    }
    return *this;
}


std::string to_string(BigInteger const &a) {
    std::string str;
    for (unsigned i = 0; i < a.digits.size(); i++)
        str += '0' + a.digits[i];
    if (a.sign)
        str += '-';
    reverse(str.begin(), str.end());
    if (str.size() == 0) str.push_back('0');
    return str;
}


ostream &operator<<(ostream &a, const BigInteger &b) {
    a << to_string(b);
    return a;
}


istream &operator>>(istream &a, BigInteger &b) {
    string c;
    a >> c;
    b = BigInteger(c);
    return a;
}

//need to gtests
bool operator==(const BigInteger &left, const BigInteger &right) {
    cout << left << "==" << right << endl;
    std::vector<unsigned> a = left.digits;
    std::vector<unsigned> b = right.digits;
    //fill the less number to equal numbers length
    int as = a.size();
    int bs = b.size();
    int t = abs(as - bs);
    for (int j = 0; j < t; ++j) {
        if (as < bs)a.push_back(0);
        if (bs < as)b.push_back(0);
    }
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    if (a[0] == 0) return true;
    return ((left.sign == right.sign));
}

BigInteger &BigInteger::operator+=(BigInteger const &right) {
    return *this + right;
}

BigInteger &BigInteger::operator-=(BigInteger const &right) {
    return *this - right;
}

BigInteger &BigInteger::operator*=(BigInteger const &right) {
    return *this * right;
}
