# codeforces/338div2/D

## Codes
```rb
MOD = 1000000000 + 7

def f(n, p)
  if p == 0 then
    return 1
  end
  m = f(n, p / 2)
  if p % 2 == 1 then
    return m * m * n % MOD
  else
    return m * m % MOD
  end
end

while s = $stdin.gets() do
  s = $stdin.gets()
  ps = s.split(" ")
  cnt = {}
  ps.each do |p|
    key = p.to_i()
    if cnt[key] then
      cnt[key] = cnt[key] + 1
    else
      cnt[key] = 1
    end
  end
  
  d = 1
  cnt.each do |key, val|
    d *= val + 1
  end

  ret = 1
  cnt.each do |key, val|
    x = f(key, (val * (val + 1) / 2) % (MOD - 1))
    y = f(x, (d / (val + 1)) % (MOD - 1))
    ret = ret * y % MOD
  end
  puts(ret)
end
```
