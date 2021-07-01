# https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-3-%E5%86%8D%E5%B8%B0%E9%96%A2%E6%95%B0%E3%82%92%E7%94%A8%E3%81%84%E3%81%9F%E5%85%A8%E6%8E%A2%E7%B4%A2

N = 3
M = 7

# 解法１　チート
# arrays = (1..M).to_a.repeated_combination(N).to_a
# arrays.each do |array|
# 	ans = 0
# 	N.times { |n| ans += array[n] * 10 ** (N - n - 1) }
# 	puts ans
# end

# 解法2　再帰関数
# def func(cur)
# 	if cur.length == N
# 		puts cur
# 		return
# 	elsif cur.length >= 1
# 		last = cur[-1].to_i
# 	else
# 		last = 1
# 	end
# 	last.upto(M) do |i|
# 		func(cur + "#{i}")
# 	end
# end
# func("")

# 解法3　スタック
stack = [""]
until stack.empty? do
  num = stack.pop
  if num.empty?
  	stack = Array.new(M) { |i| "#{M-i}" }
  elsif num.length == N
  	puts num
  else
  	M.downto(num[-1].to_i) { |i| stack << num + "#{i}" }
  end
end