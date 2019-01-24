#ifndef STATISTICS_H
#define STATISTICS_H
#include <vector>    //vector
#include <algorithm> //copy
#include <ostream>   //ostream
#include <istream>   //istream
#include <map>       //map

class Statistics;

class Statistics {
    private:
        typedef std::vector<int> ContainerType;
        ContainerType data;
    public:
        Statistics();
        template <typename T> Statistics( T const* b, T const* e );
        friend std::ostream& operator<<( std::ostream& out, Statistics const& stat );
        friend std::istream& operator>>( std::istream& in, Statistics & stat );
		float Average();
		float Deviation();
		void RemoveIf(std::binder2nd< std::greater<int> > x);
		std::map<int, int> OccuresMoreThan(const int n);
		std::vector<int> Histogram(float, float, float);
		int Minimum();
		int Maximum();
		void DrawHistogramH(float, float, float);
		void DrawHistogramV(float, float, float);
};

struct myStruct {
	int operator()(int x, int y) { return x + y * y; }
};

struct occurMore {
	occurMore() : myMap(), result(), n(0) {}

	std::map<int, int> myMap;
	std::map<int, int> result;
	int n;

	void operator()(int x) {
		++myMap[x];
		if (myMap[x] > n)
			result[x] = myMap[x];
	}
};

struct strctHistogram {
	strctHistogram() : interval(0.0f), limit(0.0f), done(false), mBegin(0.0f), mEnd(0.0f), count(0), result() {}
	float interval;
	float limit;
	bool done;
	float mBegin;
	float mEnd;
	unsigned int count;
	std::vector<int> result;

	/*
	Here using while loop is not necessary but for the case when first data in container is not
	in the particular interval, it's needed. Not using while loop will also run all test cases provided.
	*/
	void operator()(int x) {
		done = false;
		if (x >= mBegin && x < mEnd) {
			while (!done) {
				if (x < limit) {

					++count;
					done = true;
				}
				else {
					limit += interval;
					result.push_back(count);
					count = 0;
				}
			}
		}
	}
};

template <typename T>
Statistics::Statistics( T const* b, T const* e ) : data(e-b) {
    std::copy( b, e, data.begin() ); // we can use regular pointers to specify ranges!
}

#endif