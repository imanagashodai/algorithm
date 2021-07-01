# https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-1-bit-%E5%85%A8%E6%8E%A2%E7%B4%A2

N = 8
A = [100,500,1,50,10,5,1000,5000]
X = 6161

# require "set"
bits = (1 << N) - 1
array = [0]

(1..bits).each do |bit|
	num = 0
	bl = bit.bit_length
	array << A[bl-1] + array[bit - 2**(bl-1)]
end

puts array.count(X)