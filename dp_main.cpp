#include "dp_core.h"

const int MAX_WIDTH = 4200;
const int MAX_HEIGHT = 3500;
unsigned char	external_wide[MAX_WIDTH*MAX_HEIGHT];
unsigned char	external_tele[MAX_WIDTH*MAX_HEIGHT];


void init_params(params_t* params)
{
	const char wide_file_dir[] = "2#-12870.raw";
	const char tele_file_dir[] = "2#-16880-10M.raw";
	params->wide_width = 4096;
	params->wide_height = 3072;
	params->tele_width = 3264;
	params->tele_height = 2448;
	params->elem_size = 1;
	strcpy(params->input_wide_file_name, wide_file_dir);
	strcpy(params->input_tele_file_name, tele_file_dir);
}

int main()
{
	params_t p_params;
	init_params(&p_params);
	const unsigned short w_width = p_params.wide_width;
	const unsigned short w_height = p_params.wide_height;
	const unsigned short t_width = p_params.tele_width;
	const unsigned short t_height = p_params.tele_height;
	const unsigned short elem_size = p_params.elem_size;
	frame_buf_t wide_frame;
	frame_buf_t tele_frame;
	frame_buf_init(&wide_frame, external_wide, w_width, w_height,elem_size);
	frame_buf_init(&tele_frame, external_tele, t_width, t_height,elem_size);

	FILE* fp1 = fopen(p_params.input_wide_file_name, "rb");
	if (!image_read(fp1, &wide_frame)){
		printf("can't read input file\n");
		return 1;
	}
	FILE* fp2 = fopen(p_params.input_tele_file_name, "rb");
	if (!image_read(fp1, &tele_frame)){
		printf("can't read input file\n");
		return 1;
	}
	

	epipolar_rectification(&wide_frame,&tele_frame);

	fclose(fp1);
	fclose(fp2);
	return 0;
}