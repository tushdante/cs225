#include<vector>
#include<Magick++.h>
#include<EasyBMP.h>

#define NUM_CHANNELS 3
#ifndef ANIMATION_H
#define ANIMATION_H


// NOTE This is the grading "animation"  as such it doesn't actually make animations, but rather just stores the frames so the grading is faster/easier.
class animation {
  public:
    void addFrame(BMP const & img);
    int size();
    BMP frame(int frameNum);

  private:

    std::vector<BMP> BMPframes;
};
#endif
