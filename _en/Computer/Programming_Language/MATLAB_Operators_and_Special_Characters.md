---
layout:    en_post
Topic:     Programming Language
Title:     MATLAB Operators and Special Characters
Revised:   2017-07-22 17:46:00 +08 @ China-Xinjiang-Urumqi +06
Authors:   BSS9395
Resources: 
---

> ### Arithmetic Operators

> | __Symbol__ | __Operator__ | __Role__                                 |
> | :--------- | :----------- | :--------------------------------------- |
> | _`'`_      | _ctranspose_ | Complex conjugate transpose              |
> | _`*`_      | _mtimes_     | Matrix multiplication                    |
> | _`+`_      | _plus_       | Addition                                 |
> | _`+`_      | _uplus_      | Unary plus                               |
> | _`-`_      | _minus_      | Subtraction                              |
> | _`-`_      | _uminus_     | Unary minus                              |
> | _`.'`_     | _transpose_  | Transpose                                |
> | _`.*`_     | _times_      | Element-wise multiplication              |
> | _`./`_     | _rdivide_    | Element-wise right division              |
> | _`.\`_     | _ldivide_    | Element-wise left division               |
> | _`.^`_     | _power_      | Element-wise power                       |
> | _`/`_      | _mrdivide_   | Matrix right division                    |
> | _`\`_      | _mldivide_   | Matrix left divison (also known as backslash) |
> | _`^`_      | _mpower_     | Matrix power                             |

> ### Relational Operators

> | __Symbol__ | __Operator__ | __Role__                 |
> | :--------- | :----------- | :----------------------- |
> | _`<=`_     | _le_         | Less than or equal to    |
> | _`<`_      | _lt_         | Less than                |
> | _`==`_     | _eq_         | Equal to                 |
> | _`>=`_     | _ge_         | Greater than or equal to |
> | _`>`_      | _gt_         | Greater than             |
> | _`~=`_     | _ne_         | Not equal to             |

> ### Logical Operators

> | __Symbol__ | __Operator__                             | __Role__                            |
> | :--------- | :--------------------------------------- | :---------------------------------- |
> | _`&&`_     | _Logical Operators: Short-Circuit && \|\|_ | Logical AND (with short-circuiting) |
> | _`&`_      | _and_                                    | Logical AND                         |
> | _`|`_      | _or_                                     | Logical OR                          |
> | _`||`_     | _Logical Operators: Short-Circuit && \|\|_ | Logical OR (with short-circuiting)  |
> | _`~`_      | _not_                                    | Logical NOT                         |

> ### Special Characters

> | __Symbol__ | __Name__                  | __Role__                                 | __`Description                             `__ |
> | :--------- | :------------------------ | :--------------------------------------- | :--------------------------------------- |
> | _`!`_      | `Exclamation point`       | ***• Operating system command***         | The exclamation point precedes operating system commands that you want to execute from within MATLAB. |
> | _`""`_     | `Double quotes`           | ***• String constructor***               | Use double quotes to create string scalars that have class string. |
> | _`%`_      | `Percent`                 | ***• Comment*** ***• Conversion specifier*** | The percent sign is most commonly used to indicate nonexecutable text within the body of a program. This text is normally used to include comments in your code. Some functions also interpret the percent sign as a conversion specifier. Two percent signs, %%, serve as a cell delimiter as described in Run Code Sections. |
> | _`%{ %}`_  | `Percent curly bracket`   | ***• Block comments***                   | The %{ and %} symbols enclose a block of comments that extend beyond one line. |
> | _`''`_     | `Single quotes`           | ***• Character array constructor***      | Use single quotes to create character vectors that have class char. |
> | _`( )`_    | `Parentheses`             | ***• Operator precedence*** ***• Function argument enclosure*** ***• Indexing*** | Use parentheses to specify precedence of operations, enclose function input arguments, and index into an array. |
> | _`,`_      | `Comma`                   | ***• Separator***                        | Use commas to separate row elements in an array, array subscripts, function input and output arguments, and commands entered on the same line. |
> | _`...`_    | `Dot dot dot or ellipsis` | ***• Line continuation***                | Three or more periods at the end of a line continues the current command on the next line. If three or more periods occur before the end of a line, then MATLAB ignores the rest of the line and continues to the next line. This effectively makes a comment out of anything on the current line that follows the three periods. |
> | _`.`_      | `Period or dot`           | ***• Decimal point*** ***• Element-wise operation*** ***• Structure field access*** ***• Object property or method specifier*** | The period character separates the integral and fractional parts of a number, such as 3.1415. MATLAB operators that contain a period always work element-wise. The period character also enables you to access the fields in a structure, as well as the properties and methods of an object. |
> | _`:`_      | `Colon`                   | ***• Vector creation*** ***• Indexing*** ***• For-loop iteration*** | Use the colon operator to create regularly spaced vectors, index into arrays, and define the bounds of a for loop. |
> | _`;`_      | `Semicolon`               | ***• Signify end of row*** ***• Suppress output of code line*** | Use semicolons to separate rows in an array creation command, or to suppress the output display of a line of code. |
> | _`=`_      | `Equal sign`              | ***• Assignment***                       | Use the equal sign to assign values to a variable. The syntax B = A stores the elements of A in variable B. |
> | _`?`_      | `Question mark`           | ***• Metaclass for MATLAB class***       | The question mark retrieves the meta.class object for a particular class name. The ? operator works only with a class name, not an object. |
> | _`@`_      | `At symbol`               | ***• Function handle construction and reference*** | The @ symbol forms a handle to either the named function that follows the @ sign, or to the anonymous function that follows the @ sign. |
> | _`[ ]`_    | `Square brackets`         | ***• Array construction*** ***• Array concatenation*** ***• Empty matrix and array element deletion*** ***• Multiple output argument assignment*** | Square brackets enable array construction and concatenation, creation of empty matrices, deletion of array elements, and capturing values returned by a function. |
> | _`N/A`_    | `Space character`         | ***• Separator***                        | Use the space character to separate row elements in an array constructor, or the values returned by a function. In these contexts, the space character and comma are equivalent. |
> | _`{ }`_    | `Curly brackets`          | ***• Cell array assignment and contents*** | Use curly braces to construct a cell array, or to access the contents of a particular cell in a cell array. |
> | _`~`_      | `Tilde`                   | ***• Logical NOT*** ***• Argument placeholder*** | Use the tilde symbol to represent logical NOT or to suppress output of specific output arguments. |

> ### String and Character Formatting

> | __Symbol__ | __Name__              | __Role__                               | __`Description                             `__ |
> | :--------- | :-------------------- | :------------------------------------- | :--------------------------------------- |
> | _`*`_      | `Asterisk`            | ***• Wildcard character***             | In addition to being the symbol for matrix multiplication, the asterisk * is used as a wildcard character. Wildcards are generally used in file operations that act on multiple files or folders. MATLAB matches all characters in the name exactly except for the wildcard character *, which can match any one or more characters. |
> | _`+`_      | `Plus`                | ***• Package directory indicator***    | A + sign indicates the name of a package folder. |
> | _`..`_     | `Dot dot`             | ***• Parent folder***                  | Two dots in succession refers to the parent of the current folder. Use this character to specify folder paths relative to the current folder. |
> | _`/` `\`_  | `Slash and Backslash` | ***• File or folder path separation*** | In addition to their use as mathematical operators, the slash and backslash characters separate the elements of a path or folder. On Microsoft® Windows® based systems, both slash and backslash have the same effect. On The Open Group UNIX® based systems, you must use slash only. |
> | _`@`_      | `At symbol`           | ***• Class folder indicator***         | An @ sign indicates the name of a class folder. |

> | __Symbol__ | __Effect on Text__      |
> | :--------- | :---------------------- |
> | _`%%`_     | `Single percent sign`   |
> | _`''`_     | `Single quotation mark` |
> | _`\\`_     | `Single backslash`      |
> | _`\a`_     | `Alarm`                 |
> | _`\b`_     | `Backspace`             |
> | _`\f`_     | `Form feed`             |
> | _`\n`_     | `New line`              |
> | _`\N`_     | `Octal number, N`       |
> | _`\r`_     | `Carriage return`       |
> | _`\t`_     | `Horizontal tab`        |
> | _`\v`_     | `Vertical tab`          |
> | _`xN`_     | `Hexadecimal number, N` |

> ### Operator Precedence

> | 01   | `Parentheses ()`                         |
> | :--- | :--------------------------------------- |
> | 02   | `Transpose (.'), power (.^), complex conjugate transpose ('), matrix power (^)` |
> | 03   | `Power with unary minus (.^-), unary plus (.^+), or logical negation (.^~) as well as matrix power with unary minus (^-), unary plus (^+), or logical negation (^~).` |
> | 04   | `Unary plus (+), unary minus (-), logical negation (~)` |
> | 05   | `Multiplication (.*), right division (./), left division (.\), matrix multiplication (*), matrix right division (/), matrix left division (\)` |
> | 06   | `Addition (+), subtraction (-)`          |
> | 07   | `Colon operator (:)`                     |
> | 08   | `Less than (<), less than or equal to (<=), greater than (>), greater than or equal to (>=), equal to (==), not equal to (~=)` |
> | 09   | `Element-wise AND (&)`                   |
> | 10   | `Element-wise OR (|)`                    |
> | 11   | `Short-circuit AND (&&)`                 |
> | 12   | `Short-circuit OR (||)`                  |