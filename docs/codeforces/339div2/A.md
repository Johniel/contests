# codeforces/339div2/A

## Codes
main.rb
{% raw %}{{
```rb
require 'scanf'

while s = $stdin.gets() do
  l, r, k = s.scanf("%d %d %d")
  n = 1
  f = false
  while n <= r do
    if l <= n && n <= r then
      if f then
        print(" ")  
      end
      f = true
      print(n)
    end
    n *= k;
  end
  if f then
    puts("");
  else
    puts("-1");
  end
end
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/339div2/A)
{% endraw %}
