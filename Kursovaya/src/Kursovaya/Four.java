package Kursovaya;
import java.util.Scanner;
public class Four{
    public static void main(String[] args) {
        System.out.print("Введите строку: "); //введите строку
        Scanner in = new Scanner(System.in);
        String input = in.nextLine(); //ввод строки
        char[] arr = new char[input.length()]; //создаем массив символов, длинной в строку
        input.getChars(0, input.length(), arr, 0); //переводим строку в массив символов
        int len = input.length();
        //выставляем счетчики скобок разного типа:
        int Opener1 = 0; // (
        int Opener2 = 0; // {
        int Opener3 = 0; // [
        int Opener4 = 0; // <
        int Closer1 = 0; // )
        int Closer2 = 0; // }
        int Closer3 = 0; // ]
        int Closer4 = 0; // >
        for (int i = 0; i < len; i++) { //до конца массива
            if (arr[i] == '(') { //если обнаружен символ, инкрементируем счетчик
                Opener1++;
            }
            if (arr[i] == '{') {
                Opener2++;
            }
            if (arr[i] == '[') {
                Opener3++;
            }
            if (arr[i] == '<') {
                Opener4++;
            }
            if (arr[i] == ')') {
                Closer1++;
            }
            if (arr[i] == '}') {
                Closer2++;
            }
            if (arr[i] == ']') {
                Closer3++;
            }
            if (arr[i] == '>') {
                Closer4++;
            }
        }
        if (Opener1 > Closer1) { //если открывающих больше, чем закрывающих
            for (int i = 0; i < (Opener1 - Closer1); i++) { //повторить количество раз, //	равное их разнице
                input = input + ")"; //добавить в конец закрывающую
            }
        }
        if (Opener2 > Closer2) {
            for (int i = 0; i < (Opener2 - Closer2); i++) {
                input = input + "}";
            }
        }
        if (Opener3 > Closer3) {
            for (int i = 0; i < (Opener3 - Closer3); i++) {
                input = input + "]";
            }
        }
        if (Opener4 > Closer4) {
            for (int i = 0; i < (Opener4 - Closer4); i++) {
                input = input + ">";
            }
        }
        if (Closer1 > Opener1) {
            for (int i = 0; i < (Closer1 - Opener1); i++) {
                input = "(" + input;
            }
        }
        if (Closer2 > Opener2) {
            for (int i = 0; i < (Closer2 - Opener2); i++) {
                input = "{" + input;
            }
        }
        if (Closer3 > Opener3) {
            for (int i = 0; i < (Closer3 - Opener3); i++) {
                input ="[" + input;
            }
        }
        if (Closer4 > Opener4) {
            for (int i = 0; i < (Closer4 - Opener4); i++) {
                input ="<" + input;
            }
        }
        in.close();
        System.out.print("Вывод: " + input); //вывести строку
    }
}
