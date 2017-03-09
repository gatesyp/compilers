# compilers
# Istvan Gates
## Instructions
- Note: this was tested on Ubuntu 14.04
```
chmod +x run.sh
./run.sh
```
Overview
	This project successfully implements the standard logical operations, as well as arithmetic. The project is divided up into five main pieces. If a developer is looking to contribute a new expression, they would have to follow a few steps. 
	‘ast.hpp’ defines the Abstract Syntax Tree of our language. Talk about how each core element is created by structs, explain how the visitor pattern works, show that everything inherits from Expr struct. 
	The actual evaluation of an expression occurs in ‘eval.hpp’. This file contains only one function, eval, which accepts an expression as the argument. The first step in the function is choosing the correct overloaded visit function, which is determined by the argument passed in. The type of 
NOTE need to do dynamic type checking for CondrExpr? 
The expression is determined first, and then then function is evaluated accordingly. Lastly, a visitor object is created which is accepted by our expression. This is where the recursive calls may happen; by having the expression accept a new visitor, the expression will be recursively solved until it hits the base case. Finally, the result is returned. 
	In order to pretty print our results, the visit function is once more overloaded such that custom outputs may be printed for different types of expressions. For example first an expression is evaluated on if it requires parenthesis or not, and then the function is actually pretty printed. 
	Lastly, ‘type.hpp’ contains all type checking code. This way, our compiler will be able to check to see if inputs are used correctly with operands. 

