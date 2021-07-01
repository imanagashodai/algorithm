n,q = gets.split.map(&:to_i)

a = gets.split.map(&:to_i)
a.sort!
k = []
q.times do 
	k << gets.to_i
end

q.times do |i|
	key = true
	posq = a.bsearch_index{|x| x > k[i]}
	if posq.nil?
		puts n + k[i]
	elsif posq == 0
		puts k[i]
	else
		nowq = a.bsearch_index{|x| x > k[i] + posq}
		if nowq.nil?
			puts n + k[i]
			next
		end
		while posq != nowq do
			posq = nowq
			nowq = a.bsearch_index{|x| x > k[i] + posq}
			if nowq.nil?
				key = false
				puts n + k[i]
				break
			end
		end
		if key == true
			puts k[i] + posq
		end
	end


end