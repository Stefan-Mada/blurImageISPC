#include "blurImage.hpp"

void blurImageCpp(unsigned char vin[], unsigned char vout[], int height,
				int width, int blurRadius)
{
	const float divisionFactor = (2 * blurRadius + 1) * (2 * blurRadius + 1);
	int currentIndex, avgRed, avgGreen, avgBlue;
	float totalRed, totalGreen, totalBlue;
	
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			totalRed = 0;
			totalGreen = 0;
			totalBlue = 0;

			for(int dx = j - blurRadius; dx <= j + blurRadius; ++dx)
			{
				if (dx < 0 || dx >= width)
					continue;
				for(int dy = i - blurRadius; dy <= i + blurRadius; ++dy)
				{
					if (dy < 0 || dy >= height)
						continue;
					currentIndex = (dy * width + dx) * 3;
					totalRed += vin[currentIndex];
					totalGreen += vin[currentIndex + 1];
					totalBlue += vin[currentIndex + 2];
				}
			}
			avgRed = totalRed / divisionFactor;
			avgGreen = totalGreen / divisionFactor;
			avgBlue = totalBlue / divisionFactor;

			currentIndex = (i * width + j) * 3;
			vout[currentIndex] = avgRed;
			vout[currentIndex + 1] = avgGreen;
			vout[currentIndex + 2] = avgBlue;
		}
	}
}
