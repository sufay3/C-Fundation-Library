#ifndef JL_CSKIN_H
#define JL_CSKIN_H

#include <afxwin.h>

// the following class is intended to handle something associated with program skin
class JL_CSkin
{
public:
	// constructor
	JL_CSkin();

	// destructor
	~JL_CSkin();

	// interfaces
	void SetComponents(CWin[] comList);// set components which are effected by skin

	void ChangeSkin(CString colorValue);// change the skin by means of color
	void ChangeSkin(CPicture bgPic);// change the skin with a background picture
private:
	// attributions
	CWin* mComList;// a list in which the components' appearance will be changed while the skin is 
};

#endif// JL_CSKIN_H
