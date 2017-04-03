#include <cstdio>
#include <cstdlib>

#define MAX 50000

using namespace std;

int N, Q, lady[MAX], male, taller, shorter;
bool taller_fd, shorter_fd;

int main () {
  int i, j;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &lady[i]);
  }
  scanf("%d", &Q);
  for (i = 0; i < Q; i++) {
    taller_fd = false;
    shorter_fd = false;
    scanf("%d", &male);
    for (j = 0; j < N; j++) {
      if ( !shorter_fd && j < N-1 && lady[j] < male && lady[j+1] >= male) {
        shorter = lady[j];
        shorter_fd = true;
      }
      else if (!shorter_fd && j == N-1 && lady[j] < male) {
        shorter = lady[j];
        shorter_fd = true;
      }
      if (!taller_fd && j > 0 && lady[j] > male && lady[j-1] <= male) {
        taller = lady[j];
        taller_fd = true;
        break;
      }
    }
    if (!shorter_fd) {
      printf("X ");
    } else {
      printf("%d ", shorter);
    }
    if (!taller_fd) {
      printf("X\n");
    } else {
      printf("%d\n", taller);
    }
  }

  return 0;
}
