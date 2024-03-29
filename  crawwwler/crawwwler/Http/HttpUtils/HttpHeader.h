// HttpHeader.h
// Representation of an http header

#ifndef HTTPHEADER_H_
#define HTTPHEADER_H_

#include <string>

namespace Crawwwler {

	// Possible http header types
	enum tHeaderType {
		HEADER_RESULT_OK = 1,
		HEADER_USER_AGENT,
		HEADER_ACCEPT_TYPE,
		HEADER_ACCEPT_LANG,
		HEADER_ACCEPT_ENCODING,
		HEADER_PROXY_CONNECTION,
		HEADER_PRAGMA,
		HEADER_CONNECTION,
		HEADER_HOST,
		HEADER_CONTENT_LOCATION,
		HEADER_CONTENT_TYPE,
		HEADER_SERVER,
		HEADER_DATE,
		HEADER_ACCEPT_RANGES,
		HEADER_LAST_MODIFIED,
		HEADER_CONTENT_LENGTH,
		HEADER_INVALID
	};
	
class CHttpHeader
{
public:

	// Construct when wanting to parse a header
	CHttpHeader();
	// Set a new header
	CHttpHeader(tHeaderType Type, std::string Value);
	virtual ~CHttpHeader();
	
	// Try to parse the given string as a header
	bool Parse(std::string Value);
	
	// Get the type
	const tHeaderType GetType() const { return m_Type; };
	// Get the value
	const std::string GetValue() const {return m_Value; };
	
	const std::string ToString() const;
	
private:
	// Headers are in the form field:value
	// eg is Content-Type: text/html
	
	// The type (field) of this header
	tHeaderType m_Type;
	
	const std::string TypeAsString(tHeaderType Type) const;
	const tHeaderType StringAsType(std::string Value) const;
	
	// The value
	std::string m_Value;
};

}

#endif /*HTTPHEADER_H_*/
