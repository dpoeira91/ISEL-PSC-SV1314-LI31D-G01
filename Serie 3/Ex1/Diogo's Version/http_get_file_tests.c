#include <stdio.h>

int http_get_file(const char *url, const char * filename);

int main(){
	int count, tests = 1;
	count = 0;

	count = count + (1 - http_get_file("http://www.isel.pt/docs/img/fundo2.jpg", "output1.out"));
	count = count + (1 - http_get_file("http://i.imgur.com/7rBChAx.jpg", "output2.out"));
	count = count + (1 - http_get_file("http://arts.cultural-china.com/chinaWH/upload/upfiles/2010-06/24/top_ten_religious_sights_in_china121591cd1a53b986b2a8.jpg", "output3.out"));
	count = count + (1 - http_get_file("http://images.kuoni.co.uk/73/red-centre-sights-and-sounds-30256269-1362584227-ImageGalleryLightbox.jpg", "output4.out"));
	count = count + (1 - http_get_file("http://www.aurianeparishotel.com/images/sightseeing.jpg", "output5.out"));
	count = count + (1 - http_get_file("http://static.asiawebdirect.com/m/phuket/portals/www-singapore-com/homepage/tours/sightseeing-tours/TopPageContent/0/BigImage/sightseeing-tours-740.jpg", "output6.out"));

	if (count < tests){
		printf("The program failed %d \n", tests - count);
		return 1;
	}
	return 0;
}