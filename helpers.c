#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Calculate average
            int average = round((red + green + blue) / 3.0);

            // Set each RGB values to the average value
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Get sepia values based on sepia formula
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            // Cap values at 255 using fmin()
            // Set each RGB values to their sepia values
            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    
    for (int i = 0; i < height; i++)
    {
        // iterate through only half of the row so that the pixels only swap once
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels on opposite sides of each other
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}
void setRgb(int x, int y, int arr1[], int arr2[], int arr3[], RGBTRIPLE arr4[x][y], int i)
{
    arr1[i] = arr4[x][y].rgbtRed;
    arr2[i] = arr4[x][y].rgbtBlue;
    arr3[i] = arr4[x][y].rgbtGreen;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumRed;
    int sumBlue;
    int sumGreen;
    float total;
    
    RGBTRIPLE copy[width][height];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumRed = 0;
            sumBlue = 0;
            sumGreen = 0;
            total = 0.0;
            
            sumRed += copy[i][j].rgbtRed;
            sumBlue += copy[i][j].rgbtBlue;
            sumGreen += copy[i][j].rgbtGreen;
            total += 1.0;
            
            if (i > 0)
            {
                if (j > 0)
                {
                    sumRed += copy[i - 1][j - 1].rgbtRed;
                    sumBlue += copy[i - 1][j - 1].rgbtBlue;
                    sumGreen += copy[i - 1][j - 1].rgbtGreen;
                    total += 1.0;
                }
                
                sumRed += copy[i - 1][j].rgbtRed;
                sumBlue += copy[i - 1][j].rgbtBlue;
                sumGreen += copy[i - 1][j].rgbtGreen;
                total += 1.0;
                
                if (j < width - 1)
                {
                    sumRed += copy[i - 1][j + 1].rgbtRed;
                    sumBlue += copy[i - 1][j + 1].rgbtBlue;
                    sumGreen += copy[i - 1][j + 1].rgbtGreen;
                    total += 1.0;
                }
            }
            if (j > 0)
            {
                sumRed += copy[i][j - 1].rgbtRed;
                sumBlue += copy[i][j - 1].rgbtBlue;
                sumGreen += copy[i][j - 1].rgbtGreen;
                total += 1.0;
            }
            if (j < width - 1)
            {
                sumRed += copy[i][j + 1].rgbtRed;
                sumBlue += copy[i][j + 1].rgbtBlue;
                sumGreen += copy[i][j + 1].rgbtGreen;
                total += 1.0;
            }
            if (i < height - 1)
            {
                if (j > 0)
                {
                    sumRed += copy[i + 1][j - 1].rgbtRed;
                    sumBlue += copy[i + 1][j - 1].rgbtBlue;
                    sumGreen += copy[i + 1][j - 1].rgbtGreen;
                    total += 1.0;
                }
                
                sumRed += copy[i + 1][j].rgbtRed;
                sumBlue += copy[i + 1][j].rgbtBlue;
                sumGreen += copy[i + 1][j].rgbtGreen;
                total += 1.0;
                
                if (j < width - 1)
                {
                    sumRed += copy[i + 1][j + 1].rgbtRed;
                    sumBlue += copy[i + 1][j + 1].rgbtBlue;
                    sumGreen += copy[i + 1][j + 1].rgbtGreen;
                    total += 1.0;
                }
            }

            image[i][j].rgbtRed = round((float)sumRed / total);
            image[i][j].rgbtBlue = round((float)sumBlue / total);
            image[i][j].rgbtGreen = round((float)sumGreen / total);
        }
    }
}
