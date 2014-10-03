//Matt Suenkens

#include <iostream>

using namespace std;

double averageScore(double* valptr, int num, char option);//computes average score of tests
double maxScore(double* valptr, int num);//computes highest score


int main(){
	int num = 0;
	double *scorePtr;
	double score;
	double average;
	double max;
	char option;
	
	cout << "Enter the number of test scores you would like to enter: \n";
	cin >> num;
	if (num <= 0){
		cout << "Please enter again. " << endl;
		cin >> num;
	}
	
	const int NUM_TESTS = num;
	scorePtr = new double[NUM_TESTS];

	cout << "Enter the test scores. " << endl;
	for (int i = 0; i < NUM_TESTS; ++i){
		cout << "Test " << i + 1 << ": ";
		cin >> score;
		if (score >= 0){
			scorePtr[i] = score;
		}
		else {
			cout << "Try again." << endl;
			scorePtr[i] = score;
		}
	}

	
	max = maxScore(scorePtr, num);

	cout << "The highest score on the test is: " << max << endl;
	cout << "Would you like the average of the test without the lowest score(y or n)?" << endl;
	cin >> option;
	
	average = averageScore(scorePtr, num, option);
	
	cout << "The average score is: " << average << endl;


	return 0;
}

double averageScore(double *valptr, int num, char option){
	double lowest = 0.0;
	double total = 0.0;
	double average = 0.0;
	for (int i = 0; i < num; i++){
		total += valptr[i];
	}
	lowest = valptr[0];
	for (int i = 0; i < num; i++){
		if (valptr[i + 1] < lowest){
			lowest = valptr[i + 1];
		}
	}
	if (option == 'y'){
		average = ((total-lowest)) / ((num - 1));
	}
	else {
		average = total / num;
	}
	
	return average;
}


double maxScore(double *valptr, int num){
	double max = 0.0;
	max = valptr[0];
	for (int i = 0; i < num; i++){
		if (valptr[i + 1] > max){
			max = valptr[i + 1];
		}
	}
	return max;
}