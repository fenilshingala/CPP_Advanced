#pragma once
#include "CRTP.h"

namespace CS225 {
	class AbstractElement : public ObjectCounter<AbstractElement>{
	public:

		static size_t live() { return ObjectCounter::live(); }
		static size_t total() { return ObjectCounter::total(); }

		virtual int Get() const = 0;
		virtual void Set(int new_val) = 0;
		virtual void Print() const = 0;
		virtual AbstractElement* bla() const = 0;
	};
	
}