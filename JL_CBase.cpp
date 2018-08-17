//JL_CBase implementation

#include "JL_CBase.h"

void JL_CBase::Swap<typename T>(T first, T second)
{
	if (!str)
		return -1;
	else
	{
		int count = 0;
		while (*str != '\0')
		{
			count++;
			str++;
		}

		return count;
	}
}