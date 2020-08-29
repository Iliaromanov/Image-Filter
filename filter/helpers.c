#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            RGBTRIPLE *pixel = &image[row][col];
            // calculating the average of the red, green, and blue values of the pixel
            int avg = (pixel->rgbtBlue + pixel->rgbtGreen + pixel->rgbtRed) / 3;
            // changing the rgb values to the avg value to mak ethe pixel a shade of gray
            pixel->rgbtBlue = avg;
            pixel->rgbtGreen = avg;
            pixel->rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
