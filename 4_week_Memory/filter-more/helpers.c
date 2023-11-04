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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    int redX, redY, greenX, greenY, blueX, blueY;
    // Initialize Gx and Gy metrix
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            redX = 0;
            redY = 0;
            greenX = 0;
            greenY = 0;
            blueX = 0;
            blueY = 0;

            for (int s = - 1; s < 2; s++)
            {
                // Check for upper and lower edge
                if (i + s < 0 || i + s >= height)
                    continue;

                for (int m = -1; m < 2; m++)
                {
                    // Check for right and left edge
                    if (m + j< 0 || m + j >= width)
                    continue;

                    // gX
                    redX += image[i + s][j + m].rgbtRed * Gx[s + 1][m + 1];
                    greenX += image[i + s][j + m].rgbtGreen * Gx[s + 1][m + 1];
                    blueX += image[i + s][j + m].rgbtBlue * Gx[s + 1][m + 1];

                    // gY
                    redY += image[i + s][j + m].rgbtRed * Gy[s + 1][m + 1];
                    greenY += image[i + s][j + m].rgbtGreen * Gy[s + 1][m + 1];
                    blueY += image[i + s][j + m].rgbtBlue * Gy[s + 1][m + 1];

                }

            }


            copy[i][j].rgbtRed = (BYTE) fmin(round(sqrt(redX * redX + redY * redY)), 255);
            copy[i][j].rgbtGreen = (BYTE) fmin(round(sqrt(greenX * greenX + greenY * greenY)), 255);
            copy[i][j].rgbtBlue = (BYTE) fmin(round(sqrt(blueX * blueX + blueY * blueY)), 255);
        }
    }

    // Ready to iterate whole image from copy[i][j] to image[i][j]
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}
