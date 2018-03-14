#include "ft_door.h"

void ft_putstr(char *str)
{
  int i = 0;

  while(str[i])
  {
    write(1, &str[i], 1);
    i++;
  }
}

void open_door(t_door *door)
{
  ft_putstr("Door opening...\n");
  door->state = OPEN;
}

void close_door(t_door *door)
{
  ft_putstr("Door closing...\n");
  door->state = CLOSE;
}

t_bool is_door_open(t_door *door)
{
  t_bool open;
  ft_putstr("Door is open ?\n");
  return (open = door->state == OPEN ? TRUE : FALSE);
}

t_bool is_door_close(t_door* door)
{
  t_bool close;
  ft_putstr("Door is close ?\n");
  return (close = door->state == CLOSE ? TRUE : FALSE);
}
