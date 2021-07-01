# https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-4-%E5%B9%85%E5%84%AA%E5%85%88%E6%8E%A2%E7%B4%A2

N = 5 # 都市数
M = 5 # 道路数
A = [1,1,2,3,4]
B = [2,3,4,4,5]

INF = N
d = [0] + Array.new(N-1) { INF }
queue = [1]

until queue.empty? do
  cur = queue.shift
	M.times do |i|
		if A[i] == cur
			if d[B[i]-1] == INF
				queue << B[i]
				d[B[i]-1] = d[A[i]-1] + 1
			end
		end

		if B[i] == cur
			if d[A[i]-1] == INF
				queue << A[i]
				d[A[i]-1] = d[B[i]-1] + 1
			end
		end
	end
end

puts d