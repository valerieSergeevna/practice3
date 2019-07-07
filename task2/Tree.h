#pragma once
#include "Iterator.h"

using namespace std;
template <class item> class stack
{
	item *Stack; int size_;
public:
	stack(int maxt) : Stack(new item[maxt]), size_(0) {};
	~stack();
	bool empty() const { return size_ == 0; }
	int size() const { return size_; }
	void push(item & item) { Stack[size_++] = item; }
	item top() const { return Stack[size_ - 1]; }
	void pop() { if (size_) --size_; }
};



// функция деструктора Стека
template <class item>
stack<item>::~stack()
{
	free(Stack); // удаляем стек
}

template <class item> class queue
{
	item *Queue; int head, tail, size_, Max;
public:
	queue(int maxQ) : head(0), tail(0), Max(maxQ), size_(0), Queue(new item[maxQ + 1]) {}
	~queue();
	bool empty() const { return (head % Max) == tail; }
	int size() const { return size_; }
	void push(item & item) { Queue[tail++] = item; tail %= Max; ++size_; }
	item front() const { return Queue[head % Max]; }
	void pop() { head++; head %= Max; --size_; }
};

template <class item>
queue<item>::~queue()
{
	free(Queue);
}


ref class Tree_Node
{
public:
	Tree_Node(float data1, float data2, float data1_2, float data2_2, float data3, float data4, float dif, float height) {
		this->x1 = data1;
		this->y1 = data2;
		this->x2 = data1_2;
		this->y2 = data2_2;
		this->treeX = data3;
		this->treeY = data4;
		this->next_one = nullptr;
		this->next_two = nullptr;
		this->next_three = nullptr;
		this->next_four = nullptr;
		this->level = height;
		this->treeX_dif = dif;
	};
	~Tree_Node() {};

	float x1, y1,x2,y2, treeX, treeY;
	Tree_Node ^next_one, ^next_two, ^next_three, ^next_four;
	float level, treeX_dif;
};
	/*Tree_Node(double data1, double data2, double data1_2, double data2_2, double data1_3, double data2_3, double data3, double data4,int dif, int height ) {
		this->x1 = data1;
		this->y1 = data2;
		this->x2 = data1_2;
		this->y2 = data2_2;
		this->x3 = data1_3;
		this->y3 = data2_3;
		this->treeX = data3;
		this->treeY = data3;
		this->next_one = nullptr;
		this->next_two = nullptr;
		this->next_three = nullptr;
		this->level = height;
		this->treeX_dif = dif;
	};
	~Tree_Node() {};

	float x1,y1, x2, y2,x3,y3,treeX,treeY;
	Tree_Node ^next_one, ^next_two,^next_three;
	int level, treeX_dif;
};
*/
	/*ref class TreeIterator : public Iterator {
	protected:
		Node ^current;
		TreeIterator(Node^ root) : current(root) { }

	public:
		bool operator==(const nullptr_t) const override { return current == nullptr; }
		bool operator!=(const nullptr_t) const override { return !operator==(nullptr); }
		int operator*() const override { return current->data; }
		Node *get_Cur() { return current; };

	};

	void add_first(int newElem);
	void reset_list();



	Node *cur;
	Node * root;
	size_t size, max_row;
	char **SCREEN;
public:

	class DftIterator : public TreeIterator {
	private:
		stack<Node*> nodes;
	public:
		DftIterator(Node *root, size_t size) : TreeIterator(root), nodes(size) {}
		void operator++(int) override;
	};

	class BftIterator : public TreeIterator {
	private:
		queue<Node*> nodes;
	public:
		BftIterator(Node *root, size_t size) : TreeIterator(root), nodes(size) {}
		void operator++(int) override;
	};

	Tree();
	~Tree();

	size_t get_size() const;
	Node* get_root();

	DftIterator create_dft_iterator() { return DftIterator(root, size); }
	BftIterator create_bft_iterator() { return BftIterator(root, size); }
	void insert(int newElem);
	void print(Node *, int, int);

	bool contains(int);
	void pop_node(int);
	*/
