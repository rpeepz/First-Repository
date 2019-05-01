#include <stdio.h>
#define CYAN printf("\033[0;36m")
#define NC printf("\033[0m")
int main(void)
{
	char *filename = "poop", *str = "shit";
	CYAN;
	printf("Le fichierCYAN%sNC contient : {red}%s{eoc}\n", filename, str);
	NC;
	int a = 1;
	printf("hi% dholla", a);
	return (0);
}
