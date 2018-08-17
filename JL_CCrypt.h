#ifndef JL_CCRYPT_H
#define JL_CCRYPT_H

// a cryption class declaration
class JL_CCrypt
{
public:
	// constructor
	JL_CCrypt();

	// destructor
	~JL_CCrypt();

	// inferfaces
	CString MD5(CString str);// use MD5 to encrypt a string
	CString MD5ForFile(CString file);// encrypt a file by means of MD5 algorithm
	
	CString Rsa(CString str);// use RSA to encrypt a string
	
	CString Encrypt(CString str, int type = 0);// encrypt a string with the algorithm designed by the parameter type
};

#endif// JL_CCRYPT_H