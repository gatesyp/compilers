#include <iostream>
#include <string>
#include "ast.hpp"
#include "lex.hpp"
#include <vector>

using namespace std;

// helper function to remove all whitespace
std::string stripWhiteSpace(std::string& str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

int main() {
	std::vector<Token*> toks; 
	Token* tok = new Token();

	while (true) {
        //string input;
        string input;
        getline(cin, input);    

        // handle case where nothing was inputted
        if (input == "")
            break;
        input = stripWhiteSpace(input);
        Lexer lex = Lexer(input);
        while(lex.first != lex.last){
            tok = lex.next();
            toks.push_back(tok);
        }

        tok = lex.next();
        toks.push_back(tok);


        for(int i = 0; i < toks.size(); i++) {
            cout << "<kind: " << toks[i]->kind << ", attr: " << toks[i]->attribute <<">";
            cout << "\n";
        }
    }
}
