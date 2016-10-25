
/*******************************************************************
File	:	frame_buff.cpp
Desc	:	Functions for frame buffer management
Author	:	Lex
Date	:	2016-10-18
Revision 1.00  2016/10/18 Lex
********************************************************************/
#include <stdlib.h>
#include "frame_buff.h"


void frame_buf_init(frame_buf_t* p_buf, unsigned char* data, unsigned short width, unsigned short height,unsigned short elem_size)
{
	p_buf->data = data;
	p_buf->width = width;
	p_buf->height = height;
	p_buf->elem_size = elem_size;
}

int image_read(FILE* fp, frame_buf_t* p_buf)
{
	size_t size;
	unsigned char* data = p_buf->data;
	unsigned short width = p_buf->width;
	unsigned short height = p_buf->height;
	if (fp == NULL){
		return false;
	}
	int img_size = width*height * 2;
	unsigned char *pBuf = (unsigned char*)malloc(sizeof(unsigned char)*img_size);
	size = fread(pBuf, 1, width *height*2, fp);
	if (size != width * height*2) {
		return false;
	}
	for (int i = 0; i < img_size;)
	{
		unsigned char lowByte = pBuf[i];
		unsigned int hightByte = pBuf[i + 1];
		data[i] = lowByte/4 + hightByte * 64;
		i = i + 2;
	}
	return true;
}

int image_write(FILE* fp, frame_buf_t* p_buf)
{
	size_t size;
	unsigned short width = p_buf->width;
	unsigned short height = p_buf->height;
	unsigned short elem_size = p_buf->elem_size;
	size=fwrite(p_buf->data, elem_size, width*height, fp);
	if (size != width * height * elem_size) {
		return false;
	}
	return true;
}