# C++ Basics

---
## 1. Comments

```c++
/* C-Style Comments must be enclosed like this and can span
an arbitrary number of lines. And can also end
in the middle of one */ std::cout << "Hello World!";
```

Comments are **completely ignored** by the compiler:
- because the Preprocessor has already removed them
- C-Style comments cannot be nested!

```c++
/* nested C-Style Comments /* are bound */
 to produce nasty effects */
```

```c++
// C++-Style comments look like this...
// ... and span the remainder of the line
```

```c++
// C++-Style comments will disable /* C-Style Comments:
std::cout << "Hello World!";
```

```c++
/* C-Style comments will also disable 
// C++-Style Comments: */ std:: cout << Hello World!";
```

```c++
// But you cannot end one with the other */ (this is still a comment)
```

---

## 2. Output with cout (`<iostream>`
```c++
cout << "Hello World" << endl;
int i = 10;
cout << "i is" << i << endl;
```

- `cout` writes text to the `standard output` (normally: text console)
- `<<` is called the `stream operator`
- `endl` is a special value and represents
  - a line break
  - and a signal to `flush` the `output buffer`
- output is `buffered`
  - it is not written immediately
  - but collected for some time
  - and then written in one go
  - for performance reasons

---

## 3. Variables – Declaration & Initialization
```c++
DataType VariableName [, VariableName ...];
```
```c++
int a;
int b, c;
```
```c++
int a=10;
int b=20, c=30;
```
- Declares a `variable`
- Every variable must be **declared** before use (different than scripting languages)
- **Value** of variable is random at first! (i.e. unpredictable)
  - This is **not true** for all types of variables... but don’t take any chances
- Variables can be **initialized** on declaration

---

## 4. Variables - Scopes 1
- The area where the variable is valid is called the **scope** of the variable
- A variable is:
  - Only valid within the file where is was declared
(even though it is possible to access one variable from several different files)
  - Valid only from the **line** where is was first declared **downward**
  - Valid only within the **curly braces block** `{...}` where is was declared
  - And naturally within all `{...}` blocks within this block

---

## 5. Variables - Scopes 2
```c++
int i=10;
{
	int i=20;
	cout << i << endl;		// Output: 20
}
cout << i << endl;			// Output: 10
```
- There is one `global scope` (outside all curly braces blocks)
- Every variable name must be **unique** within its scope
  - i.e. inside a curly braces block you **cannot declare two variables with the same name**
- In nested scopes there can be **duplicate** variable names
  - In such a case, the variable in the innermost scope will hide the others

---

## 6. Pretty Table

| **Name**  |   **Minimum**   |  **Maximum**  |  **Bits**  |
|---|---|---|---|
|  bool  |  false  |  true  |  8 - 32*  |   
|  (signed) char  |  -128  |  127  |  8  |   
|  unsigned char  |  0  |  255  |  8  |   
|  enum  |  -2.147.483.648   |  2.147.483.647   |  32  |   
|  (signed int)  |  -2.147.483.648   |  2.147.483.647   |  32  |   
|  unsigned int  |  0  |  4.294.967.295   |  32  |   
|  short int  |  -32.768   |  32.767  |  16  |   
|  (signed) long  |  -2.147.483.648   |  2.147.483.647  |  64  |   
|  unsigned long  |  0  |  4.294.967.295   |  64  |   
|  float  |  3,4E-38  |  3,4E+38  |  32  |   
|  double  |  1,7E-308  |  1,7E+308  |  64  |   
|  long double  |  3,4E-4932  |  1,1E+4932  |  80  |   

---

## 7. Input With Cin
```c++
int i;
cin >> i;

cout << „i is “ << i;
```
- `cin` will read contents of a variable from the standard input
- An example is normally from the command line

---

## 8. Arithmetic Operators

|  **Character**  |  **Explanation**  |
|---|---|
|  +  |  Addition  |
|  -  |  Subtraction |
|  *  |  Multiplication |
|  /  |  Division |
|  %  |  Modulo (rest of whole-number division) |
|  ++  |  Increment (prefix/postfix) |
|  --  |  Decrement (prefix/postfix) |

## 8.1 Comparison Operators
|  **Character**  |  **Explanation**  |
|---|---|
|  ==  |  equals |
|  !=  |  Does not equal |
|  <, >  |  Smaller than, Greater than |
|  <=, >=  | Smaller or equals, greater or equals  |


---

## 9. Logical Operators


