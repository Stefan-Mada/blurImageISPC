export void blurImageISPC(uniform unsigned int8 vin[], uniform unsigned int8 vout[],
                   uniform int height, uniform int width, uniform int blurRadius) {
    
	uniform float divisionFactor = 2 * blurRadius + 1;
	divisionFactor *= divisionFactor;
	uniform float factor = 1 / divisionFactor;
	
	for(int i = 0; i < height; ++i)
	{
		foreach (j = 0 ... width)
		{
			float totalRed = 0;
			float totalGreen = 0;
			float totalBlue = 0;

			for(int dx = j - blurRadius; dx <= j + blurRadius; ++dx)
			{
				if (dx < 0 || dx >= width)
					continue;
				for(int dy = i - blurRadius; dy <= i + blurRadius; ++dy)
				{
					if (dy < 0 || dy >= height)
						continue;
					int currentIndex = (dy * width + dx) * 3;
					totalRed += vin[currentIndex];
					totalGreen += vin[currentIndex + 1];
					totalBlue += vin[currentIndex + 2];
				}
			}
			int avgRed = totalRed * factor;
			int avgGreen = totalGreen * factor;
			int avgBlue = totalBlue * factor;
			
			int currentIndex = (i * width + j) * 3;
			vout[currentIndex] = avgRed;
			vout[currentIndex + 1] = avgGreen;
			vout[currentIndex + 2] = avgBlue;
		}
	}
}
