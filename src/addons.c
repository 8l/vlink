#include <stdio.h>

char toupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

char tolower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

long long __moddi3(long long a, long long b) {
    long long result = a % b;
    if (result < 0) {
        result += b;
    }
    return result;
}

long long __divdi3(long long a, long long b) {
    long long result = a / b;
    if (a < 0 && a % b != 0) {
        result--;
    }
    return result;
}
