#include <stdio.h>
#include <stdlib.h>

#define N 10

int cmp(const void* a, const void* b)
{
  return *((int*)a) - *((int*)b);
}

int main(int argc, char *argv[])
{
  int nth = 1000000 - 1;

  int f[N];
  f[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = f[i - 1] * i;
  }

  int ns[N];
  for (int i = 0; i < N; ++i) {
    ns[i] = i;
  }

  for (int i = 0; i < N; ++i) {
    int d = f[N - i - 1];
    qsort(ns + i, N - i, sizeof(int), cmp);
    for (int j = i; j < N; ++j) {
      if (nth - d < 0) {
        int tmp = ns[j];
        ns[j] = ns[i];
        ns[i] = tmp;
        break;
      }
      nth -= d;
    }
  }

  for (int i = 0; i < N; ++i) {
    printf("%d", ns[i]);
  }
  puts("");

  return 0;
}
