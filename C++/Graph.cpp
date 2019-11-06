/*Задание:
Дана матрица смежности.
Методом обхода в глубину вычислить цикломатическую сложность графа.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
int arr[100][100];
bool known[100][100];//информация о проверенных клетках
int n = 0; //вершины
int e = 0; //дуги
setlocale(LC_ALL, "Russian");
cout << "Введите количество узлов будущего графа\n";
cin >> n;
if (n<3){cout<<"Цикломатическая сложность равна единице";return 0;}
cout<<"Введите матрицу смежности\n";
for (int i = 0; i<n; i++){
for (int j = 0; j<n; j++){
cin >> arr[i][j];
}
}
	
for (int i = 0; i<n; i++){
for (int j = 0; j<n; j++){
known[i][j]=false;
}
}
	
	//на всякий случай удалим петли
	for (int i = 0; i<n; i++){
		arr[i][i] = 0;
	}
	
	vector<int>st;
	vector<int>ve;
	int	CurStr = 0;
	while(ve.size()<n){	
		for(int i = 0; i<n; i++){

			if ((arr[CurStr][i] == 0)&&(i==n-1)){ //если мы дошли до конца строки и всё в ней обработали
				ve.push_back(CurStr);
				CurStr = st.back();
				st.pop_back();

				break;
			}
					
			if((arr[CurStr][i]==1)&&(i==n-1)){ //если мы дошли до конца строки, но в последней ячейке единичка
				if (known[CurStr][i]==false){
				e++;
				known[CurStr][i]=true;
			}
				ve.push_back(CurStr);
				//если этого элемента нет в векторе или стеке
				if ((find(ve.begin(), ve.end(), i)==ve.end())&&(find(st.begin(),st.end(), i)==st.end())){
					CurStr = i;

				}else{
					CurStr = st.back();
					st.pop_back();

				}
				break;
			}
				
			if((arr[CurStr][i]==1)&&(((find(ve.begin(), ve.end(), i)==ve.end())&&(find(st.begin(),st.end(), i)==st.end())))&&(i!=n-1)){ //если на пересечении единичка и число не задействовано
				
				if (known[CurStr][i]==false){
					e++;
					known[CurStr][i]=true;
				}

				st.push_back(CurStr);
				CurStr = i;

				break;
			}
			
			if((arr[CurStr][i]==1)&&(((find(ve.begin(), ve.end(), i)!=ve.end())||(find(st.begin(),st.end(), i)!=st.end())))&&(i!=n-1)){ //если единичка, но есть в списках
				if (known[CurStr][i]==false){
				e++;
				known[CurStr][i]=true;
				}
			}
		}
	}
	cout<<"\nЦикломатическая сложность = " << e - n + 2;
	return 0;}
