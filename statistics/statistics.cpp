#include "statistics.h"
#include <numeric> //accumulate
#include <cmath> //sqrt
#include <iterator> //ostream_iterator, back_inserter
#include <iomanip> //setfill setw
#include <iostream> //cout

Statistics::Statistics() : data() {}

std::ostream& operator<<( std::ostream& out, Statistics const& stat ) {
    std::copy( stat.data.begin(),  stat.data.end(),
               std::ostream_iterator<int>( out, " " ) );
    return out;
}

std::istream& operator>>( std::istream& in, Statistics & stat ) {
    std::copy( std::istream_iterator<int>(in),
               std::istream_iterator<int>(),
               std::back_inserter( stat.data ) );
    return in; 
}

float Statistics::Average() {
	return  std::accumulate(data.begin(), data.end(), 0.0f) / data.size();
}

float Statistics::Deviation() {
	float avg = Average();
	myStruct strct;
	float sum = std::accumulate(data.begin(), data.end(), 0, strct);
	return sqrtf(sum/data.size() - avg*avg);
}

void Statistics::RemoveIf(std::binder2nd< std::greater<int> > x) {
	std::vector<int>::iterator new_end;
	new_end = std::remove_if(data.begin(), data.end(), x);
	data.erase(new_end, data.end());
}

std::map<int, int> Statistics::OccuresMoreThan(const int n) {
	occurMore strct;
	strct.n = n;
	strct = for_each(data.begin(), data.end(), strct);
	return strct.result;
}

std::vector<int> Statistics::Histogram(float n, float start, float end) {
	strctHistogram strct;
	std::vector<int> sortedData(data.size());

	std::copy(data.begin(), data.end(), sortedData.begin());
	std::sort(sortedData.begin(), sortedData.end());

	strct.interval = (end-start)/n;
	strct.limit = start + strct.interval;
	strct.mBegin = start;
	strct.mEnd = end;
	strct = for_each(sortedData.begin(), sortedData.end(), strct);
	strct.result.push_back(strct.count);

	return strct.result;
}

int Statistics::Minimum() {
	return *( std::min_element(data.begin(), data.end()) );
}

int Statistics::Maximum() {
	return *( std::max_element(data.begin(), data.end()) );
}

struct strctDrawHistogram {
	void operator()(int x) {
		std::cout << std::setfill('*') << std::setw(x) << "" << std::endl;
	}
};

void Statistics::DrawHistogramH(float n, float start, float end) {
	std::vector<int> result = Histogram(n, start, end);
	strctDrawHistogram strct;
	std::for_each(result.begin(), result.end(), strct);
}

struct printV {
	printV() : max(0) {}
	
	int max;

	void operator()(int x) {
		if (max > x) {
			std::cout << " ";
		}
		else {
			std::cout << "*";
		}
	}
};

struct strctDrawHistogramV {
	strctDrawHistogramV() : printStrct(), result() {}

	printV printStrct;
	std::vector<int> result;

	void operator()(int x) {
		++x;
		printStrct = std::for_each(result.begin(), result.end(), printStrct);
		std::cout << "\n";
		--(printStrct.max);
	}
};

void Statistics::DrawHistogramV(float n, float start, float end) {
	strctDrawHistogramV strct;
	strct.result = Histogram(n, start, end);

	strct.printStrct.max = *std::max_element(strct.result.begin(), strct.result.end());
	std::vector<int> max_count(strct.printStrct.max);

	std::for_each(max_count.begin(), max_count.end(), strct);
}