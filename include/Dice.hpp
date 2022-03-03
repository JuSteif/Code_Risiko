#pragma once
#include <iostream>
#include <random>

class Dice {
public:
	Dice(int min, int max);
	virtual ~Dice();
	int roll();
	int getLastRoll();
private:
	std::default_random_engine* gen;
	std::uniform_int_distribution<int>* dis;
	std::random_device* rd;
	int lastRoll;
};