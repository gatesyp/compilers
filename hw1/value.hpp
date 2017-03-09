#ifndef VALUE_HPP
#define VALUE_HPP

// Define the kinds of value the compiler supports
enum ValueKind {
	intVal,
	boolVal,
};

// Define the value's data types
union ValueData {
	int n;
	bool b;
};

// Discriminated union or variant.
struct Value {
	ValueKind kind;
	ValueData data;
};

#endif
