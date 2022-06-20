/* Postfix_Expression.cpp
Author: BSS9395
Update: 2022-06-17T21:16:00+08@China-Shanghai+08
Design: Postfix_Expression
*/

#include<iostream>  
#include<string>  
#include<stack>  
using namespace std;
typedef unsigned int uint;
typedef intptr_t     iptr;

class Calculator {
public:
	static iptr _Priority(char oper) {
		if (oper == '+' || oper == '-') {
			return 2;
		}
		else if (oper == '*' || oper == '/') {
			return 3;
		}
		throw "error";
	}

	static string _Infix_To_Postfix(string infix = "1+(2-3)*4+4/2") {
		stack<char> run;
		string postfix = "";
		for (char* iter = &infix[0], *end = &infix[infix.length()]; iter < end;) {
			if (iter[0] == ' ' || iter[0] == '\t' || iter[0] == '\v' || iter[0] == '\r' || iter[0] == '\n' || iter[0] == '\f') {
				;
			}
			else if (iter[0] == '(') {
				run.push(iter[0]);
			}
			else if (iter[0] == ')') {
				while (0 < run.size() && run.top() != '(') {
					char oper = run.top();
					postfix += oper;
					run.pop();
				}
				if (0 < run.size() == false) {
					throw "error";
				}
				run.pop();
			}
			else if ('0' <= iter[0] && iter[0] <= '9') {
				postfix += iter[0];
			}
			else if (iter[0] == '+' || iter[0] == '-' || iter[0] == '*' || iter[0] == '/') {
				while(0 < run.size()) {
					char oper = run.top();
					if (oper == '(' || _Priority(oper) < _Priority(iter[0])) {
						break;
					}
					postfix += oper;
					run.pop();
				}
				run.push(iter[0]);
			}
			else {
				throw "error";
			}
			iter += 1;
		}
		while (0 < run.size()) {
			char oper = run.top();
			postfix += oper;
			run.pop();
		}
		return postfix;
	}

	// implement for one digit number.
	static iptr _Calculate_Postfix_Expression(string postfix = "123-4*+42/+") {
		stack<iptr> run;
		for (char* iter = &postfix[0], *end = &postfix[postfix.length()]; iter < end;) {
			if ('0' <= iter[0] && iter[0] <= '9') {  // digit
				run.push(iter[0] - '0');
			}
			else {                                   // operator
				iptr rhs = run.top();
				run.pop();
				iptr lhs = run.top();
				run.pop();

				if (iter[0] == '+') {
					lhs = lhs + rhs;
				}
				else if (iter[0] == '-') {
					lhs = lhs - rhs;
				}
				else if (iter[0] == '*') {
					lhs = lhs * rhs;
				}
				else if (iter[0] == '/') {
					lhs = lhs / rhs;
				}
				run.push(lhs);
			}
			iter += 1;
		}
		return run.top();
	}
};

int main(iptr argc, char* argv[]) {
	uint indent = 20;

	string infix = "1+(2-3)*4+4/2";
	string postfix = Calculator::_Infix_To_Postfix(infix);
	fprintf(stdout, "%*s: %s\n", indent, "infix expression", infix.c_str());
	fprintf(stdout, "%*s: %s\n", indent, "postfix expression", postfix.c_str());

	iptr result = Calculator::_Calculate_Postfix_Expression(postfix);
	fprintf(stdout, "%*s: %td\n", indent, "result", (iptr)result);
	return 0;
}
