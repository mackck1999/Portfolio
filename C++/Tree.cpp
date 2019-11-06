/*Задание:
Реализовать дерево двоичного поиска. Указатели на левого сына и правого брата. А = A ? B. Обход графа А – прямой. B – симметричный.
Листинг:
*/
#define NULL nullptr
#define TRUE true
#define FALSE false
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

class BST{
        private:
                struct bst           
                {
                       int value;              
                       bst *leftboy;
		bst *rightbrother;   
                };
                bst *root;

        public:
                BST();                               // Конструктор очереди
                bool IsEmpty();             // Функция проверки дерева на пустоту
                void Insert(int a); //добавление элемента
                void Preorder(); //прямой обход
                void Inorder(); //симметричный обход
	    void PreorderToDelete(BST& vtoroe); //прямой обход с удалением
                bool PreorderToSearch(int suspect); //прямой обход для поиска
                void Postorder(); //обратный обход
};

BST::BST()  {
        root = NULL;
}
	
void BST::Insert(int a){
		bst *tmp = new (bst);
		tmp->leftboy = NULL;
		tmp->rightbrother = NULL;
		tmp->value = a;
	if (root==NULL){
		root=tmp;
		return;
	}
	else{ //есть есть корень
		bool b = TRUE; //не добавили
		bst *cur = root;
		cur->leftboy = root->leftboy;
		while(b){ //пока не добавили
			if (a<cur->value){ //если элемент меньше текущего
				if (cur->leftboy==NULL){ //если левого сына нет
					cur->leftboy = tmp; //делаем левого
					b = TRUE;
					break;
				}
				else{ //если левый ребенок таки есть
					cur = cur->leftboy;
					continue;
				}			
			}
			else{ if (a>cur->value){ //если элемент больше текущего
				if (cur->leftboy==NULL){ //если левого ребенка нет
					b = FALSE; //очень жаль, вставки не будет
					break;
				}
				else{//если левый ребенок есть
					if(cur->leftboy->rightbrother==NULL){ //если правого ребенка нет
						cur->leftboy->rightbrother = tmp;
						b = TRUE;
						break;
					}
					else { //если правый ребенок есть
						cur = cur->leftboy->rightbrother;
						continue;
					}
				}
			}
			}
		}
	}}

bool BST::IsEmpty(){
        return root == NULL ? true : false;
}

void BST::Preorder(){ //прямой обход
	vector<bst*> ve;
	if (root==NULL){
		cout << "дерево пустое\n";
		return;
	}
	
	bst *cur = new(bst);
	if ((root!=NULL)&&(root->leftboy==NULL)){
		cout << root->value << "\n";
		return;
	}
	
	ve.push_back(root);
	cur = root;
	while(ve.size()!=0){
		cout << cur->value << " "; //выводим значение узла
		if (cur->leftboy!=NULL){ //если есть левый
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" Идём влево ";
			continue;
		}
		else{ //если нет левого
			sorry:
			if (cur->rightbrother!=NULL){ //но есть братец
				ve.pop_back(); //удалить левый из вектор
				cur = cur->rightbrother; //перейти на брата
				ve.push_back(cur);
				//cout<<" Идём вправо ";
			}else{ //если даже брата нет
				ve.pop_back();
				cur = ve.back();
				//cout<<" Идём вверх ";
				if (ve.size()>0) goto sorry;
			}
		} 
	}
}

void BST::Inorder(){ //симметричный обход
	vector<bst*> ve;
	vector<int> demo;
	if (root==NULL){
		cout << "дерево пустое\n";
		return;
	}
	
	bst *cur = new(bst);
	if ((root!=NULL)&&(root->leftboy==NULL)){
		cout << root->value << "\n";
		return;
	}
	
	ve.push_back(root);
	cur = root;
	while(ve.size()!=0){
	//	cout << cur->value << " "; //выводим значение узла
		if (cur->leftboy!=NULL){ //если есть левый
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" Идём влево ";
			continue;
		}
		else{ //если нет левого
			sorry:
			if (cur->rightbrother!=NULL){ //но есть братец
				
				
				if ((find(demo.begin(), demo.end(), (ve.back()->value)))==demo.end()){
					cout << ve.back()->value << " ";
					demo.push_back(ve.back()->value);
				}
				
				ve.pop_back(); //удалить левый из вектор
				if ((find(demo.begin(), demo.end(), ve.back()->value))==demo.end()){
					cout << ve.back()->value << " ";
					demo.push_back(ve.back()->value);
				}
				cur = cur->rightbrother; //перейти на брата
				ve.push_back(cur);
				
				//cout<<" Идём вправо ";
			}else{ //если даже брата нет
				
				if (ve.size()>0)
				{
				if ((find(demo.begin(), demo.end(), ve.back()->value))==demo.end()){	
				cout << ve.back()->value << " ";
				demo.push_back(ve.back()->value);
				}
				}
				ve.pop_back();
				cur = ve.back();
				if (ve.size()>0){
				if ((find(demo.begin(), demo.end(), ve.back()->value))==demo.end()){	
				cout << ve.back()->value << " ";
				demo.push_back(ve.back()->value);
				}
				}
				//cout<<" Идём вверх ";
				if (ve.size()>0) goto sorry;
			}
		} 
	}
}

