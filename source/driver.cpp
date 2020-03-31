#include <iostream>
#include <vector>
#include <array>
#include "simplech.h"

using namespace std;

void InitCheckerBoard(Board8x8 b)
{
        // initialize board to starting position
        memset(b, 0, 64 * sizeof(int));
        b[0][0] = CB_BLACK | CB_MAN;
        b[2][0] = CB_BLACK | CB_MAN;
        b[4][0] = CB_BLACK | CB_MAN;
        b[6][0] = CB_BLACK | CB_MAN;
        b[1][1] = CB_BLACK | CB_MAN;
        b[3][1] = CB_BLACK | CB_MAN;
        b[5][1] = CB_BLACK | CB_MAN;
        b[7][1] = CB_BLACK | CB_MAN;
        b[0][2] = CB_BLACK | CB_MAN;
        b[2][2] = CB_BLACK | CB_MAN;
        b[4][2] = CB_BLACK | CB_MAN;
        b[6][2] = CB_BLACK | CB_MAN;

        b[1][7] = CB_WHITE | CB_MAN;
        b[3][7] = CB_WHITE | CB_MAN;
        b[5][7] = CB_WHITE | CB_MAN;
        b[7][7] = CB_WHITE | CB_MAN;
        b[0][6] = CB_WHITE | CB_MAN;
        b[2][6] = CB_WHITE | CB_MAN;
        b[4][6] = CB_WHITE | CB_MAN;
        b[6][6] = CB_WHITE | CB_MAN;
        b[1][5] = CB_WHITE | CB_MAN;
        b[3][5] = CB_WHITE | CB_MAN;
        b[5][5] = CB_WHITE | CB_MAN;
        b[7][5] = CB_WHITE | CB_MAN;
}

#define OCCUPIED 0
#define FREE 16

#define MAXDEPTH 99

class BoardPrinter{
public:
	typedef std::array<unsigned char, 4> row;

	BoardPrinter():
	board_map 
	{{
		{37,  38,  39,  40},
        {32,  33,  34,  35},
        {28,  29,  30,  31},
        {23,  24,  25,  26},
        {19,  20,  21,  22},
        {14,  15,  16,  17},
        {10,  11,  12,  13},
        {5 ,  6 ,  7 ,  8}
	}}
	{}

	void operator()(int b[46])
	{
		bool odd_row = true;
		for (const auto &r : board_map )
		{
			if (odd_row) cout << "[ ]";
			for (const auto &e : r)
			{
				const char *piece;
				if (b[e] == BM)
					piece = bman;
				else if (b[e] == WM)
					piece = wman;
				else if (b[e] == BK)
					piece = bking;
				else if (b[e] == WK)
					piece = wking;
				else
					piece = empty;

				cout << "[" << piece << "][ ]";
			}
			if (odd_row) cout << "\b\b\b   ";
			cout << "\n";
			odd_row = !odd_row;
		}
	}

private:
	const int WM = (CB_WHITE | CB_MAN);
	const int BM = (CB_BLACK | CB_MAN);
	const int WK = (CB_WHITE | CB_KING);
	const int BK = (CB_BLACK | CB_KING);

	/** Unicode printing of checkers pieces                                  */
	/* see: https://altcodeunicode.com/alt-codes-die-checkers-shogi-symbols/ */
	/* and https://stackoverflow.com/a/16970900                              */
	const char *wman = "\u26C0";
	const char *wking = "\u26C1";
	const char *bman = "\u26C2";
	const char *bking = "\u26C3";
	const char *empty = " ";
	std::array<row, 8> board_map;
};


int main(){
    Board8x8 b;
    InitCheckerBoard(b);

	BoardPrinter bp;

    int board[46];
	/* initialize board */
 	for (int i = 0; i < 46; i++)
 		board[i] = OCCUPIED;
 	for (int i = 5; i <= 40; i++)
 		board[i] = FREE;

 	/*				(white)
-   				37  38  39  40
-              32  33  34  35
-                28  29  30  31
-              23  24  25  26
-                19  20  21  22
-              14  15  16  17
-                10  11  12  13
-               5   6   7   8
 					(black)   */
 	board[5] = b[0][0];
 	board[6] = b[2][0];
 	board[7] = b[4][0];
 	board[8] = b[6][0];
 	board[10] = b[1][1];
 	board[11] = b[3][1];
 	board[12] = b[5][1];
 	board[13] = b[7][1];
 	board[14] = b[0][2];
 	board[15] = b[2][2];
 	board[16] = b[4][2];
 	board[17] = b[6][2];
 	board[19] = b[1][3];
 	board[20] = b[3][3];
 	board[21] = b[5][3];
 	board[22] = b[7][3];
 	board[23] = b[0][4];
 	board[24] = b[2][4];
 	board[25] = b[4][4];
 	board[26] = b[6][4];
 	board[28] = b[1][5];
 	board[29] = b[3][5];
 	board[30] = b[5][5];
 	board[31] = b[7][5];
 	board[32] = b[0][6];
 	board[33] = b[2][6];
 	board[34] = b[4][6];
 	board[35] = b[6][6];
 	board[37] = b[1][7];
 	board[38] = b[3][7];
 	board[39] = b[5][7];
 	board[40] = b[7][7];
 	for (int i = 5; i <= 40; i++)
 		if (board[i] == 0)
 			board[i] = FREE;
 	for (int i = 9; i <= 36; i += 9)
 		board[i] = OCCUPIED;

    char str[200]="";

	const size_t NUM_MOVES = 30;
	for (int i = 0; i < NUM_MOVES; ++i)
	{
		bp(board);
		checkers(board, CB_WHITE, 200, str);
		cout << "Move: " << str << endl;

		bp(board);
		checkers(board, CB_BLACK, 200, str);
		cout << "Move: " << str << endl;
	}
}