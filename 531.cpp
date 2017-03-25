#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

#define MAX 110

using namespace std;

string in1[MAX], in2[MAX], ans[MAX];
int LCS[MAX][MAX], dir[MAX][MAX];
int cnt1, cnt2, outcnt;

/* dir
  0: default
  1: left
  2: up
  3: upper-left
*/

void init();

int main() {
  int i, j;
  init();
  while (cin >> in1[1]) {
    while (cin >> in1[cnt1] && in1[cnt1] != "#") {
      cnt1++;
    }
  
    while (cin >> in2[cnt2] && in2[cnt2] != "#") {
      cnt2++;
    }

    for (i = 1; i < cnt1; i++) {
      for (j = 1; j < cnt2; j++) {
        if (in1[i] == in2[j]) {
          LCS[i][j] = LCS[i-1][j-1] + 1;
          dir[i][j] = 3;
        } else {
          if (LCS[i-1][j] > LCS[i][j-1]) {
            LCS[i][j] = LCS[i-1][j];
            dir[i][j] = 2;
          } else {
            LCS[i][j] = LCS[i][j-1];
            dir[i][j] = 1;
          }
        }
      }
    }

    i = cnt1 - 1;
    j = cnt2 - 1;

    while (i && j) {
      if (dir[i][j] == 3) {
        ans[outcnt++] = in1[i];
        i--;
        j--;
      } else if (dir[i][j] == 2) {
        i--;
      } else{
        j--;
      } 
    }

    for ( i = outcnt - 1; i > 0; i-- ) {
      cout << ans[i] << " ";
    }
    cout << ans[0];
    cout << endl;
    init();
  }
  return 0;
}

void init() {
  int i, j;
  cnt1 = 2;
  cnt2 = 1;
  outcnt = 0;

  for (i = 0; i < MAX; i++) {
    in1[i] = " ";
    in2[i] = " ";
    ans[i] = " ";
    for (j = 0; j < MAX; j++) {
      LCS[i][j] = 0;
      dir[i][j] = 0;
    }
  }
}
