#include "array.h"

template<class T>
Array::Array():m_array(nullptr), m_length(0), m_start_index(0)
{
}

template<class T>
Array::Array(int length, int start_index):m_array(nullptr), m_length(length), m_start_index(start_index)
{

}
template<class T>
Array::Array(const Array & copy):m_array(nullptr)
{
	m_length = copy.m_length;
	m_start_index = copy.m_start_index;

	if (copy.m_array != nullptr)
	{
		for (int i = getStartIndex(); i < getLength(); ++i)
		{
			m_array[i] = copy.m_array[i];
		}
	}
}
template<class T>
Array::~Array()
{
}
template<class T>
Array & Array::operator=(const Array & rhs)
{
	delete[] m_array;
	m_array = nullptr;
	m_length = rhs.m_length;
	m_start_index = rhs.m_start_index;
	if (rhs.m_array != nullptr)
	{
		for (int i = getStartIndex(); i < getLength(); ++i)
		{
			m_array[i] = rhs.m_array[i];
		}
	}

	return *this;
}
template<class T>
T & Array::operator[](int index)
{

	return *this;
}
template<class T>
int Array::getStartIndex()
{
	return m_start_index;
}
template<class T>
void Array::setStartIndex(int start_index)
{
	m_start_index = start_index;
}
template<class T>
int Array::getLength()
{
	return m_length;
}
template<class T>
void Array::setLength(int length)
{
	m_length = length;
}
