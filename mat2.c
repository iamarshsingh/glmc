/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "glmc.h"


inline void glmc_mat2f_from_3f(mat2f dest, mat3f src){
	
	dest[0][0] = src[0][0];
	dest[0][1] = src[0][1];
	dest[1][0] = src[1][0];
	dest[1][1] = src[1][1];
	
}
inline void glmc_mat2f_from_4f(mat2f dest, mat4f src){
	
	dest[0][0] = src[0][0];
	dest[0][1] = src[0][1];
	dest[1][0] = src[1][0];
	dest[1][1] = src[1][1];
	
}

inline void glmc_mat2f_copy(mat2f dest, mat2f src){
	
	dest[0][0] = src[0][0];
	dest[0][1] = src[0][1];
	dest[1][0] = src[1][0];
	dest[1][1] = src[1][1];
	
}

inline float glmc_mat2f_determinant(mat2f mat){
	
	float mat2f_det = (mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1]);
	return mat2f_det;
	
}

inline void glmc_mat2f_inverse(mat2f dest, mat2f src_a){

	float mat2f _det = glmc_mat2f_discriminant(src_a);
	if(discr!=0){
		dest[0][0]=src_a[1][1]/mat2f _det;
		dest[0][1]=-1*src_a[0][1]/mat2f _det;
		dest[1][0]=-1*src_a[1][0]/mat2f _det;
		dest[1][1]=src_a[0][0]/mat2f _det;
	}

}

inline int  glmc_mat2f_is_normalized(mat2f src){
	
	if(((int)glmc_mat2f_determinant(src))==1){
		return 1;
	}
	else{
		return 0;
	}
	
}
void glmc_mat2f_normlize(mat2f des, mat2f src){
	
	float mat2f_det = glmc_mat2f_determinant(src);

	dest[0][0] = src[0][0]/mat2f_det;
	dest[0][1] = src[0][1]/mat2f_det;
	dest[1][0] = src[1][0]/mat2f_det;
	dest[1][1] = src[1][1]/mat2f_det;
	
}
inline void glmc_mat2f_normlize_des(mat2f dest_src){
	
	float mat2f_det = glmc_mat2f_determinant(src_dest);

	src_dest[0][0] = src_dest[0][0]/mat2f_det;
	src_dest[0][1] = src_dest[0][1]/mat2f_det;
	src_dest[1][0] = src_dest[1][0]/mat2f_det;
	src_dest[1][1] = src_dest[1][1]/mat2f_det;
	
}

// dest = src_a + src_b;
inline void glmc_mat2f_add(mat2f dest, mat2f src_a, mat2f src_b){
	
	dest[0][0] = src_a[0][0] + src_b[0][0];
	dest[0][1] = src_a[0][1] + src_b[0][1];
	dest[1][0] = src_a[1][0] + src_b[1][0];
	dest[1][1] = src_a[1][1] + src_b[1][1];
	
} 
// dest += src_a;
inline void glmc_mat2f_add_dest(mat2f src_dest, mat2f src_b){
	
	src_dest[0][0] += src_b[0][0];
	src_dest[0][1] += src_b[0][1];
	src_dest[1][0] += src_b[1][0];
	src_dest[1][1] += src_b[1][1];
	
}

// dest = src_a - src_b;
inline void glmc_mat2f_sub(mat2f dest, mat2f src_a, mat2f src_b){
	
	dest[0][0] = src_a[0][0] - src_b[0][0];
	dest[0][1] = src_a[0][1] - src_b[0][1];
	dest[1][0] = src_a[1][0] - src_b[1][0];
	dest[1][1] = src_a[1][1] - src_b[1][1];
	
}
// dest -= src_a;
inline void glmc_mat2f_sub_dest(mat2f src_dest, mat2f src_b){
	
	src_dest[0][0] -= src_b[0][0];
	src_dest[0][1] -= src_b[0][1];
	src_dest[1][0] -= src_b[1][0];
	src_dest[1][1] -= src_b[1][1];
	
}

