C program to calculate roots of a quadratic equation
C roots assumed to be real and distinct
	100	format (3E12.5)
	200	format (5(5X, E12.5))
C read input data
		read (5, 100) a, b, c
C calculate roots
		disc = (b ** 2 - 4. * a * c) ** .5
		x1 = (-b - disc) / (2. * a)
		x2 = (-b + disc) / (2. * a)
C write output
		write (6, 200) a, b, c, x1, x2
		stop
		end
