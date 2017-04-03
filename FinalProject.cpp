//EG's All-in-one Calculator! This will handle simple common calulations along with some matrix functions.
//Created/revised/finished by Conner Cox on March 16 2017.
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>

using namespace std;

//function prototypes
void calcAreaRectangle(ofstream &outHistory);
void calcAreaTriangle(ofstream &outHistory);
void calcAreaParallelogram(ofstream &outHistory);
void calcAreaCircle(ofstream &outHistory);
void calcAreaEllipse(ofstream &outHistory);

void calcSin(ofstream &outHistory);
void calcCos(ofstream &outHistory);
void calcTan(ofstream &outHistory);

void calcMatrixAdd(ofstream &outHistory);
void calcMatrixSub(ofstream &outHistory);

int main(int argc, char *argv[]) {
	int menuMain = 0;
	int menuArea = 0;
	int menuTrig = 0;
	int menuMatrix = 0;
	
	ofstream outHistory;
	outHistory.open("Calculator History.txt");
		
		if (outHistory.is_open()) {
		cout << "EG's All-in-one Calculator!" << endl;
			do { //menu selector
				outHistory << "Main Menu >> ";
				cout << endl;
				cout << "___Main Menu___" << endl << endl;
				cout << "1: Areas and Perimeters" << endl;
				cout << "2: Trig Formulas" << endl;
				cout << "3: Matricies" << endl;
				cout << "4: End the Program" << endl;	
				cout << "Enter your option: ";
				cin >> menuMain;
				cout << endl;
				
				if (menuMain == 1) {
					outHistory << "Areas and Perimeters >> ";
					cout << "___Areas and Perimeters___" << endl << endl;
					cout << "1: Squares and Rectangles" << endl;
					cout << "2: Triangles" << endl;
					cout << "3: Parallelograms" << endl;
					cout << "4: Circles" << endl;
					cout << "5: Ellipses" << endl;	
					cout << "6: Go back" << endl;	
					cout << "Enter your option: ";
					cin >> menuArea;
					cout << endl;
					switch (menuArea) {
						case 1:
							calcAreaRectangle(outHistory);
							break;
						case 2:
							calcAreaTriangle(outHistory);
							break;
						case 3:
							calcAreaParallelogram(outHistory);
							break;
						case 4:
							calcAreaCircle(outHistory);
							break;
						case 5:
							calcAreaEllipse(outHistory);
							break;
					}
				}
				else {
					if (menuMain == 2) {
						outHistory << "Trig Formulas >> ";
						cout << "___Trig Formulas___" << endl << endl;
						cout << "1: Find Sin" << endl;
						cout << "2: Find Cos" << endl;
						cout << "3: Find Tan" << endl;
						cout << "4: Go back" << endl;	
						cout << "Enter your option: ";
						cin >> menuTrig;
						cout << endl;
						switch (menuTrig) {
							case 1:
								calcSin(outHistory);
								break;
							case 2:
								calcCos(outHistory);
								break;
							case 3:
								calcTan(outHistory);
								break;
						}
					}
					else {
						if (menuMain == 3) {
							outHistory << "Matricies >> ";
							cout << "___Matricies___" << endl << endl;
							cout << "1: Addition" << endl;
							cout << "2: Subtraction" << endl;
							cout << "3: Go back" << endl;	
							cout << "Enter your option: ";
							cin >> menuMatrix;
							cout << endl;
							switch (menuMatrix) {
								case 1:
									calcMatrixAdd(outHistory);
									break;
								case 2:
									calcMatrixSub(outHistory);
									break;
							}
						}
						else {
							cout << "Program ended." << endl;
							outHistory << "End.";
						}
					}
				}
			} while (menuMain != 4);
		}
		else {
			cout << "History file location not found.";
		}
}
//function definitions
void calcAreaRectangle(ofstream &outHistory)
{
	double side1 = 0;
	double side2 = 0;
	double area = 0;
	double perimeter = 0;
	
	outHistory << "Rectanges and Squares." << endl << endl;
	
	cout << "Enter the length of the top. (-1 to end): ";
	cin >> side1;
	while (side1 != -1) {
		cout << "Enter the length of the side: ";
		cin >> side2;
		
		area = side1 * side2;
		perimeter = (side1 * 2) + (side2 * 2);
		
		outHistory << side1 << " * " << side2 << " = " << area << endl;
		outHistory << "(" << side1 << " * 2) + (" << side2 << " * 2) = " << perimeter << endl << endl;
		
		cout << "Area: " << area << endl << "Perimeter: " << perimeter << endl << endl; 
		cout << "Enter the length of the top: (-1 to end): ";
		cin >> side1;
	}
}
void calcAreaTriangle(ofstream &outHistory)
{
	double height = 0;
	double base = 0;
	double area = 0;
	
	outHistory << "Triangles." << endl << endl;
		
	cout << "Enter the height of the triangle. (-1 to end): ";
	cin >> height;
	while (height != -1) {
		cout << "Enter the base of the triangle. (-1 to end): ";
		cin >> base;
		
		area = (base * height) / 2;
		
		outHistory << base << " * " << height << " / 2 = " << area << endl << endl;
		
		cout << "Area: " << area << endl << endl;
		cout << "Enter the height of the triangle : (-1 to end): ";
		cin >> height;
	}//may update to calc perimeter
}
void calcAreaParallelogram(ofstream &outHistory)
{
	double base = 0;
	double height = 0;
	double area = 0;
	double perimeter = 0;
	
	outHistory << "Parallelograms." << endl << endl;
	
	cout << "Enter the length of the base. (-1 to end): ";
	cin >> base;
	while (base != -1) {
		cout << "Enter the height: ";
		cin >> height;
		
		area = base * height;
		perimeter = (base * 2) + (height * 2);
		
		outHistory << base << " * " << height << " = " << area << endl;
		outHistory << "(" << base << " * 2) + (" << height << " * 2) = " << perimeter << endl << endl;
		
		cout << "Area: " << area << endl << "Perimeter: " << perimeter << endl << endl; 
		cout << "Enter the length of the top: (-1 to end): ";
		cin >> base;
	}
}
void calcAreaCircle(ofstream &outHistory)
{
	double radius = 0;
	double area = 0;
	double perimeter = 0;
	
	outHistory << "Circles." << endl << endl;
	
	cout << "Enter the radius of the circle. (-1 to end): ";
	cin >> radius;
	while (radius != -1) {
		
		area = 3.1415 * pow(radius, 2);
		perimeter = 2 * 3.1415 * radius;
		outHistory << radius << "^2 * 3.1415 = " << area << endl;
		outHistory << radius << " * 3.1415 * 2 = " << perimeter << endl << endl;
		
		cout << "Area: " << area << endl << "Perimeter: " << perimeter << endl << endl; 
		cout << "Enter the radius of the circle : (-1 to end): ";
		cin >> radius;
	}
}
void calcAreaEllipse(ofstream &outHistory)
{
	double horRad = 0;
	double vertRad = 0;
	double area = 0;
	
	outHistory << "Ellipses." << endl << endl;
		
	cout << "Enter the horizontal radius of the ellipse. (-1 to end): ";
	cin >> horRad;
	while (horRad != -1) {
		cout << "Enter the verticale radius of the ellipse. (-1 to end): ";
		cin >> vertRad;
		
		area = 3.1415 * horRad * vertRad;
		outHistory << horRad << " * " << vertRad << " * 3.1415 = " << area << endl << endl;
		
		cout << "Area: " << area << endl << endl;
		cout << "Enter the horizontal radius of the ellipse. (-1 to end): ";
		cin >> horRad;
	}//do not update to calc perimeter (circumference). Massive rabbit hole
}

