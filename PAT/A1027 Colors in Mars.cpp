//
// Created by shaob on 2020/2/25.
//

//
// Created by shaob on 2020/2/25.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int result[3][2];
char num2char[13] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'
};

void fit2base13(int number, int pos) {
    int digit = 0;
    do {
        result[pos][digit++] = number % 13;
        number /= 13;
    } while (number != 0);
}

int pat_solver() {
    fill(result[0], result[0] + 6, 0);
    printf("#");
    for (int i = 0; i < 3; ++i) {
        int num;
        scanf("%d", &num);
        fit2base13(num, i);
        printf("%c%c", num2char[result[i][1]], num2char[result[i][0]]);
    }
}