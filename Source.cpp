#include <iostream>
#include <list>

using namespace std;

int priority(char symb) {
	if (symb == '+' || symb == '-') {
		return 0;
	}
	else if (symb == '*' || symb == '/') {
		return 1;
	}
	else if (symb == '^') {
		return 2;
	}
	else {
		return -1;
	}
}

int equally(string str) {
	list <float> stack;
	int chis1, chis2;
	for (int i = 0; i < str.length(); ++i) {
		if (isdigit(str[i])) {
			stack.push_back(str[i] - '0');
		}
		else {
			chis1 = stack.back();
			stack.pop_back();
			chis2 = stack.back();
			stack.pop_back();
			switch (str[i]) {
			case '+':
				stack.push_back(chis1 + chis2);
				break;
			case '-':
				stack.push_back(chis1 - chis2);
				break;
			case '*':
				stack.push_back(chis1 * chis2);
				break;
			case '/':
				stack.push_back((float)chis1 / chis2);
				break;
			case '^':
				stack.push_back(pow(chis1, chis2));
				break;
			}
		}
	}
	return stack.back();
}

void main()
{
	string input, answer = "";
	list <char> stack;
	cin >> input;
	for (int i = 0; i < input.length(); ++i) {
		if (isdigit(input[i])) {
			answer += input[i];
		}
		else {
			if (input[i] == '(') {
				stack.push_back(input[i]);
				continue;
			} if (input[i] == ')') {
				while (stack.back() != '(') {
					answer += stack.back();
					stack.pop_back();
				}
				stack.pop_back();
				continue;
			}
			if (stack.size() != 0) {
				if (priority(input[i]) <= priority(stack.back())) {
					answer += stack.back();
					stack.pop_back();
					stack.push_back(input[i]);
					continue;
				}
			}
			stack.push_back(input[i]);
		}
	}
	while (stack.size() > 0) {
		answer += stack.back();
		stack.pop_back();
	}
	cout << answer << endl;
	cout << equally(answer);
}