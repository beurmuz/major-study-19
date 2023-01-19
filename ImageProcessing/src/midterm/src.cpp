#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h> //
#include <iostream> //

//---------------------------------------------------------------------------------
//#######[2주차 과제] 3개 이미지파일 생성하는 프로그램#######
void printImage(BYTE *Img, BYTE *Out1, BYTE *Out2, BYTE *Out3, int W, int H)
{ //3개의 이미지파일을 생성하는 코드
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++)
	{
		Out1[i] = Img[i]; //오리지널
		Out2[i] = Img[i] + 50; //밝기값을 50만큼 증가시킨 영상
		Out3[i] = 255 - Img[i]; //화소가 반전이 됨
	}
}
//---------------------------------------------------------------------------------
void InverseImage(BYTE* Img, BYTE *Out, int W, int H)
{ //영상을 반전시키는 코드
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++)
	{
		Out[i] = 255 - Img[i];
	}
}
//---------------------------------------------------------------------------------
void BrightnessAdj(BYTE* Img, BYTE* Out, int W, int H, int Val)
{ //영상의 밝기를 조절하는 코드
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++)
	{
		if (Img[i] + Val > 255)
		{
			Out[i] = 255;
		}
		else if (Img[i] + Val < 0)
		{
			Out[i] = 0;
		}
		else 	Out[i] = Img[i] + Val;
	}
}
//---------------------------------------------------------------------------------
void ContrastAdj(BYTE* Img, BYTE* Out, int W, int H, double Val)
{ //영상의 대비를 조절하는 코드
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++)
	{
		if (Img[i] * Val > 255.0)
		{
			Out[i] = 255;
		}
		else 	Out[i] = (BYTE)(Img[i] * Val);
	}
}
//---------------------------------------------------------------------------------
void ObtainHistogram(BYTE* Img, int* Histo, int W, int H)
{ //이미지의 정보를 가지고와서 히스토그램을 생성하는 코드
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++) {
		Histo[Img[i]]++;
	}
}
//---------------------------------------------------------------------------------
void ObtainAHistogram(int* Histo, int* AHisto) //AHisto에 결과를 저장
{ //누적히스토그램을 구하는 코드
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j <= i; j++) {
			AHisto[i] += Histo[j];
		}
	}
}
//---------------------------------------------------------------------------------
void HistogramStretching(BYTE * Img, BYTE * Out, int * Histo, int W, int H)
{ //히스토그램을 스트레칭화하는 코드
	int ImgSize = W * H;
	BYTE Low, High;
	for (int i = 0; i < 256; i++) {
		if (Histo[i] != 0) {
			Low = i;
			break;
		}
	}
	for (int i = 255; i >= 0; i--) {
		if (Histo[i] != 0) {
			High = i;
			break;
		}
	}
	for (int i = 0; i < ImgSize; i++) {
		Out[i] = (BYTE)((Img[i] - Low) / (double)(High - Low) * 255.0);
	}
}
//---------------------------------------------------------------------------------
void HistogramEqualization(BYTE* Img, BYTE* Out, int* AHisto, int W, int H)
{ //평활화하는 코드
	int ImgSize = W * H;
	int Nt = W * H, Gmax = 255;
	double Ratio = Gmax / (double)Nt;
	BYTE NormSum[256];
	for (int i = 0; i < 256; i++)
	{
		NormSum[i] = (BYTE)(Ratio * AHisto[i]);
	}
	for (int i = 0; i < ImgSize; i++)
	{
		Out[i] = NormSum[Img[i]];
	}
}
//---------------------------------------------------------------------------------
void Binarization(BYTE * Img, BYTE * Out, int W, int H, BYTE Threshold)
{ //영상의 이진화 코드 
	int ImgSize = W * H;
	for (int i = 0; i < ImgSize; i++)
	{
		if (Img[i] < Threshold)
			Out[i] = 0;
		else //T보다 큰 경우
			Out[i] = 255;
	}
}
//---------------------------------------------------------------------------------
//3주차 과제 해설(실습내용) Gonzalez
BYTE DetermThGonzalez(int *H)
{
	BYTE ep = 3;
	BYTE Low, High;
	BYTE Th, NewTh;
	int G1 = 0, G2 = 0, cnt1 = 0, cnt2 = 0, mu1, mu2; //평균을 계산해서 넣을것이니 초기화할 필요가 없음
	for (int i = 0; i < 256; i++)
	{
		if (H[i] != 0)
		{
			Low = i;
			break;
		}
	}
	for (int i = 255; i >= 0; i--) {
		if (H[i] != 0)
		{
			High = i;
			break;
		}
	}
	Th = (Low / High) / 2;
	//printf("Th:%d\n", Th);
	while (1)
	{
		for (int i = Th + 1; i <= High; i++)
		{
			G1 += (H[i] * i); //i밝기값에 해당하는 화소가 H[i]개 있으니 *연산 필요
			cnt1 += H[i];
		}
		for (int i = Low; i <= Th; i++)
		{
			G2 += (H[i] * i);
			cnt2 += H[i];
		}
		if (cnt1 == 0)cnt1 = 1;
		if (cnt2 == 0)cnt2 = 1;

		mu1 = G1 / cnt1;
		mu2 = G2 / cnt2;

		NewTh = (mu1 + mu2) / 2;

		if (abs(NewTh - Th) < ep)
		{
			Th = NewTh; //새로구한 임계치로 업데이트 함
			break;
		}
		else
		{
			Th = NewTh; //그렇지 않은 경우 새로운 임계치로 업데이트 하기
		}
		G1 = G2 = cnt1 = cnt2 = 0; //반복 할 때마다 다시 0으로 초기화해주어야 함.
	}
	//printf("최종Th:%d", Th);
	return Th;
}
//---------------------------------------------------------------------------------
//#######[3주차 과제] Gonzalez 자동 이진화 임계치 결정 프로그램 구현 함수#######
int GonzalezBin(BYTE*Img, int*Histo, int W, int H)
{ //자동 임계치 결정 코드
	int ImgSize = W * H;
	int Low, High;
	int epsilon = 3;
	//----------------------------------------------------------
	//low값 구하기
	for (int i = 0; i < 256; i++)
	{
		if (Histo[i] != 0)
		{
			Low = i;
			break;
		}
	}
	//high값 구하기
	for (int i = 255; i >= 0; i--)
	{
		if (Histo[i] != 0)
		{
			High = i;
			break;
		}
	}
	//----------------------------------------------------------
	//gonzalez 알고리즘
	int Thres, newThres = (Low + High) / 2;
	do {
		Thres = newThres;
		int m1 = 0, m2 = 0, count_m1 = 0; //평균값m1,m2,m1세기 

		//m1, m2 각 화소별 총 갯수 구하기
		for (int i = 0; i < 256; i++) {
			if (i >= Thres) {
				m1 += Histo[i] * i;// T보다 큰 영역의 총 밝기 값
				count_m1 += Histo[i];//히스토그램 m1영역 갯수
			}
			else
				m2 += Histo[i] * i;// T보다 작은 영역의 총 밝기 값
		}

		m1 /= count_m1;
		m2 /= (ImgSize - count_m1);

		newThres = (m1 + m2) / 2;

	} while (abs(Thres - newThres) > epsilon);
	printf("최종 threshold 값 : %d\n", newThres);

	return newThres;
}
//---------------------------------------------------------------------------------
void AverageConv(BYTE*Img, BYTE*Out, int W, int H)
{ //convolution, 박스 평활화 코드
	double Kernel[3][3] = { 0.11111,0.11111 ,0.11111,
							0.11111,0.11111 ,0.11111,
							0.11111,0.11111 ,0.11111 }; //커널(마스크)정의
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) //i는 Y좌표(행)
	{
		for (int j = 1; j < W - 1; j++) //j는 X좌표(열)
		{
			for (int m = -1; m <= 1; m++) //Kernel(행)
			{
				for (int n = -1; n <= 1; n++) //Kernel(열)
				{
					SumProduct += Img[(i + m)*W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			Out[i*W + j] = (BYTE)SumProduct;
			SumProduct = 0.0;
		}
	}
}
//---------------------------------------------------------------------------------
void GaussAvrConv(BYTE*Img, BYTE*Out, int W, int H)
{ //가우시안 평활화 
	double Kernel[3][3] = { 0.0625,0.11111 ,0.0625,
							0.125 ,0.25 ,0.125,
							0.0625,0.11111 ,0.0625 }; //커널(마스크)정의
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) //i는 Y좌표(행)
	{
		for (int j = 1; j < W - 1; j++) //j는 X좌표(열)
		{
			for (int m = -1; m <= 1; m++) //Kernel(행)
			{
				for (int n = -1; n <= 1; n++) //Kernel(열)
				{
					SumProduct += Img[(i + m)*W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			Out[i*W + j] = (BYTE)SumProduct;
			SumProduct = 0.0;
		}
	}
}
//---------------------------------------------------------------------------------
void Prewitt_X_Conv(BYTE*Img, BYTE*Out, int W, int H)
{ //Prewitt 마스크X, x방향에서 봤을 때 화소값이 변하는 구간을 찾는 마스크
	double Kernel[3][3] = { -1.0, 0.0 ,1.0,
							-1.0, 0.0 ,1.0,
							-1.0, 0.0 ,1.0 }; //커널(마스크)정의
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) //i는 Y좌표(행)
	{
		for (int j = 1; j < W - 1; j++) //j는 X좌표(열)
		{
			for (int m = -1; m <= 1; m++) //Kernel(행)
			{
				for (int n = -1; n <= 1; n++) //Kernel(열)
				{
					SumProduct += Img[(i + m)*W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			/*0~255사이로 나오지 않고,0~765까지의 값이 나올 것.
			때문에 노멀라이즈 해주어야 함. 0~765 ======> 0~255*/
			Out[i*W + j] = abs((long)SumProduct) / 3;
			SumProduct = 0.0;
		}
	}
}
//---------------------------------------------------------------------------------
void Prewitt_Y_Conv(BYTE*Img, BYTE*Out, int W, int H)
{ //Prewitt 마스크Y, x방향에서 봤을 때 화소값이 변하는 구간을 찾는 마스크
	double Kernel[3][3] = { -1.0, -1.0, -1.0,
							0.0, 0.0, 0.0,
							1.0, 1.0, 1.0 }; //커널(마스크)정의
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) //i는 Y좌표(행)
	{
		for (int j = 1; j < W - 1; j++) //j는 X좌표(열)
		{
			for (int m = -1; m <= 1; m++) //Kernel(행)
			{
				for (int n = -1; n <= 1; n++) //Kernel(열)
				{
					SumProduct += Img[(i + m)*W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			/*0~255사이로 나오지 않고,0~765까지의 값이 나올 것.
			때문에 노멀라이즈 해주어야 함. 0~765 ======> 0~255*/
			Out[i*W + j] = abs((long)SumProduct) / 3;
			SumProduct = 0.0;
		}
	}
}
//---------------------------------------------------------------------------------
void Sobel_X_Conv(BYTE*Img, BYTE*Out, int W, int H)
{ //Sobel 마스크X, x방향에서 봤을 때 화소값이 변하는 구간을 찾는 마스크
	double Kernel[3][3] = { -1.0, 0.0 ,1.0,
							-2.0, 0.0 ,2.0,
							-1.0, 0.0 ,1.0 }; //커널(마스크)정의
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) //i는 Y좌표(행)
	{
		for (int j = 1; j < W - 1; j++) //j는 X좌표(열)
		{
			for (int m = -1; m <= 1; m++) //Kernel(행)
			{
				for (int n = -1; n <= 1; n++) //Kernel(열)
				{
					SumProduct += Img[(i + m)*W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			/*0~255사이로 나오지 않고,0~765 ======> 0~1020*/
			Out[i*W + j] = abs((long)SumProduct) / 4;
			SumProduct = 0.0;
		}
	}
}
//---------------------------------------------------------------------------------
void Sobel_Y_Conv(BYTE*Img, BYTE*Out, int W, int H)
{ //Sobel 마스크Y, x방향에서 봤을 때 화소값이 변하는 구간을 찾는 마스크
	double Kernel[3][3] = { -1.0, -2.0, -1.0,
							0.0, 0.0, 0.0,
							1.0, 2.0, 1.0 }; //커널(마스크)정의
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) //i는 Y좌표(행)
	{
		for (int j = 1; j < W - 1; j++) //j는 X좌표(열)
		{
			for (int m = -1; m <= 1; m++) //Kernel(행)
			{
				for (int n = -1; n <= 1; n++) //Kernel(열)
				{
					SumProduct += Img[(i + m)*W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			/*0~255사이로 나오지 않고,0~1020 ======> 0~255*/
			Out[i*W + j] = abs((long)SumProduct) / 4;
			SumProduct = 0.0;
		}
	}
}
//---------------------------------------------------------------------------------
void Laplace_Conv(BYTE*Img, BYTE*Out, int W, int H)
{ //Laplace 마스크, x방향에서 봤을 때 화소값이 변하는 구간을 찾는 마스크
	double Kernel[3][3] = { -1.0, -1.0 ,-1.0,
							-1.0, 8.0, -1.0,
							-1.0, -1.0 ,-1.0 }; //커널(마스크)정의
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) //i는 Y좌표(행)
	{
		for (int j = 1; j < W - 1; j++) //j는 X좌표(열)
		{
			for (int m = -1; m <= 1; m++) //Kernel(행)
			{
				for (int n = -1; n <= 1; n++) //Kernel(열)
				{
					SumProduct += Img[(i + m)*W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			/*0~255사이로 나오지 않고,0~2040 ======> 0~2040*/
			Out[i*W + j] = abs((long)SumProduct) / 8;
			SumProduct = 0.0;
		}
	}
}
//---------------------------------------------------------------------------------
void Laplace_Conv_DC(BYTE*Img, BYTE*Out, int W, int H)
{ //Laplace 마스크, x방향에서 봤을 때 화소값이 변하는 구간을 찾는 마스크
	double Kernel[3][3] = { -1.0, -1.0 ,-1.0,
							-1.0, 9.0, -1.0, //원래 영상의 밝기를 유지하겠다
							-1.0, -1.0 ,-1.0 }; //커널(마스크)정의
	double SumProduct = 0.0;
	for (int i = 1; i < H - 1; i++) //i는 Y좌표(행)
	{
		for (int j = 1; j < W - 1; j++) //j는 X좌표(열)
		{
			for (int m = -1; m <= 1; m++) //Kernel(행)
			{
				for (int n = -1; n <= 1; n++) //Kernel(열)
				{
					SumProduct += Img[(i + m)*W + (j + n)] * Kernel[m + 1][n + 1];
				}
			}
			/*범위가 넓어지긴 했으나, 원래 영상의 밝기를 유지되면서 작업이 이루어지므로,
			그냥 클리핑 처리를 해줌으로써 노멀라이즈를 할 수 있음*/

			//클리핑 처리하는 코드
			if (SumProduct > 255.0)
				Out[i*W + j] = 255;
			else if (SumProduct < 0.0)
				Out[i*W + j] = 0;
			else
				Out[i*W + j] = (BYTE)SumProduct;
			SumProduct = 0.0;
		}
	}
}
//---------------------------------------------------------------------------------
void swap(BYTE *a, BYTE *b)
{
	BYTE temp = *a;
	*a = *b;
	*b = temp;
}
//---------------------------------------------------------------------------------
BYTE Median(BYTE *arr, int size) //size는 1차원 배열의 사이즈 //5x5면 25, 7x7이면 49
{
	//오름차순 정렬
	const int S = size; //리터럴 상수 선언
	for (int i = 0; i < size - 1; i++) //피벗 인덱스
	{
		for (int j = i + 1; j < size; j++) //pivot과의 비교 대상 인덱스
		{
			if (arr[i] > arr[j])
			{
				swap(&arr[i], &arr[j]); //call by reference
			}
		}
	}
	return arr[S / 2]; //중간값이니 
}
//---------------------------------------------------------------------------------
BYTE MaxPooling(BYTE *arr, int size) //size는 1차원 배열의 사이즈 //5x5면 25, 7x7이면 49
{ //pepper만 제거하는 median함수
	//오름차순 정렬
	const int S = size;
	for (int i = 0; i < size - 1; i++) //피벗 인덱스
	{
		for (int j = i + 1; j < size; j++) //pivot과의 비교 대상 인덱스
		{
			if (arr[i] > arr[j])
			{
				swap(&arr[i], &arr[j]); //call by reference
			}
		}
	}
	return arr[S - 1];
}
//---------------------------------------------------------------------------------
BYTE MinPooling(BYTE *arr, int size) //size는 1차원 배열의 사이즈 //5x5면 25, 7x7이면 49
{ //salt만 제거하는 median함수
	//오름차순 정렬
	const int S = size;
	for (int i = 0; i < size - 1; i++) //피벗 인덱스
	{
		for (int j = i + 1; j < size; j++) //pivot과의 비교 대상 인덱스
		{
			if (arr[i] > arr[j])
			{
				swap(&arr[i], &arr[j]); //call by reference
			}
		}
	}
	return arr[0];
}
//---------------------------------------------------------------------------------
int push(short* stackx, short* stacky, int arr_size, short vx, short vy, int* top)
{
	if (*top >= arr_size) return(-1);
	(*top)++;
	stackx[*top] = vx;
	stacky[*top] = vy;
	return(1);
}
//---------------------------------------------------------------------------------
int pop(short* stackx, short* stacky, short* vx, short* vy, int* top)
{
	if (*top == 0) return(-1);
	*vx = stackx[*top];
	*vy = stacky[*top];
	(*top)--;
	return(1);
}
//---------------------------------------------------------------------------------
// GlassFire 알고리즘을 이용한 라벨링 함수
void m_BlobColoring(BYTE* CutImage, int height, int width)
{ //라벨링 함수
	int i, j, m, n, top, area, Out_Area, index, BlobArea[1000];
	long k;
	short curColor = 0, r, c; //r은 반지름 
	//	BYTE** CutImage2;
	Out_Area = 1;

	// 스택으로 사용할 메모리 할당
	short* stackx = new short[height * width];
	short* stacky = new short[height * width];
	short* coloring = new short[height * width];

	int arr_size = height * width; //arr_size는 height * width

	// 라벨링된 픽셀을 저장하기 위해 메모리 할당

	for (k = 0; k < height * width; k++) coloring[k] = 0;  // 메모리 초기화

	for (i = 0; i < height; i++) //i는 행 
	{
		index = i * width; //i행 *너비
		for (j = 0; j < width; j++) //1*1,1*2,1*3 ...
		{
			// 이미 방문한 점이거나 픽셀값이 255가 아니라면 처리 안함
			if (coloring[index + j] != 0 || CutImage[index + j] != 255) continue; //coloring의 (j.i)가 0이 아니거나 CutImage의 (j.i)가 255가 아니면
			r = i; c = j; top = 0; area = 1; //
			curColor++;

			while (1)
			{
			GRASSFIRE:
				for (m = r - 1; m <= r + 1; m++)
				{
					index = m * width;
					for (n = c - 1; n <= c + 1; n++)
					{
						//관심 픽셀이 영상경계를 벗어나면 처리 안함
						if (m < 0 || m >= height || n < 0 || n >= width) continue;

						if ((int)CutImage[index + n] == 255 && coloring[index + n] == 0)
						{
							coloring[index + n] = curColor; // 현재 라벨로 마크
							if (push(stackx, stacky, arr_size, (short)m, (short)n, &top) == -1) continue;
							r = m; c = n; area++;
							goto GRASSFIRE;
						}
					}
				}
				if (pop(stackx, stacky, &r, &c, &top) == -1) break;
			}
			if (curColor < 1000) BlobArea[curColor] = area;
		}
	}

	float grayGap = 255.0f / (float)curColor; //현재 덩어리 진 컴포넌트의 갯수를 구하는 식

	// 가장 면적이 넓은 영역을 찾아내기 위함 
	for (i = 1; i <= curColor; i++)
	{ //curColor는 컴포넌트 갯수.
		if (BlobArea[i] >= BlobArea[Out_Area]) Out_Area = i;
	}
	// CutImage 배열 클리어~
	for (k = 0; k < width * height; k++) CutImage[k] = 255;
	//CutImage는 메인함수에서 output배열을 파라미터로 받아오는 것. 전부 255로 하얗게 채운 후,

	// coloring에 저장된 라벨링 결과중 (Out_Area에 저장된) 영역이 가장 큰 것만 CutImage에 저장
	for (k = 0; k < width * height; k++) //0부터 화소의 끝까지 가는 k변수
	{
		if (coloring[k] == Out_Area) CutImage[k] = 0;  // 가장 큰 것(넓은영역)만 저장(size Filtering)
		//if (BlobArea[coloring[k]]>500) CutImage[k] = 0; //특정 면적이상이 되는 영역만 출력하는 코드 
		//CutImage[k] = (unsigned char)(coloring[k] * grayGap); //라벨링된 결과를 출력해줌
	}

	delete[] coloring;
	delete[] stackx;
	delete[] stacky;
}
// 라벨링 후 가장 넓은 영역에 대해서만 뽑아내는 코드 포함
//---------------------------------------------------------------------------------
void BinaryImageEdgeDetection(BYTE *Bin, BYTE *Out, int W, int H)
{ //이진화된 이미지의 경계를 검출하는 함수
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (Bin[i*W + j] == 0)//이 화소가 전경화소라면
			{ //4주변화소 검사 시작
				//만약 4주변화소 중 하나라도 전경이 아니라면 
				if (!(Bin[(i - 1)*W + j] == 0 && Bin[(i + 1)*W + j] == 0 && //위 화소와 아래 화소
					Bin[i*W + (j - 1)] == 0 && Bin[i*W + (j + 1)] == 0)) //왼쪽 화소와 오른쪽 화소
					Out[(i - 1)*W + j] = 255; //경계를 보기 위해 0으로 출력

			}
		}
	}
}
//---------------------------------------------------------------------------------
//#######[6주차 과제] 동공영역 외접사각형 그리기#######
void DrawRectOutline(BYTE * Img, int W, int H, int LU_X, int LU_Y, int RD_X, int RD_Y)
{ //사각형 그리기
	// LU_X: x의 최소값, LU_Y: y의 최소값, i=y=H
	// RD_X: x의 최대값, RU_Y: y의 최대값.
	for (int i = LU_X; i < RD_X; i++) //가로줄 그리기
	{
		Img[i + (LU_Y*W)] = 255;
		Img[i + (RD_Y*W)] = 255;
	}
	for (int i = LU_Y; i < RD_Y; i++) //세로줄 그리기
	{
		Img[(LU_X)+i * W] = 255; //W를 i만큼 곱해줘서 원하는 위치로 내려가기 (x좌표의 값은 고정)
		Img[(RD_X)+i * W] = 255;
	}
}
//---------------------------------------------------------------------------------
//#######[6주차 과제] 동공영역 무게중심 통과하는 크로스라인 그리기#######
void DrawCrossLine(BYTE * Img, int W, int H, int Cx, int Cy)
{ //Output이미지에 무게중심을 통과하는 크로스라인 그리기
	for (int i = 1; i < H; i++)
	{
		for (int j = 1; j < W; j++)
		{
			if (j == Cx || i == Cy)
			{
				Img[(i*W) + j] = 255;
			}
		}
	}
}
//---------------------------------------------------------------------------------
void VerticalFlip(BYTE *Img, int W, int H)
{ //위, 아래를 Flip하는 코드, 윗줄과 아랫줄을 swap해줌
	for (int i = 0; i < H / 2; i++) //x좌표, H/2는 영상의 세로 사이즈 만큼만 반복시켜 교환하겠다는 뜻
	{
		for (int j = 0; j < W; j++) //y좌표, 미러링 된 행만 바꾸어야하니!
		{
			swap(&Img[i*W + j], &Img[(H - 1 - i)*W + j]); //(0,0)과 (n,n)을 교환, H세로사이즈 - 1 -i만큼
		}
	}
}
//---------------------------------------------------------------------------------
void HorizontalFlip(BYTE *Img, int W, int H)
{ //좌,우를 Flip하는 코드, 첫번째 열과 마지막 열을 swap해줌
	for (int i = 0; i < W / 2; i++) //x 좌표
	{
		for (int j = 0; j < H; j++) //y 좌표
		{
			swap(&Img[j*W + i], &Img[j*W + (W - 1 - i)]); //(0,0)과 (0,n)을 교환
		}
	}
}
//---------------------------------------------------------------------------------
void Translation(BYTE *Image, BYTE *Output, int W, int H, int Tx, int Ty)
{ //Translation, 순방향 사상
	Ty *= -1;//부호를 바꿔줌
	for (int i = 0; i < H; i++) //i = y
	{
		for (int j = 0; j < W; j++) //j = x
		{
			if ((i + Ty < H && i + Ty >= 0) && (j + Tx < W && j + Tx >= 0))
				Output[(i + Ty)*W + (j + Tx)] = Image[i*W + j];
		}
	}
}
//---------------------------------------------------------------------------------
void Scaling(BYTE *Image, BYTE *Output, int W, int H, double SF_X, double SF_Y)
{ //Scaling 하는 코드
	int tmpX, tmpY;
	for (int i = 0; i < H; i++) //y좌표
	{
		for (int j = 0; j < W; j++) //x좌표
		{
			tmpX = (int)(j / SF_X);
			tmpY = (int)(i / SF_Y);
			if (tmpY < H && tmpX < W)
				Output[i*W + j] = Image[tmpY*W + tmpX];
		}
	}
}
//---------------------------------------------------------------------------------
void Rotation(BYTE *Image, BYTE *Output, int W, int H, int Angle)
{ // 역방향 rotation(회전)하는 함수
	int tmpX, tmpY; //tmpX가 X'을 구하는 것.
	double Radian = Angle * 3.141592 / 180.0; //라디안 값 계산
	for (int i = 0; i < H; i++) //y좌표
	{
		for (int j = 0; j < W; j++) //x좌표
		{ //(0,0)을 기준으로 회전, 이또한 범위를 벗어날 수 있으니 예외처리를 해주어야 함
			tmpX = (int)(cos(Radian)*j + sin(Radian)*i);
			tmpY = (int)(-sin(Radian)*j + cos(Radian)*i);
			if ((tmpY < H && tmpY >= 0) && (tmpX < W && tmpX >= 0)) //예외처리 
				Output[i*W + j] = Image[tmpY*W + tmpX];
		}
	}
}
//---------------------------------------------------------------------------------
int main()
{
	BITMAPFILEHEADER hf; // 14바이트
	BITMAPINFOHEADER hInfo; // 40바이트
	RGBQUAD hRGB[256]; // 1024바이트
	FILE* fp;
	fp = fopen("LENNA.bmp", "rb");
	if (fp == NULL) {
		printf("File not found!\n");
		return -1;
	}
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, fp);
	fread(hRGB, sizeof(RGBQUAD), 256, fp);
	int ImgSize = hInfo.biWidth * hInfo.biHeight;
	BYTE * Image = (BYTE *)malloc(ImgSize);
	BYTE * Temp = (BYTE *)malloc(ImgSize); //임시 배열
	BYTE * Output = (BYTE*)malloc(ImgSize);
	fread(Image, sizeof(BYTE), ImgSize, fp);
	fclose(fp);

	int H = hInfo.biHeight;
	int W = hInfo.biWidth;
	int Histo[256] = { 0 };
	int AHisto[256] = { 0 }; //누적히스토램을 저장할 배열 선언 후 초기화

	//---------------------------------------------------------------------------------
	//#######[6주차 과제] 동공영역 외접사각형 및 무게중심통과하는 크로스라인 그리기#######
	/*//이진화 후 라벨링하는 코드
	Binarization(Image, Temp, W, H, 50);
	InverseImage(Temp, Temp, W, H);
	m_BlobColoring(Temp, H, W);
	for (int i = 0; i < ImgSize; i++) Output[i] = Image[i]; //Output배열을 쓴 적이 없으니 우선 초기화해줌
	//BinaryImageEdgeDetection(Temp, Output, W, H);
	//---------------------------------------------------------
	// 무게중심 구하기
	int Cx = 0;
	int Cy = 0;
	int cnt = 0;
	for (int i = 1; i < H; i++) //i=y, 마진때문에 1~H-1까지
	{
		for (int j = 1; j < W; j++) //j=x
		{
			if (Temp[(i*W) + j] == 0)
			{
				Cx += j;
				Cy += i;
				cnt++;
			}
		}
	} //이미 이진화를 시켰으니 다 더해도 전경의 255만 더해짐. 전부 더한만큼 cnt로 나누어주기
	Cx = Cx / cnt; // Cx: 가로/세로 라인이 교차되는 지점의 X좌표(무게중심 x좌표)
	Cy = Cy / cnt; // Cy: 가로/세로 라인이 교차되는 지점의 Y좌표(무게중심 y좌표)
	//printf("x좌표 : %d\n", Cx);
	//printf("y좌표 : %d", Cy);
	DrawCrossLine(Output, W, H, Cx, Cy);
	//---------------------------------------------------------
	int LU_X = W;
	int LU_Y = H;
	int RD_X = 0;
	int RD_Y = 0;

	//x,y의 최대값 구하기
	for (int i = 1; i < H; i++) //i=y
	{ //이미지 전체의 화소를 검사한다.
		for (int j = 1; j < W; j++) //j=x
		{
			if (Temp[i*W + j] == 0)
			{
				if (RD_X < (j + 1))
					RD_X = j + 1;
				if (RD_Y < (i + 1))
					RD_Y = i + 1;
			}
		}
	}
	//printf("RD_X(X의 최댓값) : %d\n", RD_X); //x의 최댓값
	//printf("RD_Y(Y의 최댓값) : %d\n", RD_Y); //y의 최댓값

	//x,y의 최소값 구하기
	for (int i = 1; i < H; i++) //i=y
	{ //이미지 전체의 화소를 검사한다.
		for (int j = 1; j < W; j++) //j=x
		{
			if (Temp[i*W + j] == 0)
			{
				if (LU_X > (j + 1))
					LU_X = j + 1;
				if (LU_Y > (i + 1))
					LU_Y = i + 1;
			}
		}
	}
	//printf("LU_X(X의 최소값) : %d\n", LU_X); //x의 최댓값
	//printf("LU_Y(Y의 최소값) : %d\n", LU_Y); //y의 최댓값
	//---------------------------------------------------------
	//사각형을 출력하는 함수 호출
	DrawRectOutline(Output, W, H, LU_X, LU_Y, RD_X, RD_Y);*/
	//---------------------------------------------------------------------------------


	/*ObtainHistogram(Image, Histo, hInfo.biWidth, hInfo.biHeight);
	ObtainAHistogram(Histo, AHisto);
	HistogramEqualization(Image, Output, AHisto, hInfo.biWidth, hInfo.biHeight);*/

	/*//---------------------------------------------------------------------------------
	//#######[3주차 과제] Gonzalez 자동 이진화 임계치 결정 프로그램 구현, 호출#######
	ObtainHistogram(Image, Histo, hInfo.biWidth, hInfo.biHeight);
	int Thres = GonzalezBin(Image, Histo, hInfo.biWidth, hInfo.biHeight);
	Binarization(Image, Output, hInfo.biWidth, hInfo.biHeight, Thres);
	//---------------------------------------------------------------------------------*/

	//Gonzalez 실습(과제 해설코드)
	/*BYTE Th; //임계치 저장 변수
	ObtainHistogram(Image, Histo, W, H);
	Th = DetermThGonzalez(Histo);
	Binarization(Image, Output, W, H, Th);*/


	//AverageConv(Image, Output, hInfo.biWidth, hInfo.biHeight);
	//GaussAvrConv(Image, Output, hInfo.biWidth, hInfo.biHeight);
	/*Prewitt_X_Conv(Image, Temp, hInfo.biWidth, hInfo.biHeight);
	Prewitt_Y_Conv(Image, Output, hInfo.biWidth, hInfo.biHeight);
	for (int i = 0; i < ImgSize; i++)
	{
		if (Temp[i] > Output[i]) //x마스크 돌린 결과와 y마스크 돌린 결과를 비교
			Output[i] = Temp[i]; //Temp값이 더 strong하게 나왔으면 Output에 저장
	}
	Binarization(Output, Output, hInfo.biWidth, hInfo.biHeight, 40);*/

	/*Sobel_X_Conv(Image, Temp, hInfo.biWidth, hInfo.biHeight);
	Sobel_Y_Conv(Image, Output, hInfo.biWidth, hInfo.biHeight);
	for (int i = 0; i < ImgSize; i++)
	{
		if (Temp[i] > Output[i]) //x마스크 돌린 결과와 y마스크 돌린 결과를 비교
			Output[i] = Temp[i]; //Temp값이 더 strong하게 나왔으면 Output에 저장
	}
	Binarization(Output, Output, hInfo.biWidth, hInfo.biHeight, 40);*/

	//Laplace_Conv(Image, Output, hInfo.biWidth, hInfo.biHeight);
	//GaussAvrConv(Image, Temp, hInfo.biWidth, hInfo.biHeight);
	//Laplace_Conv_DC(Temp, Output, hInfo.biWidth, hInfo.biHeight);

	//HistogramStretching(Image, Output, Histo, hInfo.biWidth, hInfo.biHeight);
	//InverseImage(Image, Output, hInfo.biWidth, hInfo.biHeight);
	//BrightnessAdj(Image, Output, hInfo.biWidth, hInfo.biHeight, 70);
	//ContrastAdj(Image, Output, hInfo.biWidth, hInfo.biHeight, 0.5);

	//---------------------------------------------------------------------------------
	//#######[5주차 과제] Median filter 사이즈에 따른 결과 비교#######
	/*// Median filtering
	int Length = 9;  // 마스크의 한 변의 길이
	int Margin = Length / 2; //ex.2/3=1.5에서 int화하면 1이 나옴. 즉, 1을 마진으로 설정
	int WSize = Length * Length; // 마스크의 사이즈
	BYTE* temp = (BYTE*)malloc(sizeof(BYTE) * WSize); //마스크사이즈를 저장할 동적할당이 가능한 temp배열 선언
	int W = hInfo.biWidth, H = hInfo.biHeight; //영상의 가로, 세로 정의
	int i, j, m, n;
	for (i = Margin; i < H - Margin; i++)
	{ //i는 Y좌표(행), 마진부터 마진 전까지 반복
		for (j = Margin; j < W - Margin; j++)
		{ //j는 x좌표(열)
			for (m = -Margin; m <= Margin; m++)
			{ //m은 -마진부터, m이 마진보다 작거나 같을때까지, m을 하나씩 증가
				for (n = -Margin; n <= Margin; n++)
				{ //n은 -마진부터,n이 마진보다 작거나 같을때까지, n을 하나씩 증가
					temp[(m + Margin) * Length + (n + Margin)] = Image[(i + m)*W + j + n];
				} //원본Image의 (x,y)좌표, 즉 마진이외의 부분(j,i)를 인덱싱하여 temp에 넣어줌
			}
			Output[i * W + j] = Median(temp, WSize);
			// temp를 정렬해서 반환값으로 중간값을 받아 Output과 계산
		}
	}*/
	//---------------------------------------------------------------------------------

	//AverageConv(Image, Output, hInfo.biWidth, hInfo.biHeight);


	//---------------------------------------------------------------------------------
	//VerticalFlip(Image, W, H); //상하 뒤집기
	//HorizontalFlip(Image, W, H); //좌우 뒤집기
	//Translation(Image, Output, W, H, 100, 40); 이동
	//Scaling(Image, Output, W, H, 0.7,0.7); //Uniform Scaling
	Rotation(Image, Output, W, H, 60); //영상의 원점을 중심으로 회전



	fp = fopen("inverse_rotationfun.bmp", "wb");
	fwrite(&hf, sizeof(BYTE), sizeof(BITMAPFILEHEADER), fp);
	fwrite(&hInfo, sizeof(BYTE), sizeof(BITMAPINFOHEADER), fp);
	fwrite(hRGB, sizeof(RGBQUAD), 256, fp);
	fwrite(Output, sizeof(BYTE), ImgSize, fp);
	fclose(fp);
	free(Image);
	//free(temp);
	free(Output);
	free(Temp);
	return 0;
}
