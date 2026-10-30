#include <iostream>

using namespace std::

int main() {
	double value, apr, down;
	int num_pay;

	cout << "Value: ";
	cin >> value;
	cout << "Down: ";
	cin >> down;
	cout << "APR: ";
	cin >> apr;
	cout << "Terms: ";
	cin >> num_pay;

	double principle = value - down
	double r = 0.01 * apr / 12;

	double nom = principle * r * pow(1 + r, num_pay);
	double den = pow(1 + r, num_pay) - 1;

	double payments = nom/den;
	double total = payments * num_pay + down;
	cout << fixed << setprecision(2);

	cout << "payment/month =" << payments << endl;
	cout; << "total =" << total << endl;


	return 0;
} 
