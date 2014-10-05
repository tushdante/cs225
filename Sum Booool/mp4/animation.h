#include<vector>
#include<Magick++.h>
#include<EasyBMP.h>

#define NUM_CHANNELS 3

class animation {
  public:
    void addFrame(BMP const & img);
    void write(std::string filename);

  private:
    Magick::Image convertToMagickImage(BMP const & img) const;

    std::vector<Magick::Image> frames;
};
