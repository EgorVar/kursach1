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




void TxtFromFile(char* filename, char* strcatn) {
    char buffer[2048] = "";

    FILE* openFile = fopen(filename, "r");

    if (openFile != NULL) {
        while (fgets(buffer, 127, openFile) != NULL) {
            strcat(strcatn, buffer);
        }
    }
    else printf("TxtFromFile: Невозможно открыть файл - %s", filename);

    fclose(openFile);
}


void FormArrT(int N, double tstart, double tend, double** ArrT, double* dt) {

    double currT = tstart;
    free(*ArrT);
    *ArrT = (double*)malloc(sizeof(double) * (N + 1));

    *dt = (tend - tstart) / N;

    for (int i = 0; i <= N; i++) {
        (*ArrT)[i] = currT;
        currT += *dt;
    }

}

void FormArrUin(int N, double U, double a1, double* ArrT, double** ArrUin) {
    free(*ArrUin);
    *ArrUin = (double*)malloc(sizeof(double) * (N + 1));

    for (int i = 0; i <= N; i++) {
        (*ArrUin)[i] = U * powf(2.71, (-a1 * ArrT[i])) * sin(ArrT[i]);
    }

}


void FormArrOut(int N, double Uin1, double Uin2, double a2, double b, double* ArrUin, double** ArrUout) {
    free(*ArrUout);
    *ArrUout = (double*)malloc(sizeof(double) * (N + 1));


    for (int i = 0; i < (N + 1); i++) (*ArrUout)[i] = a2 * ArrUin[i] + b;

}


void OutputArrays(int N, double* ArrT, double* ArrUin, double* ArrUout) {
    printf("n          |  t          |  Vin          |  Vout          \n");
    for (int i = 0; i < (N + 1); i++) {
        printf("%-10d  %7.2lf  %14.4lf  %14.4lf \n", i, ArrT[i], ArrUin[i], ArrUout[i]);
    }
    system("pause");
    system("cls");
}