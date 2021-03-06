# Istvan Gates
##Overview
###TO RUN
```
	git clone https://github.com/gatesyp/compilers-hw-1
	bash run.sh
	cd build
	./steve-compilers
```

###IMPLEMENTATION
	This project successfully implements the standard logical operations, as well as arithmetic. The project is divided up into five main pieces. If a developer is looking to contribute a new expression, they would have to follow a few steps. 
	‘ast.hpp’ defines the Abstract Syntax Tree of our language. Talk about how each core element is created by structs, explain how the visitor pattern works, show that everything inherits from Expr struct. 
	The actual evaluation of an expression occurs in ‘eval.hpp’. This file contains only one function, eval, which accepts an expression as the argument. The first step in the function is choosing the correct overloaded visit function, which is determined by the argument passed in. The type of the expression is determined first, and then the function is evaluated accordingly. Lastly, a visitor object is created which is accepted by our expression. This is where the recursive calls may happen; by having the expression accept a new visitor, the expression will be recursively solved until it hits the base case. Finally, the result is returned. 
	In order to pretty print our results, the visit function is once more overloaded such that custom outputs may be printed for different types of expressions. For example first an expression is evaluated on if it requires parenthesis or not, and then the function is actually pretty printed. 
	Lastly, ‘type.hpp’ contains all type checking code. This way, our compiler will be able to check to see if inputs are used correctly with operands. 
	The flow of the program is as follows: 
	First, we define the base classes of integers and boolean values. The language then defines the supported expressions which are all built on top of these two basic types. 
	The base Expr struct contains the same information as the base Type struct with an additional Type pointer, which contains the type of the expression (used for type checking). 
	The Visitor class (derived from Expr) defines each function that should be overridden by any deriving classes. This way, each expression will have their own definition of the visit function. 
	Then, type checking occurs. This ensures that proper variable types are used for proper expression (i.e true < false throws an assert). After type checking, the function eval is called. eval takes any expression and will return a value - each expression defines its own eval function. 
	The print function is the last function to be called. This will pretty print our expression with its own set of rules to ensure consistent output. For example, certain expressions require parenthesis while other do not. The print function determines the specials characters needed, and prints the expressions and evaluation result to the console. 

