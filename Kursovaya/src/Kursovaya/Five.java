
package Kursovaya;

import java.util.Scanner;

public class Five {
    public static void main(String[] args) {
        System.out.print("Введите номер элемента \n"); //введите номер элемента
        Scanner in = new Scanner(System.in);
        int x = in.nextInt(); //ввод
        long a = Fib(x); //запуск функции
        in.close();
        System.out.println("Ответ: " + a);
    }

    public static long Fib(int x) { //рекурсивная функция
        if ((x==1)||(x==2)) { //первый и второй элемент равны единице
            return 1;
        }
        if (x==0) { //нулевой элемент равен нулю
            return 0;
        }
        return Fib(x-2)+Fib(x-1); //возвращаем сумму функций для двух значений меньше
    }
}
