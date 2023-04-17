// This program implements an interactive counter with overflow handling.
//It contains a Counter class with methods for increasing, decreasing, resetting and displaying the counter value as well as for setting minimum and maximum limits.
//The program has a user-friendly menu for working with the counter, and input validation ensures that the limits are set correctly.
//The project demonstrates strong C++ programming skills, including OOP concepts, input validation, error handling and a menu-based user interface.

#include <iostream>
#include <limits>
using namespace std;

class Counter {
	int k;
	int k2;
	int min;
	int max;

public:
	Counter(int minVal, int maxVal) {
		min = minVal;
		max = maxVal;
		k = min;
		k2 = 0;
	}

	void increment() {
		k++;
		if (k > max) {
			k2++;
			k = min;
		}
	}

	void decrement() {
		k--;
		if (k < min) {
			k2--;
			k = max;
		}
	}

	void reset() {
		k = min;
		k2 = 0;
	}

	void setMin(int minVal) {
		min = minVal;
		if (k < min)
			k = min;
	}

	void setMax(int maxVal) {
		max = maxVal;
		if (k > max)
			k = max;
	}

	void display() {
		cout << "Counter Value is: " << k2 << " : " << k << endl;
	}
};

int main() {

	int smin, smax;
	cout << "Enter min value: ";
	cin >> smin;
	cout << "Enter max value: ";
	cin >> smax;

	while (smin >= smax) {
		cout << "The minimum value must be less than the maximum value. Repeat the entry: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> smin;
		cout << "Enter max value: ";
		cin >> smax;
	}

	Counter counter(smin, smax);

	int choice;
	do {
		cout << "1. Increase the counter by 1\n";
		cout << "2. Decrease counter by 1\n";
		cout << "3. Reset counter\n";
		cout << "4. Enter min value\n";
		cout << "5. Enter max value\n";
		cout << "6. Display counter\n";
		cout << "0. Exit\n";
		cout << "Choose one action: ";
		cin >> choice;

		switch (choice) {
		case 1:
			counter.increment();
			counter.display();
			system("pause");
			system("cls");
			break;
		case 2:
			counter.decrement();
			counter.display();
			system("pause");
			system("cls");
			break;
		case 3:
			counter.reset();
			counter.display();
			system("pause");
			system("cls");
			break;
		case 4: {
			int newMin;
			cout << "Enter new min value: ";
			cin >> newMin;
			counter.setMin(newMin);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			int newMax;
			cout << "Enter new max value: ";
			cin >> newMax;
			counter.setMax(newMax);
			system("pause");
			system("cls");
			break;
		}
		case 6:
			counter.display();
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "Bye, my friend!\n";
			break;
		default:
			cout << "Wrong answer\n";
			system("pause");
			system("cls");
			break;
		}

	} while (choice != 0);
	return 0;
}