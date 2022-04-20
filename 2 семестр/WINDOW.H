#if !defined(_WINDOW_H_)
#define _WINDOW_H_

typedef struct window
{
	int startX, startY, endX, endY;
	char attrib;
	char name[80];
} window_t;

window_t* window_create(char *name, int startX, int startY, int endX,
				int endY, char attrib);
void window_open(window_t *w);
void window_close(window_t*);
void window_delete(window_t*);

#endif