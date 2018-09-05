# Calculate-Pi
Use random DOUBLE number to calculate the value of Pi.
I am also running a program that can calculate 10,000 digits after the decimal point of Pi.
So expect it!!!

In a square with the side of that is 100, we dram a circle with the max radius. Of course, the max radius is 10.
We generate two random DOUBLE number with which we can have a pair of number (x,y) for instance. 
If the number is in the circle, the number of VARIABLE hits will be added 1.
After innumerable repetition, VARIABLE hits divide the times of repetitions and then multiply the area of the squre. 
We get the area of the circle.

	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>
	#include<Windows.h>
	#include<math.h>

	int square = 100;  // side of the square
	double x = 0;   // random point
	double y = 0;   // random point
	double r = 0.5 * square;  // radius of the circle
	int times = 10000000;  // Repeat times
	int hits = 0;  // the times that the point is in the circle
	double Pi;

	void generate_xy() {

		x = rand() % square + rand() / 100000.0;
		y = rand() % square + rand() / 100000.0;
	}

	int inCircle() {

		double d;
		d = sqrt( pow((x - r), 2) + pow((y - r), 2) );
		if (d <= r) {
			return 1;
		}
		return 0;
	}

	void main() {

		srand(time(NULL));   // seed of random number
		int count = times;
		while (count--) {
			generate_xy();
			if (inCircle() == 1) {
				hits++;
			}

		}

		Pi = double(hits) / double(times) * double(square) * double(square) / r / r;
		printf("%lf", Pi);

		Sleep(5000);
	}
