#include <stdio.h>

int main(int argc, char *argv[])
{
  const int N = 1000;
  int i, f[N], sum = 2;
  f[0] = 1;
  f[1] = 2;
  for (i = 2; i < N; ++i) {
    if (4000000 <= (f[i] = f[i - 1] + f[i - 2])) break;
    if (f[i] % 2 == 0) sum += f[i];
  }
  printf("%d\n", sum);
  return 0;
}
