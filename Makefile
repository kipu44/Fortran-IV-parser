#!/bin/make

OPTIONS = -O3 -Wall

MODULS =	\
			block.o \
			comment.o \
			declarator.o \
			end.o \
			executableStatement.o \
			format.o \
			goTo.o \
			inOutStatement.o \
			inStatement.o \
			label.o \
			line.o \
			nonexecutableStatement.o \
			outStatement.o \
			program.o \
			read.o \
			statement.o \
			stop.o \
			write.o

main: main.cpp utils.o ${MODULS}
	g++ -o main ${OPTIONS} main.cpp utils.o ${MODULS}

utils.o: utils.cpp utils.h
	g++ -c ${OPTIONS} utils.cpp

clean:
	rm -f main *.o *.gch
