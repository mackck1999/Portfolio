package Kursovaya;
import java.util.Scanner;
public class Three {
    public static void main(String[] args) {
        System.out.println("������� ������� �������: "); //������� ������� �������
        Scanner in = new Scanner(System.in);
        int size = in.nextInt(); //���� �������
        int[][] arr = new int[size][size]; //�������� ������� ���� �������
        in.close();
        for (int i = 0; i < size; i += 1) { //�� ����� �������
            for (int j = 0; j < size; j++) {
                if(i%2==0) { arr[i][j] = j + 1; } //���� ������ ������, ��������� � � ������
                //									�������
                else {arr[i][j] = size - j;} //����� � ��������
            }
        }
        System.out.print("�������: "); //������� �������
        for (int i = 0; i < size; i +=1) {
            System.out.println("");
            for (int j = 0; j < size; j++) {
                System.out.print(arr[i][j] + "|");
           }
        }
    }
}
