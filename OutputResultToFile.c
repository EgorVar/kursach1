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




void OutputResultToFile(char* filename, int N, double* ArrT, double* ArrUin, double* ArrUout, double dt) {
    FILE* outputFile = fopen(filename, "w");

    fputs("#№       t            Uin          Uout\n", outputFile);

    for (int i = 0; i < (N + 1); i++) {
        fprintf(outputFile, "%d  %12.4lf  %12.4lf  %12.4lf\n", i, ArrT[i], ArrUin[i], ArrUout[i]);
    }
    fprintf(outputFile, "#dt = %4.4lf\n", dt);

    fclose(outputFile);

    printf("Данные записаны в файл. Нажмите Enter, чтобы вернуться в меню\n");
    system("pause");
    system("cls");
}
