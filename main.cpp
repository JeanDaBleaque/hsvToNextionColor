#include <iostream>
#include <Math.h>

void HSVToRGB(float h, float s, float v, int *rgb);

int RGBToHMI(int *rgb);

int main() {
    int rgb[3];
    float h = 100, s = 0.5, v = 0.1;
    HSVToRGB(h, s, v, rgb); //Input format 0 <= h < 360; 0 <= s <= 1; 0 <= v <= 1
    std::cout << "Hue = " << h << " ,Saturation = " << s << ", Value = " << v << std::endl;
    std::cout << "Red = " << rgb[0] << ", Green = " << rgb[1] << ", Blue = " << rgb[2] << std::endl;
    std::cout << "HMI = " << RGBToHMI(rgb) << std::endl;
    return 0;
}

void HSVToRGB(float h, float s, float v, int *rgb) {
    double C = s * v;
    double X = C * (1 - (fmod(abs(h / 60), 2) - 1));
    double m = v - C;
    double RT, GT, BT;
    if (h >= 0 && h < 60) {
        RT = C;
        GT = X;
        BT = 0;
    } else if (h >= 60 && h < 120) {
        RT = X;
        GT = C;
        BT = 0;
    } else if (h >= 120 && h < 180) {
        RT = 0;
        GT = C;
        BT = X;
    } else if (h >= 180 && h < 240) {
        RT = 0;
        GT = X;
        BT = C;
    } else if (h >= 240 && h < 300) {
        RT = X;
        GT = 0;
        BT = C;
    } else if (h >= 300 && h < 360) {
        RT = C;
        GT = 0;
        BT = X;
    }
    RT = (RT + m) * 255;
    GT = (GT + m) * 255;
    BT = (BT + m) * 255;
    rgb[0] = round(RT);
    rgb[1] = round(GT);
    rgb[2] = round(BT);
}

int RGBToHMI(int *rgb) {
    return ((rgb[0] >> 3) << 11) + ((rgb[1] >> 2) << 5) + (rgb[2] >> 3);
}