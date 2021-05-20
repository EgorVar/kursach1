#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <valarray>
#include <cmath>
#include "functions.h"





void FindMinimumOutputSignal(int N, double* ArrOut) {
    double minimumSignal = ArrOut[0];

    for (int i = 1; i < (N + 1); i++) {
        if (ArrOut[i] < minimumSignal) minimumSignal = ArrOut[i];
    }

    printf("Минимальный выходной сигнал: %4.4lf\n", minimumSignal);

    system("pause");
    system("cls");
}