
package Kursovaya;

import java.util.Scanner;

public class Five {
    public static void main(String[] args) {
        System.out.print("������� ����� �������� \n"); //������� ����� ��������
        Scanner in = new Scanner(System.in);
        int x = in.nextInt(); //����
        long a = Fib(x); //������ �������
        in.close();
        System.out.println("�����: " + a);
    }

    public static long Fib(int x) { //����������� �������
        if ((x==1)||(x==2)) { //������ � ������ ������� ����� �������
            return 1;
        }
        if (x==0) { //������� ������� ����� ����
            return 0;
        }
        return Fib(x-2)+Fib(x-1); //���������� ����� ������� ��� ���� �������� ������
    }
}
