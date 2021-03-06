// Project2019.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
int Const_Row = 0;
int Const_Col = 0;
const int row = 50;
const int col = 50;
int Min_Rows = 100;
int Min_Cols = 100;
double d = 0;
void Func_For_Inversed_Matrix();
double Matrix_Determ[row][col] = { 0.0, };
void Cofactor_Of_Matrix(double matrix[][col], double matrix_help[][col], int new_row, int new_column, int col1);
double Determinant_Of_Matrix(double matrix[][col], int col1);
void Adungirane_Matrica(double matrix[][col], double matrix_help[][col],int row);
double Inverse[col][col] = { 0, };
double  Matrix[row][col] = { 0, };
double  Matrix_Help[row][col] = { 0, };
double Transposed_Matrix[row][col] = { 0, };
double Matrix_Help_Multiplication[row][col] = { 1, };
double Matrix_Sum_For_Multiplication[row][col] = { 0, };
double Vector[row] = { 0, };
double Vector_Help[row] = { 0, };
void Main_Menu();
void Main_Page();
void Menu_Multiplication();
void Multiplication();
void Input_Vector(double vector[], int length);
void Print_Vector(double vector[], int length);
void Dot_Product(double vector[], double vector_help[], int length);
void Cross_Product(double vector[], double vector_help[]);
void Matrix_Vector_Product(double matrix_help[][col], double vector[], int length);
void Input_Matrix(double matrix[][col], int row, int col);
void Print_Matrix(double matrix[][col], int row1, int col1);
void Multiplication_Of_Matrices(double matrix1[][col], double matrix2[][col], int row1, int col1, int row2, int col2);
void Func_For_Checking_Identity();
void Sum_Of_Matrix();
void Substraction_Of_Matrix();
void Print_Transposed_Matrix();
void Sum_Or_Sub_Of_Matrices();
void Func_For_Transposed_Matrix(double matrix[][col], int row, int col);
void Dot_Product_Program();
void Cross_Product_Program();
void Func_For_Normalizing_Vector(double vector[],int length);
void Normalize_Vector();

