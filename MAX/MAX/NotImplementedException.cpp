#include "NotImplementedException.h"

char const * NotImplementedException::what() const
{
	return "Function not implemented";
}
