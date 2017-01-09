#ifndef ARRAY_H
#define ARRAY_H

template<class T> 
class Array
{
public:

	Array();
	Array(int length, int start_index = 0);
	Array(const Array & copy);
	~Array();
	Array & operator =(const Array & rhs);
	T & operator [](int index);
	int getStartIndex();
	void setStartIndex(int start_index);
	int getLength();
	void setLength(int length);

private:
	T * m_array;
	int m_length;
	int m_start_index;
};





#endif
