#ifndef JL_CEVENTCONTAINER_H
#define JL_CEVENTCONTAINER_H

#include <atlstr.h>

// an event container 
class JL_CEventContainer
{
public:
	// constructor
	JL_CEventContainer();

	// destructor
	~JL_CEventContainer();

	// interfaces
	void LeftClick(CWin msgWin, void* prePoiner);// map a left-click message of the window msgWin to a process
	void DoubleClick(CWin msgWin, void* prePointer);// map a double-click message from the source msgWin to the specified process
	void RightClick(CWin msgWin, void* prePointer); // map a right-click message from the source msgWin to the specified pre
	void Roll(int step, CWin msgWin, void* prePointer);// map a mouse-rolling message from the source msgWin to the specified pre

	void KeyDown(int keyValue, CWin msgWin, void* prePointer);// handle a key-down event by a pre pointed to
	void KeyUp(int keyValue, CWin msgWin, void* prePointer);// handle a key-up message by a function pointed to
	void KeyPress(int keyValue, CWin msgWin, void* prePointer); // handle a key-pressing event by a pre pointed to

	void PutOver(CWin msgWin, void* prePointer);// a specified pre will be called when user puts mouse over a window element
	void Drag(CWin msgWin, void* prePointer);// a specified pre will be executed when user performs a dragging act in a window control
};

#endif// JL_CEVENTCONTAINER_H