C	program to calculate area and circumference of a circle
	100	format (E12.5)
	200	format (5(5X, E12.5))
		pi = 3.141593
C	read input
	20	read (5, 100) r
C	perform calculations
		a = pi * r ** 2
		c = 2. * pi * r
C	write output
		write (6, 200) r, a, c
C	repeat for next data card
		go to 20
		end
