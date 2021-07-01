# https://www.slideshare.net/iwiwi/ss-3578491

N = 3
par = Array.new(N)

N.times do |n|
	par[n] = n
end

E = 3 # 経路の数

def find(x,par)
	return x if par[x] == x
	return par[x] = find(par[x],par)
end

def same(x,y,par)
	return find(x,par) == find(y,par)
end

def union(x,y,par)
	x = find(x,par)
	y = find(y,par)
	return if x == y
	par[x] = y
end

edges = [[20,0,1],[3,1,2],[100,2,0]]
edges.sort!

def kruskal(edges, par)
  res = 0
  edges.each do |edge|
  	if !same(edge[1],edge[2],par)
  		res += edge[0]
  		union(edge[1],edge[2],par)
  	end
  end
  return res
end

p kruskal(edges,par)