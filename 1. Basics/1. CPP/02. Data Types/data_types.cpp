// 1. Basic Classification

// C++ data types are broadly categorized into:

//     Primitive (Built-in) Types

//     Derived Types

//     User-defined Types

// 2. ✅ Primitive Data Types
// Type	Description	Example
// int	Integer values	int a = 10;
// float	Floating-point (single precision)	float b = 5.67f;
// double	Floating-point (double precision)	double d = 9.99;
// char	Single character	char c = 'A';
// bool	Boolean (true or false)	bool flag = true;
// void	Represents absence of value	Used in functions
// 3. 🧮 Integer Types with Size Modifiers
// Type	Size (Typically)	Range (Signed)
// short int	2 bytes	-32,768 to 32,767
// int	4 bytes	-2,147,483,648 to 2,147,483,647
// long int	4 or 8 bytes	Larger range than int
// long long int	8 bytes	Very large range
// Unsigned versions	Same size	Only positive values
// 4. 🔠 Character Types

//     char → 1 byte (stores ASCII values)

//     Can be signed or unsigned

// 5. 🔍 Floating Point Types
// Type	Size	Precision
// float	4 bytes	~6-7 digits
// double	8 bytes	~15 digits
// long double	10+ bytes	Higher precision
// 6. 🎯 Boolean Type

//     bool: Represents true or false

//     Internally stored as 1 or 0

// 7. 🧩 Derived Data Types

//     Arrays: int arr[5];

//     Pointers: int* ptr;

//     Functions: Return types and parameters

//     References: int &ref = x;

// 8. 🏗️ User-defined Data Types
// Type	Description
// struct	Group of variables of different types
// class	Blueprint for objects (OOP)
// union	Like struct, but shares memory
// enum	Named set of integral constants
// typedef / using	Aliases for data types
// 9. 📏 Type Modifiers

// Used to change data range/precision:

//     signed, unsigned

//     short, long

// Example:

// unsigned int a = 10;
// long double pi = 3.1415926535;

// 10. 📌 Type Conversion

//     Implicit: Automatically done by compiler

//     Explicit (Casting): Done manually

// int a = 5;
// double b = (double)a;