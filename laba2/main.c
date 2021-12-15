//
//  main.c
//  Laboratorka
//
//  Created by Kamal Muradov on 27.10.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float RandomFloat(int min, int max){
   return ((max - min) * ((double)rand() / RAND_MAX)) + min;
}

int dfdf1(){
    
    FILE *file;
    system("pwd");
    
    int n = 0, min = 0, max = 0, i = 0, indexOfNumber = 1;
    double sum = 0.0;
    unsigned char *randomNumber, *keyboardNumber;
    int menuOption = 0;
    int* randomNumberDecimal;
    
    do{
        printf("Выберите действие:\n\n1) Ввести с клавиатуры\n2) Сгенерировать случайные числа\n3) Завершить работу\nВаш выбор: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                file = fopen("textFile.txt","w");
                n = 0;
                printf("Выбрано действие 'Ввести с клавиатуры...'\n");
                printf("Введите количество вводимых чисел: ");
                scanf("%d", &n);
                if(n <= 0) {
                    printf("Кол-во чисел не может быть меньше или равно 0.\n");
                    menuOption = 1;
                    break;
                } else{
                    keyboardNumber = (unsigned char*)malloc(n * sizeof(unsigned char));
                    printf("Вводимое число не может быть меньше 0 и больше 255\n");
                    
                        for (i = 1; i < n + 1; i++){
                            scanf("%hhu", keyboardNumber);
                            fprintf ("%hhu\n%hhu", *keyboardNumber);
                    }
                    printf("\nИдет запись чисел. Ожидание...\n\n");
                    sleep(1);
                    printf("Запись чисел с клавиатуры была произведена успешно!");
                
                }
                printf("Запись прошла успешно!\n");
                fclose(file);
                free(keyboardNumber);
                break;
            case 2:
                file = fopen("textFile.txt","w");
                n = 0;
                printf("Введите кол-во случайных чисел: ");
                scanf("%d", &n);
                
                printf("Введите минимум диапазона: ");
                scanf("%d", &min);
                
                printf("Введите максимум диапазона: ");
                scanf("%d", &max);
                
                printf("\n");
                
                randomNumber = (unsigned char*)malloc(n * sizeof(unsigned char));
                randomNumberDecimal = (int*)malloc(n * sizeof(int));
                
                // создаем рандомное число и узнаем десятичную часть числа
                for (i = 0; i < n; i++) {
                    
                    randomNumber[i] = RandomFloat(min, max);
                    randomNumberDecimal[i] = (randomNumber[i] - (int)randomNumber[i]) * 1000000;
                    fprintf(file, "%hhu\n",randomNumber[i]);
                    
                }
                // проверяем условия для суммирования
                for (i = 0; i < n; i++){
                    
                    if (randomNumberDecimal[i] == indexOfNumber) {
                        sum -= randomNumber[i];
                    }
                    else {
                        sum += randomNumber[i];
                    }
                    indexOfNumber++;
                }
                // вывод суммы
                printf("Полученная сумма: %f\n\n", sum);
                free(randomNumber);
                free(randomNumberDecimal);
                fclose(file);
                break;
            case 3:
                printf("Завершение работы.\n\n");
                sleep(3);
                
        }
    }while(menuOption != 3);
    
    return 0; // программа успешно завершена
}

