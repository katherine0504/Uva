#include <cstdio>
#include <cstdlib>

#define MAX 15
using namespace std;

int input[MAX], output[MAX];
bool selected[MAX];
bool first = true;
int k;

void init();
void select(int len, int ptr);

int main() {
  int i;
  while (scanf("%d", &k) != EOF && k != 0) {
    if (!first)
      printf("\n");

    for (i = 0; i < k; i++) {
      scanf("%d", &input[i]);
    }
    
    select(0, 0);

    first = false;
  }

  return 0;
}

void init() {
  int i;
  for (i = 0; i < MAX; i++) {
    input[i] = 0;
    output[i] = 0;
    selected[i] = false;
  }
  return;
}

void select(int len, int ptr) {
  int i;
  if (len == 6) {
    for (i = 0; i < 5; i++)
      printf("%d ", output[i]);
    printf("%d\n", output[5]);
    return;
  }
  else {
    for (i = ptr; i < k; i++) {
      if (!selected[i]) {
        selected[i] = true;
        output[len] = input[i];
        select(len+1, i+1);
        selected[i] = false;
      }
    }
  }
}
