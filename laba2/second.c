//
//  second.c
//  laba2
//
//  Created by Kamal Muradov on 28.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "sortingsHeader.h"


void fastSort(int linesCount, double* randomNumber, double t, FILE* fp){
    rewind(fp);
    clock_t start = clock();
    quickSort(randomNumber, 0, linesCount - 1);
    clock_t end = clock();
    t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время, занятое сортировкой: %lf\n", t);
}

void insertSort(int linesCount, double* randomNumber, double t, FILE* fp){
    rewind(fp);
    clock_t start = clock();
    InsertionSort(linesCount, randomNumber);
    clock_t end = clock();
    t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время отсортировки: %lf\n", t);
}

void bubbleSort(int linesCount, double* randomNumber, double t, FILE* fp){
    rewind(fp);
    clock_t start = clock();
    BubbleSort(linesCount, randomNumber);
    clock_t end = clock();
    t = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время отсортировки: %lf\n", t);
}

int main(){
    FILE* fp;
    char ch;
    int i, sort = 0;
    int linesCount = 0;
    double* randomNumber;
    double t = 0;
    int menuOption = 0;
    
    fp = fopen("textFile.txt", "r");
    
    while((ch=fgetc(fp))!=EOF) {
          if(ch=='\n')
             linesCount++;
       }
    
    randomNumber = (double*)malloc(linesCount * sizeof(double));
    
    rewind(fp);
    for (i = 0; i < linesCount; i++){
        fscanf(fp, "%lf", &randomNumber[i]);
    }
    
    do{
        printf("Выберите действие:\n\n1) Печать\n2) Сортировка\n3) Сброс\n4) Выход\n\nВаш выбор: ");
        scanf("%d", &menuOption);
        
        switch(menuOption){
            case 1:
                for (i = 0; i < linesCount; i++)
                     {
                       printf("%d) %lf\n", i + 1, randomNumber[i]);
                     }
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
                rewind(fp);
                for (i = 0; i < linesCount; i++){
                    fscanf(fp, "%lf", &randomNumber[linesCount]);
                }
                printf("Массив сброшен. Он полностью пустой\n");
                break;
                
            case 4:
                printf("Завершение программы...\n\n");
                sleep(5);
                break;
                
            default:
                printf("Не корректный ввод\n\n");
        }
        
    }while(menuOption != 4);
    
    fclose(fp);
    free(randomNumber);
    
    return 0;
}
