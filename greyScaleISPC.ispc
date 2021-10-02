export void greyScaleISPC(uniform unsigned int8 vin[], uniform unsigned int8 vout[],
                   uniform int height, uniform int width) {
    
	uniform float onethird = 0.33333333;
	
	for(int i = 0; i < height; ++i)
	{
		foreach (index = 0 ... width)
		{
			int currentIndex = (i * width + index) * 3;			
			float redColor = vin[currentIndex];
			float greenColor= vin[currentIndex + 1]; 
			float  blueColor = vin[currentIndex + 2];
			
			int avgColor = (redColor + greenColor + blueColor) * onethird;

			vout[currentIndex] = avgColor;	
			vout[currentIndex + 1] = avgColor;
			vout[currentIndex + 2] = avgColor;
		}
	}
}
