#include <iostream>
#include <fstream>
#include <exception>
#include <string>

extern "C" 
{
	extern void greyScaleISPC(unsigned char vin[], unsigned char vout[], int height, int width);
	extern void blurImageISPC(unsigned char vin[], unsigned char vout[], int height,
		       		int width, int blurRadius);
}

void greyScaleImage(std::ofstream& of, unsigned char* &pixelArr, int width, int height, int maxColor);
void blurImage(std::ofstream& of, unsigned char* &pixelArr, int width, int height,
						int maxColor, int blurRadius);

//Below are Cpp implementations of the ISPC functions
void greyScaleCpp(unsigned char vin[], unsigned char vout[], int height, int width);
void blurImageCpp(unsigned char vin[], unsigned char vout[], int height,
				int width, int blurRadius);
