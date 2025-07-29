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
