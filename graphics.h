

#define ANIMATIONSLEEPTIME 4		// 5 ms per animation step
#define STEPS 12.0					// 12 number of animation steps to make
#define CLOCKHEIGHT 25

DWORD AnimationThreadFunc(HWND hwnd);
int getxymetrics(double *xmetric, double *ymetric, HWND hwnd);
int printboard(HWND hwnd, HDC hdc, HDC bmpdc, HDC stretchdc, Board8x8 board);
int printsampleboard(HWND hwnd, HDC hdc, HDC bmpdc, HDC stretchdc);
void selectstone(int x, int y, HWND hwnd);
void selectstones(Squarelist &squares, HWND hwnd);
void updatestretchDC(HWND hwnd, HDC bmpdc, HDC stretchdc, int size);
int updategraphics(HWND hwnd);
int resizegraphics(HWND hwnd);
int updateboardgraphics(HWND hwnd);
void refresh_clock(HWND hwnd);
int initgraphics(HWND hwnd);
int diagramtoclipboard(HWND hwnd);
int samplediagramtoclipboard(HWND hwnd);
int setoffsets(int _offset, int _upperoffset);
void set_animation(bool state);
