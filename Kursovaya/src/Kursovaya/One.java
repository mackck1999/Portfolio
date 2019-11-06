package Kursovaya;


import java.util.Scanner;

import static java.lang.Math.*;


public class One {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("��������������! �� ������� ������������� �����, ��������� � ������� ������� ���������� ������");
        System.out.println("������� a: ");
        float a = in.nextFloat(); //����� ������� �������
            if (a>0) {
                System.out.println("�������,����� ������� ������� �������");
            } else {
                for(;a<0;) {
                    System.out.println("�� ����� ������������� �����");
                    System.out.println("������� ������������� �����");
                    a = in.nextFloat();
                }
            }
        System.out.println("������� b: ");
        float b = in.nextFloat(); //������ ������� �������
        if (b > 0) {
            System.out.println("�������, ������ ������� ������� �������");
        } else {
            for(;b<0;) {
                System.out.println("�� ����� ������������� �����");
                System.out.println("������� ������������� �����");
                b = in.nextFloat();
            }
        }
        System.out.println("������� ��� (h): ");
        float h = in.nextFloat(); //���
        //��������� ��������� ��������
        if (h>0) {
            System.out.println("�������, ����������� ���� �������");
        } else {
            for(;h<0;){
                System.out.println("�� ����� ������������� �����");
                System.out.println("������� ������������� �����");
                h = in.nextFloat();
            }
        }
        double ans = F(a);  //���������� ������
        double max = a; //������������ ��������
        double min = a; //����������� ��������
        double Fmax = F(a); //������������ �������� �������
        double Fmin = F(a); //����������� �������� �������
        while (a < b) { //���� �� ����� �� ������ �������
            ans = F(a); //��������� �������� ������� ��� �������� ���������
            if (ans > Fmax) { //���� ��� �������� ������ �������������
                Fmax = ans; //������������� ��� ��� ������������
                max = a; //� ��� ��������, ��������������
            }
            if (ans < Fmin) { //���� ��� �������� ������ ������������
                Fmin = ans; //������������� ��� ��� �����������
                min = a; // � ��� ��� ��������
            }
            System.out.println("����� x= " + a + "; F(x)= " + ans);    //������� �������� ��� ������� ���������
            a += h; //���������� ���
        }
        in.close();
        System.out.println("��������: x= " + max + "; F(x)= " + Fmax); //������� ������������ ��������
        //	� ��� ��������
        System.out.println("�������: x= " + min + "; F(x)= " + Fmin); //������� ����������� ��������
        // � ��� ��������
    }

    public static double F(float x) //����� �������
    {
         double y = sqrt(2 * x) *(Math.sin(Math.toRadians(x/2)));
        return y;

    }
}
