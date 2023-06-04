# great-buct-compiler

 _Team project of Compiler Principles course_

## Introduction

This repository aims at creating a new programming language and building up a corresponding compiler for it as a final project of an undergraduate course.

## Structure

The overall structure of the design can be divided into following parts:

-[ ] Lexical Analyzer
-[ ] Syntax Parser
-[ ] Syntax-Directed Translator
-[ ] ?

## BUCTx

BUCTx is the new programming language we proposed in this project.

### Supported Characters

BUCTx supports following characters:

| Category       | Content                                                     |
|----------------|-------------------------------------------------------------|
| Lowercase Latin Letters | a b c d e f g h i j k l m n o p q r s t u v w x y z |
| Uppercase Latin Letters | A B C D E F G H I J K L M N O P Q R S T U V W Z X Y Z |
| Arabic Numerals | 0 1 2 3 4 5 6 7 8 9 |
| Mathematical Operators | + - * / ** % |
| Bitwise Operators | << >> ~ & \| ^ |
| Logical Operators | ! && \|\| |
| Comparison Operators | < <= >= > |
| Various Brackets | ( ) [ ] { } |
| Other Symbols | _ ' " . , |
| Whitespace Characters | tab newline space |

## Lexical Analyzer

Based on the characters supported by BUCTx, we declare following tokens for our lexical analyzer:

| Token (- Name)    | Explanation                       | Pattern (Regex)                                                                                                                                            |
|-------------------|-----------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| space             | Space                             | ( )                                                                                                                                                        |
| ws                | Whitespace Character              | {space}+                                                                                                                                                   |
| digit             | Arabic Numerals                   | 0\|1\|2\|3\|4\|5\|6\|7\|8\|9                                                                                                                               |
| letter            | Latin Letters                     | A\|B\|C\|D\|E\|F\|G\|H\|I\|J\|K\|L\|M\|N\|O\|P\|Q\|R\|S\|T\|U\|V\|W\|X\|Y\|Z\|a\|b\|c\|d\|e\|f\|g\|h\|i\|j\|k\|l\|m\|n\|o\|p\|q\|r\|s\|t\|u\|v\|w\|x\|y\|z |
| digits            | Multiple Digits                   | {digit}+                                                                                                                                                   |
| letter_           | Letter or Underscore              | {letter}\|_                                                                                                                                                |
| reserved          | Reserved Words                    | int\|main\|return\|float\|double\|string                                                                                                                   |
| identifier        | Identifier                        | {letter_}({letter_}\|{digit})*                                                                                                                             |
| number            | Real Number                       | {digits}(\.{digits})?(E{digits})?                                                                                                                          |
| SEMICOLON         | Semicolon                         | ;                                                                                                                                                          |
| ASSIGN            | Assignment Operator               | =                                                                                                                                                          |
| PLUS              | Plus Operator                     | +                                                                                                                                                          |
| MINUS             | Minus Operator                    | -                                                                                                                                                          |
| MULTIPLY          | Multiply Operator                 | *                                                                                                                                                          |
| POWER             | Power Operator                    | **                                                                                                                                                         |
| MOD               | Modulus Operator                  | %                                                                                                                                                          |
| LEFT_SHIFT        | Left Shift Operator               | <<                                                                                                                                                         |
| RIGHT_SHIFT       | Right Shift Operator              | >>                                                                                                                                                         |
| BIT_NOT           | Bitwise NOT Operator              | ~                                                                                                                                                          |
| BIT_AND           | Bitwise AND Operator              | &                                                                                                                                                          |
| BIT_OR            | Bitwise OR Operator               | \|                                                                                                                                                         |
| AND               | Logical AND Operator              | &&                                                                                                                                                         |
| OR                | Logical OR Operator               | \|\|                                                                                                                                                       |
| NOT               | Logical NOT Operator              | !                                                                                                                                                          |
| GT                | Greater Than Operator             | >                                                                                                                                                          |
| GEQ               | Greater Than or Equal To Operator | >=                                                                                                                                                         |
| LT                | Less Than Operator                | <                                                                                                                                                          |
| LEQ               | Less Than or Equal To Operator    | <=                                                                                                                                                         |
| SINGLE_QUOTE      | Single Quote                      | '                                                                                                                                                          |
| DOUBLE_QUOTE      | Double Quote                      | "                                                                                                                                                          |
| LEFT_BRACKET      | Left Parenthesis                  | (                                                                                                                                                          |
| RIGHT_BRACKET     | Right Parenthesis                 | )                                                                                                                                                          |
| LEFT_CURLYBRACE   | Left Curly Brace                  | {                                                                                                                                                          |
| RIGHT_CURLYBRACE  | Right Curly Brace                 | }                                                                                                                                                          |
| LEFT_SQUARE       | Left Square Bracket               | [                                                                                                                                                          |
| RIGHT_SQUARE      | Right Square Bracket              | ]                                                                                                                                                          |
| COMMA             | Comma                             | ,                                                                                                                                                          |