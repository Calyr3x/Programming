#if !defined (_BASE_H_)
#define _BASE_H_

#define VMEM (char*)0xB8000000L
#define BLACK		0x00
#define BLUE		0x01
#define GREEN		0x02
#define CYAN		0x03
#define RED		0x04
#define MAGENTA 	0x05
#define BROWN		0x06
#define LIGHTGRAY	0x07
#define DARKGRAY	0x08
#define LIGHTBLUE	0x09
#define LIGHTGREEN	0x0A
#define LIGHTCYAN	0x0B
#define LIGHTRED	0x0C
#define LIGHTMAGENTA	0x0D
#define YELLOW 	0x0E
#define WHITE		0x0F
#define BGBLACK	0x00
#define BGBLUE	0x10
#define BGGREEN	0x20
#define BGCYAN	0x30
#define BGRED		0x40
#define BGMAGENTA	0x50
#define BGBROWN	0x60
#define BGLIGHTGRAY	0x70
#define BLINK		0x80

#define FONT		0xB0
#define UDBORDER	0xCD
#define LFBORDER	0xBA
#define ULEFTCORNER	0xC9
#define DRIGHTCORNER	0xBC
#define URIGHTCORNER	0xBB
#define DLEFTCORNER	0xC8
#define ORDUDBORDER	0xC4
#define ORDLFBORDER	0xB3
#define ORDULEFTCORNER	0xDA
#define ORDURIGHTCORNER 	0xBF
#define ORDDRIGHTCORNER	0xC0
#define ORDDLEFTCORNER	0xD9

void write_char(int x, int y, char ch, char attrib);
void write_string(int x, int y, char *string, char attrib);
char* get_memory(int startX, int startY, int endX, int endY);
void get_vmem(int startX, int startY, int endX, int endY, char *buffer);
void put_vmem(int startX, int startY, int endX, int endY, char *buffer);
void clear(int startX, int startY, int endX, int endY, char attrib);
void desktop(void);
void border(int startX, int startY, int endX, int endY, char attrib, int type);
void name(int startX, int startY, int endY, char *str, char attrib);


#endif
