C	Program to calculate roots of a quadratic equation
	100	format (3E12.5)
	200	format (5(5X, E12.5))
C	Read input data
	1	read (5, 100) a, b, c
C	test for a = 0
		if(a) 5, 40, 5
C	test sign of discriminant
	5	if(b**2 - 4.*a*c) 30, 20, 10
C	real, distinct roots
	10	disc = (b**2 - 4.*a*c)**.5
		x1 = (-b - disc) / (2.*a)
		x2 = (-b + disc) / (2.*a)
		go to 50
C	real, repeated roots
	20	x1 = -b / (2.*a)
		x2 = x1
		go to 50
C	complex roots
	30	root = (4.*a*c - b**2)**.5
		xreal = -b / (2.*a)
		ximag = root / (2.*a)
		go to 60
C	one real root
	40	x1 = -c / b
C	write output
		write (6, 200) a, b, c, x1
		write (6, 200)
		go to 1
	50	write (6, 200) a, b, c, x1, x2
		write (6, 200)
		go to 1
	60	write (6, 200) a, b, c
		write (6, 200) xreal, ximag
		write (6, 200)
		go to 1
		end
