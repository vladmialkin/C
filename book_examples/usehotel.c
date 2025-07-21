/* Программа определяет стоимость номеров в отеле. Страница 351.*/
#include <stdio.h>
#include "hotel.h"

int main(void)
{
	int nights; 		//количество ночей
	double hotel_rate; 	//рейтинг отеля
	int code; 		//выбор меню
	
	while((code = menu()) != QUIT)
	{
		switch(code)
		{
		case 1: hotel_rate = HOTEL1;
			break;
		case 2: hotel_rate = HOTEL2;
			break;
		case 3: hotel_rate = HOTEL3;
			break;
		case 4: hotel_rate = HOTEL4;
			break;
		default:
			hotel_rate = 0.0;
			printf("Ошибка!\n");
			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("Благодарим за использование и желаем успехов.\n");
	return 0;
}
