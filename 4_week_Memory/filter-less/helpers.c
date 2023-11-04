#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = (BYTE) round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = (BYTE) round(fmin((.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue), 255));
            BYTE tempd = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = (BYTE) round(fmin((.349 * temp + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue), 255));
            image[i][j].rgbtBlue = (BYTE) round(fmin((.272 * temp + .534 * tempd + .131 * image[i][j].rgbtBlue), 255));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Swapping pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];
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
            int red = 0;
            int green = 0;
            int blue = 0;
            double counter = 0;

            for (int s = i - 1; s < i + 2; s++)
            {
                // Check for upper and lower edge
                if (s < 0 || s >= height)
                    continue;

                for (int m = j - 1; m < j + 2; m++)
                {
                    // Check for right and left edge
                    if (m < 0 || m >= height)
                    continue;

                    red += copy[s][m].rgbtRed;
                    green += copy[s][m].rgbtGreen;
                    blue += copy[s][m].rgbtBlue;
                    counter++;
                }

            }


            image[i][j].rgbtRed = (BYTE) round(red / counter);
            image[i][j].rgbtGreen = (BYTE) round(green / counter);
            image[i][j].rgbtBlue = (BYTE) round(blue / counter);
        }
    }
    return;
}
