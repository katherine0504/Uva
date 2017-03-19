#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#define MAX 550

using namespace std;

string str;
int arr1[MAX], arr2[MAX], ans[MAX];
int len1, len2, anslen, i, j;
bool fnd;

int main() {
  while ( getline(cin, str) ) {
    len1 = str.length();
    for (i = 0; i < len1; i++) {
      arr1[i] = str[len1-i-1] - '0'
    }

    getline(cin, str);
    len2 = str.length();
    for (i = 0; i < len2; i++) {
      arr2[i] = str[len2-i-1] - '0';
    }

    anslen = len1 + len2;
    fnd = false;
    for (i = 0; i < MAX; i++) {
      ans[i] = 0;
    }

    for (i = 0; i < len1; i++) {
      for (j = 0; j< len2; j++) {
        ans[i+j] = ans[i+j] + arr1[i] * arr2[j];
        ans[i+j+1] = ans[i+j+1] + ans[i+j]/10;
        ans[i+j] = ans[i+j]%10;
      }
    }

    for (i = anslen-1; i >= 0; i--) {
      if (!fnd && ans[i] == 0) {
        if(i == 0) {
          printf("0");
        }
        else {
          continue;
        }
      }
      else{
        printf("%d", ans[i]);
        fnd = true;
      }
    }

    printf("\n");
  }
  return 0;
}
