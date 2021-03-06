#pragma once

#include "BattleshipBoard.h"
#include <windows.h>
#include "IBattleshipGameAlgo.h"


class PrintGameBoard
{
public:

	static const int RED_COLOR = 12;
	static const int BLUE_COLOR = 9;
	static const int YELLOW_COLOR = 14;
	static const int WHITE_COLOR = 15;
	static const int PLAYER_A_COLOR = BLUE_COLOR;
	static const int PLAYER_B_COLOR = YELLOW_COLOR;
	static const int ATTACK_COLOR = RED_COLOR;
	static const char ATTACK_CHAR = '@';
	static const char HIT_CHAR = 'X';
	static const char BLANK_CHAR = ' ';
	
	const static int printDefatultDealy = 300;
	const static bool printDeafultIsQuiet = false;

	static void printStartBoard(const BattleshipBoard& board);
	static void printCurrentAttack(int playerAttackedId, std::pair<int, int> coord, char currChar, AttackResult res);

	static void setDelay(int newDelay) { delay = newDelay; }
	static void setIsQuiet(bool newIsQuiet) { isQuiet = newIsQuiet; }
	static bool IsQuiet() { return isQuiet;  }
	static int getDelay() { return delay; }
	static void setCursorAfterBoard(int rows) { if (!isQuiet) { gotoxy(0, rows + 5); showCursor(); } }
	

private:
	PrintGameBoard() = delete;
	static bool isQuiet;
	static int delay;

	static void gotoxy(const int x, const int y);
	static void hideCursor();
	static void showCursor();
	static void setColor(WORD color);

};
