# Main
all: lexer.o
	g++ lexer.o main.cpp -o shmath -Wall
	rm *.o

lexer.o: token.h
	g++ -c lexer.cpp

run:
	./shmath

clear:
	rm *.o