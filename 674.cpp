#include <cstdio>
#include <cstdlib>

#define MAX 7500

int coin[5] = {1, 5, 10, 25, 50};
int arr[MAX];
int input;

void init();

int main() {
  int i, j;
  while (scanf("%d", &input) != EOF) {
    init();
    for (i = 0; i < 5; i++) {
      for (j = coin[i]; j <= input; j++) {
          arr[j] = arr[j] + arr[j-coin[i]];
      }
    }
    printf("%d\n", arr[input]);
  }
  return 0;
}

void init() {
  int i;
  
  arr[0] = 1;

  for (i = 1; i < MAX; i++) {
    arr[i] = 0;
  }
}
