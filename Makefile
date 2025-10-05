# Diretories
DIR_SRC = src
DIR_BUILD = build

# Files
MAIN = $(DIR_SRC)/main.cpp
SCANNER = $(DIR_SRC)/scanner.cpp
TOKEN_H = $(DIR_SRC)/token.h
SCANNER_H = $(DIR_SRC)/scanner.h
EXECUTABLE = $(DIR_BUILD)/shmath

# Main
all: scanner.o
	g++ scanner.o $(MAIN) -o $(EXECUTABLE) -Wall
	mv *.o $(DIR_BUILD)

scanner.o: $(TOKEN_H) $(SCANNER_H)
	g++ -c $(SCANNER)

run:
	./$(EXECUTABLE)

clear:
	rm -rf $(DIR_BUILD)/*