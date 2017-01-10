#include "Exception.h"

Exception::Exception():m_msg(nullptr)
{
}

Exception::Exception(char * msg):m_msg(msg)
{
}

Exception::Exception(const Exception & copy)
{
	
}

Exception::~Exception()
{
}

Exception & Exception::operator=(const Exception & rhs)
{
	return *this;
}

const char * Exception::getMessage()
{
	return m_msg;
}

void Exception::setMessage(char * msg)
{
	m_msg = msg;
}

ostream & Exception::operator<<(ostream & stream, const Exception & except)
{
	return ;
}
