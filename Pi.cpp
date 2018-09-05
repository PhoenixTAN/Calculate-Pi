#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<math.h>

int square = 100;
double x = 0;
double y = 0;
double r = 0.5 * square;
int times = 10000000;
int hits = 0;
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

	srand(time(NULL));
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
