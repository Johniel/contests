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
