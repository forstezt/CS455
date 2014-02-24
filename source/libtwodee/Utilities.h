#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

namespace td {

/* ------------------------------------------------------------------------- */

const double PI = 3.1415926535897932384626433832795;

enum {
  HSV,
  HSVA,
  RGB,
  RGBA
};

/* ------------------------------------------------------------------------- */

/**
 A container class for several standalone utility methods.
 */
class Utilities {
  public:
    /**
     Gets the contents of the specified file as a string.
     @param path Path to file
     @return String contents of file
     */
    static char *FileToString(const std::string& path);

    /**
     Convert array of one type to array of another. Assumes destination array
     has already been allocated.
     @param dst Preallocated destination array
     @param src Array from which to copy values
     @param nitems Number of items to copy
     */
    template<class T, class U>
    static void ConvertArray(U *dst,
                             const T *src,
                             int nitems);

    static bool IsLittleEndian();

    static void ReverseEndian(void *p,
                              int nbytes);

    static bool Replace(std::string& in,
                        const std::string& replacee,
                        const std::string& replacer);
};

/* ------------------------------------------------------------------------- */

template<class T, class U>
void Utilities::ConvertArray(U *dst,
                             const T *src,
                             int nitems) {
  for (int i = 0; i < nitems; i++) {
    dst[i] = (U) src[i];
  }
}

/* ------------------------------------------------------------------------- */

}

#endif
