/*
\033[l;cH: Moves the cursor to line l and column c.
\033[nA: Moves the cursor up n lines.
\033[bB: Moves the cursor down n lines.
\033[nC: Moves the cursor forward n characters.
\033[nD: Moves the cursor backward n characters.
\033[2J: Clears the screen and moves the cursor to line 0 and column 0
\033[K : Without moving the cursor, clear the line starting from the current cursor position.
\033[s : Store the current cursor position
\033[u : Move the cursor back to the previously stored location.
*/

#include <stdio.h>

int	main(void)
{
	printf("lol\nlol\nsfafaf\n\033[3;7Hloooooolz\n");
	return (0);
}
