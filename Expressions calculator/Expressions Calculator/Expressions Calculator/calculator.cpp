#include <iostream>
#include <cmath>

using namespace std;

float number()
{
	int res = 0;
	for (;;)
	{
		char c = cin.get();
		if (c >= '0' && c <= '9')
			res = res * 10 + c - '0';
		else
		{
			cin.putback(c);
			return res;
		}
	}
}

float expression();

float brackets()
{
	char c = cin.get();
	if (c == '(')
	{
		float x = expression();
		cin.get();
		return x;
	}
	else
	{
		cin.putback(c);
		return number();
	}
}

float factor()
{
	float x = brackets();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '*':
			x *= brackets();
			break;
		case '/':
			x /= brackets();
			break;
		default:
			cin.putback(c);
			return x;
		}
	}
}

float expression()
{
	float x = factor();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '+':
			x += factor();
			break;
		case '-':
			x -= factor();
			break;
		default:
			cin.putback(c);
			return x;
		}
	}
}

void add(double* firstValue, double* secondValue, double* result)
{
	*result = *firstValue + *secondValue;
	cout << "\nResult: " << *result << endl;
}

void subtract(double* firstValue, double* secondValue, double* result)
{
	*result = *firstValue - *secondValue;
	cout << "\nResult: " << *result << endl;
}

void multiply(double* firstValue, double* secondValue, double* result)
{
	*result = *firstValue * *secondValue;
	cout << "\nResult: " << *result << endl;
}

void divide(double* firstValue, double* secondValue, double* result)
{
	*result = *firstValue / *secondValue;
	cout << "\nResult: " << *result << endl;
}

void sqr(double* firstValue, double* secondValue, double* result)
{
	*result = pow(*firstValue, *secondValue);
	cout << "\nResult: " << *result << endl;
}


int main()
{
	int change;
	char operation;
	double firstValue, secondValue, result;
	cout << "Welcome!\nThis is my calculator!\n";
	cout << "Did you have simple or difficult exercise?\n";
	cout << "Simple - button 1!\nHard - button 2!\n";
	cout << "What will you choose: ";
	cin >> change;
	switch (change)
	{
	case 1:
		cout << "\nEnter A: ";
		cin >> firstValue;
		cout << "Operation (+, -, *, /, ^): ";
		cin >> operation;
		cout << "Enter B: ";
		cin >> secondValue;
		switch (operation)
		{
		case '+':
			add(&firstValue, &secondValue, &result);
			break;
		case '-':
			subtract(&firstValue, &secondValue, &result);
			break;
		case '*':
			multiply(&firstValue, &secondValue, &result);
			break;
		case '/':
			divide(&firstValue, &secondValue, &result);
			break;
		case '^':
			sqr(&firstValue, &secondValue, &result);
			break;
		default:
			cout << "\nInvalid operator!";
			break;
		}
		break;
	case 2:
		cout << "\nEnter a mathematical expression: ";
		cin.ignore();
		cin >> ws;
		result = expression();
		cout << "\nResult: " << result << endl;
		break;
	default:
		cout << "\nInvalid choice! Have a nice day!";
		break;
	}
	return 0;
}