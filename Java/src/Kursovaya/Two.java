package Kursovaya;
import java.util.Scanner;

public class Two {
public static void main(String[] args) {
Scanner in =new Scanner(System. in);
System.out.println("�������(���-�� �����) M=");
int M =in.nextInt();
System.out.println("�������(���-�� ��������) N=");
int N=in.nextInt();
int [][] arr = new int[M][N]; //������� ��������� ������
for (int i = 0; i < M; i++) { //���������� ������� ���������
System.out.print("������� " + (i + 1) + " ������: ");
for (int j = 0; j < N; j++) {

arr[i][j] = in.nextInt();
}
}
in.close();
int min = 0;	//����������� �������

for (int i = 0; i < M; i++) {  //��� ������������ ������� ���� �������
System.out.println("");
for (int j = 0; j < N; j++) {
System.out.print(arr[i][j] + "|");
}
}
for (int i = 0; i < M; i++) { //��������� ��������� ��������
for (int j = 0; j < N; j++) { //� ������ �������
if (arr[j][i] > 0) { //���� ����� �������������
min = arr[j][i]; //�����������
break; //������� �� �����
}
}
for (int j = 0; j < N; j++) {
if ((arr[j][i] < min) && (arr[j][i] > 0)) { //���� ����� ������ ���� � ������
//													��������
min = arr[j][i];							//����������� ��� ��������
}
}
//������� ����������� ������������� � ������ �������:
System.out.print("\n����������� ������������� ����� � " + (i + 1) + " ������� = " + min);
}
}
}
