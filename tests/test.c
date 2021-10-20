/* A terrible driver program by csd4802 */

/* assertion checks are perfomed by providing NULL pointers as arguments */

/* output has been generated using the pre-build string.h functions */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "mystring.h"


#define MAX_SIZE 100

/* redefing assert to get the desired output, yes its a bad practice */

#if __APPLE__
void __assert_rtn (__attribute__((unused)) const char * assertion, __attribute__((unused)) const char * file,
    __attribute__((unused))  int line, __attribute__((unused)) const char * function)
{
  fprintf(stdout, "Assertion failed\n");
  exit(EXIT_FAILURE);
}
#endif

#if __linux__
void __assert_fail( __attribute__((unused)) const char * assertion, __attribute__((unused)) const char * file,
    __attribute__((unused)) unsigned int line, __attribute__((unused)) const char * function)
{
  fprintf(stdout,"Assertion failed\n");
  exit(EXIT_FAILURE);

}
#endif

int get_input() /* getting input,char by char from stdin */
{
  int input = 0, tmp = 0;

  while ((tmp = getchar()) != EOF && tmp != '\n')
  {
    input = tmp;
  }

  return input - '0';
}

void check_copy(char *str1)
{
  char dest[MAX_SIZE] = {0};

  puts(ms_copy(dest,str1));


  ms_copy(NULL,NULL);
}

void check_concat(char *str1)
{
  char dest[MAX_SIZE]  = {0};

  ms_copy(dest,"Hello");

  puts(ms_concat(dest,str1));

  ms_concat(NULL,NULL);

  return;
}

void check_cmp(void)
{
  printf("%d\n",ms_compare("Hello","Hella"));
  printf("%d\n",ms_compare("Hello","Hellz"));
  printf("%d\n",ms_compare("Hello","Hello"));

  ms_compare(NULL,NULL);

  return;
}

void check_len(char *str)
{
  printf("%lu\n",(unsigned long)ms_length(str));

  ms_length(NULL);
}

void check_search(void)
{
  char *str = "Are you a SIMP: Sniper Monkey?";
  char *token = "SIMP";

  puts(ms_search(str,token));

  ms_search(NULL,NULL);
}

void check_ncmp(void)
{
  printf("%d\n",ms_ncompare("Hello","Hell",3));
  printf("%d\n",ms_ncompare("Hello","Helz",4));
  printf("%d\n",ms_ncompare("Hello","Hela",4));
  printf("%d\n",ms_ncompare("Hello","Hela",0));

  ms_ncompare(NULL,NULL,2);

}

void check_ncopy(char *str)
{
  char dest[MAX_SIZE] = {0};

  puts(ms_ncopy(dest,str,3));

  memset(dest,0,sizeof(dest));

  puts(ms_ncopy(dest,str,0));

  ms_ncopy(NULL,NULL,2);

}

void check_nconcat(char *str)
{
  char dest[MAX_SIZE] = {0};

  ms_copy(dest,"Hello");

  puts(ms_nconcat(dest,str,3));

  memset(dest,0,sizeof(dest));

  puts(ms_nconcat(dest,str,0));

  ms_nconcat(NULL,NULL,0);

}

int main(void)
{
  int input = get_input();
  char str[MAX_SIZE] = " world!";

  switch(input)
  {
    case 0:
      check_copy(str);
      break;
    case 1:
      check_concat(str);
      break;
    case 2:
      check_cmp();
      break;
    case 3:
      check_len(str);
      break;
    case 4:
      check_search();
      break;
    case 5:
      check_nconcat(str);
      break;
    case 6:
      check_ncopy(str);
      break;
    case 7:
      check_ncmp();
      break;
  }

  return 0;
}
