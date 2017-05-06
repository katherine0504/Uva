#include <cstdio>
#include <cstdlib>

#define MAX 800
using namespace std;

int out[MAX], ans[10];
int in, mx;
void init();

int main() {
	int i, j, cnt;
	while(scanf("%d", &in)	!= EOF) {
		if (in == 0) {
			break;
		} else if ( in > 0 && in <= 366) {
			init();
			for (cnt = in; cnt > 0; --cnt) {
				for (i = 0; i < MAX; ++i) {
					out[i] = out[i]*cnt;
				}
				for (i = 0; i < MAX; ++i) {
					if(out[i] >= 10) {
						out[i+1] += out[i]/10;
						out[i] %= 10;
						if (i+1 > mx) {
							mx = i+1;
						}
					}
				}
			}
			for (i = 0; i <= mx; ++i) {
				ans[out[i]]++;
			} 
			printf("%d! --\n", in);
			for (i = 0; i < 10; ++i) {
				if (i == 0) {
					printf("   (%d)%5d", 0, ans[0]);
				} else if (i == 5) {
				printf("\n   (%d)%5d", 5, ans[5]);
				} else {
					printf("    (%d)%5d", i, ans[i]);
				}
			}
			printf("\n");
		} else {
			continue;
		}
	}
	return 0;
}

void init() {
	out[0] = 1;
	mx = 0;
	for (int i = 1; i < MAX; ++i) {
		out[i] = 0;
	}
	for (int i = 0; i < 10; ++i) {
		ans[i] = 0;
	}
}

