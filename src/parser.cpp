#include "parser.h"

Parser::Parser(string input)
{
    scanner = new Scanner(input);
    advance();
}