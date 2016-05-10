#pragma once
#include <string>

class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);

private:
	std::string owner;
	double amount;
	static double interestRate;
	static constexpr double curRate = 3.14;
	static double initRate() { return curRate; }
	static constexpr int period = 30;
	double daily_tbl[period];
};

void Account::rate(double r)
{
	interestRate = r;
}

constexpr int Account::period;
double Account::interestRate = initRate();
