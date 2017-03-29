#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int len, maxlen, cnt = 0;
char in[105][105];

void init();

int main() {
  int i, j;
  init();
  while (gets(in[cnt])) {
    len = strlen(in[cnt]);
    in[cnt][len] = ' ';
    if (len > maxlen) {
      maxlen = len;
    }
    cnt++;
  }

  for (i = 0; i < maxlen; i++) {
    for (j = cnt-1; j >= 0; j--) {
      printf("%c", in[j][i]);
    }
    printf("\n");
  }
  return 0;
}

void init () {
  int i, j;

  for (i = 0; i < 105; i++) {
    for (j = 0; j < 105; j++) {
      in[i][j] = ' ';
    }
  }
  return;
}
