#ifndef JL_CHTTP_H
#define JL_CHTTP_H

#include <afxinet.h>

// declaration of the class JL_CHttp which abstracts the http protocol
class JL_CHttp
{
public:
	// constructor
	JL_CHttp();

	// destructor
	~JL_CHttp();

	// interfaces
	CString Request(CString& reqUrl, CString& reqMethod, CString& reqbody, CString& cookies, CString& addReqHeader, bool isGbk, CString& location,);
private:
	// internal methods
	CString GetHost(CString& reqUrl);// get the host name

	CString BuildHeader(CString& reqUrl, CString& reqMethod, CString& cookies, CString& addReqHeader);// build a complete request header
	CString BuildReqLine(CString& reqUrl, CString& reqMethod);// build the request line
	CString BuildReqHeader(CString& cookies, CString& addReqHeader);// build the request header

	CString GetBody(CString& res);// parse responsion body
	CString GetHeader(CString& headerName, CString& res);// get the header entity via the header name 
	CString GetCookies(CString& res);// get cookies from the result
	CString GetLocation(CString &res);// get the location redirecting to
	CString IsChunked(CString& res);// check if the responsion is chunked
};

#endif// JL_CHTTP_H