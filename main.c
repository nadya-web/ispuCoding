/*
Тема 6 задача 7
Разбить текст на страницы. Дан текстовый файл. Преобразовать его, разбив текст на страницы и пронумеровав их, 
причем номер нечетной страницы должен размещаться в правом нижнем углу, а номер четной страницы - в ее левом нижнем углу.
Число чтрок на странице задается, а ширина страницы определяется самой длинной строкой на данной странице.
Конец страницы отмечается символом с кодом 12, который помещаетс яна отдельной строке.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int page, k, maxlen, n;
    int symb = 12;
    char text[200];
    printf ("Введите кол-во строк на странице:");
    scanf("%d", &n);
 
    FILE *file = fopen("in.txt", "rt");
    FILE *out = fopen("out.txt", "w+");
 
    page = 1;
    k = 0;
    maxlen = 0;
    while (!feof(file)) {
        fgets(text, 200, file);
        k++;
 
        int len = strlen(text)-1;
 
        if (len > maxlen) {
            maxlen = len;
        }
 
        fputs(text, out);
        fputc('\n', out);
 
        if (k == n) {
            if (page % 2 == 0) {
                fprintf(out, "%d \n", page);
            } else {
                char str[10];
                sprintf(str, "%c%dd\n", '%', maxlen);
                fprintf(out, str, page);
            }
            fprintf(out, "%c \n", symb);
            page++;
            maxlen = 0;
            k = 0;
        }
    }
    printf ("Текст разбит на страницы");
 
    fclose(out);
    fclose(file);
}