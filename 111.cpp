#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

#define MAX 25

using namespace std;

int mx,len, in[MAX], ans[MAX], LCS[MAX][MAX];

void init();

int main() {
  int i, j, tmp;
  init();
  scanf("%d", &len);
  for (i = 1; i <= len; i++) {
      scanf("%d", &tmp);
      ans[tmp] = i;
  }
  while (scanf("%d", &tmp) != EOF) {
    in[tmp] = 1;

    for (i = 2; i <= len; i++) {
        scanf("%d", &tmp);
        in[tmp] = i;
    }

    for (i = 1; i <= len; i++) {
      for (j = 1; j <= len; j++) {
        if (ans[i] == in[j]) {
          LCS[i][j] = LCS[i-1][j-1] + 1;
        } else {
          if (LCS[i-1][j] > LCS[i][j-1]) {
            LCS[i][j] = LCS[i-1][j];
          } else {
            LCS[i][j] = LCS[i][j-1];
          }
        }
        if (LCS[i][j] > mx) {
            mx = LCS[i][j];
        }
      }
    }
    printf("%d\n", mx);
    init();
  }
  return 0;
}

void init() {
  int i, j;
  mx = 0;

  for (i = 0; i < MAX; i++) {
    in[i] = 0;
    for (j = 0; j < MAX; j++) {
      LCS[i][j] = 0;
    }
  }
  return;
}
