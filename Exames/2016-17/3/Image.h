#pragma once

//Alínea a) - getPixel
//Alínea e) - template <class T> - substituir "int" por "T" nas funções

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//template <class T>
class Image {
public:
	Image(size_t nLins = 0, size_t nCols = 0, /*T*/ int pixVal = 0); //nLins & nCols are the dimensions of the image; pixVal is the initial value of every pixel
	void setPixel(size_t lin, size_t col, /*T*/ int pixVal); //modifies the value of the pixel at (lin,col)
	bool read(string fileName); // reads the image saved in file fileName, storing it in img; returns true if sucessful, false otherwise
	Image getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const; // returns an image containing a rectangular region of img
	int getPixel(size_t lin, size_t col) const; //Alínea a)
	// ... other methods
private:
	vector<vector<int>> img; // image representation
	// ... other attributes
};