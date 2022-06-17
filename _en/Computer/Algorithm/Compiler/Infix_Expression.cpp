/* Infix_Expression.cpp
Author: BSS9395
Update: 2022-06-18T01:32:00+08@China-Shanghai+08
Design: Infix_Expression
Credit: https://blog.csdn.net/qq_26286193/article/details/80214805
*/

#include<iostream>  
#include<string>  
#include<stack>  
using namespace std;
typedef unsigned int uint;
typedef intptr_t     iptr;

class Calculator {
public:
	stack<double> _operand;
	stack<char> _operation;

public:
	iptr _Priority(char oper) {
		if (oper == '+' || oper == '-') {
			return 2;
		}
		else if (oper == '*' || oper == '/') {
			return 3;
		}
		throw "error";
	}

	void _Operate() {
		char oper = _operation.top();
		_operation.pop();
		double rhs = _operand.top();
		_operand.pop();
		double lhs = _operand.top();
		_operand.pop();
		if (oper == '+') {
			lhs = lhs + rhs;
		}
		else if (oper == '-') {
			lhs = lhs - rhs;
		}
		else if (oper == '*') {
			lhs = lhs * rhs;
		}
		else if (oper == '/') {
			lhs = lhs / rhs;
		}
		_operand.push(lhs);
	}

	double _Calculate(string infix = "1+(2-3)*4+10/2") {
		_operand = stack<double>();
		_operation = stack<char>();
		for (char* iter = &infix[0], *end = &infix[infix.length()]; iter < end;) {
			if (iter[0] == ' ' || iter[0] == '\r' || iter[0] == '\n' || iter[0] == '\t' || iter[0] == '\v') {
				iter += 1;
			}
			else if (iter[0] == '(') {
				_operation.push(iter[0]);
				iter += 1;
			}
			else if (iter[0] == ')') {
				while (0 < _operation.size() && _operation.top() != '(') {
					_Operate();
				}
				if (0 < _operation.size() == false) {
					throw "error";
				}
				_operation.pop();
				iter += 1;
			}
			else if ('0' <= iter[0] && iter[0] <= '9') {
				char* head = iter;
				while (iter += 1, iter < end && '0' <= iter[0] && iter[0] <= '9');
				if (iter[0] == '.') {
					while (iter += 1, iter < end && '0' <= iter[0] && iter[0] <= '9');
				}
				double number = strtold(string(head, iter).c_str(), NULL);
				_operand.push(number);
			}
			else if (iter[0] == '+' || iter[0] == '-' || iter[0] == '*' || iter[0] == '/') {
				while (0 < _operation.size()) {
					char oper = _operation.top();
					if (oper == '(' || _Priority(oper) < _Priority(iter[0])) {
						break;
					}
					_Operate();
				}
				_operation.push(iter[0]);
				iter += 1;
			}
			else {
				throw "error";
			}
		}

		while (!_operation.empty()) {
			_Operate();
		}
		return _operand.top();
	}
};

int main(int argc, char* argv[]) {
	uint indent = 20;

	string infix = "1+(2-3)*4+10/2";
	fprintf(stdout, "%*s: %s\n", indent, "infix expression", infix.c_str());

	double result = Calculator()._Calculate(infix);
	fprintf(stdout, "%*s: %lf\n", indent, "result", result);
	return 0;
}
