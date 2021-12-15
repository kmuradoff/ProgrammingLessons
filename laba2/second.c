//
//  second.c
//  laba2
//
//  Created by Kamal Muradov on 28.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "sortingsHeader.h"


void fastSort(int linesCount, unsigned char* randomNumber, double t, FILE* fp){
    rewind(fp);
    clock_t start = clock();
    quickSort(randomNumber, 0, linesCount - 1);
    clock_t end = clock();
    t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время, занятое сортировкой: %lf\n", t);
}

void insertSort(int linesCount, unsigned char* randomNumber, double t, FILE* fp){
    rewind(fp);
    clock_t start = clock();
    InsertionSort(linesCount, randomNumber);
    clock_t end = clock();
    t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время отсортировки: %lf\n", t);
}

void bubbleSort(int linesCount, unsigned char* randomNumber, double t, FILE* fp){
    rewind(fp);
    clock_t start = clock();
    BubbleSort(linesCount, randomNumber);
    clock_t end = clock();
    t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время отсортировки: %lf\n", t);
}

int main(int argc, char *argv[]){
    
    FILE* fp;
    char ch;
    int i, sort = 0, p = 0;
    int linesCount = 0;
    double secondSum = 0, sqrtedNums = 0, maxVector = -INFINITY, normVector = 0;
    unsigned char* randomNumber, *pRandomNumber;
    double t = 0;
    int menuOption = 0;
    

    fp = fopen("textFile.txt", "r");
    
    while((ch=fgetc(fp))!=EOF) {
          if(ch=='\n')
             linesCount++;
       }
    
    randomNumber = (unsigned char*)malloc(linesCount * sizeof(unsigned char));
    pRandomNumber = (unsigned char*)malloc(linesCount * sizeof(unsigned char));

    rewind(fp);
    for (i = 0; i < linesCount; i++){
        fscanf(fp, "%hhu", &randomNumber[i]);
    }
    
    if(argc == 2){
        if (strcmp("--fast", argv[1]) == 0) {
            fastSort(linesCount,randomNumber,t,fp);
            for (i = 0; i < linesCount; i++){
                   printf("%d) %hhu\n", i + 1, randomNumber[i]);
                
            }
            return 0;
        } else if (strcmp("--bubble", argv[1]) == 0) {
           bubbleSort(linesCount,randomNumber,t,fp);
            for (i = 0; i < linesCount; i++){
                   printf("%d) %hhu\n", i + 1, randomNumber[i]);
                
            }
           return 0;
        } else if (strcmp("--insertion", argv[1]) == 0) {
            insertSort(linesCount,randomNumber,t,fp);
            for (i = 0; i < linesCount; i++){
                   printf("%d) %hhu\n", i + 1, randomNumber[i]);
                
            }
            return 0;
       }
    }
    
    do{
        printf("Выберите действие:\n\n1) Печать\n2) Сортировка\n3) Сброс\n4) Вычисление первой нормы вектора\n5) Вычисление второй нормы вектора\n6) Вычисление Гельдеровой нормы вектора\n7) Вычисление бесконечной нормы вектора\n8) Выполнить нормировку вектора\n9) Выход\n\nВаш выбор: ");
        scanf("%d", &menuOption);
        secondSum = 0;
        
        switch(menuOption){
            case 1:
                for (i = 0; i < linesCount; i++)
                     {
                       printf("%d) %hhu\n", i + 1, randomNumber[i]);
                     }
                sleep(2);
                break;
                
            case 2:
                do{
                    printf("Выберите метод сортировки:\n1. Пузырьком\n2. Вставкой\n3. Быстрая\n\nВаш выбор: ");
                    scanf("%d", &sort);
                    switch(sort){
                        case 1: // пузырёк
                            bubbleSort(linesCount,randomNumber,t,fp);
                            break;
                        case 2: // вставка
                            insertSort(linesCount,randomNumber,t,fp);
                            break;
                        case 3:
                            fastSort(linesCount,randomNumber,t,fp);
                            break;
                        default:
                            printf("Не правильный выбор, пожалуйста попробуйте еще раз.\n\n");
                            break;
                            }
                }while(sort <= 0 || sort > 3);
                
                break;
                
            case 3:
                for (i = 0; i < linesCount; i++){
                    fscanf(fp, "%hhu", &randomNumber[i]);
                }
                printf("Массив сброшен.\n");
                sleep(2);
                break;
                
            case 4:
                for(i = 0; i < linesCount; i++){
                    pRandomNumber[i] = (randomNumber[i]);
                    secondSum += pRandomNumber[i];
                    
                }
                printf("%f\n", secondSum);
                sleep(2);
                break;
                
            case 5:
                for(i = 0; i < linesCount; i++){
                    pRandomNumber[i] = (randomNumber[i]);
                    secondSum += pRandomNumber[i] * pRandomNumber[i];
                    
                }
                
                printf("%f\n", sqrt(secondSum));
                sleep(2);
                break;
                
            case 6:
                printf("Введите значение P: ");
                scanf("%d", &p);
                for(i = 0; i < linesCount; i++){
                    secondSum += pow((randomNumber[i]), p);
                }
                normVector = pow(secondSum, 1.0/p);
                printf("%f\n\n", normVector);
                sleep(2);
                break;
                
            case 7:
                for(i = 0; i < linesCount; i++){
                    pRandomNumber[i] = (randomNumber[i]);
                }
                for(i = 0; i < linesCount; i++){
                    if(pRandomNumber[i] > maxVector){
                        maxVector = pRandomNumber[i];
                    }
                }
                printf("Бесконечная норма вектора равна %f", maxVector);
                sleep(2);
                break;
                
            case 8:
                for(i = 0; i < linesCount; i++){
                    pRandomNumber[i] = (randomNumber[i]);
                    secondSum += pRandomNumber[i] * pRandomNumber[i];
                    
                }
                sqrtedNums = sqrt(secondSum);
                for(i = 0; i < linesCount; i++){
                    printf("%d) %f\n", i + 1,randomNumber[i]/sqrtedNums);
                }
                sleep(2);
                break;
                
                
            case 9:
                printf("Завершение программы...\n\n");
                sleep(3);
                break;
                
                
            default:
                printf("Не корректный ввод\n\n");
        }
        
    }while(menuOption != 9);
    
    fclose(fp);
    free(randomNumber);
    
    return 0;
}
