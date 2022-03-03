#include "Dice.hpp"

Dice::Dice(int min, int max) {
	gen = new std::default_random_engine();
	dis = new std::uniform_int_distribution<int>(min, max);
	rd = new std::random_device;
	gen->seed((*rd)());
}

Dice::~Dice() {
	delete gen;
	delete dis;
	delete rd;
}

int Dice::roll() {
	lastRoll = (*dis)((*gen));
	return lastRoll;
}

int Dice::getLastRoll() {
	return lastRoll;
}