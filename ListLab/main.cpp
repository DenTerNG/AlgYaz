#include <iostream>
#include <vector>
#include <list>

struct Node {
	int data;
	Node* next;
};

class LinkedList {
	public:
		LinkedList();
		LinkedList(int Data);
		LinkedList(std::vector<int>);
		bool add_element(int data);
		void delete_element(int data);
		bool find_element(int data);
		void insert(int data, int position);
		~LinkedList();
		void print();
	private:
		Node* first;
		Node* last;
};

LinkedList::LinkedList() {
	first = nullptr;
	last = nullptr;
}

LinkedList::LinkedList(int data) {
	Node* nd = new Node{ data, nullptr };
	first = nd;
	last = nd;

}

LinkedList::LinkedList(std::vector<int> vt) {
	for (int i = 0; i < vt.size();++i) {
		Node* nd = new Node{vt[i], nullptr};
		if (last == nullptr) {
			first = nd;
			last = nd;
			return;
		}
		last->next = nd;
		last = nd;
	}
}

bool LinkedList::add_element(int data) {
	Node* nd = new Node{ data, nullptr };
	if (first == nullptr && last == nullptr) {
		first = nd;
		last = nd;
		return true;
	}
	last->next = nd;
	last = nd;
	return true;
}

void  LinkedList::delete_element(int data) {
	Node* nd1 = first;
	Node* nd2 = first->next;
	while (nd2 && nd2->data != data) {
		nd2 = nd2->next;
		nd1 = nd1->next;
	}
	nd1->next = nd2->next;
	delete nd2;
}

void LinkedList::insert(int data, int Pos) {
	Node* PP = first;
	if (Pos == 0) {
		add_element(data);
	}
	int i = 0;
	while (PP) {
		if (i == Pos - 1)
		{
			break;
		}
		PP = PP->next;
		i = i + 1;

	}
	Node* PPP = new Node{ data, PP->next };
	PP->next = PPP;
}

bool LinkedList::find_element(int data) {
	int i = 0;
	Node* PP = first;
	while (PP) {
		if (PP->data == data)
			{
			i = i + 1;
			}
		PP = PP->next;
		}
	if (i == 0) {
		return false;
		}
	return true;
}

LinkedList::~LinkedList() {

}

void LinkedList::print() {
	Node* PP = first;
	while (PP) {
		std::cout << PP->data << " ";
		PP = PP->next;
	}
	std::cout << std::endl;

}

int main()
{
	std::vector<int> vec = { 10,20,30,35,50 };
	LinkedList lst;

	lst.add_element(10);
	lst.add_element(20);
	lst.add_element(30);
	lst.add_element(35);
	lst.add_element(50);
	lst.print();

	int ch; std::cout << "Find element: "; std::cin >> ch;
	if (lst.find_element(ch)) {
		std::cout << "Found";
	} else {
		std::cout << "Not found";
	}

	lst.delete_element(30); std::cout << std::endl;
	std::cout << "Remove 30: ";
	lst.print();

	lst.insert(333, 2);
	std::cout << "Insert 333: ";
	lst.print();


	return 0;
}