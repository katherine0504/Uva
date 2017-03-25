#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <string>

#define MAX 150
using namespace std;


int len;
bool correct;

int main() {
	int i,j;
	char c;
	stack<char> stk;

	while (scanf("%d\n", &len) != EOF) {
		for (i = 0; i < len; i++) {
			/*init*/
			while (stk.empty() == false) {
				stk.pop();
			}
			correct = true;

			scanf("%c", &c);
			
			while (c != 10 ) {
				if (c == '(' || c == '[') {
					stk.push(c);
				}
				else if (c == ')') {
					if ((stk.empty() == false) && stk.top() == '(') {
						stk.pop();
					}
					else {
						correct = false;
					}
				}
				else if (c == ']') {
					if ((stk.empty() == false) && stk.top() == '[') {
						stk.pop();
					}
					else {
						correct = false;
					}
				}

				scanf("%c", &c);
			}
			if (stk.empty() && correct) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}

		}
	}
	return 0;
}