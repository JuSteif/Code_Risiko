#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

#include "Dice.hpp"

#define DICE_MIN 1
#define DICE_MAX 6
#define ROLL_COUNT 100000
#define CONFIG_NAME "Testsuite/Dice/Testsuit_Dice_Config.txt"

struct RollMsg {
	int number;
	int count;
};



int main() {
	std::fstream configFile(CONFIG_NAME, std::ios::in);
	int diceMin = DICE_MIN;
	int diceMax = DICE_MAX;
	int rollCount = ROLL_COUNT;

	std::string str;
	int val;
	configFile >> str >> val;
	if (str == std::string("DICE_MIN")) {
		diceMin = val;
	}
	configFile >> str >> val;
	if (str == std::string("DICE_MAX")) {
		diceMax = val;
	}
	configFile >> str >> val;
	if (str == std::string("ROLL_COUNT")) {
		rollCount = val;
	}

	time_t tm = time(0);
#pragma warning(suppress : 4996)
	char* dt = ctime(&tm);

	Dice dice(diceMin, diceMax);
	std::vector<RollMsg> numbers;
	std::fstream outputFile("Testsuite/Dice/Testsuit_Dice_Output.txt", std::ios::out);

	for (int i = diceMin; i <= diceMax; i++) {
		RollMsg rMsg;
		rMsg.count = 0;
		rMsg.number = i;

		numbers.push_back(rMsg);
	}

	for (int i = 0; i < rollCount; i++) {
		int rollResult = dice.roll();
		numbers[rollResult - numbers[0].number].count++;
	}

	outputFile << "Ergebnis des Dice_Testsuit vom " << dt << std::endl;
	outputFile << "Untereschranke: " << diceMin << "\t\tObereschranke: " << diceMax << std::endl;
	outputFile << "Wiederholungen: " << rollCount << std::endl;
	RollMsg min = numbers[0];
	RollMsg max = numbers[0];
	outputFile << "Durchschnitt: " << rollCount / numbers.size() << std::endl << std::endl;
	for (RollMsg& rMsg: numbers) {
		if (rMsg.count < min.count)
			min = rMsg;
		if (rMsg.count > max.count)
			max = rMsg;
		outputFile << "Zahl: " << rMsg.number << " \t\tVorkommen:  " << rMsg.count << std::endl;
	}
	outputFile << std::endl;
	outputFile << "Geringste Haeufigkeit: " << min.number << "\t\tHaeufigkeit: " << min.count << std::endl;
	outputFile << "Groesste Haeufigkeit: " << max.number << "\t\tHaeufigkeit: " << max.count << std::endl;
	outputFile << "Differenz: " << max.count - min.count << std::endl;

	return 0;
}