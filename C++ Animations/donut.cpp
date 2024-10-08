#include <iostream>
#include <cmath>
#include <cstring>
#include <chrono>
#include <thread> // Include the thread library
#include <windows.h>
#include <winbase.h>

using namespace std; // Use the entire std namespace

const int width = 80;  // Console width
const int height = 22; // Console height
const float pi = 3.14159f;

int main()
{
  float A = 0, B = 0; // Rotation angles

  float R1 = 1;                                // Radius of the circle
  float R2 = 2;                                // Radius of the donut (torus)
  float K2 = 5;                                // Distance from the viewer to the screen
  float K1 = width * K2 * 3 / (8 * (R1 + R2)); // Scaling factor

  char buffer[width * height];
  float zbuffer[width * height];
  cout << "\x1b[2J"; // Clear the console

  while (true)
  {
    // Initialize buffer and Z-buffer
    memset(buffer, ' ', width * height);
    memset(zbuffer, 0, width * height * sizeof(float));

    // Theta goes around the circle
    for (float theta = 0; theta < 2 * pi; theta += 0.07)
    {
      // Phi goes around the torus
      for (float phi = 0; phi < 2 * pi; phi += 0.02)
      {
        float cosTheta = cos(theta), sinTheta = sin(theta);
        float cosPhi = cos(phi), sinPhi = sin(phi);

        // Donut (x, y, z) coordinates before rotation
        float circleX = R2 + R1 * cosTheta;
        float circleY = R1 * sinTheta;

        // 3D (x, y, z) coordinates after rotation
        float x = circleX * (cos(B) * cosPhi + sin(A) * sin(B) * sinPhi) - circleY * cos(A) * sin(B);
        float y = circleX * (sin(B) * cosPhi - sin(A) * cos(B) * sinPhi) + circleY * cos(A) * cos(B);
        float z = K2 + cos(A) * circleX * sinPhi + circleY * sin(A);
        float ooz = 1 / z; // One over z (for perspective)

        // Project the 3D (x, y) coordinates onto the 2D plane (console screen)
        int xp = (int)(width / 2 + K1 * ooz * x);
        int yp = (int)(height / 2 - K1 * ooz * y);

        // Calculate luminance (intensity) of the point
        float L = cosPhi * cosTheta * sin(B) - cos(A) * cosTheta * sinPhi - sin(A) * sinTheta + cos(B) * (cos(A) * sinTheta - cosTheta * sin(A) * sinPhi);

        // If the point is visible (inside the screen boundaries)
        if (L > 0 && xp >= 0 && xp < width && yp >= 0 && yp < height)
        {
          int idx = xp + yp * width;
          if (ooz > zbuffer[idx])
          {
            zbuffer[idx] = ooz;
            // Select a character based on luminance (brightness)
            int luminance_index = L * 8;
            buffer[idx] = ".,-~:;=!*#$@"[luminance_index > 0 ? luminance_index : 0];
          }
        }
      }
    }

    // Output the frame
    cout << "\x1b[H"; // Reset the cursor to top-left
    for (int k = 0; k < width * height; k++)
    {
      cout << (k % width ? buffer[k] : '\n');
    }

    A += 0.04f;
    B += 0.02f;

    // Control animation speed
    // this_thread::sleep_for(chrono::milliseconds(50));
    Sleep(50);
  }

  return 0;
}

/**
 * Analysis:
 * Problem: Revolving Donut Animation
 * This program generates a 3D revolving donut animation using ASCII characters in a console.
 * It computes 3D points of a torus (donut) using parametric equations, projects them into 2D,
 * and displays them as ASCII characters. A simple z-buffer is used for handling depth.
 *
 * Time Complexity: O(n), where n is the number of points calculated in each frame.
 * Space Complexity: O(n), where n is the size of the buffer for storing the frame data.
 */
