#include "test.hpp"

#define _SIZE_MAP 2000

int main (void)
{
	_MAP m;

	for (int i = 0; i < _SIZE_MAP; i++)
		m.insert(_MVALUE(rand(), (rand() % 50) + 48));

	for (int i = 0; i < _SIZE_MAP; i++)
		COUT(m[i]);

	_MAP empty;

	COUT(empty[0]);

	return (0);
}