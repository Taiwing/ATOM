#include <unistd.h>

int ft_spy(int c, char *v[]);
int ft_find_word(char *to_find, char *str);
int ft_is_same_letter(char a, char b);

int main(int argc, char *argv[])
{
  if(ft_spy(argc, argv))
    write(1, "Alert!!!\n", 9);

  return 0;
}

int ft_spy(int c, char *v[])
{
  int i;

  i = 1;

  while(i < c)
  {
    if(ft_find_word("president", v[i]) || ft_find_word("attack", v[i])
       || ft_find_word("powers", v[i]))
      return 1;
    i++;
  }

  return 0;
}

int ft_find_word(char *to_find, char *str)
{
  int i;
  int j;
  int found;

  i = 0;
  found = 0;

  while(str[i])
  {
    j = i;
    while(ft_is_same_letter(str[j], to_find[0]) && to_find[i-j] != '\0')
    {
      found = ft_is_same_letter(str[i], to_find[i-j]);
      if(!found)
        return 0;
      i++;
    }
    if(!ft_is_same_letter(str[j], to_find[0])
       && !(str[j] > 8 && str[j] < 12) && str[j] != 32)
        return 0;
    i = str[i] ? i+1 : i;
  }

  return found;
}

int ft_is_same_letter(char a, char b)
{
  if(a == b || a-32 == b || a+32 == b)
    return 1;
  else
    return 0;
}
