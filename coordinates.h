int coortonumber(coor c, int gametype);
void coorstocoors(int *x, int *y, int invert, int mirror);

inline bool is_valid_board8_square(int x, int y)
{
	return(((x + y + 1) % 2) != 0);
}