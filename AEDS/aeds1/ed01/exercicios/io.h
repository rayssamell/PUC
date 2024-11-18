// 999999_AED1
#include <stdio.h>
#include <stdbool.h>

void print   ( char *text )
{
	printf   ( "%s"  , text );    
}
void println ( char *text )
{
	printf   ( "%s\n", text );    
}
void pause   ( char *text )
{
	printf   ( "%s\n", text );    
	getchar( );
}
int readint  ( char *text )
{
	int     x = 0;
	printf  ( "%s" , text );
	scanf   ( "%d" , &x   );   getchar ( );
	return  ( x );
}
double readdouble ( char *text )
{
	double  x = 0.0;
	printf  ( "%s" , text );
	scanf   ( "%lf", &x   );   getchar ( );
	return  ( x );
}
bool   readbool   ( char *text )
{
	int     x = 0;
	printf  ( "%s" , text );
	scanf   ( "%d" , &x   );   getchar ( );
	return  ( x != 0 );
}
char   readchar   ( char *text )
{
	char    x = '0';
	char    y = '0';
	printf  ( "%s" , text );
	scanf   ( "%c" , &x   );   getchar ( );
	do
	{
		y = getchar ( );
	}
	while ( y != '\n' );
	return  ( x );
}

