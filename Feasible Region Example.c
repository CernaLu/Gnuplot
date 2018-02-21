/* Luis Eduardo Cerna
   Universidad de Guanajuato
   20/02/2018
   Tarea 1, Investigación de operaciones

   Este es un programa para realizar el método gráfico
   para la maximización de una función.
   */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
int c, n;
double i, j, x1, x2, *src;
FILE *dst;
src = malloc( c * sizeof(double));
dst = fopen("Tarea_01.p", "w");

c = 0;
fprintf(dst, "set xrange [0:10]\n");
fprintf(dst, "set yrange [0:10]\n");
fprintf(dst, "plot '-' w p ls 1");

for (x1=0.0; x1<=4.0; x1=x1+0.05)
  {
  for (x2=0.0; 2.0*x2<=12.0; x2=x2+0.05)
    {
    if (3.0*x1 + 2.0*x2 <= 18.0)
     {
     src[ 2*c ] = x1;
     src[ 2*c + 1 ] = x2;
     c++;
     }
    }
  }

  
double z;
int Z;
for (int a=0; a < c; a++)
  {
  z = (3.0*src[ 2*a ] + 2.0*src[ 2*a + 1]) / 2.0;
  Z = (int)z;
  fprintf(dst, ", '-' w p lc %d notitle", Z);
  }

for (int i = 0; i < c; i++)
  {
  fprintf(dst, "%lf %lf\n", src[ 2*i ], src[ 2*i + 1] );
  fprintf(dst, "e\n");
  }

fclose(dst);
free(src);
}
