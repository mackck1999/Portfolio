package Kursovaya;


import java.util.Scanner;

import static java.lang.Math.*;


public class One {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Предупреждение! Не вводите отрицательные числа, поскольку в функции имеется квадратный корень");
        System.out.println("Введите a: ");
        float a = in.nextFloat(); //левая граница отрезка
            if (a>0) {
                System.out.println("Отлично,левая граница отрезка принята");
            } else {
                for(;a<0;) {
                    System.out.println("Вы ввели отрицательное число");
                    System.out.println("Введите положительное число");
                    a = in.nextFloat();
                }
            }
        System.out.println("Введите b: ");
        float b = in.nextFloat(); //правая граница отрезка
        if (b > 0) {
            System.out.println("Отлично, правая граница отрезка принята");
        } else {
            for(;b<0;) {
                System.out.println("Вы ввели отрицательное число");
                System.out.println("Введите положительное число");
                b = in.nextFloat();
            }
        }
        System.out.println("Введите шаг (h): ");
        float h = in.nextFloat(); //шаг
        //установка начальных значений
        if (h>0) {
            System.out.println("Отлично, размерность шага принята");
        } else {
            for(;h<0;){
                System.out.println("Вы ввели отрицательное число");
                System.out.println("Введите положительное число");
                h = in.nextFloat();
            }
        }
        double ans = F(a);  //вычисление ответа
        double max = a; //максимальный аргумент
        double min = a; //минимальный аргумент
        double Fmax = F(a); //максимальное значение функции
        double Fmin = F(a); //минимальное значение функции
        while (a < b) { //пока не дошли до правой границы
            ans = F(a); //вычисляем значение функции для текущего аргумента
            if (ans > Fmax) { //если это значение больше максимального
                Fmax = ans; //устанавливаем его как максимальное
                max = a; //и его аргумент, соответственно
            }
            if (ans < Fmin) { //если это значение меньше минимального
                Fmin = ans; //устанавливаем его как минимальное
                min = a; // и уже его аргумент
            }
            System.out.println("Когда x= " + a + "; F(x)= " + ans);    //выводим значение для каждого аргумента
            a += h; //прибавляем шаг
        }
        in.close();
        System.out.println("Максимум: x= " + max + "; F(x)= " + Fmax); //выводим максимальное значение
        //	и его аргумент
        System.out.println("Минимум: x= " + min + "; F(x)= " + Fmin); //выводим минимальное значение
        // и его аргумент
    }

    public static double F(float x) //метод функции
    {
         double y = sqrt(2 * x) *(Math.sin(Math.toRadians(x/2)));
        return y;

    }
}
