#ifndef __SYSTEM_H
#define __SYSTEM_H

/* main.c */
extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *memset(unsigned char *, unsigned char, int count);
extern unsigned short *memsetw(unsigned short *, unsigned short, int);
extern int strlen(const char *);
extern unsigned char inportb(unsigned short);
extern void outportb(unsigned short, unsigned char);

#endif
