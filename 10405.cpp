#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX 1010

using namespace std;

string in1, in2;
int LCS[MAX][MAX];
int cnt1, cnt2, mx;

void init();

int main() {
  int i, j;
  init();
  while (getline(cin, in1)) {
    getline(cin, in2);

    cnt1 = in1.size();
    cnt2 = in2.size();

    for (i = 1; i <= cnt1; i++) {
      for (j = 1; j <= cnt2; j++) {
        if (in1[i-1] == in2[j-1]) {
          LCS[i][j] = LCS[i-1][j-1] + 1;
        } else {
          if (LCS[i-1][j] > LCS[i][j-1]) {
            LCS[i][j] = LCS[i-1][j];
          } else {
            LCS[i][j] = LCS[i][j-1];
          }
        }
      }
    }
    printf("%d\n", LCS[cnt1][cnt2]);
    init();
  }
  return 0;
}

void init() {
  int i, j;
  cnt1 = 0;
  cnt2 = 0;
  for (i = 1; i <= cnt1; i++) {
    for (j = 1; j <= cnt2; j++) {
      LCS[i][j] = 0;
    }
  }
  return;
}
