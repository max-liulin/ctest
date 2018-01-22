#include <stdio.h>
#include "mathwork.h"


void main(void)
{
 int i,j;



 float matA[3*4]=  // row 2, column 3
 {
   1,2,3,8,
   4,5,6,10,
   3,0,0.3,4
 };
 struct float_Matrix mat_A;
 mat_A.nr =3; mat_A.nc=4; mat_A.pmat=matA;


 float matB[3*4]=  // row 2, column 3
 {
   43,4,6,0.5,
   6,5,4,5,
   3,2,1,5
 };
 struct float_Matrix mat_B;
 mat_B.nr =3; mat_B.nc=4; mat_B.pmat=matB;

 float matX[4*4]=
{
   6,3,0.6,0.3,
   5,2,0.5,0.2,
   4,1,0.4,0.1,
   4,1,0.4,0.1
};
 struct float_Matrix mat_X;
 mat_X.nr =4; mat_X.nc=4; mat_X.pmat=matX;


float matClm[3*1]={0};


 float matM[2*2]=
{
   14.23,-2.5,
   2.10,80.445877
};
struct float_Matrix mat_M;
mat_M.nr=2; mat_M.nc=2; mat_M.pmat=matM;

 float matN[2*2]=
{
  3,23.2,
  3.5,13.6
};
struct float_Matrix mat_N;
mat_N.nr=2; mat_N.nc=2; mat_N.pmat=matN;

 float invmatN[2*2]={0};
 struct float_Matrix invmat_N; invmat_N.nr=2; invmat_N.nc=2; invmat_N.pmat=invmatN;


 float determ;

  float matC[3*4]={0};
  struct float_Matrix mat_C; mat_C.nr=3; mat_C.nc=4; mat_C.pmat=matC;

  float matD[2*4]={0};

  float matY[3*4]={0};
  struct float_Matrix mat_Y; mat_Y.nr=3; mat_Y.nc=4; mat_Y.pmat=matY;

  //----- Matrix ADD_SUB Operation ----
  printf("mat_A = \n");
  Matrix_Print(mat_A);
  printf("mat_B = \n");
  Matrix_Print(mat_B);
  Matrix_Add(&mat_A,&mat_B,&mat_C);
  printf("mat_C = \n");
  Matrix_Print(mat_C);
  //----- copy a column from a matrix ---
  Matrix_CopyColumn(&mat_A,2,&mat_A,1);
  printf("Matrix_CopyColumn(mat_A,2,mat_A,1), mat_A=\n");
  Matrix_Print(mat_A);
  Matrix_Add(&mat_A, &mat_A,&mat_A);
  printf("mat_A = mat_A + mat_A =\n");
  Matrix_Print(mat_A);
  Matrix_Sub(&mat_A,&mat_B,&mat_A);
  printf("matA = matA-matB =\n");
  Matrix_Print(mat_A);

  //----- Matrix Multiply Operation ----
   printf("\nmatB=\n");
   Matrix_Print(mat_B);
   printf("\nmatX=\n");
   Matrix_Print(mat_X);
   Matrix_Multiply(&mat_B, &mat_X, &mat_Y);
   printf("\n matY = matB*matX = \n");
   Matrix_Print(mat_Y);

   //----- Matrix MultFactor and DivFactor ----
   Matrix_MultFactor(&mat_X,5.0);
   printf("matX = matX*5.0 = \n");
   Matrix_Print(mat_X);
   Matrix_DivFactor(&mat_Y,5.0);
   printf("matY = matY/5.0 = \n");
   Matrix_Print(mat_Y);

   //----- Matrix Transpose Operation ----
   Matrix_Transpose(&mat_Y, &mat_Y);
   printf("\nmatY = Transpose(matY,matY) = \n");
   Matrix_Print(mat_Y);

   //----- Matrix Determinant Calculation ----
   Matrix_Determ(&mat_M, &determ);
   printf("\nmatM = \n");
   Matrix_Print(mat_M);
   printf("Matrix_Determ(mat_M)=%f \n",determ);

   //---- Matrix Inverse Computatin -----
   printf("\nmatN = \n");
   Matrix_Print(mat_N);
   Matrix_Determ(&mat_N, &determ);
   printf(" Matrix_Determ(matN) = %f \n",determ);
   Matrix_Inverse(&mat_N, &invmat_N);
   printf("\ninvmatN = \n");
   Matrix_Print(invmat_N);

   //----- 3X3 Matrix Determinant Computation ----
   float mat3X3[3*3]={
		23,35,6.455,
		2.353,434,5656,
		233,344,343543.23
		};
   printf("mat3x3 = \n");
   for(i=0; i<3; i++)
   {
	for(j=0; j<3; j++)
		printf("%f ",mat3X3[3*i+j]);
	printf("\n");
   }
   printf("|mat3X3| = %f \n",Matrix3X3_Determ(mat3X3) );

   //----- 4X4 Matrix Determinant Computation ----
   float mat4X4[4*4]={
		1,1,1,1,
		1,23,35,6.455,
		1,2.353,434,5656,
		1,233,344,343543.23
		};
   printf("mat4x4 = \n");
   for(i=0; i<4; i++)
   {
	for(j=0; j<4; j++)
		printf("%f ",mat4X4[4*i+j]);
	printf("\n");
   }
   printf("|mat4X4| = %e \n",MatrixGT3X3_Determ(4,mat4X4) );

   //----- 8X8 Matrix Determinant Computation ----
   float mat6X6[6*6]={
1548196.19929056,       317736.825975421,       65209.2355136882,       13382.9133063996,       2746.5797928119,
563.681493376731,
537.339513653319,       267.231594241498,       132.900564999072,       66.0945807220341,       32.8703914904499,
16.3472197710038,
0.0226191669422462,     0.0344597830259496,     0.0524986905674963,     0.0799805532503283,     0.121848541917522,
0.185633464186686,
107730.122892644,       29729.5669002975,       8204.2712321051,        2264.07827183226,       624.802651687529,
172.422640335594,
753042.807566855,       167432.476943158,       37227.1457261511,       8277.13000618498,       1840.34740786374,
409.185137734936,
40359797792706,      0.281614466038468,      0.329949967550431,      0.386581636298681,      0.452933402699983,
0.530673596515285,
		};
   printf("mat6x6 = \n");
   for(i=0; i<6; i++)
   {
	for(j=0; j<6; j++)
		printf("%f   ",mat6X6[6*i+j]);
	printf("\n");
   }
   printf("|mat6X6|= %e \n",MatrixGT3X3_Determ(6,mat6X6) );


   //----- 8X8 Matrix Determinant Computation ----
   float mat8X8[8*8]={
1548196.19929056,       317736.825975421,       65209.2355136882,       13382.9133063996,       2746.5797928119,
563.681493376731,       115.684542210269,       23.7419774529573,
537.339513653319,       267.231594241498,       132.900564999072,       66.0945807220341,       32.8703914904499,
16.3472197710038,        8.12985736172746,      4.04316952043861,
0.0226191669422462,     0.0344597830259496,     0.0524986905674963,     0.0799805532503283,     0.121848541917522,
0.185633464186686,      0.282808333063805,      0.430852021216898,
107730.122892644,       29729.5669002975,       8204.2712321051,        2264.07827183226,       624.802651687529,
172.422640335594,       47.5823315089988,       13.1309801742137,
753042.807566855,       167432.476943158,       37227.1457261511,       8277.13000618498,       1840.34740786374,
409.185137734936,       90.9787338128256,       20.2283251342007,
40359797792706,      0.281614466038468,      0.329949967550431,      0.386581636298681,      0.452933402699983,
0.530673596515285,      0.621756894854155,      0.728473470014719,
9.87536751506927e-007,  4.59013148592374e-006,  2.13352131208463e-005,  9.91673812194352e-005,  0.000460936079814079,
0.00214245921452982,    0.00995828204156898,    0.0462867066718926,
2600.45128660534,       1085.42261166079,       453.052995829233,       189.103317753609,       78.9313063032946,
32.9457525587259,	13.7514842018456,       5.7398390708038,
		};
   printf("mat8x8 = \n");
   for(i=0; i<8; i++)
   {
	for(j=0; j<8; j++)
		printf("%f   ",mat8X8[8*i+j]);
	printf("\n");
   }
   printf("|mat8X8|= %f \n",MatrixGT3X3_Determ(8,mat8X8) );



}