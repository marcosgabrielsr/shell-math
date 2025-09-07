# Diretories
DIR_SRC = src
DIR_BUILD = build

# Files
MAIN = $(DIR_SRC)/main.cpp
LEXER = $(DIR_SRC)/lexer.cpp
TOKEN_H = $(DIR_SRC)/token.h
LEXER_H = $(DIR_SRC)/lexer.h
EXECUTABLE = $(DIR_BUILD)/shmath

# Main
all: lexer.o
	g++ lexer.o $(MAIN) -o $(EXECUTABLE) -Wall
	mv *.o $(DIR_BUILD)

lexer.o: $(TOKEN_H) $(LEXER_H)
	g++ -c $(LEXER)

run:
	./$(EXECUTABLE)

clear:
	rm -rf $(DIR_BUILD)/*