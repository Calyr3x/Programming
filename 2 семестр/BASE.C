#include <base.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void write_char(int x, int y, char ch, char attrib)
{
	char *v;
	v = VMEM + x*160 + y*2;
	*(v++) = ch;
	*v = attrib;
}

void write_string(int x, int y, char *string, char attrib)
{
	for(; *string; string++) write_char(x, y++, *string, attrib);
}

char* get_memory(int startX, int startY, int endX, int endY)
{
	char *buffer;
	int size = (endX - startX + 1)*(endY - startY + 1)*2*sizeof(char);
	buffer = malloc(size);
	if(!buffer)
	{
		fprintf(stderr, "ERROR");
		exit(1);
	}
	return buffer;
}

void get_vmem(int startX, int startY, int endX, int endY, char *buffer)
{
	int x, y;
	char *p;
	for(x = startX; x <= endX; x++) for(y = startY; y <= endY; y++)
	{
		p = VMEM + x*160 + y*2;
		*buffer++ = *p++;
		*buffer++ = *p;
	}
}

void put_vmem(int startX, int startY, int endX, int endY, char *buffer)
{
	int x, y;
	char *p;
	for(x = startX; x <= endX; x++) for(y = startY; y <= endY; y++)
	{
		p = VMEM + x*160 + y*2;
		*p++ = *buffer++;
		*p = *buffer++;
	}
}

void clear(int startX, int startY, int endX, int endY, char attrib)
{
	int x, y;
	for(x = startX; x <= endX; x++) for(y = startY; y <= endY; y++)
		write_char(x, y, '\0', attrib);
}

void desktop(void)
{
	int x, y;
	for(x = 0; x < 26; x++) for(y = 0; y < 81; y++) write_char(x, y, FONT,
	WHITE | BGBLUE);
}

void border(int startX, int startY, int endX, int endY, char attrib, int type)
{
	int x, y;
switch(type)
{
case 1:
	for(x = startX; x <= endX; x++) for(y = startY; y <= endY; y++)
	{
		if(x == startX && y == startY) write_char(x, y, ULEFTCORNER, attrib);
		if(x == startX && y != startY && y != endY ||
		x == endX && y != startY && y != endY) write_char(x, y, UDBORDER, attrib);
		if(y == startY && x != startX && x != endX ||
		y == endY && x != startX && x != endX) write_char(x, y, LFBORDER, attrib);
		if(x == startX && y == endY) write_char(x, y, URIGHTCORNER, attrib);
		if(x == endX && y == startY) write_char(x, y, DLEFTCORNER, attrib);
		if(x == endX && y == endY) write_char(x, y, DRIGHTCORNER, attrib);
	} break;
case 0:
	for(x = startX; x <= endX; x++) for(y = startY; y <= endY; y++)
	{
		if(x == startX && y == startY) write_char(x, y, ORDULEFTCORNER, attrib);
		if(x == startX && y != startY && y != endY ||
		x == endX && y != startY && y != endY) write_char(x, y, ORDUDBORDER, attrib);
		if(y == startY && x != startX && x != endX ||
		y == endY && x != startX && x != endX) write_char(x, y, ORDLFBORDER, attrib);
		if(x == startX && y == endY) write_char(x, y, ORDURIGHTCORNER, attrib);
		if(x == endX && y == startY) write_char(x, y, ORDDRIGHTCORNER, attrib);
		if(x == endX && y == endY) write_char(x, y, ORDDLEFTCORNER, attrib);
	} break;
default:
	fprintf(stderr, "UNKNOW TYPE");
	break;
}
}

void name(int startX, int startY, int endY, char *str, char attrib)
{
	int y = startY + (endY - startY - strlen(str)) / 2;
	write_string(startX, y, str, attrib);
}