/*�������:
���� ������� ���������.
������� ������ � ������� ��������� ��������������� ��������� �����.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
int arr[100][100];
bool known[100][100];//���������� � ����������� �������
int n = 0; //�������
int e = 0; //����
setlocale(LC_ALL, "Russian");
cout << "������� ���������� ����� �������� �����\n";
cin >> n;
if (n<3){cout<<"��������������� ��������� ����� �������";return 0;}
cout<<"������� ������� ���������\n";
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
	
	//�� ������ ������ ������ �����
	for (int i = 0; i<n; i++){
		arr[i][i] = 0;
	}
	
	vector<int>st;
	vector<int>ve;
	int	CurStr = 0;
	while(ve.size()<n){	
		for(int i = 0; i<n; i++){

			if ((arr[CurStr][i] == 0)&&(i==n-1)){ //���� �� ����� �� ����� ������ � �� � ��� ����������
				ve.push_back(CurStr);
				CurStr = st.back();
				st.pop_back();

				break;
			}
					
			if((arr[CurStr][i]==1)&&(i==n-1)){ //���� �� ����� �� ����� ������, �� � ��������� ������ ��������
				if (known[CurStr][i]==false){
				e++;
				known[CurStr][i]=true;
			}
				ve.push_back(CurStr);
				//���� ����� �������� ��� � ������� ��� �����
				if ((find(ve.begin(), ve.end(), i)==ve.end())&&(find(st.begin(),st.end(), i)==st.end())){
					CurStr = i;

				}else{
					CurStr = st.back();
					st.pop_back();

				}
				break;
			}
				
			if((arr[CurStr][i]==1)&&(((find(ve.begin(), ve.end(), i)==ve.end())&&(find(st.begin(),st.end(), i)==st.end())))&&(i!=n-1)){ //���� �� ����������� �������� � ����� �� �������������
				
				if (known[CurStr][i]==false){
					e++;
					known[CurStr][i]=true;
				}

				st.push_back(CurStr);
				CurStr = i;

				break;
			}
			
			if((arr[CurStr][i]==1)&&(((find(ve.begin(), ve.end(), i)!=ve.end())||(find(st.begin(),st.end(), i)!=st.end())))&&(i!=n-1)){ //���� ��������, �� ���� � �������
				if (known[CurStr][i]==false){
				e++;
				known[CurStr][i]=true;
				}
			}
		}
	}
	cout<<"\n��������������� ��������� = " << e - n + 2;
	return 0;}
