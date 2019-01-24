#include "vector.h"
using namespace CS225;

void SparseVector::PrintRaw() const {
	ElementNode* curr = pHead;
	std::cout << "Raw vector: ";
	while (curr) {
		std::cout << "(" << curr->data << ", " << curr->pos << ")";
		curr = curr->next;
	}
	std::cout << std::endl;
}

/* CONSTRUCTORS ---------------------------------------------------------------------- */

SparseVector::SparseVector() : pHead(NULL), dimension(0) {}

	/* COPY CONSTRUCTOR */
SparseVector::SparseVector(const SparseVector& S) : pHead(NULL), dimension(0) {
	ElementNode* current = S.pHead;
	if (current == NULL) { return; }
	while (current->next != NULL) {
		this->Insert(current->data, current->pos);
		current = current->next;
	}
	this->Insert(current->data, current->pos);
}

	/* DESTRUCTOR */
SparseVector::~SparseVector() {
	ElementNode* temp;
	while (pHead) {
		temp = pHead->next;
		delete(pHead);
		pHead = temp;
	}
}


/* OPERATOR OVERLOADING -------------------------------------------------------------- */

	/*	 ElementProxy [](long) 	*/
ElementProxy SparseVector::operator[](long pos) {
	ElementProxy obj(*this, pos);
	return obj;
}

	/*	 int [](long) 	*/
int SparseVector::operator[](const long pos) const{
	SparseVector temp(*this);
	return temp[pos];
}

	/*	 ElementProxy =(int) 	*/
ElementProxy& ElementProxy::operator=(const int val) {
	this->v.Insert(val, this->pos);
	return *this;
}

	/* 	SparseVector +(SparseVector) 	*/
SparseVector SparseVector::operator+(SparseVector const &S) {
	int result = 0;
	ElementNode* ls1 = this->pHead;
	ElementNode* ls2 = S.pHead;
	SparseVector sp;

	while (ls1 && ls2) {

		if (ls1->pos == ls2->pos) {
			result = ls1->data + ls2->data;
			sp.Insert(result, ls1->pos);
			ls1 = ls1->next;
			ls2 = ls2->next;
		}

		else if (ls1->pos < ls2->pos) {
			result = ls1->data;
			sp.Insert(result, ls1->pos);
			ls1 = ls1->next;
		}

		else if (ls1->pos > ls2->pos) {
			result = ls2->data;
			sp.Insert(result, ls2->pos);
			ls2 = ls2->next;
		}

	}
	while (ls1) {
		sp.Insert(ls1->data, ls1->pos);
		ls1 = ls1->next;
	}
	while (ls2) {
		sp.Insert(ls2->data, ls2->pos);
		ls2 = ls2->next;
	}

	return sp;
}

	/*	 SparseVector *(int) 	*/
SparseVector SparseVector::operator*(int x) const {
	SparseVector temp;
	ElementNode* current = this->pHead;
	while (current) {
		temp.Insert(current->data*x, current->pos);
		current = current->next;
	}
	return temp;
}

	/*	 int *(SparseVector) 	*/
int SparseVector::operator*(SparseVector const &S) const{
	ElementNode* c_h1 = this->pHead;
	ElementNode* c_h2 = S.pHead;
	int result = 0;

	while (c_h1 && c_h2) {
		if (c_h1->pos == c_h2->pos) {
			result += (c_h1->data * c_h2->data);
			c_h1 = c_h1->next;
			c_h2 = c_h2->next;
		}
		else if (c_h1->pos > c_h2->pos) {
			c_h2 = c_h2->next;
		}
		else if (c_h1->pos < c_h2->pos) {
			c_h1 = c_h1->next;
		}
	}

	return result;
}


ElementProxy::operator int() const { return this->v.Get(this->pos); }

	/*	 ElementProxy +=(int) 	*/
ElementProxy& ElementProxy::operator+=(const int x) {
	int temp = this->v.Get(this->pos) + x;
	this->v.Insert(temp, this->pos);
	return *this;
}

	/*	 ElementProxy -=(int) 	*/
ElementProxy& ElementProxy::operator-=(const int x) {
	int temp = this->v.Get(this->pos) - x;
	this->v.Insert(temp, this->pos);
	return *this;
}

	/*	 ElementProxy =(ElementProxy) 	*/
ElementProxy& ElementProxy::operator=(ElementProxy proxy) {
	this->v.Insert(proxy.v.Get(proxy.pos), this->pos);
	return *this;
}

	/*	 SparseVector =(SparseVector) 	*/
SparseVector& SparseVector::operator=(const SparseVector& S) {
	ElementNode* current = S.pHead;
	if (current == NULL) { return *this; }
	while (current->next != NULL) {
		this->Insert(current->data, current->pos);
		current = current->next;
	}
	this->Insert(current->data, current->pos);
	return *this;
}


/* INSERT GET DELETE ----------------------------------------------------------------- */
void SparseVector::Insert(int val, long pos) {
	ElementNode* current = pHead;

	if (current == NULL || current->pos > pos) {
		ElementNode* temp;

		if (val == 0) { return; }

		temp = new ElementNode;
		if (!temp) return;
		temp->pos = pos;
		temp->data = val;

		temp->next = current;
		pHead = temp;
	}
	else {
		ElementNode* temp;

		current = pHead;

		if (current->pos == pos) {
			if (val != 0) { current->data = val; }
			else { Delete(pos); }
			return;
		}

		while (current->next != NULL && current->next->pos <= pos) {
			current = current->next;
		}

		if (current->pos == pos) {
			if (val == 0) {
				Delete(pos);
				return;
			}
			else {
				current->data = val;
			}
		}
		else {
			if (val == 0) { return; }
			/* Create new temporary data */
			temp = new ElementNode;
			if (!temp) return;
			temp->pos = pos;
			temp->data = val;
			
			temp->next = current->next;
			current->next = temp;
		}
	}
}

int SparseVector::Get(long pos) const {
	ElementNode* current = pHead;
	if (current == NULL) return 0;
	do {
		if (current->pos == pos) return current->data;
		current = current->next;
	} while (current != NULL);
	return 0;
}

void SparseVector::Delete(long pos) {
	ElementNode* current = pHead;
	ElementNode* prev = current;

	/* IF NO ELEMENTS IN *d_e return */
	if (current == NULL) { return; }

	while (current) {
		if (current->pos == pos) {
			if (prev == current) {
				pHead = current->next;
				delete(current);
				return;
			}
			else {
				prev->next = current->next;
				delete(current);
				return;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}