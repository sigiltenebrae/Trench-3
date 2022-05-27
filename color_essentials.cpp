//
// Created by chris on 5/27/2022.
//
#include "color_essentials.h"

Mat black2(Mat image, Mat outline, Vec3b pixel)
{
    Mat image2, temp;
    image2 = image.clone();
    vector<Mat> channels(3);
    split(image2, channels);
    channels.at(0) = 255 - channels.at(0);
    channels.at(1) = 255 - channels.at(1);
    channels.at(2) = 255 - channels.at(2);
    threshold(channels.at(0), channels.at(0), 225, 255, THRESH_BINARY);
    threshold(channels.at(1), channels.at(1), 225, 255, THRESH_BINARY);
    threshold(channels.at(2), channels.at(2), 225, 255, THRESH_BINARY);
    bitwise_and(channels.at(0), channels.at(1), temp, outline);
    bitwise_and(temp, channels.at(2), temp, outline);
    channels.at(0) = temp - (255 - pixel.val[0]);
    channels.at(1) = temp - (255 - pixel.val[1]);
    channels.at(2) = temp - (255 - pixel.val[2]);
    merge(channels, image2);
    return image2;
}

Mat white2(Mat image, Mat outline, Vec3b pixel)
{
    Mat image2, temp;
    image2 = image.clone();
    vector<Mat> channels(3);
    split(image2, channels);
    threshold(channels.at(0), channels.at(0), 30, 255, THRESH_BINARY);
    threshold(channels.at(1), channels.at(1), 30, 255, THRESH_BINARY);
    threshold(channels.at(2), channels.at(2), 30, 255, THRESH_BINARY);
    bitwise_and(channels.at(0), channels.at(1), temp, outline);
    bitwise_and(temp, channels.at(2), temp, outline);
    channels.at(0) = temp - pixel.val[0];
    channels.at(1) = temp - pixel.val[1];
    channels.at(2) = temp - pixel.val[2];
    merge(channels, image2);
    return image2;
}

Mat neon_glow(Mat image, int gaus)
{
    RNG rng(12345);
    Mat outline; //Threshold and outline of image
    Mat image2; //Grayscale copy of image
    Mat light; //The light effect for output
    Mat relight; //Relight black
    Mat relight2; //Relight white
    Mat temp; //Temp image to get correct light value
    Mat glow; //The glow effect for output
    Mat out; //Output
    Vec3b whiteto; //Color value to replace white with
    Vec3b blackto; //Color value to replace black with
    int cannysize; //Ratio for edge detection
    int gaussize;//Ratio for gaussian blur

    whiteto = cl_cyan_white;
    blackto = cl_blue_magenta;

    cannysize = 50;
    gaussize = gaus;
    if (gaussize % 2 == 0)
    {
        gaussize -= 1;
    }
    //Edge detect
    cvtColor(image, image2, COLOR_BGR2GRAY);
    Canny(image2, outline, cannysize, cannysize * 3, 3);

    //Expand the edges
    outline = 255 - outline;
    distanceTransform(outline, outline, DIST_L2, DIST_MASK_5);
    outline = 255 - outline;
    threshold(outline, outline, 252, 255, THRESH_BINARY);
    outline.convertTo(outline, CV_8U);

    image.copyTo(light, outline);

    //Replace the black and white in the image
    relight = black2(light, outline, blackto);
    relight2 = white2(light, outline, whiteto);
    light = light + relight;
    light = light - relight2;
    light.copyTo(glow);

    //Clean the channels
    vector<Mat> channels(3);
    split(light, channels);
    channels.at(0) = channels.at(0) + 150;
    channels.at(1) = channels.at(1) + 150;
    channels.at(2) = channels.at(2) + 150;
    threshold(channels.at(0), channels.at(0), 151, 255, THRESH_TOZERO);
    threshold(channels.at(1), channels.at(1), 151, 255, THRESH_TOZERO);
    threshold(channels.at(2), channels.at(2), 151, 255, THRESH_TOZERO);
    if (gaus != 0)
    {
        merge(channels, light);
        light.copyTo(temp, outline);
        temp.copyTo(light);
        //Make the glow
        GaussianBlur(glow, glow, Size(gaussize, gaussize), 0, 0);
        glow = glow * 4;
        //Merge the glow and outline
        glow.copyTo(out, 255 - outline);
        out.convertTo(out, light.type());
        out = out + light;
    }
    else
    {
        channels.at(0) = channels.at(0) - 230;
        channels.at(1) = channels.at(1) - 230;
        channels.at(2) = channels.at(2) - 230;
        merge(channels, light);
        light.copyTo(temp, outline);
        temp.copyTo(light);
        out = light;
    }
    return out;
}

Mat neon_icon(Mat image)
{
    Mat image2, outline;
    int cannysize = 5;
    cvtColor(image, image2, COLOR_BGR2GRAY);
    Canny(image2, outline, cannysize, cannysize * 3, 3);
    namedWindow("window", WINDOW_AUTOSIZE);
    imshow("window", outline);
    return outline;
}