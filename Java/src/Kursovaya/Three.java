package Kursovaya;
import java.util.Scanner;
public class Three {
    public static void main(String[] args) {
        System.out.println("Введите степень матрицы: "); //введите степень матрицы
        Scanner in = new Scanner(System.in);
        int size = in.nextInt(); //ввод степени
        int[][] arr = new int[size][size]; //создание массива этой степени
        in.close();
        for (int i = 0; i < size; i += 1) { //до конца массива
            for (int j = 0; j < size; j++) {
                if(i%2==0) { arr[i][j] = j + 1; } //если строка четная, заполняем её в прямом
                //									порядке
                else {arr[i][j] = size - j;} //иначе в обратном
            }
        }
        System.out.print("Матрица: "); //выводим матрицу
        for (int i = 0; i < size; i +=1) {
            System.out.println("");
            for (int j = 0; j < size; j++) {
                System.out.print(arr[i][j] + "|");
           }
        }
    }
}
