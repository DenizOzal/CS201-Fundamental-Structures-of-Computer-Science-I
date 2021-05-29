#include "StrangeCalculator.h"
string infix2prefix(const string exp) {
	// Creating a char stack object
	StackChar exp_stack;

	// Creating a string for storing postfix exression
	string preFixExp = "";

	// Creating a dynamic char array
	char* ch = new char[exp.length()];
	//cout << "Length: " << exp.length();

	// Temp char
	char temp_ch = ' ';

	// Reversing the exp
	string reverse_exp = "";
	reverse_exp = reverseString(exp);

	// Copying string exp items into the char array
	for (int i = 0; i < reverse_exp.length(); i++) {
		ch[i] = reverse_exp[i];
	}
	// Changing the way of paranthesis'
	for (int i = 0; i < reverse_exp.length(); i++) {
		if (ch[i] == '(') {
			ch[i] = ')';
		}
		else if (ch[i] == ')') {
			ch[i] = '(';
		}
	}

	for (int i = 0; i < reverse_exp.length(); i++) {
		// if ch is an operand
		if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= '0' && ch[i] <= '9')) {
			preFixExp += ch[i];
		}
		// if ch is open parenthesis push ch to the stack
		else if (ch[i] == '(') {
			exp_stack.push(ch[i]);
		}
		// if ch is close parenthesis pop the stack until matching '('
		else if (ch[i] == ')') {
			exp_stack.getTop(temp_ch);
			while (temp_ch != '(') {
				//cout << "ch: " << ch[i] << endl;
				exp_stack.pop(temp_ch);
				preFixExp += temp_ch;
				exp_stack.getTop(temp_ch);
			}
			exp_stack.pop(); // Remove the open parenthesis
		}
		// if ch is an operator
		else {
			exp_stack.getTop(temp_ch);
			while (!exp_stack.isEmpty() && temp_ch != '(' && ((precedence(ch[i]) < precedence(temp_ch)))) {
				exp_stack.pop(temp_ch);
				preFixExp += temp_ch;
			}
			exp_stack.push(ch[i]); // save new operator
			//cout << "operator: " << ch[i];
		}
	}
	while (!exp_stack.isEmpty()) {
		exp_stack.pop(temp_ch);
		preFixExp += temp_ch;
		exp_stack.getTop(temp_ch);
	}

	// Reverse again to correct form of prefix
	preFixExp = reverseString(preFixExp);
	// Deleting dynamic char array
	delete[] ch;
	// Return postFix expression
	return preFixExp;
}
double evaluatePrefix(const string exp) {
	// Changing infix expression to prefix expression
	string preFixExp = exp;

	// Gettinf reverse of preFixExp
	string reverse_preFixExp = reverseString(preFixExp);

	// Creating a dynamic char array
	string* ch = new string[exp.length()];
	// Temp char
	double temp_double = 0;
	// Creating a stack object
	StackDouble exp_stack;

	// Operands
	double operand1 = 0;
	double operand2 = 0;
	double result = 0;

	// Copying string preFixExp items into the char array
	for (int i = 0; i < reverse_preFixExp.length(); i++) {
		ch[i] = reverse_preFixExp[i];
	}

	for (int i = 0; i < reverse_preFixExp.length(); i++) {
		// if ch is an operand
		if ((ch[i] >= "a" && ch[i] <= "z") || (ch[i] >= "A" && ch[i] <= "Z") || (ch[i] >= "0" && ch[i] <= "9")) {
			stringstream character(ch[i]);

			// The object has the value 12345 and stream
			// it to the integer x
			int temp_int = 0;
			character >> temp_int;
			exp_stack.push(temp_int);
		}
		else {
			// ch is an operator named op evaluate and push the result
			exp_stack.pop(temp_double);
			operand2 = temp_double;
			exp_stack.pop(temp_double);
			operand1 = temp_double;
			if (ch[i] == "+")
				result = operand1 + operand2;
			if (ch[i] == "-")
				result = operand2 - operand1;
			if (ch[i] == "*")
				result = operand1 * operand2;
			if (ch[i] == "/")
				result = operand2 / operand1;
			exp_stack.push(result);
		}
	}
	// Deleting dynamic char array
	delete[] ch;

	return result;
}
bool isBalancedInfix(const string exp) {
	// Creating a char stack object
	StackChar exp_stack;

	// Creating a dynamic char array
	char* ch = new char[exp.length()];

	// Creating a boolean to check a balance
	bool balancedSoFar = true;


	// Copying string preFixExp items into the char array
	for (int i = 0; i < exp.length(); i++) {
		ch[i] = exp[i];
	}
	int i = 0;
	while (balancedSoFar && i < exp.length()) {
		if (ch[i] == '(') // push an open brace
			exp_stack.push(ch[i]);
		else if (ch[i] == ')') // close brace
			if (!exp_stack.isEmpty())
				exp_stack.pop(); // pop a matching open brace
			else
				balancedSoFar = false;
		// ignore all characters other than braces
		i++;
	}
	if (balancedSoFar && exp_stack.isEmpty()) {
		// Deleting dynamic char array
		delete[] ch;
		return true;
	}
	else {
		// Deleting dynamic char array
		delete[] ch;
		return false;
	}
}
void evaluateInputPrefixExpression() {
	string infix = " ";
	// (i) Asking user for an infix input
	cout << "Please enter an infix input: ";
	cin >> infix;

	// (ii) Removing possible spaces in the input
	remove(infix.begin(), infix.end(), ' ');

	// (iii) Checking if the expression has a balanced number of parantheses
	if (isBalancedInfix(infix) != true)
		cout << "This infix expression is not balanced...Please try again." << endl;
	else {
		// (iv) if the input is correct format converts the input expression to prefix
		string prefix = infix2prefix(infix);

		// (v) compute the final result
		double result = evaluatePrefix(prefix);
		cout << "Infix Format: " << infix << endl;
		cout << "Prefix Format: " << prefix << endl;
		cout << "The result of this prefix expression is: " << result << endl;
	}
}
int precedence(const char ch) {
	if (ch == '*' || ch == '/') // Higher precedence
		return 2;
	if (ch == '+' || ch == '-') // Lower precedence
		return 1;
	return -1;
}
string reverseString(const string exp) {
	string str = "";
	for (int i = exp.length() - 1; i >= 0; i--) {
		str += exp[i];
	}
	return str;
}
