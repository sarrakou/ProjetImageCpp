#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION 
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "stb_image.h"

bool Image::saveImage(const std::string& filename, const std::string& format) {
    int saveResult = 0;
    if (format == "png") {
        saveResult = stbi_write_png(filename.c_str(), width, height, channels, data.data(), width * channels);
    }
    else if (format == "bmp") {
        saveResult = stbi_write_bmp(filename.c_str(), width, height, channels, data.data());
    }
    else if (format == "jpg") {
        saveResult = stbi_write_jpg(filename.c_str(), width, height, channels, data.data(), 100); // Qualit� 100
    }

    return saveResult != 0;
}

bool Image::loadImage(const std::string& filename) {
    // Lib�ration de la m�moire si l'image �tait d�j� charg�e
    data.clear();

    int w, h, channels;
    unsigned char* imgData = stbi_load(filename.c_str(), &w, &h, &channels, 0);
    if (!imgData) return false;

    width = w;
    height = h;
    this->channels = channels;
    model = channels == 1 ? "GRAY" : channels == 3 ? "RGB" : "UNKNOWN";

    // Copie des donn�es de l'image
    data.assign(imgData, imgData + (width * height * channels));

    // Lib�ration de la m�moire allou�e par stbi_load
    stbi_image_free(imgData);

    return true;
}
