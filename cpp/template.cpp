#include <iostream>

using namespace std;

template <class T> 
class List;

template <class S> 
class Node{
public:
	S data;
	Node(S new_data){
		data = new_data;
		next = NULL;
	};
private:
	Node<S> * next;

friend class List<S>;
};

template <class T>
class List{

public:
	// default constructor
	List(){
		head = NULL;
	};
	// destructor
	~List(){
		if (head !=NULL){
			Node<T> *cur = head;
			Node<T> *temp;
			while(cur != NULL){
				temp = cur;
				cur = cur->next;
				delete temp;	
			}
			cout << "List destructor called " << endl;
		};
	};

	void add(T data){
		Node<T> *ptr = new Node<T>(data);
		ptr->next = head;
		head = ptr;
	}

	void print(){
		Node<T> *cur = head;
		if (head==NULL) {cout << "List empty" << endl;}
		else
			while (cur != NULL){
				cout << cur->data <<endl;
				cur = cur->next;
			}
	};

private:
	Node<T> *head;	
};

int main(){
	List<int> list1;
	list1.add(5);
	list1.add(45);
	list1.print();

	List<double> list2;
	list2.add(5.6);
	list2.add(45.5);
	list2.print();

	return 0;
}


