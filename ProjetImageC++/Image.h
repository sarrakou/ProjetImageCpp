#pragma once
#include "stb_image.h"
#include <vector>
#include <cstdint>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;

class Image
{
private:
    unsigned int width;
    unsigned int height;
    unsigned int channels;
    std::string model;
    std::vector<unsigned char> data;

public:
    // Constructeur par défaut
    Image() : width(0), height(0), channels(0), model("NONE") {}

    // Constructeur avec dimensions, modèle et valeur de remplissage
    Image(unsigned int width, unsigned int height, unsigned int channels, const std::string& model, unsigned char fillValue)
        : width(width), height(height), channels(channels), model(model), data(width* height* channels, fillValue) {}

    // Constructeur avec dimensions, modèle et buffer
    Image(unsigned int width, unsigned int height, unsigned int channels, const std::string& model, const std::vector<unsigned char>& buffer)
        : width(width), height(height), channels(channels), model(model), data(buffer) {}

    // Règle des trois
    ~Image() {} // Destructeur
    Image(const Image& other) = default; // Constructeur de copie
    Image& operator=(const Image& other) = default; // Opérateur d'affectation

    // Getters
    unsigned int getWidth() const { return width; }
    unsigned int getHeight() const { return height; }
    unsigned int getChannels() const { return channels; }
    std::string getModel() const { return model; }

    // Setters
    void setWidth(unsigned int width) { this->width = width; }
    void setHeight(unsigned int height) { this->height = height; }
    void setChannels(unsigned int channels) { this->channels = channels; }
    void setModel(const std::string& model) { this->model = model; }

    // Fonctions at
    unsigned char at(unsigned int x, unsigned int y, unsigned int channel) const {
        if (x >= width || y >= height || channel >= channels) {
            throw std::out_of_range("Coordinates are out of bounds.");
        }
        return data[(y * width + x) * channels + channel];
    }

    unsigned char& at(unsigned int x, unsigned int y, unsigned int channel) {
        if (x >= width || y >= height || channel >= channels) {
            throw std::out_of_range("Coordinates are out of bounds.");
        }
        return data[(y * width + x) * channels + channel];
    }

    // Opérateur d'accès
    unsigned char& operator()(unsigned int x, unsigned int y, unsigned int channel) {
        checkBounds(x, y, channel);
        return data[(y * width + x) * channels + channel];
    }

    unsigned char operator()(unsigned int x, unsigned int y, unsigned int channel) const {
        checkBounds(x, y, channel);
        return data[(y * width + x) * channels + channel];
    }

    // Opérations arithmétiques
    Image operator+(const Image& other) const {
        return arithmeticOperation(other, std::plus<>());
    }

    Image& operator+=(const Image& other) {
        *this = *this + other;
        return *this;
    }

    Image operator+(unsigned char value) const {
        Image result = *this;
        for (auto& pixel : result.data) {
            int newVal = pixel + value;
            pixel = std::clamp(newVal, 0, 255);
        }
        return result;
    }

    Image& operator+=(unsigned char value) {
        *this = *this + value;
        return *this;
    }

    Image operator+(const std::vector<unsigned char>& pixelValues) const {
        if (pixelValues.size() != channels) {
            throw std::invalid_argument("Pixel channel size does not match.");
        }

        Image result = *this;
        for (size_t i = 0; i < data.size(); i += channels) {
            for (size_t c = 0; c < channels; ++c) {
                int newVal = data[i + c] + pixelValues[c];
                result.data[i + c] = std::clamp(newVal, 0, 255);
            }
        }
        return result;
    }

    Image& operator+=(const std::vector<unsigned char>& pixelValues) {
        *this = *this + pixelValues;
        return *this;
    }



    // Soustraction
    Image operator-(const Image& other) const {
        return arithmeticOperation(other, std::minus<>());
    }

    Image& operator-=(const Image& other) {
        *this = *this - other;
        return *this;
    }

    Image operator-(unsigned char value) const {
        Image result = *this;
        for (auto& pixel : result.data) {
            int newVal = pixel - value;
            pixel = std::clamp(newVal, 0, 255);
        }
        return result;
    }

    Image& operator-=(unsigned char value) {
        *this = *this - value;
        return *this;
    }

