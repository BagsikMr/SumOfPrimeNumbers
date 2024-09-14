# SumOfPrimeNumbers

## Table of contents
* [General info](#general-info)
* [Setup](#setup)
* [Input Format](#input-format)
* [Output Format](#output-format)
* [TODO](#todo)

## General info
This code is a C++ program that aims to find combinations of numbers that add up to a given input value. The program utilizes various functions and algorithms to calculate and display these combinations.<br />
For example:<br />
Input:<br />
16 7<br />
<br />
<br />
Output:<br />
7+3+2+2+2<br />
7+3+3+3<br />
7+5+2+2<br />
7+7+2<br />
<br />
(Yea, the entire code is written in Polish...)
	<br />
## Setup
Just run sln and follow [Input Format](#input-format).

## Input Format
The program expects input in the following format:
```cpp
<ilelini>
<liczba1> <maks1>
<liczba2> <maks2>
...
```
- `<ilelini>` represents the number of input lines.
- `<liczba>` represents a number to be checked and decomposed into combinations.
- `<maks>` represents the starting value for finding combinations.

## Output Format
The program outputs the combinations found for each input line. For example:
```cpp
<combination1>
<combination2>
...
```
Each combination is displayed as a sum of numbers, separated by `+`, followed by a newline character.

## TODO
-Translate the code into English.
-Change new and delete to smart pointers.
