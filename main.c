//
//  main.c
//  Laboratorka
//
//  Created by Kamal Muradov on 27.10.2021.
//

#include <stdio.h>
#include <stdlib.h>

float RandomFloat(int min, int max){
   return ((max - min) * ((double)rand() / RAND_MAX)) + min;
}

int main(){
    
    int n = 0, min = 0, max = 0, i = 0;
    double sum = 0.0;
    double* randomNumber;
    int* randomNumberDecimal;
    
    printf("Введите кол-во случайных чисел: ");
    scanf("%d", &n);
    
    printf("Введите минимум диапазона: ");
    scanf("%d", &min);
    
    printf("Введите максимум диапазона: ");
    scanf("%d", &max);
    
    printf("\n");
    
    randomNumber = (double*)malloc(n * sizeof(double));
    randomNumberDecimal = (int*)malloc(n * sizeof(int));
    
    // создаем рандомное число и узнаем десятичную часть числа
    for (i = 0; i < n; i++) {
        
        randomNumber[i] = RandomFloat(min, max);
        randomNumberDecimal[i] = (randomNumber[i] - (int)randomNumber[i]) * 1000000;
        
    }
    // проверяем условия для суммирования
    for (i = 0; i < n; i++){
        
        if (randomNumberDecimal[i] > 0) {
            sum -= randomNumber[i];
        }
        else {
            sum += randomNumber[i];
        }
        
    }
    // вывод суммы
    printf("Полученная сумма: %f", sum);
    return 0; // программа успешно завершена
}

