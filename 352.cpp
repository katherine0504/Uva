#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

char arr[30][30];
int len, cnt, num;

using namespace std;

void init();
void DFS(int i, int j);

int main(){
  int i, j;
  num = 0;
  while (scanf("%d\n", &len) != EOF) {
    init();
    cnt = 0;
    num ++;
    for (i = 0; i < len; i++) {
      for (j = 0; j < len; j++) {
        scanf("%c", &arr[i][j]);
      }
      scanf("\n");
    }

    for (i = 0; i < len; i++) {
      for (j = 0; j < len; j++) {
        if (arr[i][j] == '1') {
            DFS(i, j);
            cnt ++;
        }
        else 
          continue;
      }
    }
    printf("Image number %d contains %d war eagles.\n", num, cnt);
  }

  return 0;
}

void DFS(int i, int j) {
  if ( i < len-1 && arr[i+1][j] == '1' ) {
    arr[i+1][j] = 0;
    DFS(i+1, j);
    /*down*/
  }
  if (j < len-1 && arr[i][j+1] == '1') {
    arr[i][j+1] = 0;
    DFS(i, j+1);
    /*right*/
  }
  if ( i > 0 && arr[i-1][j] == '1') {
    arr[i-1][j] = 0;
    DFS(i-1, j);
    /*up*/
  }
  if ( j > 0 && arr[i][j-1] == '1') {
    arr[i][j-1] = 0;
    DFS(i, j-1);
    /*left*/
  }
  if (i < len-1 && j < len-1 && arr[i+1][j+1] == '1') {
    arr[i+1][j+1] = 0;
    DFS(i+1, j+1);
    /* right down*/
  }
  if (i < len-1 && j > 0 && arr[i+1][j-1] == '1') {
    arr[i+1][j-1] = 0;
    DFS(i+1, j-1);
    /* left down */
  }
  if ( i > 0 && j < len-1 && arr[i-1][j+1] == '1') {
    arr[i-1][j+1] = 0;
    DFS(i-1, j+1);
    /*left up*/
  }
  if ( i > 0 && j > 0 && arr[i-1][j-1] == '1') {
    arr[i-1][j-1] = 0;
    DFS(i-1, j-1);
    /*right up */
  }
  return;
}

void init() {
  int i, j;
  for (i = 0; i < 30; i++) {
    for (j = 0; j < 30; j++) {
      arr[i][j] = '0';
    }
  }
}