void calcSin(ofstream &outHistory)
{
	double x = 1;
	double answer = 1;
	
	outHistory << "Sin." << endl << endl;
		
	cout << "This program calculates the sine of x. {sin(x) = answer}" << endl;
	cout << "Enter x. (0 to end): ";
	cin >> x;
	while (x != 0) {
		
		answer = sin(x);
		outHistory << "Sin(" << x << ") = " << answer << endl << endl;
		
		cout << "Sin(" << x << ") = " << answer << endl << endl;
		cout << "Enter x. (0 to end): ";
		cin >> x;
	}
}
void calcCos(ofstream &outHistory)
{
	double x = 1;
	double answer = 1;
	
	outHistory << "Cos." << endl << endl;
		
	cout << "This program calculates the cos of x. {cos(x) = answer}" << endl;
	cout << "Enter x. (0 to end): ";
	cin >> x;
	while (x != 0) {
		
		answer = cos(x);
		outHistory << "Cos(" << x << ") = " << answer << endl << endl;
		
		cout << "Cos(" << x << ") = " << answer << endl << endl;
		cout << "Enter x. (0 to end): ";
		cin >> x;
	}
}
void calcTan(ofstream &outHistory)
{
	double x = 1;
	double answer = 1;
	
	outHistory << "Tan." << endl << endl;
		
	cout << "This program calculates the tan of x. {tan(x) = answer}" << endl;
	cout << "Enter x. (0 to end): ";
	cin >> x;
	while (x != 0) {
		
		answer = tan(x);
		outHistory << "Tan(" << x << ") = " << answer << endl << endl;
		
		cout << "Tan(" << x << ") = " << answer << endl << endl;
		cout << "Enter x. (0 to end): ";
		cin >> x;
	}
}
void calcMatrixAdd(ofstream &outHistory)
{
	int row = 0;
	int col = 0;
	
	outHistory << "Addition." << endl << endl;
	
	cout << "What size of matricies do you have? (x*y)?" << endl << "Enter x: ";
	cin >> row;
	cout << "What size of matricies do you have? (" << row << "*y)?" << endl << "Enter y: ";
	cin >> col;
	
	double arrayA[row][col];
	double arrayB[row][col];
	double arrayC[row][col];
	
	outHistory << "Matrix A" << endl;
	
	//populating matrix A
	for (int x = 0; x < row; x++) {
		outHistory << endl;
		for (int y = 0; y < col; y++) {
			cout << "Enter the number for matrix A " << x + 1 << ", " << y + 1 << ": ";
			cin >> arrayA[x][y];
			outHistory << arrayA[x][y] << "  ";

		}
	}
	
	outHistory << endl << endl << "Matrix B" << endl;
	
	//populating matrix B
	cout << endl;
	for (int x = 0; x < row; x++) {
		outHistory << endl;
		for (int y = 0; y < col; y++) {
			cout << "Enter the number for matrix B " << x + 1 << ", " << y + 1 << ": ";
			cin >> arrayB[x][y];
			outHistory << arrayB[x][y] << "  ";
		}
	}
	//Addition of A + B matricies
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			arrayC[x][y] = arrayA[x][y] + arrayB[x][y];
		}
	}
	//display new matrix
	cout << endl << "Matrix A + B =" << endl;
	outHistory << "Matrix A + B =" << endl;
	for (int x = 0; x < row; x++) {
		cout << endl;
		outHistory << endl;
		for (int y = 0; y < col; y++) {
			cout << arrayC[x][y] << "  ";
			outHistory << arrayC[x][y] << "  ";
		}
	}
	cout << endl;

}
void calcMatrixSub(ofstream &outHistory)
{
	int row = 0;
	int col = 0;
	
	outHistory << "Subtraction." << endl << endl;
	
	cout << "What size of matricies do you have? (x*y)?" << endl << "Enter x: ";
	cin >> row;
	cout << "What size of matricies do you have? (" << row << "*y)?" << endl << "Enter y: ";
	cin >> col;
	
	double arrayA[row][col];
	double arrayB[row][col];
	double arrayC[row][col];
	
	outHistory << "Matrix A" << endl;
	
	//populating matrix A
	for (int x = 0; x < row; x++) {
		outHistory << endl;
		for (int y = 0; y < col; y++) {
			cout << "Enter the number for matrix A " << x + 1 << ", " << y + 1 << ": ";
			cin >> arrayA[x][y];
			outHistory << arrayA[x][y] << "  ";

		}
	}
	
	outHistory << endl << endl << "Matrix B" << endl;
	
	//populating matrix B
	cout << endl;
	for (int x = 0; x < row; x++) {
		outHistory << endl;
		for (int y = 0; y < col; y++) {
			cout << "Enter the number for matrix B " << x + 1 << ", " << y + 1 << ": ";
			cin >> arrayB[x][y];
			outHistory << arrayB[x][y] << "  ";
		}
	}
	//Subtraction of A - B matricies
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			arrayC[x][y] = arrayA[x][y] - arrayB[x][y];
		}
	}
	//display new matrix
	cout << endl << "Matrix A - B =" << endl;
	outHistory << "Matrix A - B =" << endl;
	for (int x = 0; x < row; x++) {
		cout << endl;
		outHistory << endl;
		for (int y = 0; y < col; y++) {
			cout << arrayC[x][y] << "  ";
			outHistory << arrayC[x][y] << "  ";
		}
	}
	cout << endl;
}