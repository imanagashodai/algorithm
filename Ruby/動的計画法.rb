# メモ化再帰
# https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-6-%E7%99%BA%E5%B1%95%E5%86%8D%E5%B8%B0%E9%96%A2%E6%95%B0%E3%82%92%E7%94%A8%E3%81%84%E3%81%9F%E5%85%A8%E6%8E%A2%E7%B4%A2%E3%81%AE%E5%BF%9C%E7%94%A8%E3%83%A1%E3%83%A2%E5%8C%96%E5%86%8D%E5%B8%B0

# def func(a, memo)
#   return 1 if a == 0
#   return memo[a] if memo[a] >= 1
#   z1 = 0
#   z1 = func(a-1, memo) if (a>=1)
#   z2 = 0
#   z2 = func(a-2, memo) if (a>=2)
#   memo[a] = z1 + z2
#   return memo[a]
# end

# N = 35
# memo = Array.new(N+1) { 0 }
# p func(N, memo)

# ナップサックDP
# https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-2%E3%83%8A%E3%83%83%E3%83%97%E3%82%B5%E3%83%83%E3%82%AF%E5%95%8F%E9%A1%8C

# n = 6
# wv = [[2,3],[1,2],[3,6],[2,1],[1,3],[5,85]] # [weight, value]
# W = 9

# # dp[k][w]はk番目までの数値を用いた時の値がw以下となるときの最適解
# # よってdp[0][w]=0。kとwはどちらも1つ多めにとる
# dp = Array.new(1){Array.new(W+1,0)}
# dp += Array.new(n){Array.new(W+1)}

# n.times do |k|
#   (W+1).times do |w|
#     if w >= wv[k][0]
#       dp[k+1][w] = [dp[k][w-wv[k][0]] + wv[k][1], dp[k][w]].max
#     else
#       dp[k+1][w] = dp[k][w]
#     end
#   end
# end

# puts dp[n][W]

# # 確かめ
# print sprintf("%3s", "")
# print sprintf("%3s", "w")
# (W+1).times do |w|
#   print sprintf("%3d", w)
# end

# puts
# puts sprintf("%3s", "k")

# (n+1).times do |k|
#   print sprintf("%3d", k)
#   print sprintf("%3s", "")
#   (W+1).times do |w|
#     print sprintf("%3d", dp[k][w])
#   end
#   puts
# end

# 区間DP
# http://kutimoti.hatenablog.com/entry/2018/03/10/220819

# n = 5
# w = [5, 1, 2, 3, 6]

# # dp[l][r]は区間[l,r]で取り除くことのできるブロックの数
# dp = Array.new(n){Array.new(n,-1)}
# n.times { |i| dp[i][i] = 0 }

# def func(l, r, dp, w)
#   if dp[l][r] != -1
#     return dp[l][r]
#   elsif r - l == 1
#     return dp[l][r] = (w[r]-w[l]).abs<=1 ? 2 : 0
#   else
#     if (w[r]-w[l]).abs <= 1 && func(l+1,r-1,dp,w) == r-l-1
#       return dp[l][r] = r-l+1
#     else
#       array2 = []
#       (l+1).upto(r-1) do |mid|
#         array2 << func(l,mid,dp,w) + func(mid+1,r,dp,w)
#       end
#       return dp[l][r] = array2.max
#     end
#   end
# end

# p func(0,n-1,dp,w)

# bitDP
# https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#11-bit-dp

N = 4
Dist = [[0,8,7,3],[8,0,9,1],[7,9,0,4],[3,1,4,0]]

INF = 100000000

# dpテーブルは余裕をもったサイズにする
dp = Array.new(1<<N) { Array.new(N) } 

# bitを探索済で、現在地がvの時の最小値
def rec(bit, v, dp)
	# すでに探索済みだったらリターン
	return dp[bit][v] if dp[bit][v] != -1

	# 初期値
  return dp[bit][v] = 0 if bit == (1<<v)

  # 答えを格納する変数
  res = INF

  # bit の v を除いたもの
  prev_bit = bit & ~(1<<v)

  # v の手前のノードとして u を全探索
  N.times do |u|
  	# u が prev_bit になかったらダメ
  	next if (prev_bit & (1<<u)) == 0

    # 再帰的に探索
    if res > rec(prev_bit, u, dp) + Dist[u][v]
    	res = rec(prev_bit, u, dp) + Dist[u][v]
    end
  end
  
  # メモしながらリターン
  return dp[bit][v] = res
end


# テーブルを全部 -1 にしておく (-1 でなかったところは探索済)
(1 << N).times do |bit|
	N.times do |v|
		dp[bit][v] = -1
	end
end

res = INF
N.times do |v|
	if res > rec((1<<N)-1, v, dp)
		res = rec((1<<N)-1, v, dp)
	end
end

puts res