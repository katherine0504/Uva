#include <iostream>
#include <cstdio>
#include <cstdlib>


#define MAX 2000
using namespace std;

char inputA[MAX], inputB[MAX], c;
int resultA, resultB, temp, lenA, lenB, Acount, Bcount, mode;
int i = 0;
double ans;
bool changedA, changedB;

void init();
void calculateA();
void calculateB();
void calculateResult();

int main() {
	init();
	while (scanf("%c", &c) != EOF) {
		if (mode == 0 && c != 10) {
			if (lenA < MAX) {
				inputA[lenA] = c;
				lenA ++;
			}
			else {
				continue;
			}
		}
		else if (mode == 0 && c == 10) {
			calculateA();
		}
		else if (mode == 1 && c != 10) {
			if (lenB < MAX) {
				inputB[lenB] = c;
				lenB ++;
			}
			else {
				continue;
			}
		}
		else if (mode == 1 && c == 10) {
			calculateB();
			calculateResult();
			init();
		}
		else {
			continue;
		}
	}
	return 0;
}

void init() {
	resultA = 0;
	resultB = 0;
	mode = 0;
	lenA = 0;
	lenB = 0;
	changedA = false;
	changedB = false;
	Acount = 0;
	Bcount = 0;

	for (i = 0; i < MAX; i++) {
		inputA[i] = 0;
		inputB[i] = 0;
	}
}

void calculateA() {
	for (i = 0; i < lenA; i++) {
		temp = (int)inputA[i];

		if (Acount <25) {
			if (temp >= 65 && temp <= 90) {
				Acount ++;
				changedA = true;
				resultA = resultA + temp - 64;
			}
			else if (temp >= 97 && temp <= 122) {
				Acount ++;
				changedA = true;
				resultA = resultA + temp -96;
			}
			else {
				continue;
			}
		}
		else
			break;
	}
	mode = 1;
	return;
}

void calculateB() {
	for (i = 0; i < lenB; i++) {
		temp = (int)inputB[i];

		if (Bcount < 25) {
			if (temp >= 65 && temp <= 90) {
				Bcount ++;
				changedB = true;
				resultB = resultB + temp - 64;
			}
			else if (temp >= 97 && temp <= 122) {
				Bcount ++;
				changedB = true;
				resultB = resultB + temp -96;
			}
			else {
				continue;
			}
		}
		else
			break;
	}
	mode = 0;
	return;
}

void calculateResult() {
	if ((!changedA) && (!changedB)) {
		printf("\n");
	}

	else {
		while (resultA >= 10) {
		if (resultA >= 100)
			resultA = resultA/100 + (resultA%100)/10 + resultA%10;
		else
			resultA = resultA/10 + resultA%10;
		}
		while (resultB >= 10) {
			if (resultB >= 100)
				resultB = resultB/100 + (resultB%100)/10 + resultB%10;
			else
				resultB = resultB/10 + resultB%10;
		}
		
		if (resultA >= resultB) {
			ans = (double)resultB / (double)resultA;
		}
		else {
			ans = (double)resultA / (double)resultB;
		}

		printf("%.2f %%\n", ans*100);
	}
	
}

