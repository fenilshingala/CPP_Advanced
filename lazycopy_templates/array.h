#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

namespace CS225 {

	template <typename DataType>
	class Proxy;

	template <typename DataType>
	class Array{
	public:
		Array();
		Array(Array<DataType> const& a);
		~Array();
		void Insert(int pos, DataType const& val);

		template <typename T>
		friend std::ostream& operator<<(std::ostream &out, Array<T> const& array);

		Proxy<DataType> operator[](long const pos);
		DataType& operator[](long const pos) const;
		Array<DataType>& operator=(Array<DataType>& a);
	public:
		int size;
		DataType* data;
		int* counter;
	};

	// PROXY
	template <typename DataType>
	class Proxy {
	public:
		Proxy(Array<DataType>& ar, long pos) : ar(ar), pos(pos) {}
		Proxy<DataType>& operator=(DataType& ar);
		Proxy<DataType>& operator=(int data);
		void DeepCopy();

		template <typename T>
		friend std::ostream& operator<< (std::ostream &out, Proxy<T> const& proxy);
	public:
		Array<DataType>& ar;
		long pos;
	};
	
}

#include "array.cpp"

#endif // !ARRAY_H