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




int main() {
    setlocale(LC_ALL, "Russian");

    system("cls");

    char dataFileName[128] = "dataFile.txt";
    char miniatureFileName[128] = "miniature.txt";
    char outputFile[128] = "outputData.txt";
    char strcatn[2048] = "";

    TxtFromFile(miniatureFileName, strcatn);

    printf("%s", strcatn);

    char menuFileName[128] = "menu.txt";
    char menustr[2048] = "";

    TxtFromFile(menuFileName, menustr);


    int N;
    double U = 5,
        tstart = 3.14,
        tend = 6.28,
        a1 = 0.5,
        a2 = 2.5,
        b = 10,
        Uin1 = 10,
        Uin2 = 2;


    int choise = 0;

    int filesData;

    double* ArrT = NULL;

    double* ArrUin = NULL;

    double* ArrUout = NULL;

    double dt;

    do {
        printf("%s", menustr);
        scanf_s("%d", &choise);

        system("cls");

        switch (choise) {
        case 1:
            printf("Введите N: ");
            scanf_s("%d", &N);
            FormArrT(N, tstart, tend, &ArrT, &dt);
            FormArrUin(N, U, a1, ArrT, &ArrUin);
            FormArrOut(N, Uin1, Uin2, a2, b, ArrUin, &ArrUout);

            printf("Cформированный массив: \n");
            OutputArrays(N, ArrT, ArrUin, ArrUout);
            break;
        case 2:
            FindMinimumOutputSignal(N, ArrUout);
            break;
        case 3:
            OutputResultToFile(outputFile , N, ArrT, ArrUin, ArrUout, dt);
            break;
        case 4:
            printf("Программа завершена\n");
            return 0;
            break;
        default:
            printf("main: Нет такого пункта меню");
            break;
        }
    }

    while (1);




    //getch();
    return 0;
}



