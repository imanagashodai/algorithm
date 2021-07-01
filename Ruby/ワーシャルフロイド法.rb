# 計算量に余裕のある時or負の辺がある時だけ！O(V^3)
# 普通はダイクストラ法を回す。O(V^2logV)
# つまり、あまり使われない(´；ω；`)

v = 4
e = 5
r = 0
es = [[2,0,4],[1,2,2],[0,1,1],[1,3,5],[2,3,1]]
dp = Array.new(v){Array.new(v) {Float::INFINITY}}

v.times {|i| dp[i][i] = 0}
es.each do |array|
  dp[array[0]][array[1]] = array[2]
  dp[array[1]][array[0]] = array[2]
end


v.times do |k|
  v.times do |i|
    v.times do |j|
      dp[i][j]=[dp[i][j],dp[i][k]+dp[k][j]].min
    end
  end
end

v.times do |i|
  ans = []
  v.times do |j|
    if dp[i][j] == Float::INFINITY
      ans << "INF"
    else
      ans << dp[i][j]
    end
  end
  p ans
end