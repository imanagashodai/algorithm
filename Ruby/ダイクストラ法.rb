v = 4
e = 5
r = 0
es = [[2,0,4],[1,2,2],[0,1,1],[1,3,5],[2,3,1]]
d = Array.new(v, Float::INFINITY)

priority_queue = [[r,0]]
d[r] = 0
until priority_queue.empty? do
  cur = priority_queue.shift[0]
  e.times do |i|
    if es[i][0] == cur || es[i][1] == cur
      if es[i][0] == cur
        nex = es[i][1]
      else
        nex = es[i][0]
      end
      dd = es[i][2] + d[cur]
      if dd < d[nex]
        d[nex] = dd
        ins = priority_queue.bsearch_index{|x| x[1] >= dd}
        if ins.nil?
          priority_queue << [nex,dd]
        else
          priority_queue.insert(ins,[nex,dd])
        end
      end
    end
  end
end

d.each do |i|
  if i == Float::INFINITY
    puts "INF"
  else
    puts i
  end
end