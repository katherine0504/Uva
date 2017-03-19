#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define MAX 10010

using namespace std;

int arr[MAX];
int cnt = 0, input;

int main() {
  while(scanf("%d", &input) != EOF) {
    arr[cnt++] = input;
    sort(arr, arr+cnt);

    if (cnt == 1) {
      printf("%d\n", input);
    }
    else if (cnt%2 == 0) {
      printf("%d\n", (arr[cnt/2] + arr[cnt/2-1])/2);
    }
    else{
      printf("%d\n", arr[cnt/2]);
    }
  }

  return 0;
}

