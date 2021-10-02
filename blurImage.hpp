extern "C" 
{
	extern void greyScaleISPC(unsigned char vin[], unsigned char vout[], int height, int width);
	extern void blurImageISPC(unsigned char vin[], unsigned char vout[], int height,
		       		int width, int blurRadius);
}
