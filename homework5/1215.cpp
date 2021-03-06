#include <iostream>
#include <cstdio>

using namespace std;

template<class T>
class priorQueue{
private:
	int currentSize;
	T *array;
	int maxSize;
public:
	priorQueue(int capacity=20000);
	~priorQueue();
	void enQueue(const T &x);
	T deQueue();
	T getHead() const;
	void printQueue() const;
};

template<class T>
priorQueue<T>::priorQueue(int capacity)
{
	array = new T [capacity];
	maxSize = capacity;
	currentSize = 0;
}

template<class T>
priorQueue<T>::~priorQueue()
{
	delete [] array;
}

template<class T>
T priorQueue<T>::getHead() const
{
	return array[1];
}

template<class T>
void priorQueue<T>::enQueue(const T &x)
{
	int hole = ++currentSize;
	
	for(;hole>1 and x<array[hole/2];hole/=2){
		array[hole] = array[hole/2];
	}
	array[hole] = x;
}

template<class T>
T priorQueue<T>::deQueue()
{
	T minItem;
	minItem = array[1];
	array[1] = array[currentSize--];
	int hole = 1;
	int child;
	T tmp = array[hole];
	
	for(;hole*2<=currentSize;hole=child){
		child = hole*2;
		if(child!=currentSize and array[child+1]<array[child]){
			child++;
		}
		if(array[child]<tmp){
			array[hole] = array[child];
		}else{
			break;
		}
	}
	
	array[hole] = tmp;
	return minItem;
} 

template<class T>
void priorQueue<T>::printQueue() const
{
	for(int i = 1;i<=currentSize;i++){
		cout<<array[i]<<' ';
	}
	cout<<endl;
}

int main()
{
	int n = 0;
	cin>>n;
	
	priorQueue<int> prique;
	char operation[7] = {0};
	int output = 0;
	int tmp = 0;
	
	for(int i = 0;i<n;i++){
		cin>>operation;
		
		if(operation[0]=='i'){
			cin>>output;
			prique.enQueue(output);
		}else if(operation[0]=='d'){
			prique.deQueue();
		}else if(operation[0]=='m'){
			tmp = prique.getHead();
			cout<<tmp<<endl;
		}
	}
	
	cout<<flush;
	return 0;
}

