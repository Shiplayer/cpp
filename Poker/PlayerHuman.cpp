#include <iostream>
#include <sstream>
#include <cstdio>

#include "PlayerHuman.h"

using namespace std;

//make bet, return -1 if bad input(not digits)
uint32_t playerH::bet(uint32_t sum, Board state) {
    printf("[%s] Your sum to bet(min = %i),0 for check/fold:\n",this->getName().c_str(),sum);
    string s;
    getline(cin, s);
    for (uint32_t i = 0; i < s.size(); i++) {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return -1;
    }
    stringstream ss;
    ss << s;
    long as;
    ss >> as;
    return as;
}
