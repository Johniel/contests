function d(n)
  local m = 1
  for i = 2, n do
    if n < i * i then
      break
    end
    if n % i == 0 then
      m = m + i + math.floor(n / i)
      if i * i == n then
        m = m - i
      end
    end
  end
  return m
end

local a = {}
local sum = 0

for i = 2, 10000+1 do
  if a[i] == nil then
    a[i] = d(i)
  end
  if a[a[i]] == nil then
    a[a[i]] = d(a[i]);
  end
  if a[a[i]] == i and a[i] ~= i then
    sum = sum + i
  end
end

print(sum)
