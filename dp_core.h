
#ifndef _DP_CORE_H_INCLUDED_
#define _DP_CORE_H_INCLUDED_

#include <stdlib.h>
#include <string.h>
#include "frame_buff.h"
#include "epipolar_rectification.h"


struct params_t{

	char  input_wide_file_name[100];
	char  input_tele_file_name[100];

	unsigned short wide_width;
	unsigned short wide_height;
	unsigned short tele_width;
	unsigned short tele_height;
	unsigned short elem_size;

};

#endif /*_DP_CORE_H_INCLUDED_*/