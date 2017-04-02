#include <cstdio>
#include <cstdlib>

#define MAX 32800

int LIS[MAX] = {1}, num[MAX] = {0};
int cnt, ans, in;

void init();
void findLIS();

int main() {
  int i;
  int casecnt = 1;
  while (scanf("%d", &in) != EOF) {
    if (in == -1) {
      break;
    }
    init();
    num[0] = in;
    cnt = 1;
    while (scanf("%d", &in) != EOF && in != -1) {
      num[cnt++] = in;
    }
    
    findLIS();

    if (casecnt == 1) {
      printf("Test #%d:\n  maximum possible interceptions: %d\n", casecnt++, ans);
    }
    else {
      printf("\nTest #%d:\n  maximum possible interceptions: %d\n", casecnt++, ans);
    
    }
  }
  return 0;
}

void init() {
  int i;

  for (i = 0; i < MAX; i++) {
    LIS[i] = 1;
  }
  return;
}

void findLIS() {
  int i, j;
  ans = 0;
  for (i = cnt-1; i >= 0; i--) {
    for (j = cnt-1; j >= i; j--) {
      if (num[j] < num[i] && LIS[j]+1 > LIS[i]) {
        LIS[i] = LIS[j] + 1;
      }
    }
    if (LIS[i] > ans) {
      ans = LIS[i];
    }
  }
  return;
}
