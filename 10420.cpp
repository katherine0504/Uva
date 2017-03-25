#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int len, i;
char input[80], country[80];
char token[] = " ";
char *ptr;
bool first;

int main() {
	map<string, int> M;
	map<string, int>::iterator it;

	scanf("%d\n", &len);

	for (i=0; i<len; i++) {
		first = true;
		gets(input);
		for ( ptr=strtok(input,token); ptr; ptr=strtok(NULL,token) ) {
			if (first) {
				strcpy(country, ptr);
				first = false;
				M[country]++;
			}
			else
				continue;
		}
	}

	for (it = M.begin(); it!=M.end(); it++) {
		cout << it->first << " " << it->second <<endl;
	}

	return 0;
}