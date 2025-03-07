#include <iostream>
#include <string>
#include "hash.h"
#include <cmath>
#include <climits>

using namespace std;

int hash_function(string text) {
    // Implement your own hash function here
    int hash = 1;
    double multiplier = tan(text.size() * text.at((text.size() * (text.at(31 % text.size()) + text.at(23 % text.size()))) % text.size()));
    int hash2 = 1;

    for(char c: text) {
        hash = (int)((double)(hash * 31 * c) * multiplier);
        multiplier += c;
        hash += (int)tan(multiplier);
        hash2 = (INT_MAX ^ hash ^ hash2) << 2;
    }

    hash ^= hash2;

    return (hash >= 0) ? hash: -1 * hash;
}