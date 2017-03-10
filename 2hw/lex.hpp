#ifndef LEX_HPP
#define LEX_HPP
#include "ast.hpp"
#include <typeinfo>
#include <cassert>
#include <string>
#include <iostream>
// We define each type of token our lexer supports
// Code from class
enum Token_kind {
    EOFTok, plusTok, 
    minusTok, mulTok,
    divTok, modTok, 
    ampTok, orTok,
    notTok, eqTok,
    neqTok, ltTok,
    gtTok,  ltEqTok, 
    gtEqTok, quTok,
    colonTok, leftParenTok,
    rightParenTok, intTok,
    boolTok, commTok,
    bitLeftTok, bitRightTok,
    xorTok, compTok,
};

// Token object represents each token, has an optional string attribute and an id which corresponds to the enum
// Code from class
struct Token {
    std::string attribute;
    int kind;
    Token(Token_kind k, int a)
        :kind(k), attribute(std::to_string(a)) {}
    Token(Token_kind k, std::string str)
        :kind(k), attribute(str) {}
    virtual ~Token() = default;

};

// Define our actual lexer 
struct Lexer {
    // Hold char pointers to the beginning of sentence and end of it
    const char* first;
    const char* last;
    int n;
    // String to hold the buffer
    std::string buf;

    // Default constructor simple intializes everything to null (or zero)
    Lexer() {
        const char* first = nullptr;
        const char* last = nullptr;
        buf = "";
        n = 0;
    }

    // String contructor initializes first and last
    Lexer(std::string str) {
        first = &str[0];
        last = &str[str.length()-1];
    }

    // Auxiliary function to check if we are at the end
    bool is_eof() {
        return first == last;
    }

    // Function to check what is next
    char lookahead() const {
        return *first;
    }

    // Iterates over the input and adds to buffer
    void consume() {
        buf += *first++;
    }

    // Actually tokenize the input
    Token *next();
};


Token *Lexer::next() {
    // Hold our token
    Token *tok;
    // Use a temp variable to make code a bit cleaner
    std::string t;
    // Detect comments
    if (lookahead() == '#') {
        while (first != last) {
            consume();
        }
        t = buf; 
        // Clear buffer
        buf = "";
        // Return the token with comments
        return new Token(commTok, t);
    }
    // Handle each token case
    switch (lookahead()) {
        case '+': consume();
                  buf = "";
                  return new Token(plusTok, 0);
        case '-': consume();
                  buf = "";
                  return new Token(minusTok, 0);
        case '*': consume();
                  buf = "";
                  return new Token(mulTok, 0);
        case '/': consume();
                  buf = "";
                  return new Token(divTok, 0);
        case '<': consume();
                  if (lookahead() == '=') {
                      consume();
                      buf = "";
                      return new Token(ltEqTok, 0);
                  }
                  if (lookahead() == '<') {
                      consume();
                      buf = "";
                      return new Token(bitLeftTok, 0);
                  }
                  buf = "";
                  return new Token(ltTok, 0);
        case '>': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(gtEqTok, 0);
                  }
                  if (lookahead() == '>') {
                      consume();
                      buf = "";
                      return new Token(bitRightTok, 0);
                  }
                  buf = "";
                  return new Token(gtTok, 0);
        case '=': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(eqTok, 0);
                  } 
        case '!': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(neqTok, 0);
                  } else {
                      buf = "";
                      return new Token(notTok, 0);
                  }
        case '&': consume();
                  if (lookahead() == '&') {
                      consume();
                      buf = "";
                      return new Token(ampTok, 0);
        case '|': consume();
                  if(lookahead() == '|') {
                      consume();
                      buf = "";
                      return new Token(orTok, 0);
                  } 
        case '%': consume();
                  buf = "";
                  return new Token(modTok, 0);
        case ')': consume();
                  buf = "";
                  return new Token(leftParenTok, 0);
        case '(': consume();
                  buf = "";
                  return new Token(rightParenTok, 0);
        case '^': consume();
                  buf = "";
                  return new Token(xorTok, 0);
        // Handle true boolean
        case 't':consume();
                 if (lookahead() == 'r') {
                     consume();
                     if (lookahead() == 'u') {
                         consume();
                         if (lookahead() == 'e') {
                             consume();
                             buf = "";
                             return new Token(boolTok, 1);
                         }
                     }
                 }
        // Handle false boolean
        case 'f': consume();
                  if (lookahead() == 'a') {
                      consume();
                      if (lookahead() == 'l') {
                          consume();
                          if (lookahead() == 's') {
                              consume();
                              if (lookahead() == 'e') {
                                  consume();
                                  buf = "";
                                  return new Token(boolTok, 0);
                              }
                          }
                      }
                  }
        // Handle int tokens. 
        // These will 'fall through' to capture multidigit integers
        case '0':
                  consume();
                  while(std::isdigit(lookahead()))
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        case '1':
                  consume();
                  while(std::isdigit(lookahead()))
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        case '2':
                  consume();
                  while(std::isdigit(lookahead())) 
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        case '3':
                  consume();
                  while(std::isdigit(lookahead())) 
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        case '4':
                  consume();
                  while(std::isdigit(lookahead())) 
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        case '5':
                  consume();
                  while(std::isdigit(lookahead())) 
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        case '6':
                  consume();
                  while(std::isdigit(lookahead()))
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        case '7':
                  consume();
                  while(std::isdigit(lookahead()))
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        case '8':
                  consume();
                  while(std::isdigit(lookahead()))
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        case '9':
                  consume();
                  while(std::isdigit(lookahead()))
                      consume();
                  n = std::stoi(buf);
                  tok = new Token(intTok, buf);
                  buf = "";
                  return tok;
        default: return new Token(boolTok, "default");
    }
};
#endif
