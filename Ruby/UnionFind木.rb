# https://www.slideshare.net/iwiwi/ss-3578491

N = 5
par = Array.new(N)

N.times do |n|
	par[n] = n
end

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

p par
p find(3,par)
p same(2,3,par)
union(3,4,par)
p par
p same(3,4,par)
