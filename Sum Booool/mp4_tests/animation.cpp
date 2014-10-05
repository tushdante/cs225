#include"animation.h"

void animation::addFrame(BMP const & img) {
  BMPframes.push_back(img);
}

int animation::size() {
  return BMPframes.size();
}

BMP animation::frame(int frameNum) {
  return BMPframes[frameNum];
}