// dest = src_a * src_b;
inline void glmc_mat2f_mul(mat2f dest, mat2f src_a, mat2f src_b){
	
	dest[0][0] = (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1]);
	dest[0][1] = (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1]);
	dest[1][0] = (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1]);
	dest[1][1] = (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1]);
	
}
// dest *= src_a;
inline void glmc_mat2f_mul_dest(mat2f src_dest, mat2f src_b){
	
	mat2f temp;

	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];

	src_dest[0][0] = (temp[0][0]*src_b[0][0] + temp[1][0]*src_b[0][1]);
	src_dest[0][1] = (temp[0][1]*src_b[0][0] + temp[1][1]*src_b[0][1]);
	src_dest[1][0] = (temp[0][0]*src_b[1][0] + temp[1][0]*src_b[1][1]);
	src_dest[1][1] = (temp[0][1]*src_b[1][0] + temp[1][1]*src_b[1][1]);
	
} 
// dest = src_a * scalar
inline void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b){
	
	dest[0][0] = src_a[0][0] * src_b;
	dest[0][1] = src_a[0][1] * src_b;
	dest[1][0] = src_a[1][0] * src_b;
	dest[1][1] = src_a[1][1] * src_b;
	
}

// dest = src_a / src_b;
inline void glmc_mat2f_div(mat2f dest, mat2f src_a, mat2f src_b){
	
	mat2f inv;
	glmc_mat2f_inverse(inv, src_b);
	glmc_mat2f_mul(dest, src_a, inv);
	
}
// dest /= src_a;
inline void glmc_mat2f_div_dest(mat2f src_dest, mat2f src_b){
	
	mat2f temp;

	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	
	mat2f inv;
	glmc_mat2f_inverse(inv, src_b);
	glmc_mat2f_mul(src_dest, temp, inv);	
	
}
// dest = src_a / scalar
inline void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b){
	
	dest[0][0] = src_a[0][0] / src_b;
	dest[0][1] = src_a[0][1] / src_b;
	dest[1][0] = src_a[1][0] / src_b;
	dest[1][1] = src_a[1][1] / src_b;
	
}

// dest += src_a + src_b;
inline void glmc_mat2f_addadd(mat2f dest, mat2f src_a, mat2f src_b){
	
	dest[0][0] += src_a[0][0] + src_b[0][0];
	dest[0][1] += src_a[0][1] + src_b[0][1];
	dest[1][0] += src_a[1][0] + src_b[1][0];
	dest[1][1] += src_a[1][1] + src_b[1][1];
	
}
// dest += src_a - src_b;
inline void glmc_mat2f_subadd(mat2f dest, mat2f src_a, mat2f src_b){
	
	dest[0][0] -= src_a[0][0] - src_b[0][0];
	dest[0][1] -= src_a[0][1] - src_b[0][1];
	dest[1][0] -= src_a[1][0] - src_b[1][0];
	dest[1][1] -= src_a[1][1] - src_b[1][1];
	
}

// dest += src_a * src_b;
inline void glmc_mat2f_madd(mat2f dest, mat2f src_a, mat2f src_b){
	
	dest[0][0] += (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1]);
	dest[0][1] += (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1]);
	dest[1][0] += (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1]);
	dest[1][1] += (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1]);
	
}
// dest -= src_a * src_b;
inline void glmc_mat2f_msub(mat2f dest, mat2f src_a, mat2f src_b){
	
	dest[0][0] -= (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1]);
	dest[0][1] -= (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1]);
	dest[1][0] -= (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1]);
	dest[1][1] -= (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1]);
	
}

inline void glmc_mat2f_transpose(mat2f dest, mat2f src){
	
	dest[0][0] = src[0][0];
	dest[0][1] = src[1][0];
	dest[1][0] = src[0][1];
	dest[1][1] = src[1][1];
	
}
inline void glmc_mat2f_transpose_dest(mat2f src_dest){
	
	float temp;
	temp = src_dest[0][1];
	src_dest[0][1] = src_dest[1][0];
	src_dest[1][0] = temp;
	
}

inline void glmc_mat2f_identity(mat2f dest){
	
	dest[0][0] = 1.0f;
	dest[0][1] = 0;
	dest[1][0] = 0;
	dest[1][1] = 1.0f;

	
}
inline void glmc_mat2f_scale(mat2f dest, float src_sx){
	
	dest[0][0] = src_sx;
	dest[0][1] = 0;
	dest[1][0] = 0;
	dest[1][1] = 1.0f;
	
}
inline void glmc_mat2f_translation(mat2f dest, float src_t1){
	
	dest[0][0] = 1.0f;
	dest[0][1] = 0;

	dest[1][0] = src_t1;
	dest[1][1] = 1.0f;
	
}

inline void glmc_mat2f_mul_vec2f(vec2f dest, mat2f mat, vec2f vec)
{
	dest[0] = mat[0][0]*vec[0] + mat[1][0]*vec[1];
	dest[1] = mat[0][1]*vec[0] + mat[1][1]*vec[1];
}