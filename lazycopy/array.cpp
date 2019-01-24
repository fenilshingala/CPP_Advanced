#include "array.h"

CS225::Array::Array(int * array,
	unsigned int _size,
	const ElementFactory* _pElementFactory
)
	: data(new AbstractElement*[_size]), size(_size),
	pElementFactory(_pElementFactory), counter(new int)
{
	for (unsigned int i = 0; i < size; ++i) {
		//create Element with id = 1 (that is Element1 )
		data[i] = pElementFactory->MakeElement(1, array[i]);
	}
	*counter = 1;
}

CS225::Array::~Array() {
	if (1 != *counter) {
		--*counter;
	}
	else {
		DeleteData();
	}
}

void CS225::Array::DeleteData(){
	for (unsigned int i = 0; i < size; ++i) {
		delete data[i];
	}
	delete [] data;
	delete(counter);
}

int CS225::Array::Get(unsigned int pos) const { return data[pos]->Get(); }

void CS225::Array::DeepCopy(){
	AbstractElement** AE = data;
	data = new AbstractElement*[size];
	for (unsigned int i = 0; i < size; ++i)
		data[i] = AE[i]->bla();
	--*counter;
}

void CS225::Array::Set(int id, int pos, int value) {
	//setter will delete the old and create new 
	//slightly inefficient if new and old have the same type
	if (1 != *counter) {
		DeepCopy();
		counter = new int;
		*counter = 1;
	}
	delete data[pos];
	data[pos] = pElementFactory->MakeElement(id, value);
}

void CS225::Array::Print() const {
	for (unsigned int i = 0; i < size; ++i) data[i]->Print();
	std::cout << std::endl;
}

CS225::Array& CS225::Array::operator=(Array& a) {
	if (data == a.data) {
		return *this;
	}

	// if current counter is > 1
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
		DeleteData();
		size = a.size;
		data = a.data;
		counter = a.counter;
		++*counter;
	}

	return *this;
}

CS225::Array::Array(const CS225::Array& a)
	: data(a.data), size(a.size), pElementFactory(a.pElementFactory), counter(a.counter)
{
	++(*counter);
}