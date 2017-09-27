
#include "fdf.h"

int		get_color(int z)
{
	if (z >= 0 && z < 5)
		return (GREEN);
	if (z >= 5 && z < 10)
		return (BROWN);
	return (WHITE);
}