package Kursovaya;

import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;

public class Seven {
    public static void main(String[] args) {
        Deque<Double> Queue = new ArrayDeque<Double>(); //������ �������
        Deque<Double> Queue2 = new ArrayDeque<Double>(); //������ �������
        Scanner in = new Scanner(System.in);
        System.out.print("������� 10 ������������ �����: "); //������� 10 ���. �����
        for (int i = 0; i < 10; i++) {
            Queue.addLast(in.nextDouble()); //������������ �� � ����� ������� ������� ������
        }
        System.out.print("������� �: ");
        double C = in.nextFloat(); //������� C
        in.close();
        System.out.print("�����:");
        while(!Queue.isEmpty()) { //���� ������ ������� �� �����
            double a = Queue.removeFirst(); //����������� ���������� ����� ������ ������� �������
            //									� ������� ��� �� �������
            if(a<C) { //���� �� ������ C, �� ������� ���
                System.out.print(" " + a);
            }
            else {
                Queue2.addLast(a); //���� ���, �� ��������� �� ������ �������
            }
        }
        //����� : �� ������ ��� �������� ������ C, � ������ ���������� �� 2 �������
        while(!Queue2.isEmpty()) { //���� ������ ������� �� �����
            System.out.print(" " + Queue2.removeFirst()); //������� ��� � ��������
        }
    }
}
