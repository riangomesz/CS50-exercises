/* Filter Less Activity from CS50 week 4 */

#include "helpers.h"
#include <math.h>

//
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = (int)((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0 + 0.5);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
}

//
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            //// Covert Red
            image[i][j].rgbtRed = fmin(255, (int)(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue + 0.5));
            // Covert Green
            image[i][j].rgbtGreen = fmin(255, (int)(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue + 0.5));
            // Covert Blue
            image[i][j].rgbtBlue = fmin(255, (int)(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue + 0.5));
        }
    }
}

//
void reflect (int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j]; //
            image[i][width - 1 - j] = temp;
        }
    }
}

//
//
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0; int totalGreen = 0; int totalBlue = 0;
            float counter = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentX > (width - 1))
                    {
                        continue;
                    }
                totalRed += image[currentX][currentY].rgbtRed;
                totalGreen += image[currentX][currentY].rgbtGreen;
                totalBlue += image[currentX][currentY].rgbtBlue;

                counter++;
                }
            }

            temp[i][j].rgbtRed = round(totalRed / counter);
            temp[i][j].rgbtGreen = round(totalGreen / counter);
            temp[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];

        }
    }
    return;
}
