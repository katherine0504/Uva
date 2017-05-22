#include <cstdio>

int n, cnt;

int main() {
  cnt = 1;

  while(scanf("%d", &n) != EOF) {
    if (n == 0) {
      break;
    }
    printf("Case %d: %d\n", cnt++, n/2);
  }
  return 0;
}
