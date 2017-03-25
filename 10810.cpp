#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define MAX 500000

using namespace std;

int len, cnt, i, j, temp, times;
long int input[MAX];

void init();

int main()
{
	while (scanf("%d", &len) != EOF) {
		if (len == 0) {
			break;
		}
		else {
			init();
			for (cnt = 0; cnt < len; ++cnt) {
				scanf("%ld", &input[cnt]);
			}
			for (i = 0; i < len; ++i) {
				for (j = len-1; j >= i; --j) {
					if (input[j-1] > input[j]) {
						swap(input[j-1], input[j]);
						times ++;
					}
				}
			}
			printf("%d\n", times);
		}
	}
	return 0;
}

void init() {
	times = 0;
	for (i = 0; i < MAX; i ++) {
		input[i] = 0;
	}
	return;
}