|  Character  |  Explanation  |
|---|---|
|  !  |  Not (Logical Negation)  |
|  &&  |  And  |
|  \|\| |  Or  |

---

## 10. Bitwise Operators

|  Character  |  Explanation  |
|---|---|
|  ~  |  Not (bitwise complement) |
|  &  |  And (bitwise)  |
|  \|  |  Or (bitwise) |
|  ^  | Xor (bitwise)  |
|  >>  |  Shift Right (bitwise shift right) |
| <<   |  Shift Left (bitwise shift left) |

---

## 11. Assignment Operators

- Assignment:
  - `=`

- Combined operators:
  - `+=`
  - `-=`
  - `*=`
  - `/=`
  - `%=`
  - `|=`
  - `&=`
  - `^=`
  - `<<=`
  - `>>=`

- Examples:
  - `a += 2;` instead of `a = a +2;`
  - `a *= 2; ` instead of `a = a * 2;`
 
 ---
 
 ## 12. Control Structures
 - Controls the flow of program execution
 - i.e. everything that is **not** linear (sequential) execution
 
 - **Jumps - Unconditional**
   - `goto`, `break` and `continue`
 - **Branches - Conditional**
   - `if` and `switch`
- **Loops**
  - `for`, `while`and `do...while`

---

## 13. If
```c++
if( Condition ) { ... }
if( Condition ) { ... } else { ... }

if( a == b ) 
{ 
	cout << „equal“; 
} else {
	cout << „not equal“;
}

```


---

## 14. For - Loops
```c++
for( Initialization; Condition; PostCycleInstruction) 
{ 
	... 
}
````

```c++
for(i=0; i<100; ++i)
{
	cout << i << endl;
}
```

- Empty commands are allowed when:
```c++
for(;;)
{
	cout << „endless...“ << „\n“;
}
```

---

## 15. For - Loops (2)
```c++
for(int i=0; i<100; ++i)
{
	cout << i << „\n“;
}
```
- Declaration of run-variable in loop head
- Standard says: scope of `i` is loop body
  - has not always been like that; only in newer version of standard
  - `MS-VC++` has got (just like many other compilers) an option for this behavior (default is true)

---

## 16. While - Loop
```c++
while (Condition) 
{ 
	... 
}
```
```c++
int i=0;
while(i<100)
{
	cout << i++ << „\n“;
}
```
- Condition checked **before** every cycle of the loop
- i.e. loop may never be executed

---

## 17. Do...While - Loop
```c++
do	
{ 
	... 
} while (condition)
```
```c++
i=0;
do {
	cout << i++ << „\n“;
} while (i<100);
```
- Condition checked **after** every cycle of the loop
- i.e. loop will be executed at least once

---

## 18. Break and Continue
- **Break:** 
  - Terminates the current `loop` immediately 
  - Possible only within a `loop` or switch statement
- **Continue:** 
  - Terminates current cycle of the `loop` immediately, but continues right away with next cycle (i.e. skips remainder of current cycle)
possible only within a loop

---

## 19. Goto
```c++
here:
	cout << "blah" << endl;

	goto here;
```
- Labels can be placed **anywhere** in the code
- Names are arbitrary and end with a colon **:**
- `goto` will jumps directly to a label

- **Is goto „evil“?**
  - Yes... no... maybe ☺
  - Goto spoils structure; makes code harder to read and more error-prone
  - Fact: you don’t need it
  - It is there because it works (C allows you every freedom!)
  - Professionals say: goto is useful to write very efficient/short code
you are not professionals! (yet)

--- 

## 20. Switch - 1
```c++
cin << i;
switch(i)
{
	case 1: cout << „one“; break;
	case 2: cout << „two“; break;
	case 3: cout << „three“; break;
	default: cout << „something else“;
}
```
- Works (unfortunately) only with `integer` types
- Is much more efficient than a number of `ifs`
  - Implemented as a **jump-table** (therefore only works with integers)
- Cases are just jump labels, execution will continue sequentially
- Therefore: break after every case (leaves the switch)
- Otherwise: fall-through (can be used intentionally!)
default is optional

---

## 21. Switch - 2
```c++
switch(i)
{
	case 1:
		int i = 10;			// Error!
		break;
	case 2:
		{
			int i = 10; 		// ok;
		}
		break;
}
```
- Declaration of variables inside a switch statement is **not** allowed  (why not?)
- Therefore: open a scope with `{ }`!
- Break can be used inside or outside or the `{ }` block


--- 

