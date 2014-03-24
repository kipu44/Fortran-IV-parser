100	format (E12.5)
	read (5, 100) x
	y = 3. * x ** 3 + 7. * x ** 2 - 2. * x + 5.
	write (6, 100) y
	stop
	end
