#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define LEN 3

void user_mult(double*, double*, double*);
void user_mult(int*, int*, int*);
double user_mult(char*, char*, char*);



int main()
{
	setlocale(0, "RUS");

	/********************************************/
	/*------------УМНОЖЕНИЕ МАТРИЦ--------------*/
	/********************************************/

	double matr_1[LEN][LEN] = { {5, 2, 4},
								{10, 6.3, -5},
								{-1.11, 0, 39} };
	double matr_2[LEN][LEN] = { {-4, 9, 0.532},
								{10.1, 1, -75},
								{0, 123, 3.9} };
	double matr_rez[LEN][LEN];

	user_mult(*matr_1, *matr_2, *matr_rez);

	cout << endl;
	cout << "Произведение 2 х матриц:" << endl;

	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < LEN; j++)
			cout << matr_rez[i][j] << ' ';
		cout << endl;
	}

	/********************************************/
	/*------УМНОЖЕНИЕ МАТРИЦЫ НА ВЕКТОР---------*/
	/********************************************/

	int matr_3[LEN][LEN] = { {5, 2, 4},
							{10, 63, -5},
							{-111, 0, 39} };
	int vect_2[LEN] = {-4, 9, 1};
	int vect_rez[LEN];

	user_mult(*matr_3, vect_2, vect_rez);

	cout << endl;
	cout << "Произведение матрицы на вектор:" << endl;

	for (int i = 0; i < LEN; i++)
		cout << vect_rez[i] << endl;

	/********************************************/
	/*------------УМНОЖЕНИЕ 3x СТРОК------------*/
	/********************************************/

	double str_rez; char a[] = "10,0", b[] = "5,1", c[] = "25,2";

	str_rez = user_mult(a, b, c);

	cout << endl;
	cout << "Произведение 3х строк: " << endl;
	cout << str_rez << endl;
}

void user_mult(double* arg1, double* arg2, double* arg3)
{
	int i, j, k;
	for (i = 0; i < LEN; i++)
		for (j = 0; j < LEN; j++)
		{
			*(arg3 + i * LEN + j) = 0;
			for (k = 0; k < LEN; k++)
				*(arg3 + i * LEN + j) += *(arg1 + i * LEN + k) * *(arg2 + k * LEN + j);
		}
}

void user_mult(int* arg1, int* arg2, int* arg3)
{
	for (int i = 0; i < LEN; i++)
	{
		int temp = 0;
		for (int j = 0; j < LEN; j++)
		{
			temp += arg1[i * LEN + j] * arg2[j];
		}
		arg3[i] = temp;
	}
} 

double user_mult(char* arg1, char* arg2, char* arg3)
{
	return (atof(arg1) * atof(arg2) * atof(arg3));
}
	
	

	
