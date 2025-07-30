//выводит строку
void put1(const char *);

//выводит строку и количество символов, без учета '\n'
int put2(const char *);

//объединяет две строки
char *str_cat(const char *, const char *, int *);

char *str_cat2(const char *, const char *);

//сравнивает строки
int str_cmp(const char *, const char *);

//сравнивает строки до n
int str_ncmp(const char *, const char *, int);

//копирует строку в строку
char *str_cpy(char *, const char *);

//копирует строку в строку до n элемента
char *str_ncpy(char *, const char *, int n);

//возвращает указатель на первую ячейку из s1, в которой содержится символ ch
char *str_chr(const char *, const char);
