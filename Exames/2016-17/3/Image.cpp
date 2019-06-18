#include "Image.h"

//Alínea b)
Image Image::getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const
{
	Image region(nLins, nCols);
	for (size_t i = 0; i < nLins; i++)
		for (size_t j = 0; j < nCols; j++)
			region.img[i][j] = img[lin + i][col + j];
	return region;
}