void Normalize_Vector() {
	cout << "Molq vuvedete duljinata na vectora:-> ";
	int length;
	cin >> length;
	cout << endl;
	cout << "Molq vuvedete vektora s  duljina: " << length << ":-> ";
	Input_Vector(Vector_Help, length);
	cout << endl;
	Func_For_Normalizing_Vector(Vector_Help, length);
	cout << endl;
	Print_Vector(Vector_Help, length);
	cout << "Molq vuvedete symbol, za da se vurnete obratno v glavnoto menu" << endl;
	cout << "Za da se vurnete v glavnoto menu,Molq vuvedete:  'm'" << endl;
	cout << "Za da se izlezete ot programata, Molq vuvedete: 'e' " << endl;
	cout << "Molq vuvedi simvol:-> ";
	char symbol;
	cin >> symbol;
	cout << endl;
	switch (symbol) {
	case'm':Main_Menu(); break;
	case'e':exit(0); break;
	}
	
}
void Func_For_Normalizing_Vector(double vector[],int length) {
	double Length_Vector = 0;
	for (int i = 0; i < length; i++) {
		Length_Vector += pow(vector[i], 2);
	}
	Length_Vector = sqrt(Length_Vector);
	for (int i = 0; i < length; i++) {
		vector[i] = vector[i] / Length_Vector;
	}

}
void Func_For_Checking_Identity() {
	int row;
	cout << "Molq vuvedete kvadratna matrica, s broi na redovete i kolonite : ";
	cin >> row;
	cout << endl;
	cout << "Molq vuvedete matricata,za koqto shte se proverqva dali moje da se preobrazuva : ";
	Input_Matrix(Matrix_Help, row, row);
	double determ = Determinant_Of_Matrix(Matrix_Help, row);
	if (determ == 0) {
		cout << "Matricata ne moje da se preobrazuva do edinichna!";
	}
	else { 
		cout << "Matricata moje da se preobrazuva do edinichna!" << endl;
	}
	cout << "Molq vuvedete symbol, za da se vurnete obratno v glavnoto menu" << endl;
	cout << "Za da se vurnete v glavnoto menu,Molq vuvedete:  'm'" << endl;
	cout << "Za da se izlezete ot programata, Molq vuvedete: 'e' " << endl;
	cout << "Molq vuvedi simvol:-> ";
	char symbol;
	cin >> symbol;
	cout << endl;
	switch (symbol) {
	case'm':Main_Menu(); break;
	case'e':exit(0); break;
	}

}
void Func_For_Inversed_Matrix() {
	cout << "Molq vuvedete kvadratna matrica ! :) " << endl;
	int row1;
	cout << "Molq vuvedete redovete na  matricata!->  ";
	cin >> row1;
	cout << endl;
	int col1;
	cout << "Molq vuvedete kolonite na  matricata!->  ";
	cin >> col1;
	cout << endl;
	if (col1 != row1) {
		cout << "Takava Matrica ne moje da se preobrazuva do edinichna,vrushtame vi obratno v glavnoto menu! " << endl;
		Main_Menu();
	}
	Input_Matrix(Matrix_Help, row1, col1);
	cout << endl;
	double determ = Determinant_Of_Matrix(Matrix_Help, row1);
	if (determ == 0) {
		cout << "Molq vuvedete pravilna matrica s nenuleva determinanta ! " << endl;
		cout << "Shte budete vurnete v menuto za svejdane do obratna matrica otnovo! " << endl;

	}
	double help[col][col];
	Adungirane_Matrica(Matrix_Help, help, row1);
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < row1; j++) {
			Inverse[i][j] = help[i][j] / determ;

		}
	}
	Func_For_Transposed_Matrix(Inverse, row1, row1);
	Print_Matrix(Inverse, row1, row1);
	cout << endl;
	cout << "Molq vuvedete symbol, za da se vurnete obratno v glavnoto menu" << endl;
	cout << "Za da se vurnete v glavnoto menu,Molq vuvedete:  'm'" << endl;
	cout << "Za da se izlezete ot programata, Molq vuvedete: 'e' " << endl;
	cout << "Molq vuvedete simvol:->";
	char symbol;
	cin >> symbol;
	cout << endl;
	switch (symbol) {
	case'm':Main_Menu(); break;
	case'e':exit(0); break;
	}
}
void Input_Matrix(double matrix[][col], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cin >> matrix[i][j];
		}
	}
}
void Determinant_Of_Matrix() {
	cout << "Vie izbrahte da namerete determinantata na proizvolna kvardratna  matrica " << endl;
	cout << "Molq vuvedete kvadratna matrica!! V protiven sluchai shte se vurnete v menuto!" << endl;
	int row1;
	cout << "Molq vuvedete redovete na  matricata!->  ";
	cin >> row1;
	cout << endl;
	int col1;
	cout << "Molq vuvedete kolonite na matricata!->  ";
	cin >> col1;
	cout << endl;
	if (row1 != col1) {
		cout << "Molq vie ne ste vuveli matrica, koqto da otgovarq na iziskvaniqta ! " << endl;
		Determinant_Of_Matrix();
	}
	Input_Matrix(Matrix_Determ, row1);
	cout << endl;
	double determ = Determinant_Of_Matrix(Matrix_Determ, row1);
	cout << "Determinantata na matricata: " << determ;
	cout << endl;
	cout << "Molq vuvedete pravilen symbol!!" << endl;
	cout << "Za da se vurnete v menuto, Molq izberete : 'm' " << endl;
	cout << "Za da izlezete ot programata,Molq izberete: 'e' " << endl;
	char symbol;
	cin >> symbol;
	cout << endl;
	switch (symbol) {
	case 'm':Main_Menu(); break;
	case'e':exit(0); break;
	}
}
void Cofactor_Of_Matrix(double matrix[][col], double matrix_help[][col], int new_row, int new_column, int col1) {
	int i = 0;
	int j = 0;
	for (int row_help = 0; row_help < col1; row_help++) {
		for (int col_help = 0; col_help < col1; col_help++) {
			if (row_help != new_row&&col_help != new_column) {
				matrix_help[i][j++] = matrix[row_help][col_help];
				if (j == col1 - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}
double Determinant_Of_Matrix(double matrix[][col], int col1) {
	double determ = 0;
	int multiplicator = 1;
	double Matrix_Cofactor[col][col];
	if (col1 == 1) {
		return matrix[0][0];
	} 
	
	for (int i = 0; i < col1; i++) {
		Cofactor_Of_Matrix(matrix, Matrix_Cofactor, 0, i, col1);
		determ = determ + multiplicator*matrix[0][i] * Determinant_Of_Matrix(Matrix_Cofactor, col1 - 1);
		multiplicator = -multiplicator;
	}
	return determ;
}
void Adungirane_Matrica(double matrix[][col], double matrix_help[][col], int col1) {
	int multiplicator;
	double Matrix_Adungirane[col][col];
	if (col == 1) {
		matrix_help[0][0] = 1;
		return;
	} 
	for (int i = 0; i < col1; i++) {
		for (int j = 0; j < col1; j++) {
			Cofactor_Of_Matrix(matrix, Matrix_Adungirane, i, j, col1);
			if ((i + j) % 2 == 0) {
				multiplicator = 1;
			}
			else {
				multiplicator= -1;
			}
			matrix_help[j][i] = (Determinant_Of_Matrix(Matrix_Adungirane, col1 - 1))*multiplicator;
		}
	}

}
void Input_Vector(double vector[], int length) {
	for (int i = 0; i < length; i++) {
		cin >> vector[i];
	}
	cout << endl;
}
void Print_Vector(double vector[], int length) {
	for (int i = 0; i < length; i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
}
void Matrix_Vector_Product(double matrix_help[][col], double vector[], int length) {
	int counter = 0;
	
	for (int i = 0; i < length;i++) {
		Vector[counter] = 0;
		for (int j = 0; j < length; j++) {
			Vector[counter] = Vector[counter] + (matrix_help[i][j] * vector[j]);
		}
		counter++;
	}
}
void Func_For_Matrix_Vector_Product() {
	cout << "Molq vuvedete razmernost, koqto da otgovarq za matricata i za duljinata na vektora!!: -> ";
	int a;
	cin >> a;
	cout << "Molq, vuvedete matricata s razmernost: " << a << "x" << a << endl;
	Input_Matrix(Matrix_Help, a, a);
	cout << endl;
	cout << "Molq,vuvedete i vectora s razmernost: " << a << endl;
	Input_Vector(Vector_Help, a);
	cout << endl;
	Matrix_Vector_Product(Matrix_Help, Vector_Help, a);
	cout << endl;
	Print_Vector(Vector, a);
	cout << "Ako iskate da se vurnete obratno v glavnoto menu, vuvedete simvol : 'm' " << endl;
	cout << "Ako iskate da se izlezete ot programata, vuvedete simvol : 'e' " << endl;
	cout << "Molq vuvedete simvol:-> ";
	char symbol;
	cin >> symbol;
	cout << endl;
	switch (symbol)
	{
	case 'm':Main_Menu(); break;
	case'e': exit(0); break;
	default:cout << "Molq sledvashtiq put budete po-tochno v izbiraneto na simvol :) Veseli praznici :)!!" << endl;
		break;
	}
}
void Dot_Product_Program() {
	cout << "Vie izbrahte da namerete skalarnoto proizvedenie na dva vektora ! " << endl;
	cout << "Molq vuvedete purviq vector s razmernost 3" << endl;
	Input_Vector(Vector, 3);
	cout << "Molq vuvedete vtoriq vector s razmernost 3" << endl;
	Input_Vector(Vector_Help, 3);
	Dot_Product(Vector, Vector_Help, 3);
	cout << "Ako iskate da se vurnete obratno v glavnoto menu, vuvedete simvol : 'm' " << endl;
	cout << "Ako iskate da se izlezete ot programata, vuvedete simvol : 'e' " << endl;
	cout << "Molq vuvedete simvol:-> ";
	char symbol;
	cin >> symbol;
	cout << endl;
	switch (symbol)
	{
	case 'm':Main_Menu(); break;
	case'e': exit(0); break;
	default:cout << "Molq sledvashtiq put budete po-tochno v izbiraneto na simvol :)";Main_Page();
		break;
	}
}

void Dot_Product(double vector1[], double vector2[], int length) {
	double sum = 0;
	for (int i = 0; i < length; i++) {
		sum = sum + (vector1[i] * vector2[i]);
	}
	cout << "Skalarnoto proizvedenie na dvata vectora e : ";
	cout << sum;
	cout << endl;
}
void Cross_Product_Program() {
	cout << "Vie izbrahte da umnojavate dva vectora ! " << endl;
		cout << "Molq vuvedete purviq vector s razmernost 3" << endl;
		Input_Vector(Vector, 3);
		cout << endl;
		cout << "Molq vuvedete vtoriq vector s razmernost 3" << endl;
		Input_Vector(Vector_Help, 3);
		cout << "Vectorut,koito se poluchava pri vectornoto proizvedenie e : " << endl;
		Cross_Product(Vector, Vector_Help);
		cout << "Ako iskate da se vurnete obratno v glavnoto menu, vuvedete simvol : 'm' " << endl;
		cout << "Ako iskate da se izlezete ot programata, vuvedete simvol : 'e' " << endl;
		cout << "Molq vuvedete simvol:->";
		char symbol;
		cin >> symbol;
		cout << endl;
		switch (symbol)
		{
		case 'm':Main_Menu(); break;
		case'e': exit(0); break;
		default:cout << "Molq sledvashtiq put budete po-tochno v izbiraneto na simvol :)"; Main_Page();
			break;
		}

}
void Cross_Product(double vector1[], double vector2[]) {
		double New_Vector[3];
		New_Vector[0] = (vector1[1] * vector2[2]) - (vector1[2] * vector2[1]);
		New_Vector[1] = (vector1[2] * vector2[0]) - (vector1[0] * vector2[2]);
		New_Vector[2] = (vector1[0] * vector2[1]) - (vector1[1] * vector2[0]);
		for (int i = 0; i < 3; i++) {
			cout << New_Vector[i] << " ";
		}
		cout << endl;

}
void Multiplication() {
	Menu_Multiplication();
	cout << endl;
	cout << "Uvajaemi potrebiteli,vie shte budete pomoleni da vuvedete razmernosti na dvete matrici!" << endl;
	cout << endl;
	int row1;
	cout << "Molq vuvedete redovete na purvata matrica!->  ";
	cin >> row1;
	cout << endl;
	int col1;
	cout << "Molq vuvedete kolonite na purvata matrica!->  ";
	cin >> col1;
	cout << endl;
	cout << "Molq vuvedete  matricata!" << endl;
	Input_Matrix(Matrix_Help, row1, col1);
	cout << endl;
	cout << "Molq vuvedete redovete na vtorata  matrica!->  ";
	int row2;
	cin >> row2;
	cout << endl;
	cout << "Molq vuvedete kolonite na vtorata matrica!->  ";
	int col2;
	cin >> col2;
	cout << endl;
	if (col1 == row2) {
		cout << "Molq vuvedete vtorata matrica! " << endl;
		Input_Matrix(Matrix_Help_Multiplication, row2, col2);
		Multiplication_Of_Matrices(Matrix_Help,Matrix_Help_Multiplication,row1,col1,row2,col2);
		cout << endl;
		cout << "Matricata, koqto  se poluchava, pri umnojenieto na dvete matrici, e :" << endl;
		Print_Matrix(Matrix_Sum_For_Multiplication, row1, col2);
		cout << endl;
		cout << endl;
		cout << "Ako iskate da se vurnete obratno v glavnoto menu, vuvedete simvol : 'm' " << endl;
		cout << "Ako iskate da se izlezete ot programata, vuvedete simvol : 'e' " << endl;
		cout << "Molq vuvedi simvol:-> ";
		char symbol;
		cin >> symbol;
		cout << endl;
		switch (symbol)
		{
		case 'm':Main_Menu(); break;
		case'e': exit(0); break;
		default:cout << "Molq sledvashtiq put budete po-tochno v izbiraneto na simvol :) Veseli praznici :)!!" << endl; Main_Menu();
			break;
		}

	}
	else {
		cout << endl;
		cout << "Ne ste vuvevli pravilni razmernosti za matricite!!!" << endl;
		cout << "Ako iskate da opitate otnovo, vuvedete simvol: 'y' " << endl;
		cout << "Ako iskate da se vurnete obratno v glavnoto menu, vuvedete simvol : 'm' " << endl;
		cout << "Ako iskate da se izlezete ot programata, vuvedete simvol : 'e' " << endl;
		cout << "Molq vuvedi simvol:-> ";
		char symbol;
		cin >> symbol;
		cout << endl;
		switch (symbol)
		{
		case 'y':Multiplication(); break;
		case 'm':Main_Menu(); break;
		case'e': exit(0); break;
		default:cout << "Molq sledvashtiq put budete po-tochno v izbiraneto na simvol :) Veseli praznici :)!!" << endl; Main_Menu();
			break;
		}
	}
  
}
void Multiplication_Of_Matrices(double matrix1[][col], double matrix2[][col],int row1,int col1,int row2,int col2) {
	for(int i=0;i<row1;i++){
		for (int j = 0; j < col2; j++) {
			Matrix_Sum_For_Multiplication[i][j] = 0;
			for (int k = 0; k < col1; k++) {
				Matrix_Sum_For_Multiplication[i][j] += matrix1[i][k] * matrix2[k][j];
			}

		}
	}
}
void Print_Matrix(double matrix[][col], int row1, int col1) {
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void Input_Matrix(double matrix[][col], int row1, int col1) {
	cout << "Molq vuvedete matrica,koqto trqbva da e bude : " << row1 << "x" << col1 << endl;
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			cin >> matrix[i][j];
		}
		
	}
	cout << endl;
}
void Sum_Of_Matrix() {
	
	Input_Matrix(Matrix_Help, Const_Row, Const_Col);
	for (int i = 0; i < Const_Row; i++)
{
		for (int j = 0; j < Const_Col; j++) {
			Matrix[i][j] += Matrix_Help[i][j];
		}
	}

}
void Substraction_Of_Matrix() {
	
	Input_Matrix(Matrix_Help, Const_Row, Const_Col);
	for (int i = 0; i < Const_Row; i++)
	{
		for (int j = 0; j < Const_Col; j++) {
			Matrix[i][j] -= Matrix_Help[i][j];
		}
	}

}
void Func_For_Transposed_Matrix(double matrix[][col], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Transposed_Matrix[j][i] = Matrix_Help[i][j];

		}
	}

}
void Print_Transposed_Matrix() {
	int Row_Matrix;
	int Col_Matrix;
	cout << "Molq vuvedete kvadratna matrica!!" << endl;
	cout << "Molq vuvedete broq na redovete v matricata: -> ";
	cin >> Row_Matrix;
	cout << endl;	
	cout << "Molq vuvedete broq na stulbovete v matricata: ->";
	cin >> Col_Matrix;
	cout << endl;
	Input_Matrix(Matrix_Help, Row_Matrix, Col_Matrix);
	Func_For_Transposed_Matrix(Matrix_Help, Row_Matrix, Col_Matrix);
	cout << endl;
	cout << "The Transposed Matrix is : " << endl;
	for (int i = 0; i < Col_Matrix; i++) {
		for (int j = 0; j < Row_Matrix; j++) {
			cout << Transposed_Matrix[i][j] << " ";
			if (j == Row_Matrix - 1) {
				cout << endl;
			}
		}
	}
	cout << endl;
	cout << "Molq vuvedete symbol, za da se vurnete obratno v glavnoto menu" << endl;
	cout << "Za da se vurnete v glavnoto menu,Molq vuvedete:  'm'" << endl;
	cout << "Za da se izlezete ot programata, Molq vuvedete: 'e' " << endl;
	cout << "Molq vuvedi simvol:-> ";
	char symbol;
	cin >> symbol;
	cout << endl;
	switch (symbol) {
	case'm':Main_Menu(); break;
	case'e':exit(0); break;
	}
}
void Sum_Or_Sub_Of_Matrices() {
	int broi;
	cout << "Molq vuvedete broi na matricite, koito da subirate ili da izvajdate posledovatelno:-> ";
	cin >> broi;
	cout << endl;
	cout << "Molq vuvedete matrici s ednakva razmernost! " << endl;
	cout << "Molq vuvedete broq na redicite : -> ";
	cin >> Const_Row;
	cout << endl;
	cout << "Molq vuvedete broq na kolonite : ->  ";
		cin >> Const_Col;
		cout << endl;
	for (int i = 0; i < broi; i++) {
		cout << "Izberi dali da subirash ili da izvajdash:" << endl;
		cout << "Za izvajdasne natishi '-'" << endl;
		cout << "Za subirane natisni  '+' " << endl;
		cout << "Molq vuvedi pravilen symbol:->";
		char symbol;
		cin >> symbol;
		cout << endl;
		switch (symbol) {
		case '-':Substraction_Of_Matrix(); break;
		case '+':Sum_Of_Matrix(); break;
		default:Sum_Or_Sub_Of_Matrices(); break;
		}
	}
	cout << "Matricata, koqto se poluchava pri subirane ili izvajdane e : " << endl;
		Print_Matrix(Matrix, Const_Row,Const_Col);
		cout << endl;
		cout << "Molq vuvedete symbol, za da se vurnete obratno v glavnoto menu" << endl;
		cout << "Za da se vurnete v glavnoto menu,Molq vuvedete:  'm'" << endl;
		cout << "Za da se izlezete ot programata, Molq vuvedete: 'e' " << endl;
		cout << "Molq vuvedi pravilen symbol:->";
		char symbol;
		cin >> symbol;
		cout << endl;
		switch (symbol) {
		case'm':Main_Menu(); break;
		case'e':exit(0); break;
		}
	
}


int main()
{
	Print_Matrix(Matrix_Help_Multiplication, 5, 5);
	/*Main_Page();*/

 return 0;
} 

void Main_Menu() {
	char symbol;
	cout << "======================================MENU======================================================" << endl;
	cout << "    Molq vuvedete pravilen simvol!!!!    " << endl;
	cout << "Za da izberete Deistviq sus Subirane i Izvajdane  na matrici, Molq natisnete: ' s' " << endl;
	cout << "Za da izberete Umnojenie na matrici, natisni: ' u ' " << endl;
	cout << "Za da izberete Dali  matrica moje da se preobrazuva do edinichna, Molq  natisnete: ' i ' " << endl;
	cout << "Za da izberete Presmqtane na determinanta, Molq natisnete: 'd' " << endl;
	cout << "Za da izberete Namirane na obratna matrica,Molq natisnete:  'a' " << endl;
	cout << "Za da izberete Transponirane na matrica,Molq vuvedete: 't ' " << endl;
	cout << "Za izberete Normalizirane na Vector,Molq izberete: 'n' " << endl;
	cout << "Za da izberete Skalarno proizvedenie na dva vectora, Molq  natisnete: ' p ' " << endl;
	cout << "Za da izberete Vectorno proizvedenie na dva vectora, Molq  natisnete: ' c ' " << endl;
	cout << "Za da izberete umnojenie na Vector s Matrica,Molq natisnete: ' v '" << endl;
	cout << "Za da izberete Izlezete ot programata, Molq  natisnete: ' e ' " << endl;
	cout << "Molq vuvedi simvol:-> ";
	cin >> symbol;
	cout << endl;
	switch (symbol) {
	case'n':Normalize_Vector(); break;
	case't':Print_Transposed_Matrix(); break;
	case'd':Determinant_Of_Matrix(); break;
	case 's':Sum_Or_Sub_Of_Matrices(); break;
	case'u':Multiplication();	break;
	case'i':Func_For_Checking_Identity(); break;
	case'm':Main_Menu(); break;
	case'a':Func_For_Inversed_Matrix(); break; 
	case'e':exit(0); break;
	case'v':Func_For_Matrix_Vector_Product(); break;
	case'p':Dot_Product_Program(); break;
	case'c':Cross_Product_Program(); break;
	default:Main_Menu(); break;

	}
}
void Main_Page() {
	int counter = 0;
	cout << "======================================PROJECT===================================" << endl;
	cout << "Zdraveite,za da produljite Molq izberete vnimatelno i striktno edna ot opciite, pokazani nqkolko reda po-dolu     ";
	while (counter < 3)
	{
		cout << endl;
		counter++;
	}
	Main_Menu();
}
void Menu_Multiplication() {
	cout << "Vie izbrahte da umnojavate matrici! Molq, izberete podhodqshti razmernosti takiva, che broqt na kolonite na purvata matrica" << endl;
	cout << "da bude raven na broq na redovete na vtorata matricata" << endl;
	cout << "v protiven sluchai shte budete vurnati otnovo v menuto i shte se naloji da prochetete suobshtenieto oshte vednuj :) " << endl;
}

