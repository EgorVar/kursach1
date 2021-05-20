#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <valarray>
#include <cmath>


void TxtFromFile(char* filename, char* strcatn);

void FormArrT(int N, double tstart, double tend, double** ArrT, double* dt);

void FormArrUin(int N, double U, double a1, double* ArrT, double** ArrUin);

void FormArrOut(int N, double Uin1, double Uin2, double a2, double b, double* ArrUin, double** ArrUout);

void OutputArrays(int N, double* ArrT, double* ArrUin, double* ArrUout);

void OutputResultToFile(char* filename, int N, double* ArrT, double* ArrUin, double* ArrUout, double dt);

void FindMinimumOutputSignal(int N, double* ArrUout);

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


void FindMinimumOutputSignal(int N, double* ArrOut) {
    double minimumSignal = ArrOut[0];

    for (int i = 1; i < (N + 1); i++) {
        if (ArrOut[i] < minimumSignal) minimumSignal = ArrOut[i];
    }

    printf("Минимальный выходной сигнал: %4.4lf\n", minimumSignal);

    system("pause");
    system("cls");
}
