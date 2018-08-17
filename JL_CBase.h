#ifndef JL_CBASE_H
#define JL_CBASE_H

// wrap base functions to a class
class JL_CBase
{
public:
	template void Swap<class T>(T first, T second);
};

extern JL_CBase JL_Base;