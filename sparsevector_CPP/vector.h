#include <iostream>

struct ElementNode {
	int data;
	int pos;
	struct ElementNode *next;
};

namespace CS225 {

	class ElementProxy;

	class SparseVector {
	public:
		SparseVector();
		SparseVector(const SparseVector& S);
		~SparseVector();

		int Get(long pos) const;
		void Insert(int val, long pos);
		void Delete(long pos);

		void PrintRaw() const;

		friend std::ostream& operator<<(std::ostream &out, const SparseVector &v) {
			int i, last_pos = -1;
			ElementNode* p_e = v.pHead;
			while (p_e) {
				for (i = last_pos + 1; i < p_e->pos; ++i) out << " " << "0";
				out << " " << p_e->data;
				last_pos = p_e->pos;
				p_e = p_e->next;
			}
			for (i = last_pos + 1; i < v.dimension; ++i) out << " " << "0";

			return out;
		}

		ElementProxy operator[](long pos);
		int operator[](const long pos) const;
		SparseVector operator+(SparseVector const &S);
		SparseVector operator*(int x) const;
		
		friend SparseVector operator*(int x, const SparseVector &S) {
			SparseVector temp;
			ElementNode* current = S.pHead;
			while (current) {
				temp.Insert(current->data*x, current->pos);
				current = current->next;
			}
			return temp;
		}
		
		int operator*(SparseVector const &S) const;

		SparseVector& operator=(const CS225::SparseVector&);
	private:
		ElementNode* pHead;
		long dimension;
	};


	class ElementProxy {
	public:
		ElementProxy(CS225::SparseVector& v, long pos) : v(v), pos(pos) {}
		
		ElementProxy& operator=(const int val);
		operator int() const;
		ElementProxy& operator+=(const int x);
		ElementProxy& operator-=(const int x);
		ElementProxy& operator=(ElementProxy proxy);
	private:
		CS225::SparseVector &v;
		long pos;
	};
}