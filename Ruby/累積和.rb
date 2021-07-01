# https://qiita.com/drken/items/56a6b68edef8fc605821

N = 6
array = [3,7,6,1,9,5]

# arrayの〇番目までの和(array[0]は1番目)
ruiseki = Array.new(N+1) { 0 } 
array.length.times do |i|
  ruiseki[i+1] = ruiseki[i] + array[i]
end

p ruiseki
p ruiseki[6] - ruiseki[2]