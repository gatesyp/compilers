#Emerson Cloud - Compiler Design - Homework 2
###Internal representation for a small expression language - Application in a Calculator

#Overview
The addition for Homework 2 is the addition of lexical analysis. Lexical analysis is the 
method by which the compiler takes external syntax and transforms it to internal syntax.
The internal syntax is made up of tokens that represent the semantics of the language. 
The lexer matches tokens to input lexemes, each with a name and attribute.

#Implementation
##Lexer
The lexer was implemented with 19 valid tokens in mind. Each token is described in the 
`Token_kind` enumeration. The token objects to be returned to the parser of the compiler are defined
in the struct 'Token'. `Token` defines an integer that corresponds to the `kind` of the token
enumerated in the enum `Token_kind`. `Token` also includes an optional attribute, which a string
simplicity. This integer represents the values help by integer tokens. There are two
constructors, a default and another that accepts a `Token_kind` and integer attribute.

In addition there is a struct `Lexer` that defines a lexer object. This object contains: a character
pointer to the first element, a character pointer to the last element and buffer string buf.
Also defined are several member functions; `eof()`- which returns true if the end of the object
is reached, `lookahead()` used to determine the next character to be lexed, `consume()` that adds
the next character to the buffer and increments the first pointer, and finally `next()` that performs
the `lookahead()`, `consume()` pattern until a token is returned. 

The `next()` function contains a switch statement to switch on each of the valid characters of the
language in order to make the proper token for that element. `next()` has the added benefit of ignoring
white-space inputted from the calculator. In addition `next()` ignores comments by calling `comments()`
until the end of the line.

##Calculator
The front end to the lexer and testing is contained in `lexmain.cpp`. Here input is taken in 
line by line and then put through the lexer and the tokens created are outputted. 
A while loop reads in each line from `std::cin` and creates a `Lexer` object with the line.
Then in a `while` loop the tokens are created from the `lexer.next()` function and appended
to a `toks` vector for holding.

#How to run
1. Clone repository
2. cd calculator
3. mkdir build
4. cd build
5. cmake ..
6. make
7. ./calc
