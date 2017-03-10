#include <iostream>
#include <string>
#include "ast.hpp"
#include "lex.hpp"
#include <vector>

// Remove all whitespace from input
std::string stripWhiteSpace(std::string& str){
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

void prettyPrintTokens(std::vector<Token*> tokenList){
        for(int i = 0; i < tokenList.size(); i++) {
            std::cout << "<kind: " << tokenList[i]->kind << ", attr: " << tokenList[i]->attribute <<">\n";
        }
}

int main() {
    // vector to hold our tokens
	std::vector<Token*> tokenList; 
	Token* token = new Token();

	while (true) {
        //string input;
        std::string input;
        getline(std::cin, input);    

        // handle case where nothing was inputted
        if (input == "")
            break;

        input = stripWhiteSpace(input);
        Lexer lex = Lexer(input);

        while(lex.first != lex.last){
            token = lex.next();
            tokenList.push_back(token);
        }

        // push the last item
        token = lex.next();
        tokenList.push_back(token);

        prettyPrintTokens(tokenList);
    }
}
