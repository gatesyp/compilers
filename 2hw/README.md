# Istvan Gates
# Homework 2

##Introduction

Lexical analysis is the first phase of a compiler. It breaks a character stream into a series of tokens, and removes and comments and/or whitespace from the stream. Each token is defined already by the implementation of the compiler. A token is a symbol which has a name (id) and an optional attribute. These tokens are commonly held in a symbol table. The next step is a syntax analyzer, which requests token from the lexical analyzer as needed. 
In this project, we successfully implement a lexer which strips all whitespace and tokenizes the resulting ‘sentence’. The purpose of the lexer is to support a console based calculator application, and supports all common operations. 

##Procedure
	The project is relatively simple. First, the tokens defined in our enumeration. Nineteen of these token exist in the Token_List enumeration, which also gives each token its id. The struct Token holds the definition for each of these tokens, and has a member variable of type string which can hold the optional attribute. 
	The Lexer struct defines the actual lexer. It holds a char* which points to the first character in the string, and also one to point at the last element. The default constructor simply initializes the object to default (null) values, and the string constructor will take in the sentence to be parsed and sets the first/last pointers appropriately. 
	There are a few auxiliary functions such as is_eof(), lookahead(), consume() and comments(). Respectively, these functions return a bool if the end of string has been reached, iterates over the string and adds a character to the buffer, returns the next character in buffer, and treats the rest of a string as comment (ignores them). 
	The most important function is the next() function. This function will return a proper token, and matches the current character it is examining. Depending on the type of token, it will either write to the buffer (e.g. 523) or clears the buffer (e.g. 523 + 3 will clear the buffer after 523 had been tokenized, because the + character had been detected). This function simply has a series of switch statements, where each case will return a specific token. The next() function handles comments appropriately - when it sees the comment token (‘#’), it will consume the rest of the string and returns the comment as a token. In practice this comment token could be stripped out and never returned, as the rest of the compiler will never have to use this information. 
	There is a lexerHandler as well. This handler simply creates the lexer struct, strips all whitespace, passes in the string from console input, and keeps track of all the tokens that are returned. When all tokens had been returned and printed to the console, the loop repeats itself and the handler awaits new input. 


