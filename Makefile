SRC = src/
INCLUDE = include/
TESTSUITE = Testsuite/
CC = g++
FLAGS = -Wall
DEBUG = debug/

DiceTestsuite: ${DEBUG}Executables/DiceTestsuite.exe
	./${DEBUG}Executables/DiceTestsuite.exe




${DEBUG}Executables/DiceTestsuite.exe: ${DEBUG}TestsuitDice.o ${DEBUG}Dice.o
	@echo "compile Testsuite"
	${CC} ${FLAGS} -o ${DEBUG}Executables/DiceTestsuite.exe ${DEBUG}TestsuitDice.o ${DEBUG}Dice.o

${DEBUG}TestsuitDice.o: ${TESTSUITE}Dice/TestsuitDice.cpp ${INCLUDE}Dice.hpp
	@echo "compile Testsuiteobject"
	${CC} ${FLAGS} -c ${TESTSUITE}Dice/TestsuitDice.cpp -I ${INCLUDE} -o ${DEBUG}TestsuitDice.o






${DEBUG}Dice.o: ${SRC}Dice.cpp ${INCLUDE}Dice.hpp
	@echo "compile Diceobject"
	${CC} ${FLAGS} -c ${SRC}Dice.cpp -I ${INCLUDE} -o ${DEBUG}Dice.o
	





clean:
	rm ${DEBUG}*.*
	rm ${DEBUG}Executables/*.*
#	rm ${DEBUG}*
#	rm ${DEBUG}Executables/*

.PHONY: clean DiceTestsuite 
