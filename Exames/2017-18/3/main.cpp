#include <iostream>

using namespace std;

void readGrades(int grades[], int numStudents)
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Insert the grade: ";
		cin >> grades[i];
	}
}

//Alínea a)
float average(const int grades[], int numStudents)
{
	float sum = 0;
	for (int i = 0; i < numStudents; i++)
		sum += grades[i];
	return sum / numStudents;
}

//Alínea b)
int main()
{
	int *grades, numStudents;
	cout << "Insert the number of students: ";
	cin >> numStudents;
	grades = new int[numStudents];
	readGrades(grades, numStudents);
	cout << average(grades, numStudents);
	return 0;
}