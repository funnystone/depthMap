#include "dp.core.h"


void readRawImg(const char* fileName, const int& width,  const int& height, int* dst_img)
{
	FILE *pFile;
	int err = fopen_s(&pFile, fileName, "r");
	int img_size = width*height * 2;
	unsigned char *pBuf = (unsigned char*)malloc(sizeof(unsigned char)*img_size);
	fread(pBuf, 1, img_size, pFile);
	for (int i = 0; i < img_size;)
	{
		unsigned int lowByte = pBuf[i];
		unsigned int hightByte = pBuf[i + 1];
		dst_img[i / 2] = lowByte + hightByte * 256;
		i = i + 2;
	}
	fclose(pFile);
	free(pBuf);
}

void writeImg(const char* file_dir, const int& width, const int& height, const int* src_img)
{
	FILE* pFile;
	int err= fopen_s(&pFile,file_dir, "w");
	fwrite(src_img, 4, width*height, pFile);
	fclose(pFile);
}



int main()
{
	const int w_width = 4096;
	const int w_height = 3072;
	const int t_width = 3264;
	const int t_height = 2448;
	const char wide_file_dir[] = "2#-12870.raw";
	const char tele_file_dir[] = "2#-16880-10M.raw";
	int* wide_img = (int*)malloc(sizeof(int)*w_width*w_height);
	int* tele_img = (int*)malloc(sizeof(int)*t_width*t_height);
	readRawImg(wide_file_dir,w_width,w_height, wide_img);
	readRawImg(tele_file_dir, t_width, t_height, tele_img);
	writeImg("wide.raw", w_width, w_height, wide_img);
	writeImg("tele.raw", t_width, t_height, tele_img);

	
	
	free(wide_img);
	free(tele_img);
	return 0;
}