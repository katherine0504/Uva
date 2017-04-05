#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

char in[100], out[100];
int cnt, t, len;

void init();

int main() {
  int i, j, k;
  scanf("%d", &t);
  
  for (i = 0; i < t; i++) {
    init();
    cin >> in;
    len = strlen(in);

    for (j = 1; j <= len; j++) {
      if ((len%j) == 0) {
        for (k = j; k < len; k++) {
          if (in[k] != in[k%j]) {
            break;
          }
        }

        if (k == len) {
          printf("%d\n", j);
          if (i < t-1) {
            printf("\n");
          }
          break;
        }
      }
    }
  }
  
  return 0;
}

void init() {
  int i;
  for (i = 0; i < 100; i++) {
    in[i] = ' ';
  }
  return;
}

