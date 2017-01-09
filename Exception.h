#include <ostream>
using std::ostream;

#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
public:
	Exception();
	Exception(char * msg);
	Exception(const Exception & copy);
	~Exception();
	Exception & operator=(const Exception & rhs);
	const char * getMessage();
	void setMessage(char * msg);
	ostream & operator<<(ostream & stream, const Exception & except);

private:
	char * m_msg;
};



#endif
