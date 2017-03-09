#ifndef LEX_HPP
#define LEX_HPP
#include "ast.hpp"
#include <typeinfo>
#include <cassert>
#include <string>
#include <iostream>
// We define each type of token our lexer supports. 
enum Token_kind {
    EOF_tok, Plus_tok, 
    Minus_tok, Mul_tok,
    Div_tok, Mod_tok, 
    Amp_tok, Or_tok,
    Not_tok, Eq_tok,
    Neq_tok, Lt_tok,
    Gt_tok,  LtEq_tok, 
    GtEq_tok, Qu_tok,
    Colon_tok, LeftParen_tok,
    RightParen_tok, Int_tok,
    Bool_tok, Comm_tok,
    BitLeft_tok, BitRight_tok,
    Xor_tok, Comp_tok,
};

// Token object represents each token, has an optional string attribute and an id which corresponds to the enum
struct Token {
    int kind;
    std::string attribute;
    Token() {}
    Token(Token_kind k, int a)
        :kind(k), attribute(std::to_string(a)) {}
    Token(Token_kind k, std::string str)
        :kind(k), attribute(str) {}
    virtual ~Token() = default;

};

// Define our int and bool tokens - note we are not using the optional string attribute
struct Int_token : Token {
    int value;
};
struct Bool_token : Token {
    bool value;
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
        n = 0;
        buf = "";
        const char* first = nullptr;
        const char* last = nullptr;
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

    // Detect if a comment was placed and handle appropriately (ignore it)
    void comments() {
        while (first != last) {
            consume();
        }
    }

    // Actually tokenize the input
    Token *next();
};


Token *Lexer::next() {
    // Hold our token
    Token *tok;
    // Use a temp variable to make code a bit cleaner
    std::string temp;
    // Detect comments
    if (lookahead() == '#') {
        comments();
        temp = buf; 
        // Clear buffer
        buf = "";
        // Return the token with comments
        return new Token(Comm_tok, temp);
    }
    // Handle each token case
    switch (lookahead()) {
        case '<': consume();
                  if (lookahead() == '=') {
                      consume();
                      buf = "";
                      return new Token(LtEq_tok, 0);
                  }
                  if (lookahead() == '<') {
                      consume();
                      buf = "";
                      return new Token(BitLeft_tok, 0);
                  }
                  buf = "";
                  return new Token(Lt_tok, 0);
        case '>': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(GtEq_tok, 0);
                  }
                  if (lookahead() == '>') {
                      consume();
                      buf = "";
                      return new Token(BitRight_tok, 0);
                  }
                  buf = "";
                  return new Token(Gt_tok, 0);
        case '+': consume();
                  buf = "";
                  return new Token(Plus_tok, 0);
        case '-': consume();
                  buf = "";
                  return new Token(Minus_tok, 0);
        case '*': consume();
                  buf = "";
                  return new Token(Mul_tok, 0);
        case '/': consume();
                  buf = "";
                  return new Token(Div_tok, 0);
        case '%': consume();
                  buf = "";
                  return new Token(Mod_tok, 0);
        case '&': consume();
                  if (lookahead() == '&') {
                      consume();
                      buf = "";
                      return new Token(Amp_tok, 0);
                  } else {
                      std::cout << "ERRRORORORO!";
                  }
        case '|': consume();
                  if(lookahead() == '|') {
                      consume();
                      buf = "";
                      return new Token(Or_tok, 0);
                  } 
        case '=': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(Eq_tok, 0);
                  } 
        case '!': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(Neq_tok, 0);
                  } else {
                      buf = "";
                      return new Token(Not_tok, 0);
                  }
        case ')': consume();
                  buf = "";
                  return new Token(LeftParen_tok, 0);
        case '(': consume();
                  buf = "";
                  return new Token(RightParen_tok, 0);
        case '^': consume();
                  buf = "";
                  return new Token(Xor_tok, 0);
        case 't':consume();
                 if (lookahead() == 'r') {
                     consume();
                     if (lookahead() == 'u') {
                         consume();
                         if (lookahead() == 'e') {
                             consume();
                             buf = "";
                             return new Token(Bool_tok, 1);
                         }
                     }
                 }
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
                                  return new Token(Bool_tok, 0);
                              }
                          }
                      }
                  }
        case '0':
        case '1':
        case '2':
        case '3':
                  std::cout << "next is a 3";
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': consume();
                  while(std::isdigit(lookahead())) {
                      consume();
                  }
                  n = std::stoi(buf);
                  tok = new Token(Int_tok, buf);
                  buf = "";
                  return tok;
        default: return new Token(Bool_tok, "Default");
    }
};
#endif
