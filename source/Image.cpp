#include "Image.h"
#include <fstream>
#include <iostream>
#include <assert.h>
#include <sstream>

Image::Image(const std::string& path) {
	std::ifstream in(path);
	std::string magic_number;
	int max;
	in >> magic_number >> width >> height >> max;
	//std::cout << std::endl << "magic_number: " << magic_number << std::endl << "width: " << width << std::endl << "height: " << height << std::endl;
	pixels = new unsigned char[width * height * 3];
	for (int r = height - 1; r >= 0; --r) {
		for (int c = 0; c < width; ++c) {
			for (int i = 0; i < 3; ++i) {
				int value;
				in >> value;
				pixels[(c + r * width) * 3 + i] = value;
			}
		}
	}
	in.close();

	nchannels = 3;
}

Image::Image(const std::string& path, bool is_flipped) {
	std::ifstream in(path);
	std::string magic_number;
	int max;
	in >> magic_number >> width >> height >> max;
	//std::cout << std::endl << "magic_number: " << magic_number << std::endl << "width: " << width << std::endl << "height: " << height << std::endl;
	pixels = new unsigned char[width * height * 3];
	
	if (!is_flipped) {
		for (int r = height - 1; r >= 0; --r) {
			for (int c = 0; c < width; ++c) {
				for (int i = 0; i <= 2; ++i) {
					int value;
					in >> value;
					pixels[(c + r * width) * 3 + i] = value;
				}
			}
		}
	} else {	
		for (int r = 0; r < height; ++r) {
			for (int c = 0; c < width; ++c) {
				for (int i = 0; i <= 2; ++i) {
					int value;
					in >> value;
					pixels[(c + r * width) * 3 + i] = value;
				}
			}
		}
	}
	in.close();
}

Image::Image(int width, int height, int nchannels) {
	this->width = width;
	this->height = height;
	this->nchannels = nchannels;
	pixels = new unsigned char[width * height * nchannels];
}

int Image::GetWidth() const {
	return width;
}

int Image::GetHeight() const {
	return height;
}

int Image::GetChannelCount() const {
	return nchannels;
}

const unsigned char* Image::GetPixels() const {
	return pixels;
}

unsigned char* Image::operator()(int c, int r) {
	assert(c >= 0 && c < GetWidth());
	assert(r >= 0 && r < GetHeight());
	return &pixels[(c + r * GetWidth()) * GetChannelCount()];
}

unsigned char& Image::operator()(int c, int r, int channel) {
	if(c >= GetWidth()) c = GetWidth() - 1;
	if(r >= GetHeight()) r = GetHeight() - 1;
	return pixels[(c + r * GetWidth()) * GetChannelCount() + channel];
}

const unsigned char& Image::operator()(int c, int r, int channel) const {
	if(c >= GetWidth()) c = GetWidth() - 1;
	if(r >= GetHeight()) r = GetHeight() - 1;
	return pixels[(c + r * GetWidth()) * GetChannelCount() + channel];
}

float Interpolate(float position_a,
				  float value_a,
				  float position_b,
				  float value_b,
				  float position_t) {
				  
	return (position_t - position_a) / (position_b - position_a) * (value_b - value_a) + value_a;
}

float Image::operator()(float c, float r, int channel) {
	int ci = (int)c;
	int ri = (int)r;
	
	float below = Interpolate(ci, (*this)(ci, ri, channel), ci + 1, (*this)(ci + 1, ri, channel), c);
	float above = Interpolate(ci, (*this)(ci, ri + 1, channel), ci + 1, (*this)(ci + 1, ri + 1, channel), c);

	float goldilocks = Interpolate(ri, below, ri + 1, above, r);
	
	return goldilocks;
}

Image* Image::GetWhiteNoise(int width, int height, int nchannels) {
	Image* image = new Image(width, height, nchannels);
	for (int r = 0; r < height; ++r) {
		for (int c = 0; c < width; ++c) {
			for (int i = 0; i < nchannels; ++i) {
				(*image)(c, r, i) = (unsigned char)(255.0f * rand() / RAND_MAX);
			}
		}
	}
	
	return image;
}

Image* Image::GetSmoothNoise(int width, int height, int noctaves) {
	Image* noise = new Image(width, height, 1);
	for(int r = 0; r < height; ++r) {
		for(int c = 0; c < width; ++c) {
			(*noise)(c, r, 0) = 0;
		}
	}
	
	
	int current_width = width;
	int current_height = height;
	for (int i = 0; i < noctaves; ++i) {
		Image* white = GetWhiteNoise(current_width, current_height, 1);
		
		Image* scaled = white->Scale(width, height);
		delete white;
		
		int numerator = 1 << i;
		int denominator = (1 << noctaves) - 1;
		float factor = numerator / (float)denominator;
		
		for(int r = 0; r < height; ++r){
			for(int c = 0; c < width; ++c) {
				(*noise)(c, r, 0) += factor * (*scaled)(c, r, 0);
			}
		}
		
		current_width /= 2;
		current_height /= 2;
	}
	
	return noise;
}

Image *Image::Scale(int new_width, int new_height) {
	Image* scaled = new Image(new_width, new_height, nchannels);
	
	for(int r = 0; r < new_height; ++r) {
		for(int c = 0; c < new_width; ++c) {
			float rf = r / (float)new_height * GetHeight();
			float cf = c / (float)new_width * GetWidth();
			for (int i = 0; i < GetChannelCount(); ++i) {
				scaled->pixels[(c + r * new_width) * GetChannelCount()] = (*this)(cf, rf, i);
			}	
		}
	}

	return scaled;
}

void Image::WriteToFile(const std::string& path) {

	//remove file first, just in case
	char* fileToRemove = new char [path.length()+1];
	path.copy(fileToRemove, path.size(), 0);
	remove(fileToRemove);

	//open a connection to write to the file
	std::ofstream out(path);

	//assign the magic number, based on the number of channels
	std::string magic_number = "";
	if (nchannels == 1) {
		magic_number = "P2";
	} else if (nchannels == 3) {
		magic_number = "P3";
	}
	out << magic_number << std::endl << GetWidth() << " " << GetHeight() << std::endl << "255" << std::endl;
  
	for(int r = 0; r < GetHeight(); ++r){
		for(int c = 0; c < GetWidth(); ++c){
			for(int i = 0; i < nchannels; ++i) {
				out << (int) pixels[(c + (GetHeight() - 1 - r) * GetWidth()) * nchannels + i] << std::endl;
			}
		}
	}
	out.close();
}

