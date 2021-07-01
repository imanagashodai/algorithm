# 蟻本 p162
# https://hcpc-hokudai.github.io/archive/structure_binary_indexed_tree_001.pdf

N = 4
a = [3,1,4,2]

bit = Array.new(N+1){0} # bit[0]は使わないため

def sum(i,bit)
	s = 0
	while i > 0 do
		s += bit[i]
		i -= i & -i
	end
	return s
end

def add(i,x,bit)
	while i <= N do
		bit[i] += x
		i += i & -i
	end
end

ans = 0
N.times do |n|
	ans += n - sum(a[n],bit)
	add(a[n],1,bit)
end

puts ans