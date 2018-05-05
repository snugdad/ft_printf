#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ft_printf.h"

int main()
{
//INTEGER TESTS
/*	int num = 5;

	printf("Force Plus sign only:\n");
	ft_printf("%+i\n", num);
	printf("%+i\n", num);
	printf("\n\n");
	
	printf("Force Plus sign && zero pad (width = 10)\n");
	ft_printf("%+010i\n", num);
	printf("%+010i\n", num);
	printf("\n\n");

	printf("Force Plus sign (width = 10 preci = 2)\n");
	ft_printf("%+10.2i\n", num);
	printf("%+10.2i\n", num);
	printf("\n\n");

	printf("Force plus sign (width = 1 preci = 10\n");
	ft_printf("%+1.10i\n", num);
	printf("%+1.10i\n", num);
	printf("\n\n");

	printf("Force plus sign && zero pad (width = 15 preci = 10)\n");
	ft_printf("%+015.10i\n", num);
	printf("%+015.10i\n", num);
	printf("\n\n");

	printf("Force ' ' sign && zero pad (width = 15, preci = 10)\n");
	ft_printf("% 015.10i\n", num);
	printf("% 015.10i\n", num);
	printf("\n\n");
	
	printf("Force + sign && left align (width = 15) (preci = 10)\n");
	ft_printf("%+-15.10i\n", num);
	printf("%+-15.10i\n", num);

	printf("\n\n");

	printf("Force ' ' sign && left align (width = 15, preci = 10)\n");
	ft_printf("% -15.10i\n", num);
	printf("% -15.10i\n", num);
	printf("\n\n");

	printf("No sign\n");
	ft_printf("%i\n", num);
	printf("%i\n", num);
	printf("\n\n");

	printf("No sign && left align\n");
	ft_printf("%-i\n", num);
	printf("%-i\n", num);
	printf("\n\n");

	printf("No sign && left_align(width = 15 preci = 10)\n");
	ft_printf("%-15.10i\n", num);
	printf("%-15.10i\n", num);
	printf("\n\n");

	printf("Force Plus sign only with input\n");
	ft_printf("%Heres some input :+i\n", num);
	printf("Heres some input :%+i\n", num);
	printf("\n\n");
	
	printf("Force Plus sign && zero pad with input(width = 10)\n");
	ft_printf("Heres some input :%+010i\n", num);
	printf("Heres some input :%+010i\n", num);
	printf("\n\n");

	printf("Force Plus sign with input(width = 10 preci = 2)\n");
	ft_printf("Heres some input :%+10.2i\n", num);
	printf("Heres some input :%+10.2i\n", num);
	printf("\n\n");

	printf("Force plus sign with input(width = 1 preci = 10\n");
	ft_printf("Heres some input :%+1.10i\n", num);
	printf("Heres some input :%+1.10i\n", num);
	printf("\n\n");

	printf("Force plus sign && zero pad with input(width = 15 preci = 10)\n");
	ft_printf("Heres some input :%+015.10i\n", num);
	printf("Heres some input :%+015.10i\n", num);
	printf("\n\n");

	printf("Force ' ' sign && zero pad with input(width = 15, preci = 10)\n");
	ft_printf("Heres some input :% 015.10i\n", num);
	printf("Heres some input :% 015.10i\n", num);
	printf("\n\n");
	
	printf("Force + sign && left align with input(width = 15) (preci = 10)\n");
	ft_printf("Heres some input :%+-15.10i\n", num);
	printf("Heres some input :%+-15.10i\n", num);

	printf("\n\n");

	printf("Force ' ' sign && left align with input(width = 15, preci = 10)\n");
	ft_printf("Heres some input :% -15.10i\n", num);
	printf("Heres some input :% -15.10i\n", num);
	printf("\n\n");

	printf("No sign with input\n");
	ft_printf("Heres some input :%i\n", num);
	printf("Heres some input :%i\n", num);
	printf("\n\n");

	printf("No sign && left align with input\n");
	ft_printf("Heres some input :%-i\n", num);
	printf("Heres some input :%-i\n", num);
	printf("\n\n");

	printf("No sign && left_align with input(width = 15 preci = 10)\n");
	ft_printf("Heres some input :%-15.10i\n", num);
	printf("Heres some input :%-15.10i\n", num);
	printf("\n\n");

	printf("Force Plus sign only with input\n");
	ft_printf("Heres some input: %+i between string %+i\n", num, num);
	printf("Heres some input :%+i between string %+i\n", num, num);
	printf("\n\n");
	
	printf("Force Plus sign && zero pad with input(width = 10)\n");
	ft_printf("Heres some input :%+010i between string %+010i\n", num, num);
	printf("Heres some input :%+010i between string %+010i\n", num, num);
	printf("\n\n");

	printf("Force Plus sign with input(width = 10 preci = 2)\n");
	ft_printf("Heres some input :%+10.2i between string %+10.2i\n", num, num);
	printf("Heres some input :%+10.2i between string %+10.2i\n", num, num);
	printf("\n\n");

	printf("Force plus sign with input(width = 1 preci = 10\n");
	ft_printf("Heres some input :%+1.10i between string %+1.10i\n", num, num);
	printf("Heres some input :%+1.10i between string %+1.10i\n", num, num);
	printf("\n\n");

	printf("Force plus sign && zero pad with input(width = 15 preci = 10)\n");
	ft_printf("Heres some input :%+015.10i between string %+015.10i\n", num, num);
	printf("Heres some input :%+015.10i between string %+015.10i\n", num, num);
	printf("\n\n");

	printf("Force ' ' sign && zero pad with input(width = 15, preci = 10)\n");
	ft_printf("Heres some input :% 015.10i between string % 015.10i\n", num, num);
	printf("Heres some input :% 015.10i between string % 015.10i\n", num, num);
	printf("\n\n");
	
	printf("Force + sign && left align with input(width = 15) (preci = 10)\n");
	ft_printf("Heres some input :%+-15.10i between string %+-15.10i\n", num, num);
	printf("Heres some input :%+-15.10i between string %+-15.10i\n", num, num);

	printf("\n\n");

	printf("Force ' ' sign && left align with input(width = 15, preci = 10)\n");
	ft_printf("Heres some input :% -15.10i between string % -15.10i\n", num, num);
	printf("Heres some input :% -15.10i between string % -15.10i\n", num, num);
	printf("\n\n");

	printf("No sign with input\n");
	ft_printf("Heres some input :%i between string %i\n", num, num);
	printf("Heres some input :%i between string %i\n", num, num);
	printf("\n\n");

	printf("No sign && left align with input\n");
	ft_printf("Heres some input :%-i between string %-i\n", num, num);
	printf("Heres some input :%-i between string %-i\n", num, num);
	printf("\n\n");

	printf("No sign && left_align with input(width = 15 preci = 10)\n");
	ft_printf("Heres some input :%-15.10i between string %-15.10i\n", num, num);
	printf("Heres some input :%-15.10i between string %-15.10i\n", num, num);
	printf("\n\n");

	//STRING TESTS
	char *s;
	s = "Hello";
	printf("Basic Test\n");
	ft_printf("%s\n", s);
	printf("%s\n", s);
	printf("\n\n");

	//CHAR TESTS
	char c = '*';
	printf("Basic Test\n");
	ft_printf("%c\n", c);
	printf("%c\n", c);
	printf("\n\n");
	

	//HEX TESTS
	printf("HEX\n");
	char *p;
	p = &c;
	printf("Basic Test p\n");
	ft_printf("%p\n", p);
	printf("%p\n", p);
	printf("\n\n");

	printf("Basic Test x\n");
	ft_printf("%x\n", (unsigned int)p);
	printf("%x\n", (unsigned int)p);
	printf("\n\n");

	printf("Basic Test X\n");
	ft_printf("%X\n", (unsigned int)p);
	printf("%X\n", (unsigned int)p);
	printf("\n\n");
*/
	//BIN TESTS
	printf("BINARY\n");
	unsigned int b = 5;

	printf("Basic Test \n");
	ft_printf("%b\n", (unsigned int)b);
	printf("\n\n");

}
