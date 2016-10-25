
/*******************************************************************
File	:	frame_buf.h
Desc	:	Header file for frame buffer structures definition and related function declarations
Author	:	Lex
Date	:	2016-10-18
Revision 1.00  2016/10/18 Lex
********************************************************************/

#ifndef __FRAME_BUF_H__
#define __FRAME_BUF_H__

#include <stdio.h>


typedef struct frame_buf_
{
	unsigned char*    data;
	unsigned short	  width;
	unsigned short    height;
	unsigned short    elem_size;
}frame_buf_t;



void frame_buf_init(frame_buf_t* p_buf, unsigned char* data, unsigned short width, unsigned short height,unsigned short elem_size);

int image_read(FILE* fp, frame_buf_t* p_buf);

int image_write(FILE* fp, frame_buf_t* p_buf);



#endif //__FRAME_BUF_H__