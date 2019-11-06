package Kursovaya;

import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;

public class Seven {
    public static void main(String[] args) {
        Deque<Double> Queue = new ArrayDeque<Double>(); //перва€ очередь
        Deque<Double> Queue2 = new ArrayDeque<Double>(); //втора€ очередь
        Scanner in = new Scanner(System.in);
        System.out.print("¬ведите 10 вещественных чисел: "); //введите 10 вещ. чисел
        for (int i = 0; i < 10; i++) {
            Queue.addLast(in.nextDouble()); //проталкиваем их с конца первого массива подр€д
        }
        System.out.print("¬ведите —: ");
        double C = in.nextFloat(); //элемент C
        in.close();
        System.out.print("¬ывод:");
        while(!Queue.isEmpty()) { //пока перва€ очередь не пуста
            double a = Queue.removeFirst(); //присваиваем переменной самый первый элемент очереди
            //									и удал€ем его из очередь
            if(a<C) { //если он меньше C, то выводим его
                System.out.print(" " + a);
            }
            else {
                Queue2.addLast(a); //если нет, то добавл€ем во вторую очередь
            }
        }
        //итого : мы вывели все элементы меньше C, а больше переложили во 2 очередь
        while(!Queue2.isEmpty()) { //пока втора€ очередь не пуста
            System.out.print(" " + Queue2.removeFirst()); //выводим все еЄ элементы
        }
    }
}
