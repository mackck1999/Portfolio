package Kursovaya;

import java.util.Scanner;

public class Six {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("������� 9 ���������: ");
        int arr[] = new int[9]; //����� ����� ������ �� 9 �������� ������ ����
        for (int i = 0; i < 9; i++) { //������ ��
            arr[i] = in.nextInt();
        }
        in.close();
        QSort(arr, 0, arr.length - 1); //���������(��������� ����� ������� ����� ������ �������
        //��������, � ��������� ������ ������ ����������)

        Output(arr);
    }

    public static void swap(int[] arr, int ind1, int ind2) { //������� ������ ����������
        //���� ��������� �������. ��������� ������, ������ ������� � ������ �������.
        int r = arr[ind1]; //����������� ��������� ���������� ������� � ������ ��������
        arr[ind1] = arr[ind2]; //�������� � ������ �������� ����������� �������� ��������
        //						�� ������ ��������
        arr[ind2] = r; //�������� �� ������ �������� ����������� �������� ����������
    }

    public static void QSort(int[] arr, int lo, int hi) { //������� ���������� �����
        //	��������� ������, ����� ����� ��� ������, ����� ������
        if (lo >= hi) { //���� ����� ������ ��� ����� �������, ��������� ������
            return;
        }
        int pivot = arr[lo]; //��������� ����� ����� �� ������� �������
        int i = lo - 1; //"���������" ����� �� ������������ �������, ���������� ���������������
        //					���� ����� ������ �������
        int j = hi + 1; //� ������ ����������
        while (1 > 0) { //����������� ����
            do { //��������� ������������ ������ "���������"
                i = i + 1;
            } while (arr[i] < pivot); //���� ��� �������� ������ ����������

            do { //������ ��� ��
                j = j - 1;
            } while (arr[j] > pivot);

            if (i >= j) { //���� ��������� �����������
                break; //�� ������� �� �����
            }

            swap(arr, i, j); //������ ��� ������ �������� ��� ����������� �������
        }
        QSort(arr, lo, j); //��� ����� ���������
        QSort(arr, j + 1, hi); //� ��� ������ ���������
    }

    public static void Output(int arr[]) { //����� �������
        System.out.print("�����: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
