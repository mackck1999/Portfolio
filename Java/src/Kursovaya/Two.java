package Kursovaya;
import java.util.Scanner;

public class Two {
public static void main(String[] args) {
Scanner in =new Scanner(System. in);
System.out.println("Введите(кол-во строк) M=");
int M =in.nextInt();
System.out.println("Введите(кол-во столбцов) N=");
int N=in.nextInt();
int [][] arr = new int[M][N]; //создаем двумерный массив
for (int i = 0; i < M; i++) { //заполнение массива построчно
System.out.print("Введите " + (i + 1) + " строку: ");
for (int j = 0; j < N; j++) {

arr[i][j] = in.nextInt();
}
}
in.close();
int min = 0;	//минимальный элемент

for (int i = 0; i < M; i++) {  //для демонстрации выводим нашу матрицу
System.out.println("");
for (int j = 0; j < N; j++) {
System.out.print(arr[i][j] + "|");
}
}
for (int i = 0; i < M; i++) { //установка начальных значений
for (int j = 0; j < N; j++) { //в каждом столбце
if (arr[j][i] > 0) { //если число положительное
min = arr[j][i]; //присваиваем
break; //выходим из цикла
}
}
for (int j = 0; j < N; j++) {
if ((arr[j][i] < min) && (arr[j][i] > 0)) { //если число больше нуля и меньше
//													минимума
min = arr[j][i];							//присваиваем его минимуму
}
}
//Выводим минимальное положительное в каждом столбце:
System.out.print("\nМинимальное положительное число в " + (i + 1) + " столбце = " + min);
}
}
}
