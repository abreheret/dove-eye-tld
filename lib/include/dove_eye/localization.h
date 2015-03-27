#ifndef DOVE_EYE_LOCALIZATION_H_
#define DOVE_EYE_LOCALIZATION_H_

#include "dove_eye/positset.h"

namespace dove_eye {

struct Location {
  double x;
  double y;
  double z;
};

class Localization {
 public:
  Location Locate(const Positset &positset);
};

} // namespace dove_eye

#endif // DOVE_EYE_LOCALIZATION_H_
