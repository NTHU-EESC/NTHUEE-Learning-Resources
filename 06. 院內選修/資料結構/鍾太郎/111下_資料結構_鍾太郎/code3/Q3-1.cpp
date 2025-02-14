#include <iostream>
using namespace std;

template <class T> class CircularList;

template <class T>
class ChainNode
{
	template <class U>
    friend class CircularList;
    template <class U>
    friend ostream &operator<<(ostream &os, CircularList<U> &L);
    template <class U>
	friend istream &operator>>(istream& is, CircularList<U> &L);
private:
    T data;
    ChainNode<T>* link;
};

template <class T>
class CircularList
{
    template <class U>
    friend ostream &operator<<(ostream &os, CircularList<U> &L);
    template <class U>
	friend istream &operator>>(istream& is, CircularList<U> &L);
public:
    CircularList() {first = NULL;};
    int count();
    void insertFront(T e);
    void insertBack(T e);
    void deleteFirst();
    void deleteLast();
    void deleteOther();
    void deconcatenate(CircularList<T> &split, int i);
    CircularList<T> merge(CircularList<T> &L2);
private:
    ChainNode<T>* first;
};

template <class T>
int CircularList<T>::count()
{
	int num = 1;
	ChainNode<T>* temp = first;
	
	while(temp->link != first){
		num++;
		temp = temp->link;
	}
	
	return num;
}

template <class T>
void CircularList<T>::insertFront(T e)
{
    ChainNode<T>* temp = first;
    
    if (first == NULL) {
        ChainNode<T> *newchain = new ChainNode<T>;
        newchain->data = e;
        newchain->link = newchain;
        first = newchain;
    }
    else{
    	while(temp->link != first) temp = temp->link;
    	ChainNode<T> *newchain = new ChainNode<T>;
        newchain->data = e;
        newchain->link = first;
        temp->link = newchain;
        first = newchain;
	}
	
    return;
}

template <class T>
void CircularList<T>::insertBack(T e)
{
    ChainNode<T>* temp = first;
    
    if (first == NULL) {
        ChainNode<T> *newchain = new ChainNode<T>;
        newchain->data = e;
        newchain->link = newchain;
        first = newchain;
    }
    else{
    	while(temp->link != first) temp = temp->link;
    	ChainNode<T> *newchain = new ChainNode<T>;
        newchain->data = e;
        newchain->link = first;
        temp->link = newchain;
	}
	
    return;
}

template <class T>
void CircularList<T>::deleteFirst()
{
    if (first == NULL) throw "The List is empty, cannot delete.";
    ChainNode<T>* temp = first;
    
    while(temp->link != first) temp = temp->link;
    temp->link = first->link;
    temp = first->link;
    delete first;
    first = temp;
    
    return;
}

template <class T>
void CircularList<T>::deleteLast()
{
    if (first == NULL) throw "The List is empty, cannot delete.";
    ChainNode<T>* temp = first;
    
    while(temp->link->link != first) temp = temp->link;
	delete temp->link;
    temp->link = first;
    
    return;
}

template <class T>
void CircularList<T>:: deleteOther()
{
	int num = count();
	num = (num + 1) / 2;
	ChainNode<T>* temp;
	ChainNode<T>* de;
	
	if (first == NULL) throw "The List is empty, cannot delete.";
	deleteFirst();
	num--;
	temp = first;
	for(int i = 0; i < num; i++){
		de = temp->link;
		temp->link = temp->link->link;
		delete de; 
		temp = temp->link;
	}
	
	return;
}

template <class T>
void CircularList<T>::deconcatenate(CircularList<T> &split, int i)
{
    ChainNode<T>* temp = first;
    ChainNode<T>* end;
    
    for(int j = 1; j < i;j++) temp = temp->link;
    end = temp;
    temp = temp->link;
    while (temp != first) {
        split.insertBack(temp->data);
        temp = temp->link;
    }
    end->link = first;
    
    return;
}

template <class T>
CircularList<T> CircularList<T>::merge(CircularList<T> &L2)
{
    ChainNode<T>* temp1 = first;
    ChainNode<T>* temp2 = L2.first;
    CircularList<T> me;
    
    if (first == NULL && L2.first == NULL) throw "Two Lists are both empty, cannot merge.";
    while(temp1->link != first && temp2->link != L2.first){
		me.insertBack(temp1->data);
		temp1 = temp1->link;
		me.insertBack(temp2->data);
		temp2 = temp2->link;
    }
    me.insertBack(temp1->data);
	temp1 = temp1->link;
    me.insertBack(temp2->data);
    temp2 = temp2->link;
    while(temp1 != first){
		me.insertBack(temp1->data);
		temp1 = temp1->link;
	}
    while(temp2 != L2.first){
		me.insertBack(temp2->data);
		temp2 = temp2->link;
	}
	
    return me;
}

template <class T>
ostream &operator<<(ostream &os, CircularList<T> &L)
{
    ChainNode<T>* temp = L.first;
    int i = 0;
    
	os << temp->data;
	temp = temp->link;
	while(temp != L.first){
		os << " ��" << temp->data;
		temp = temp->link;
	}
    os << endl;
    
    return os;
}

template <class T>
istream &operator>>(istream& is, CircularList<T> &L)
{
    int num;
    int temp;
    
	cout << "How many element do you want to plug in : ";
	is >> num;
	cout << "What do you want to plug in : ";
	for(int i = 0; i < num; i++){
		is >> temp;
		L.insertBack(temp);
	}
	
    return is;
}

int main(void)
{
    CircularList<int> L1, L2, L3, L4;
    int k, num;
    
    cin >> L1;
    cin >> L2;
	cout << "L1 = " << L1;
    cout << "Length of L1 : " << L1.count() << endl;
    cout << "L2 = " << L2;
    
    cout << "Delete the first node in L1 : ";
    L1.deleteFirst();
    cout << L1;
    cout << "Delete the last node in L1 : ";
    L1.deleteLast();
    cout << L1;
    
    cout << "What number do you want to insert in front? : ";
    cin >> num;
	L1.insertFront(num);
    cout << "After insert : ";
    cout << L1;
    cout << "What number do you want to insert in back? : ";
    cin >> num;
    cout << "After insert : ";
    L1.insertBack(num);
    cout << L1;
    
    cout << "Delete every other node in L1 : ";
    L1.deleteOther();
    cout << L1;
    
    cout << "Where do you want to split in L2? : ";
    cin >> num;
    cout << "Split L2 : ";
    L2.deconcatenate(L3, num);
    cout << "First piece : " << L2;
    cout << "Second piece : " << L3;
    cout << "merge L2 Back : ";
    L4 = L2.merge(L3);
    cout << L4;
    
    return 0;
}
