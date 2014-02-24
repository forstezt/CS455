#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------- */

struct Field3 {
  int width;
  int height;
  int depth;
  float *data;

  Field3(int width, int height, int depth)
    : width(width),
      height(height),
      depth(depth),
      data(new float[width * height * depth]) {
  }

  ~Field3() {
    delete[] data;
  }

  const float& operator()(int c, int r, int z) const {
    return data[(z * height + r) * width + c];
  }

  float& operator()(int c, int r, int z) {
    return data[(z * height + r) * width + c];
  }

  /**
   Create a field of the specified width and height filled with random values
   between 0 and max.
   @param width Field width
   @param height Field height
   @param max Maximum possible random value
   @return Field of random values, to be deallocated by caller
   */
  static Field3 *GetRandom(int width, int height, int depth, double max) {
    Field3 *f = new Field3(width, height, depth);
    for (int z = 0; z < depth; ++z) {
      for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
          (*f)(c, r, z) = ((float) rand()) / RAND_MAX * max;
        }
      }
    }
    return f;
  }

  /**
   Get an interpolated intensity value. The relative coordinates are applied
   to the field. The four known neighboring intensities are blended together
   based on the distance from them.
   @param rel_c A relative x-coordinate in [0, 1].
   @param rel_r A relative y-coordinate in [0, 1].
   @return The interpolated intensity.
   */
  float Interpolate(float rel_c, float rel_r, float rel_z) const {
    float fc = rel_c * (width - 1);
    float fr = rel_r * (height - 1);
    float fz = rel_z * (depth - 1);

    int ic = (int) floorf(fc);
    int ir = (int) floorf(fr);
    int iz = (int) floorf(fz);

    float frac_c = fc - ic;
    float frac_r = fr - ir;
    float frac_z = fz - iz;

    int next_c = ic < width - 1 ? ic + 1 : width - 1;
    int next_r = ir < height - 1 ? ir + 1 : height - 1;
    int next_z = iz < depth - 1 ? iz + 1: depth - 1;

    float a = (1.0f - frac_c) * (*this)(ic, ir, iz) + frac_c * (*this)(next_c, ir, iz);
    float b = (1.0f - frac_c) * (*this)(ic, next_r, iz) + frac_c * (*this)(next_c, next_r, iz);
    float c = (1.0f - frac_c) * (*this)(ic, ir, next_z) + frac_c * (*this)(next_c, ir, next_z);
    float d = (1.0f - frac_c) * (*this)(ic, next_r, next_z) + frac_c * (*this)(next_c, next_r, next_z);

    float e = (1.0f - frac_r) * a + frac_r * b;
    float f = (1.0f - frac_r) * c + frac_r * d;

    return (1.0f - frac_z) * e + frac_z * f;
  }

  /**
   Scale the field to the given dimensions. Intensities in the scaled field are
   linearly interpolated from the original values. The invoking field is not
   modified.
   @param new_width Width of new field
   @param new_height Height of new field
   @return Resampled field
   */
  Field3 *Resample(int new_width, int new_height, int new_depth) const {
    Field3 *f = new Field3(new_width, new_height, new_depth);

    for (int z = 0; z < f->depth; ++z) {
      for (int r = 0; r < f->height; ++r) {
        for (int c = 0; c < f->width; ++c) {
          float rel_c = c / (f->width - 1.0f);
          float rel_r = r / (f->height - 1.0f);
          float rel_z = z / (f->depth - 1.0f);
          (*f)(c, r, z) = Interpolate(rel_c, rel_r, rel_z);
        }
      }
    }

    return f;
  }

  /**
   Generate a field of beautiful Perlin noise.
   @param width Width of noise
   @param height Height of noise
   @param noctaves Number of levels of subnoise to accumulate. The larger
                   the number, the smoother the field.
   @return Noise field
   */
  static Field3 *GetNoise(int width, int height, int depth, int noctaves) {
    Field3 **octaves = new Field3*[noctaves];

    // Generate random, smaller and smaller
    double max = 1.0f / powf(2.0f, noctaves);
    octaves[0] = Field3::GetRandom(width, height, depth, max);
    for (int i = 1; i < noctaves; ++i) {
      max *= 2.0f;
      octaves[i] = Field3::GetRandom(octaves[i - 1]->width / 2,
                                     octaves[i - 1]->height / 2,
                                     octaves[i - 1]->depth / 2, max);
    }

    // Resample all to be the same size
    for (int i = 1; i < noctaves; ++i) {
      Field3 *tmp = octaves[i]->Resample(octaves[0]->width,
                                         octaves[0]->height,
                                         octaves[0]->depth);
      delete octaves[i];
      octaves[i] = tmp;
    }

    // Sum up all the octaves into the first octave
    for (int i = 1; i < noctaves; ++i) {
      for (int z = 0; z < octaves[0]->depth; ++z) {
        for (int r = 0; r < octaves[0]->height; ++r) {
          for (int c = 0; c < octaves[0]->width; ++c) {
            (*octaves[0])(c, r, z) += (*octaves[i])(c, r, z);
          }
        }
      }
    }

    // Only the first octave is needed now.
    Field3 *noise = octaves[0];
    for (int i = 1; i < noctaves; ++i) {
      delete octaves[i];
    }
    delete[] octaves;

    return noise;
  }

  // Marble can be created by perturbing a periodic signal traveling along
  // a constant direction. sin(r + c) will generate a period along the image
  // diagonal.
  static Field3 *GetMarble(int width, int height, int depth, int noctaves = 6, float weight = 50.0f) {
    Field3 *noise = Field3::GetNoise(width, height, depth, noctaves);
    Field3 *marble = new Field3(width, height, depth);
    for (int z = 0; z < depth; ++z) {
      for (int r = 0; r < width; ++r) {
        for (int c = 0; c < width; ++c) {
          (*marble)(c, r, z) = sinf((r + c + z) / 2.0f + weight * (*noise)(c, r, z));
        }
      }
    }
    delete noise;
    return marble;
  }

  // Wood can be created by perturbing an image of concentric circles. We
  // find the distance of each pixel from the image center. sin(distance) will
  // generate concentric circles.
  static Field3 *GetWoodGrain(int width, int height, int depth, int noctaves = 6, float weight = 10.0f) {
    Field3 *noise = Field3::GetNoise(width, height, depth, noctaves);
    Field3 *wood = new Field3(width, height, depth);
    for (int z = 0; z < depth; ++z) {
      for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
          float diff_x = c - width / 2;
          float diff_y = r - height / 2;
          float distance = sqrtf(diff_x * diff_x + diff_y * diff_y);
          (*wood)(c, r, z) = sinf(distance / 10.0f + weight * (*noise)(c, r, z));
        }
      }
    }
    delete noise;
    return wood;
  }
};

/* ------------------------------------------------------------------------- */

