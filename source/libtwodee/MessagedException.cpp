#include <iostream>

#include "MessagedException.h"

namespace td {

/* ------------------------------------------------------------------------- */

MessagedException::MessagedException(const std::string& message) throw()
  : message(message) {
}

/* ------------------------------------------------------------------------- */

MessagedException::~MessagedException() throw() {
}

/* ------------------------------------------------------------------------- */

const char *MessagedException::what() const throw() {
  return message.c_str(); 
}

/* ------------------------------------------------------------------------- */

}
