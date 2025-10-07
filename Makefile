# Diretories
DIR_SRC = src
DIR_BUILD = build

# Files
MAIN = $(DIR_SRC)/main.cpp
SCANNER = $(DIR_SRC)/scanner.cpp
PARSER = $(DIR_SRC)/parser.cpp
SYNTATIC_TREE = $(DIR_SRC)/syntatic-tree.cpp
TOKEN = $(DIR_SRC)/token.cpp
TOKEN_H = $(DIR_SRC)/token.h
SCANNER_H = $(DIR_SRC)/scanner.h
PARSER_H = $(DIR_SRC)/parser.h
SYNTATIC_TREE_H = $(DIR_SRC)/syntatic-tree.h
EXECUTABLE = $(DIR_BUILD)/shmath

# Main
all: $(EXECUTABLE)

$(EXECUTABLE): $(DIR_BUILD)/scanner.o $(DIR_BUILD)/parser.o $(DIR_BUILD)/syntatic-tree.o
	g++ $(DIR_BUILD)/scanner.o $(DIR_BUILD)/parser.o $(DIR_BUILD)/syntatic-tree.o $(MAIN) -o $(EXECUTABLE) -Wall

$(DIR_BUILD)/scanner.o: $(SCANNER) $(TOKEN_H) $(SCANNER_H)
	g++ -c $(SCANNER) -o $@ -Wall

$(DIR_BUILD)/syntatic-tree.o: $(SYNTATIC_TREE) $(TOKEN_H) $(SYNTATIC_TREE_H)
	g++ -c $(SYNTATIC_TREE) -o $@ -Wall

$(DIR_BUILD)/parser.o: $(PARSER) $(SCANNER_H) $(SYNTATIC_TREE_H) $(PARSER_H)
	g++ -c $(PARSER) -o $@ -Wall

run:
	./$(EXECUTABLE)

clear:
	rm -rf $(DIR_BUILD)/*