#include <window.h>
#include <base.h>
#include <string.h>

char *buf;
window_t *w;

window_t* window_create(char *name, int startX, int startY, int endX, int endY, char attrib)
{
	w->startX = startX;
	w->startY = startY;
	w->endX = endX;
	w->endY = endY;
	w->attrib = attrib;
	strcpy(w->name, name);
	return w;
}

void window_open(window_t *w)
{
	buf = get_memory(w->startX, w->startY, w->endX, w->endY);
	desktop();
	get_vmem(w->startX, w->startY, w->endX, w->endY, buf);
	clear(w->startX, w->startY, w->endX, w->endY, w->attrib);
	border(w->startX, w->startY, w->endX, w->endY, BLACK | BGBLUE, 0);
	name(w->startX, w->startY, w->endY, w->name, WHITE | BGBLUE);
}

void window_close(window_t *w)
{
	put_vmem(w->startX, w->startY, w->endX, w->endY, buf);
	free(buf);
}

void window_delete(window_t *w)
{

}