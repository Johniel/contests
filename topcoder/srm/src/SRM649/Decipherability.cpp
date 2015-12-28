#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class Decipherability {
public:
  string check(string s, int K)
  {
    if (s.size() == K) return "Certain";
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i + 1; j < s.size(); ++j) {
        if (s[i] == s[j] && j - i <= K) {
          return  "Uncertain";
        }
      }
    }
    return "Certain";

  }


};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
