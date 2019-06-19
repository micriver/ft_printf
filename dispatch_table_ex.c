#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define GL_OPMAX 5


int
ft_add (int a, int b)
{
  return (a + b);
}


int
ft_sub (int a, int b)
{
  return (a - b);
}


int
ft_mul (int a, int b)
{
  return (a * b);
}


int
ft_div (int a, int b)
{
  return (b != 0 ? (a / b) : 0);
}


int
ft_mod (int a, int b)
{
  return (b != 0 ? (a % b) : 0);
}


typedef int (*math_f) (int, int);


typedef struct s_trans
{
  char op;
  math_f f;
} t_trans;


t_trans g_opertab[] = {
  {'*', &ft_mul},		// 0
  {'/', &ft_div},		// 1
  {'+', &ft_add},		// 2
  {'-', &ft_sub},		// 3
  {'%', &ft_mod}		// 4
};




int
main ()
{
  char ops[6] = { '+', '-', '/', '*', '%' };	//0 1 2 3 4
  int i1 = 22;
  int i2 = 20;
  int ans = 0;
  int i = -1;
  int j = -1;
  while (++j < 5)
    {
      i = -1;
      while (++i < GL_OPMAX)
	if (g_opertab[i].op == ops[j])
	  {
	    ans = g_opertab[i].f (i1, i2);	//i 2 j 0
	    printf ("ans: %d\n", ans);
	  }
    }
}