    // Supposons que le pixel est un std::vector<unsigned char> représentant les valeurs de chaque canal.
    Image operator-(const std::vector<unsigned char>& pixelValues) const {
        if (pixelValues.size() != channels) {
            throw std::invalid_argument("Pixel channel size does not match.");
        }

        Image result = *this;
        for (size_t i = 0; i < data.size(); i += channels) {
            for (size_t c = 0; c < channels; ++c) {
                int newVal = data[i + c] - pixelValues[c];
                result.data[i + c] = std::clamp(newVal, 0, 255);
            }
        }
        return result;
    }

    Image& operator-=(const std::vector<unsigned char>& pixelValues) {
        *this = *this - pixelValues;
        return *this;
    }


    //Différence : XOR
    Image operator^(const Image& other) const {
        return arithmeticOperation(other, [](unsigned char a, unsigned char b) { return a ^ b; });
    }

    Image& operator^=(const Image& other) {
        *this = *this ^ other;
        return *this;
    }

    Image operator^(unsigned char value) const {
        Image result = *this;
        for (auto& pixel : result.data) {
            pixel ^= value; // Utilise l'opérateur XOR binaire
        }
        return result;
    }

    Image& operator^=(unsigned char value) {
        *this = *this ^ value;
        return *this;
    }

    //Même logique que la soustraction mais avec la valeur absolue
    Image absoluteDifference(const std::vector<unsigned char>& pixelValues) const {
        if (pixelValues.size() != channels) {
            throw std::invalid_argument("Pixel channel size does not match.");
        }

        Image result = *this;
        for (size_t i = 0; i < data.size(); i += channels) {
            for (size_t c = 0; c < channels; ++c) {
                // Calcule la différence absolue et applique std::clamp pour rester dans les limites de [0, 255]
                int newVal = std::abs(static_cast<int>(data[i + c]) - static_cast<int>(pixelValues[c]));
                result.data[i + c] = std::clamp(newVal, 0, 255);
            }
        }
        return result;
    }



    //Multiplication
    Image operator*(float value) const {
        Image result = *this;
        for (auto& pixel : result.data) {
            int newVal = static_cast<int>(pixel * value);
            pixel = std::clamp(newVal, 0, 255);
        }
        return result;
    }

    Image& operator*=(float value) {
        *this = *this * value;
        return *this;
    }

    //Division
    Image operator/(float value) const {
        if (value == 0) throw std::runtime_error("Division by zero.");
        return *this * (1 / value);
    }

    Image& operator/=(float value) {
        *this = *this / value;
        return *this;
    }

    //Seuillage
    Image operator>(unsigned char threshold) const {
        Image result(width, height, channels, model, 0);
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = (data[i] > threshold) ? 255 : 0;
        }
        return result;
    }

    //Inversion
    Image operator~() const {
        Image result = *this;
        for (auto& pixel : result.data) {
            pixel = 255 - pixel;
        }
        return result;
    }

    // Surcharge de l'opérateur << pour l'affichage
    friend std::ostream& operator<<(std::ostream& os, const Image& img) {
        os << img.width << "x" << img.height << "x" << img.channels << " (" << img.model << ")";
        return os;
    }


    bool loadImage(const std::string& filename);
    bool saveImage(const std::string& filename, const std::string& format);

private:
    void checkBounds(unsigned int x, unsigned int y, unsigned int channel) const {
        if (x >= width || y >= height || channel >= channels) {
            throw std::out_of_range("Coordinates are out of bounds.");
        }
    }

    template<typename Op>
    Image arithmeticOperation(const Image& other, Op op) const {
        // Vérification de la compatibilité des images
        if (this->model != other.model) {
            throw std::invalid_argument("Images models do not match.");
        }

        unsigned int maxWidth = std::max(this->width, other.width);
        unsigned int maxHeight = std::max(this->height, other.height);
        unsigned int maxChannels = std::max(this->channels, other.channels);

        Image result(maxWidth, maxHeight, maxChannels, this->model, 0);

        for (unsigned int y = 0; y < maxHeight; ++y) {
            for (unsigned int x = 0; x < maxWidth; ++x) {
                for (unsigned int c = 0; c < maxChannels; ++c) {
                    unsigned char val1 = (x < this->width && y < this->height && c < this->channels) ? this->operator()(x, y, c) : 0;
                    unsigned char val2 = (x < other.width && y < other.height && c < other.channels) ? other(x, y, c) : 0;
                    result(x, y, c) = std::clamp(op(val1, val2), 0, 255);
                }
            }
        }

        return result;
    }

};

