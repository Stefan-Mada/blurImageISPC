#include "blurImage.hpp"

void greyScaleCpp(unsigned char vin[], unsigned char vout[], int height, int width)
{
	int currentIndex, avgColor;
	float redColor, greenColor, blueColor;
	
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			currentIndex = (i * width + j) * 3;

			redColor = vin[currentIndex];
			greenColor = vin[currentIndex + 1];
			blueColor = vin[currentIndex + 2];

			avgColor = (redColor + greenColor + blueColor) / 3;

			for(int i = 0; i < 3; ++i)
				vout[currentIndex + i] = avgColor;
		}
	}
}
