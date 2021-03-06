/**
 * Author: Alessio Placitelli
 * Contact: a.placitelli _@_ a2p.it
 *
 */
 
#ifndef _PNGImageContainer_h_
#define _PNGImageContainer_h_
 
#include "ImageContainer.h"

// forward declarations
struct FIBITMAP;

class PNGImageContainer : public ImageContainer 
{
public:
    PNGImageContainer();
    PNGImageContainer(const std::string& fileName);
    ~PNGImageContainer();
    
    bool load(const std::string& fileName);

    gpu_int getWidth() const;
    gpu_int getHeight() const;
    gpu_int getBitsPerPixel() const;
    gpu_int getFormat() const;
    bool resize(gpu_int width, gpu_int height);
    unsigned char* getRawBytes() const;

    void destroy();

    static bool writePNG(const std::string& fileName, const unsigned char* imageData, gpu_int width, gpu_int height, gpu_int bytesPerPixel); 

private:
    gpu_int width_;
    gpu_int height_;
    gpu_int bytesPerPixel_;
    gpu_int imageFormat_;

    unsigned char* data_;
    FIBITMAP* dib_;
};
 
#endif // _PNGImageContainer_h_