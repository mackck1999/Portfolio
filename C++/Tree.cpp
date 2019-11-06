/*�������:
����������� ������ ��������� ������. ��������� �� ������ ���� � ������� �����. � = A ? B. ����� ����� � � ������. B � ������������.
�������:
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
                BST();                               // ����������� �������
                bool IsEmpty();             // ������� �������� ������ �� �������
                void Insert(int a); //���������� ��������
                void Preorder(); //������ �����
                void Inorder(); //������������ �����
	    void PreorderToDelete(BST& vtoroe); //������ ����� � ���������
                bool PreorderToSearch(int suspect); //������ ����� ��� ������
                void Postorder(); //�������� �����
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
	else{ //���� ���� ������
		bool b = TRUE; //�� ��������
		bst *cur = root;
		cur->leftboy = root->leftboy;
		while(b){ //���� �� ��������
			if (a<cur->value){ //���� ������� ������ ��������
				if (cur->leftboy==NULL){ //���� ������ ���� ���
					cur->leftboy = tmp; //������ ������
					b = TRUE;
					break;
				}
				else{ //���� ����� ������� ���� ����
					cur = cur->leftboy;
					continue;
				}			
			}
			else{ if (a>cur->value){ //���� ������� ������ ��������
				if (cur->leftboy==NULL){ //���� ������ ������� ���
					b = FALSE; //����� ����, ������� �� �����
					break;
				}
				else{//���� ����� ������� ����
					if(cur->leftboy->rightbrother==NULL){ //���� ������� ������� ���
						cur->leftboy->rightbrother = tmp;
						b = TRUE;
						break;
					}
					else { //���� ������ ������� ����
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

void BST::Preorder(){ //������ �����
	vector<bst*> ve;
	if (root==NULL){
		cout << "������ ������\n";
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
		cout << cur->value << " "; //������� �������� ����
		if (cur->leftboy!=NULL){ //���� ���� �����
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" ��� ����� ";
			continue;
		}
		else{ //���� ��� ������
			sorry:
			if (cur->rightbrother!=NULL){ //�� ���� ������
				ve.pop_back(); //������� ����� �� ������
				cur = cur->rightbrother; //������� �� �����
				ve.push_back(cur);
				//cout<<" ��� ������ ";
			}else{ //���� ���� ����� ���
				ve.pop_back();
				cur = ve.back();
				//cout<<" ��� ����� ";
				if (ve.size()>0) goto sorry;
			}
		} 
	}
}

void BST::Inorder(){ //������������ �����
	vector<bst*> ve;
	vector<int> demo;
	if (root==NULL){
		cout << "������ ������\n";
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
	//	cout << cur->value << " "; //������� �������� ����
		if (cur->leftboy!=NULL){ //���� ���� �����
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" ��� ����� ";
			continue;
		}
		else{ //���� ��� ������
			sorry:
			if (cur->rightbrother!=NULL){ //�� ���� ������
				
				
				if ((find(demo.begin(), demo.end(), (ve.back()->value)))==demo.end()){
					cout << ve.back()->value << " ";
					demo.push_back(ve.back()->value);
				}
				
				ve.pop_back(); //������� ����� �� ������
				if ((find(demo.begin(), demo.end(), ve.back()->value))==demo.end()){
					cout << ve.back()->value << " ";
					demo.push_back(ve.back()->value);
				}
				cur = cur->rightbrother; //������� �� �����
				ve.push_back(cur);
				
				//cout<<" ��� ������ ";
			}else{ //���� ���� ����� ���
				
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
				//cout<<" ��� ����� ";
				if (ve.size()>0) goto sorry;
			}
		} 
	}
}

void BST::PreorderToDelete(BST& vtoroe){ //������ ��� ��������
	/* ���������� ���������� �� �������� */
	BST Temp;
	{ //������ �����
	vector<bst*> ve;
	if (root==NULL){
		//cout << "������ ������\n";
		return;
	}
	
	bst *cur = new(bst);
	if ((root!=NULL)&&(root->leftboy==NULL)){ //���� ���� ������ ������
		//cout << root->value << "\n";
		bool ToAdd = vtoroe.PreorderToSearch(root->value); //���� ����� ���� ���� �� ������ ������
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
		//cout << cur->value << " "; //������� �������� ����
		if (cur->leftboy!=NULL){ //���� ���� �����
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" ��� ����� ";
			continue;
		}
		else{ //���� ��� ������
			sorry:
			if (cur->rightbrother!=NULL){ //�� ���� ������
				ve.pop_back(); //������� ����� �� ������
				cur = cur->rightbrother; //������� �� �����
				ve.push_back(cur);
				//cout<<" ��� ������ ";
			}else{ //���� ���� ����� ���
				ve.pop_back();
				cur = ve.back();
				//cout<<" ��� ����� ";
				if (ve.size()>0) goto sorry;
			}
		} 
	}
}
this->root=Temp.root;
}

bool BST::PreorderToSearch(int suspect){ //������ ��� ������
		/*������� ���� ���� � ������������� ��������� */
		
		vector<bst*> ve;
	if (root==NULL){
		cout << "������ ������\n";
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
		if (cur->leftboy!=NULL){ //���� ���� �����
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" ��� ����� ";
			continue;
		}
		else{ //���� ��� ������
			sorry:
			if (cur->rightbrother!=NULL){ //�� ���� ������
				ve.pop_back(); //������� ����� �� ������
				cur = cur->rightbrother; //������� �� �����
				ve.push_back(cur);
				//cout<<" ��� ������ ";
			}else{ //���� ���� ����� ���
				ve.pop_back();
				cur = ve.back();
				//cout<<" ��� ����� ";
				if (ve.size()>0) goto sorry;
			}
		} 
	}
	return FALSE;
}

void Intersection(BST& A, BST& B){
	cout << "\n������������ �����������...\n";
	A.PreorderToDelete(B);
	return;
}

void BST::Postorder(){ //�������� �����
		vector<bst*> ve;
	if (root==NULL){
		cout << "������ ������\n";
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
		//cout << cur->value << " "; //������� �������� ����
		if (cur->leftboy!=NULL){ //���� ���� �����
			cur = cur->leftboy;
			ve.push_back(cur);
			//cout<<" ��� ����� ";
			continue;
		}
		else{ //���� ��� ������
			sorry:
			if (cur->rightbrother!=NULL){ //�� ���� ������
				cout << cur->value << " ";
				ve.pop_back(); //������� ����� �� ������
				cur = cur->rightbrother; //������� �� �����
				ve.push_back(cur);
				//cout<<" ��� ������ ";
			}else{ //���� ���� ����� ���
				cout << cur->value << " ";
				ve.pop_back();
				cur = ve.back();
				//cout<<" ��� ����� ";
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
	
	cout << "������ A: \n";
	cout << "������� ��������� �� ������ ������? \n";
	cin >> n;
	cout << "�������: ";
	for (int i =0; i<n; i++){
		cin>>u;
		A.Insert(u);
	}
	
	cout << "������ B: \n";
	cout << "������� ��������� �� ������ ������? \n";
	cin >> n;
	cout << "�������: ";
	for (int i =0; i<n; i++){
		cin>>u;
		B.Insert(u);
	}
	
	cout << "������ A ������ �������: ";
	A.Preorder();
	cout << "\n";
	
	cout << "������ B ������������ �������: ";
	B.Inorder();
	cout <<"\n";
	
 	Intersection(A, B);
 	
 	cout << "������ ������ A �������� ���: ";
 	A.Preorder();
 	
	return 0; }
