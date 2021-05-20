#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void TxtFromFile(char* filename, char* strcatn);

void FormArrT(int N, double tstart, double tend, double** ArrT, double* dt);

void FormArrUin(int N, double U, double a1, double* ArrT, double** ArrUin);

void FormArrOut(int N, double Uin1, double Uin2, double a2, double b, double* ArrUin, double** ArrUout);

void OutputArrays(int N, double* ArrT, double* ArrUin, double* ArrUout);

void OutputResultToFile(char* filename, int N, double* ArrT, double* ArrUin, double* ArrUout, double dt);

void FindMinimumOutputSignal(int N, double* ArrUout);


#endif
