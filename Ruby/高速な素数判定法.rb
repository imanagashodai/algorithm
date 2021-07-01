# 通常

define_method(:square) {|n| (n**(1/2.0)).floor}

def is_prime(n)
	2.upto(square(n)) do |i|
		return false if n % i == 0
	end
	return n != 1 # 1の場合は例外
end

p is_prime(295927)

# エラトステネスの篩
# n以下の素数を全て表示

def sieve(n)
	p = [] # 素数ボックス
	is_prime = [false, false] + Array.new(n-1) { true }
	2.upto(n) do |i|
		if is_prime[i]
			p << i
			2.upto(n/i) do |j|
				is_prime[i*j] = false
			end
		end
	end
	return p
end

p sieve(7)