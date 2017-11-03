#pragma once
#include <stdint.h>

/* movegen.h: function prototypes of movegen.c */

/* bitboard masks for moves in various directions */

/* here "1" means the squares in the columns 1357 and "2" in 2468.*/
#define RF1 0x0F0F0F0F
#define RF2 0x00707070
#define LF1 0x0E0E0E0E
#define LF2 0x00F0F0F0
#define RB1 0x0F0F0F00
#define RB2 0x70707070
#define LB1 0x0E0E0E00
#define LB2 0xF0F0F0F0

/* bitboard masks for jumps in various directions */
#define RFJ1 0x00070707
#define RFJ2 0x00707070
#define LFJ1 0x000E0E0E
#define LFJ2 0x00E0E0E0
#define RBJ1 0x07070700
#define RBJ2 0x70707000
#define LBJ1 0x0E0E0E00
#define LBJ2 0xE0E0E000

/* back rank masks */
#define WBR 0xF0000000
#define BBR 0x0000000F
#define NWBR 0x0FFFFFFF
#define NBBR 0xFFFFFFF0

#define MAXMOVES 28

/* center and edge mask */

/*       CB_WHITE
	   28  29  30  31
	 24  25  26  27
	   20  21  22  23
	 16  17  18  19
	   12  13  14  15
	  8   9  10  11
	    4   5   6   7
	  0   1   2   3
	      CB_BLACK
*/
struct pos {
	uint32_t bm;
	uint32_t bk;
	uint32_t wm;
	uint32_t wk;
};

struct move {
	uint32_t bm;
	uint32_t bk;
	uint32_t wm;
	uint32_t wk;
};

int makemovelist(pos *p, move movelist[MAXMOVES], int color);

/* captgen.h: function prototypes for captgen.c */
int makecapturelist(pos *p, move movelist[MAXMOVES], int color);

static void blackmancapture1
			(
				pos *p,
				move movelist[MAXMOVES],
				int *n,
				move *partial,
				uint32_t square
			);
static void blackkingcapture1
			(
				pos *p,
				move movelist[MAXMOVES],
				int *n,
				move *partial,
				uint32_t square
			);
static void whitemancapture1
			(
				pos *p,
				move movelist[MAXMOVES],
				int *n,
				move *partial,
				uint32_t square
			);
static void whitekingcapture1
			(
				pos *p,
				move movelist[MAXMOVES],
				int *n,
				move *partial,
				uint32_t square
			);
static void blackmancapture2
			(
				pos *p,
				move movelist[MAXMOVES],
				int *n,
				move *partial,
				uint32_t square
			);
static void blackkingcapture2
			(
				pos *p,
				move movelist[MAXMOVES],
				int *n,
				move *partial,
				uint32_t square
			);
static void whitemancapture2
			(
				pos *p,
				move movelist[MAXMOVES],
				int *n,
				move *partial,
				uint32_t square
			);
static void whitekingcapture2
			(
				pos *p,
				move movelist[MAXMOVES],
				int *n,
				move *partial,
				uint32_t square
			);
