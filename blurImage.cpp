#include "blurImage.hpp"


void greyScaleImage(std::ofstream& of, unsigned char* &pixelArr, int width, int height, int maxColor)
{
	of << "P6" << " " << width << " " << height << " " << maxColor << "\n";

	//Create other array to store data
	unsigned char* pixels = new unsigned char[height*width*3];
	
	//greyScaleISPC(pixelArr, pixels, height, width);
	greyScaleCpp(pixelArr, pixels, height, width);

	for(int i = 0; i < height * width * 3; ++i)
		of << pixels[i];

	delete[] pixels;
}
void blurImage(std::ofstream& of, unsigned char* &pixelArr, int width, int height, 
						int maxColor, int blurRadius)
{	
	
	of << "P6" << " " << width << " " << height << " " << maxColor << "\n";
	
	//Create other array to store data
	unsigned char* pixels = new unsigned char[height*width*3];
	
	//blurImageISPC(pixelArr, pixels, height, width, blurRadius);
	blurImageCpp(pixelArr, pixels, height, width, blurRadius);

	for(int i = 0; i < height * width * 3; ++i)
		of << pixels[i];

	delete[] pixels;


}
int main(int argc, char *argv[])
{
	//Check for valid command line arguments
	if(argc < 2)
		throw std::invalid_argument("Must pass a file as an argument");
	else if (argc > 4)
		throw std::invalid_argument("At most 2 arguments can be passed");	
	
	//First read an input file to a stream
	std::ifstream image;
	image.open(std::string(argv[1]));
	
	//Check that it is the proper format
	std::string fileType;
	image >> fileType;
	
	if(fileType != "P6")
		throw std::invalid_argument("Must be a .ppm file");

	//Find the width, height, and maximum color values
	int width, height, maxColor;
	image >> width >> height >> maxColor;
	
	if(maxColor > 255)
		throw std::invalid_argument("Max colors must be at most 255 for this program");

	//Make a dynamic array that is the size of the image to store the RGB values
	unsigned char* pixels = new unsigned char[height*width*3];


	//Create the output file, and the value that will temporarily hold rgb values
	std::ofstream output;
	if(argc == 3)
		output.open(std::string(argv[2]));
	else
		output.open("output.ppm");
	

	unsigned char color[3];
	image.read(reinterpret_cast<char*>(color), 1);	//Needs to read a whitespace character

	//Read the file, get the character values, and fill the array
	for(int i = 0; i < height; ++i)
	{	
		for(int j = 0; j < width; ++j)
		{
			image.read(reinterpret_cast<char*>(color), 3);
			pixels[(i*width + j) * 3] = color[0];
			pixels[(i*width + j) * 3 + 1] = color[1];
			pixels[(i*width + j) * 3 + 2] = color[2];
		}
	}



	
	blurImage(output, pixels, width, height, maxColor, 10);
//	greyScaleImage(output, pixels, width, height, maxColor);

	//Remove the array's memory
	delete[] pixels;
}
