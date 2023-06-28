#include "main.h"


int putchr(char q)
{
	return write(1, &q, 1);
}
