#include <stdlib.h>
#include <stdio.h>
#include <base.h>
#include <window.h>

int main()
{
	window_t *w;
	w = window_create("WINDOW", 5, 10, 20, 70, WHITE | BLUE);
	window_open(w);
	getchar();
	window_close(w);
	window_delete(w);
	getchar();
	return 0;
}