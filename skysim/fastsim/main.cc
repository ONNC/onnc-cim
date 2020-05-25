#include "fastsim/operator.hh"
#include<cstdio>

int main() {
	float a[]={1.5,2.3,8.7};
	float b[]={1,1,1};
	float c[3];
	int32_t ashape[] = {3};
	int32_t bshape[] = {3};
	int32_t cshape[] = {3};
	AddOp op(a, 1, ashape
		 , b, 1, bshape
		 , c, 1, cshape);
	op.inference();
	for(size_t i=0; i<3; i++)
		printf("%f\n", c[i]);
}
