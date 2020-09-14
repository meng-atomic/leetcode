#include <iostream>
#include <stdio.h>
#include <string.h>

static int count = 0;

void printNumber(char* number) {
    int pos = 0;
    while (number[pos] == '0') {
        pos++;
    }
    while (number[pos] != '\0') {
        printf("%c", number[pos++]);
    }
    printf(", ");
    count++;
}

bool increment(char* number) {
    int pos = 0;
    while (number[pos] != '\0') {
        pos++;
    }
    pos--;
    if (number[pos] == '9') {
        int shift = pos - 1;
        while (number[shift] == '9') {
            number[shift] = '0';
            shift--;
        }
        if (shift < 0) {
            return false;
        }
        number[pos] = '0';
        number[shift] += (char)(1);
    } else {
        number[pos] += (char)(1);
    }
    return true;
}

void printMaxNDigits(int n) {
    if (n < 0 || n > 10) {
        return;
    }
    char* number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';
    while (increment(number)) {
        printNumber(number);
    }
    printf("\ntotal number count: %d\n", count);
    delete [] number;
}

int main() {
    printMaxNDigits(5);
}