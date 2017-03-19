#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define MAX 25

using namespace std;

int arr[5];
int len;

void init();

int main(){
  int i;

  scanf("%d", &len);
  for (i = 0; i < len; i++) {
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    sort(arr, arr+3);
    printf("Case %d: %d\n", i+1, arr[1]);
  }
  return 0;
}

void init(){
  return;
}