void BST::PreorderToDelete(BST& vtoroe){ //прямой для удаления
	/* определяет кандидатов на удаление */
	BST Temp;
	{ //прямой обход
	vector<bst*> ve;
	if (root==NULL){
		//cout << "дерево пустое\n";
		return;
	}
	
	bst *cur = new(bst);
	if ((root!=NULL)&&(root->leftboy==NULL)){ //если есть только корень
		//cout << root->value << "\n";
		bool ToAdd = vtoroe.PreorderToSearch(root->value); //если такой узел есть во втором дереве
		if (ToAdd==TRUE){
			Temp.Insert(root->value);
			root=Temp.root;
		} 
		return;
	}
	
	ve.push_back(root);
	cur = root;
	while(ve.size()!=0){
		bool ToAdd = vtoroe.PreorderToSearch(cur->value);
		if (ToAdd){
			Temp.Insert(cur->value);
		}
		//cout << cur->value << " "; //выводим значение узла
		if (cur->leftboy!=NULL){ //если есть левый
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" Идём влево ";
			continue;
		}
		else{ //если нет левого
			sorry:
			if (cur->rightbrother!=NULL){ //но есть братец
				ve.pop_back(); //удалить левый из вектор
				cur = cur->rightbrother; //перейти на брата
				ve.push_back(cur);
				//cout<<" Идём вправо ";
			}else{ //если даже брата нет
				ve.pop_back();
				cur = ve.back();
				//cout<<" Идём вверх ";
				if (ve.size()>0) goto sorry;
			}
		} 
	}
}
this->root=Temp.root;
}

bool BST::PreorderToSearch(int suspect){ //прямой для поиска
		/*функция ищет узел с подозреваемым значением */
		
		vector<bst*> ve;
	if (root==NULL){
		cout << "дерево пустое\n";
		return FALSE;
	}
	
	bst *cur = new(bst);
	if ((root!=NULL)&&(root->leftboy==NULL)){
		
		if (root->value!=suspect){
		return FALSE;
		}else{
			return TRUE;
		}
	}
	
	ve.push_back(root);
	cur = root;
	while(ve.size()!=0){
		//cout << cur->value << " ";
		int evidence = cur-> value;
		if (evidence==suspect)
		{
			return TRUE;
		}
		if (cur->leftboy!=NULL){ //если есть левый
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" Идём влево ";
			continue;
		}
		else{ //если нет левого
			sorry:
			if (cur->rightbrother!=NULL){ //но есть братец
				ve.pop_back(); //удалить левый из вектор
				cur = cur->rightbrother; //перейти на брата
				ve.push_back(cur);
				//cout<<" Идём вправо ";
			}else{ //если даже брата нет
				ve.pop_back();
				cur = ve.back();
				//cout<<" Идём вверх ";
				if (ve.size()>0) goto sorry;
			}
		} 
	}
	return FALSE;
}

void Intersection(BST& A, BST& B){
	cout << "\nПроизводится пересечение...\n";
	A.PreorderToDelete(B);
	return;
}

void BST::Postorder(){ //обратный обход
		vector<bst*> ve;
	if (root==NULL){
		cout << "дерево пустое\n";
		return;
	}
	
	bst *cur = new(bst);
	if ((root!=NULL)&&(root->leftboy==NULL)){
		cout << root->value << "\n";
		return;
	}
	
	ve.push_back(root);
	cur = root;
	while(ve.size()!=0){
		//cout << cur->value << " "; //выводим значение узла
		if (cur->leftboy!=NULL){ //если есть левый
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" Идём влево ";
			continue;
		}
		else{ //если нет левого
			sorry:
			if (cur->rightbrother!=NULL){ //но есть братец
				cout << cur->value << " ";
				ve.pop_back(); //удалить левый из вектор
				cur = cur->rightbrother; //перейти на брата
				ve.push_back(cur);
				//cout<<" Идём вправо ";
			}else{ //если даже брата нет
				cout << cur->value << " ";
				ve.pop_back();
				cur = ve.back();
				//cout<<" Идём вверх ";
				if (ve.size()>0) goto sorry;
			}
		} 
	}
}

int main (void){
	setlocale(LC_ALL, "Russian");
	BST A;
	BST B;
	int n = 0;
	int u;
	
	cout << "Дерево A: \n";
	cout << "Сколько элементов вы хотите ввести? \n";
	cin >> n;
	cout << "Вводите: ";
	for (int i =0; i<n; i++){
		cin>>u;
		A.Insert(u);
	}
	
	cout << "Дерево B: \n";
	cout << "Сколько элементов вы хотите ввести? \n";
	cin >> n;
	cout << "Вводите: ";
	for (int i =0; i<n; i++){
		cin>>u;
		B.Insert(u);
	}
	
	cout << "Дерево A прямым обходом: ";
	A.Preorder();
	cout << "\n";
	
	cout << "Дерево B симметричным обходом: ";
	B.Inorder();
	cout <<"\n";
	
 	Intersection(A, B);
 	
 	cout << "Теперь дерево A выглядит так: ";
 	A.Preorder();
 	
	return 0; }
