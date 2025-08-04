# Main
all: mathExp.o opTree.o
	gcc mathExp.o opTree.o shmath.c -o shmath -Wall
	rm *.o

mathExp.o: mathExp.h
	gcc -c mathExp.c

opTree.o: opTree.h
	gcc -c opTree.c

run:
	./shmath

clear:
	rm *.o