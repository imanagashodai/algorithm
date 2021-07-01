# https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-2-%E9%A0%86%E5%88%97%E5%85%A8%E6%8E%A2%E7%B4%A2

N = 5
A = [
	[0,3,2,5,6],
	[6,0,3,3,1],
	[7,3,0,6,5],
	[1,2,1,0,3],
	[7,5,6,9,0]
]
 
arrays = (0..N-1).to_a.permutation(N).to_a
ans = 100

 arrays.each do |array|
	ret = 0
	(N-1).times { |n| ret += A[array[n]][array[n+1]] }
	ans = [ans, ret].min
	
end

puts ans