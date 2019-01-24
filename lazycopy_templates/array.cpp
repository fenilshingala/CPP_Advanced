#include "array.h"
#include <iostream>

namespace CS225 {

	template <typename DataType>
	Array<DataType>::Array()
		: size(0), data(NULL), counter(new int)
	{
		*counter = 1;
	}

	template <typename DataType>
	Array<DataType>::Array(Array<DataType> const& a)
		: size(a.size), data(a.data), counter(a.counter) { ++*counter; }

	template <typename DataType>
	Array<DataType>::~Array(){
		if (1 != *counter) {
			--*counter;
		}
		else {
			delete[] data;
			delete(counter);
		}
	}

	template<typename DataType>
	void Array<DataType>::Insert(int pos, DataType const& val) {
		/*
		 * ....
		 */
		if (pos >= size) {
			int old_size = size;
			size = 2 * pos + 1;
			DataType* new_data = new DataType[size];
			for (int i = 0; i < old_size; ++i) {
				new_data[i] = data[i];
			}

			delete[] data;
			data = new_data;
		}
		data[pos] = val;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream &out, Array<T> const& array) {
		for (int i = 0; i < array.size; ++i) {
			out << array.data[i] << " ";
		}
		return out;
	}


	template<typename DataType>
	Proxy<DataType> Array<DataType>::operator[](long const pos) {
		Proxy<DataType> obj(*this, pos);
		return obj;
	}

	template <typename DataType>
	DataType& Array<DataType>::operator[](long const pos) const {
		return data[pos];
	}

	template<typename DataType>
	Proxy<DataType>& Proxy<DataType>::operator=(DataType& data) {
		this->ar.Insert(this->pos, data);
		return *this;
	}

	template <typename T>
	std::ostream& operator<< (std::ostream &out, Proxy<T> const& proxy) {
		out << proxy.ar.data[proxy.pos];
		return out;
	}

	template <typename DataType>
	Proxy<DataType>& Proxy<DataType>::operator=(int data) {
		DataType tempData(data);

		if (1 != *this->ar.counter) {
			DeepCopy();
			ar.counter = new int;
			*ar.counter = 1;
		}

		this->ar.Insert(this->pos, tempData);
		return *this;
	}

	template <typename DataType>
	Array<DataType>& Array<DataType>::operator=(Array<DataType>& a) {
		if (data == a.data) {
			return *this;
		}

		if (1 != *counter) {
			if (1 != *a.counter) {
				--*counter;
				++*a.counter;
			}
			else {
				--*counter;
			}
			data = a.data;
			size = a.size;
			counter = a.counter;
			++*counter;
		}

		// if current counter is 1
		if (1 == *counter) {
			delete[] data;
			delete(counter);

			size = a.size;
			data = a.data;
			counter = a.counter;
			++*counter;
		}

		return *this;
	}

	template <typename DataType>
	void Proxy<DataType>::DeepCopy() {
		DataType* tempData;
		tempData = new DataType[ar.size];
		for (int i = 0; i < ar.size; ++i) {
			tempData[i] = ar.data[i];
		}
		ar.data = tempData;
		--*ar.counter;
	}
}