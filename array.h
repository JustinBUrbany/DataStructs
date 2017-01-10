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

template<class T>
Array<T>::Array() :m_array(nullptr), m_length(0), m_start_index(0)
{
}

template<class T>
Array<T>::Array(int length, int start_index) : m_array(nullptr), m_length(length), m_start_index(start_index)
{
}
template<class T>
Array<T>::Array(const Array & copy) : m_array(nullptr), m_length(0), m_start_index(0)
{
	m_length = copy.m_length;
	m_start_index = copy.m_start_index;
	m_array = new T[m_length];
	if (copy.m_array != nullptr)
	{
		for (int i = getStartIndex(); i < getLength(); ++i)
		{
			m_array[i] = copy.m_array[i];
		}
	}
}
template<class T>
Array<T>::~Array()
{
}
template<class T>
Array<T> & Array<T>::operator=(const Array & rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;
		m_array = nullptr;
		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;
		if (rhs.m_array != nullptr)
		{
			m_array = new T[m_length];
			for (int i = getStartIndex(); i < getLength(); ++i)
			{
				m_array[i] = rhs.m_array[i];
			}
		}
	}

	return *this;
}
template<class T>
T & Array<T>::operator[](int index)
{

	return this[index];
}
template<class T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}
template<class T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<class T>
int Array<T>::getLength()
{
	return m_length;
}

template<class T>
void Array<T>::setLength(int length)
{
	m_length = length;
}

#endif