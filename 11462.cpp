#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 2000000

using namespace std;

int len, input, i;
bool first;


int main() {
	vector<int> age;
	while (scanf("%d", &len) != EOF) {
		if (len == 0)
			break;
		else {
			first = true;
			for ( i=0; i<len; i++ ) {
				scanf("%d", &input);
				age.push_back(input);
			}

			sort(age.begin(), age.end());

			for ( i=0; i<len; i++) {
				if (i == 0) {
					printf("%d", age[i]);
				}
				else {
					printf(" %d", age[i]);
				}
			}

			printf("\n");

			age.clear();
		}
	}
	return 0;
}