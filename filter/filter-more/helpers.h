#include "bmp.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
      for (int i = 0; i < height; i++)
      {
            for (int j = 0; j < width; j++)
            {
                  // Make black pixels turn red
                  if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
                  {
                        image[i][j].rgbtRed = 0xff;
                        image[i][j].rgbtBlue = 0xff;
                        image[i][j].rgbtGreen = 0xff;
                  }
                  else
                  {
                        image[i][j].rgbtRed = 0x00;
                        image[i][j].rgbtBlue = 0x00;
                        image[i][j].rgbtGreen = 0x00;
                  }
            }
      }
};
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);
