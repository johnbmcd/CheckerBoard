#pragma once
#include <Windows.h>
#include <cstdarg>
#include "CBstructs.h"
#include "min_movegen.h"

void log_fen(char *msg, int board[8][8], int color);
void log_bitboard(char *msg, uint32_t black, uint32_t white, uint32_t king);
void builddb(char *str);
int builtingametype(void);
void CBlog(char *text);
void cblog(const char *fmt, ...);
void checklevelmenu(CBoptions *options, HMENU hmenu, int resource);
int errorlog(char *str);
int extract_path(char *name, char *path);
int FENtoclipboard(HWND hwnd, int board8[8][8], int color, int gametype);
int fileispresent(char *filename);
int getopening(struct CBoptions *CBoptions);
int getthreeopening(int n, struct CBoptions *CBoptions);
int initcolorstruct(HWND hwnd, CHOOSECOLOR *ccs, int index);
int logtofile(char *filename, char *str, char *mode);
int num_3move_ballots(CBoptions *options);
int PDNtoclipboard(HWND hwnd, PDNgame &game);
void setmenuchecks(struct CBoptions *CBoptions, HMENU hmenu);
char *textfromclipboard(HWND hwnd, char *str);
int texttoclipboard(char *text);
double timelevel_to_time(int level);
int timelevel_to_token(int level);
int timetoken_to_level(int token);
double timetoken_to_time(int token);
void toggle(int *x);
