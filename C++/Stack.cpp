#define NUMBER 10
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Stack
{
        private:
                struct stack           // Структура элемента очереди
                {
                       int value;              // Значение элемента очереди
                       stack *next;   // Адрес следующего элемента очереди
                };
                stack *head;         // Голова очереди

        public:
                Stack();                               // Конструктор очереди
                ~Stack();                             // Деструктор
                void Push(int v);            // Функция записи нового элемента в конец очереди(вход)
                int Pop();                           // Функция удаления элемента
                void ShowAll();             // Функция вывода значений всей очереди
                int Peek();            // Функция возращающая значение головы очереди
                bool isEmpty();             // Функция проверки списка на пустоту
				int Size();
				void BinaryInsertionSort(); //поиск бинарными вставками
			private:
				int GetFromPosition(int index);
				void PutIntoPosition(int index, int value);
				void BinaryInsertion(int value, int leftborder, int rightborder);
				int RemoveFromPosition(int index);
				
};

Stack::Stack()  {
        head = NULL;
}

Stack::~Stack() { 
        stack *tmp;
        while (head != NULL) {
                tmp = head;
                head = head->next;
                delete tmp;
        }
        delete head;
}

void Stack::Push(int v) {       //Добавление
         stack *tmp = new(stack);
         tmp->value = v;
		if (head==NULL){ //если стек пока пустой
			head = tmp;
			head->next = NULL;
			head->value = v;
		}else{ //если стек не пустой
			tmp->next = head;
			head = tmp;
		}
}

int Stack::Pop() {
	if (head==NULL){
		cout<<"Стек пуст(Pop)"<<endl;
	}else{
	int a = head->value;
	stack *tmp = head;
	head=head->next;
	delete(tmp);	
	return a;

	}
}

void Stack:: ShowAll()
{
Stack B;
while (!this->isEmpty()){
	cout << this->Peek() << " ";
	B.Push(this->Pop());
	}
	while(!B.isEmpty()){
		this->Push(B.Pop());
	}
}

int Stack::Peek() {
        return head->value;
}
bool Stack::isEmpty()
{
        return head == NULL ? true : false;
}

int Stack::Size(){
	int size = 0;
	if (head==NULL){
		return 0;
	}else{
		stack *cur = head;
		while(cur!=NULL){
			size++;
			cur = cur -> next;
		}
		return size;
	}
	
}

void Stack::BinaryInsertionSort(){
	int processed = 0;
	int basesize = this->Size();
	while (processed<basesize){
		int a = this->RemoveFromPosition(processed);
		if (processed==0){
			this->Push(a); //automatically processed
			processed++;
			continue;
		}
		this->BinaryInsertion(a, 0, processed-1);
		processed++;
	}
}

int Stack::GetFromPosition(int index){
	Stack B;
	int a = 0;
	for (int i = 0; i<index; i++){
		B.Push(this->Pop());
	}
	a = this->Peek();
	for (int i = 0; i<index; i++){
		this->Push(B.Pop());
	}
	return a;
}

void Stack::PutIntoPosition(int index, int value){
	Stack B;
		for (int i = 0; i<index; i++){
		B.Push(this->Pop());
		}
		this->Push(value);
		for (int i = 0; i<index; i++){
		this->Push(B.Pop());
	}
}

void Stack::BinaryInsertion(int value, int leftborder, int rightborder){
	if (rightborder==0){
		if (value<=this->Peek()){
			this->Push(value);
		}else{
			this->PutIntoPosition(leftborder+1, value);
		}
		
	}else{
		while(leftborder!=rightborder){
			int a = GetFromPosition(leftborder+(rightborder-leftborder)/2);
			if (a<=value){ //если value больше
				leftborder = (leftborder+(rightborder-leftborder)/2);

			}else{ //если value меньше
				rightborder = (leftborder+(rightborder-leftborder)/2);
			}
			if ((rightborder-leftborder==1)&&(value>=this->GetFromPosition(leftborder))&&(value<this->GetFromPosition(rightborder))){
				leftborder++;
			}
			if ((rightborder-leftborder==1)&&(value<this->GetFromPosition(leftborder))&&(value<this->GetFromPosition(rightborder))){
				rightborder--;
			}
			if ((value>=this->GetFromPosition(rightborder))&&(rightborder-leftborder==1)){
				leftborder=rightborder+1;
				this->PutIntoPosition(leftborder, value);
				return;
			}
		}
		this->PutIntoPosition(leftborder, value);
	}	
}

int Stack::RemoveFromPosition(int index){
	Stack B;
	int a = 0;
	for (int i = 0; i<index; i++){
		B.Push(this->Pop());
	}
	a = this->Pop();
	for (int i = 0; i<index; i++){
		this->Push(B.Pop());
	}
	return a;
}

int main(void){
	setlocale(LC_ALL, "Russian");
	Stack A;
	srand(time(0));
	
	for (int i = 0; i<NUMBER; i++){
		A.Push(rand());
	}

	A.ShowAll();
	cout << endl;
	A.BinaryInsertionSort();
	cout << endl << "Отсортировали\n";
	A.ShowAll();
	return 0;
}