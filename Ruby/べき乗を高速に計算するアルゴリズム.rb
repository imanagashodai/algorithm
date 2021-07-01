# https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an

def modpow(a,n,mod)
  res = 1
  while n > 0 do
    if (n & 1) != 0
      res = res * a % mod
    end
    a = a * a % mod
    n >>= 1
  end
  return res
end

p modpow(3,45,100000)
p 3 ** 45 % 100000