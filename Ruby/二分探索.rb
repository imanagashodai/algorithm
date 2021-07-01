# オリジナル

N = [6,20,9,21,1,50,7,0,3]

def func(array, num)
	return array.sort.bsearch{ |x| x >= num }
end

p func(N, 4)