#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  const int N = 2000000 + 1;
  bool prime[N];
  int i, j;
  unsigned long long int sum = 0;
  memset(prime, true, N);
  prime[0] = prime[1] = false;
  for (i = 2; i * i < N; ++i) {
    for (j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }
  for (i = 0; i < N; ++i) {
    if (prime[i]) sum += i;
  }
  printf("%lld\n", sum);
  return 0;
}
