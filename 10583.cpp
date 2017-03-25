#include <cstdio>
#include <cstdlib>
#include <iostream>

#define MAX 50000

using namespace std;

int student, len, std1, std2, counter, case_cnt, i;
int p[MAX];

void init();
void Union(int x, int y);
int Find(int x);

int main() {
	case_cnt = 0;
	while (scanf("%d %d", &student, &len) != EOF) {

		if (student == 0 && len == 0) {
			break;
		}
		else {
			init();
			case_cnt ++;
			for (i = 0; i< len; i++) {
				scanf("%d %d", &std1, &std2);
				Union(std1, std2);
			}
			printf("Case %d: %d\n", case_cnt, counter);
		}
	}
	return 0;
}

void init() {
	for (i=0; i<MAX; i++) {
		p[i] = i;
	}
	counter = student;
	return;
}

void Union(int x, int y) {
	int X = Find(x);
	int Y = Find(y);
	if (X != Y) {
		counter --;
		p[X] = Y;
	}

}

int Find(int x) {
	if (x == p[x])
		return x;
	else
		return p[x] = Find(p[x]);
}

