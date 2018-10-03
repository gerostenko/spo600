#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "vol.h"
#include "lookup.h"

// Function to scale a sound sample using a volume_factor
// in the range of 0.00 to 1.00.

int main() {

	// Allocate memory for large in and out arrays
	int16_t*	in;
	int16_t*	out;

	in = (int16_t*) calloc(SAMPLES, sizeof(int16_t));
	out = (int16_t*) calloc(SAMPLES, sizeof(int16_t));

	int		x;
	int		ttl;

	// Seed the pseudo-random number generator
	srand(-1);

	// Fill the array with random data
	for (x = 0; x < SAMPLES; x++) {
		in[x] = (rand()%65536)-32768;
	}

	// ######################################
	// This is the interesting part!
	// Scale the volume of all of the samples
	for (x = 0; x < SAMPLES; x++) {
		out[x]=getLookupValue(32768+in[x]);   //lookup[32768+in[x]];
		//if (x == 100 || x == 32768 || x == 65536) {
		//printf("x=%d, in[x]=%d, out[x]=%d\n", x, in[x], out[x]);	
		//}
	}

	// ######################################

	// Sum up the data
	for (x = 0; x < SAMPLES; x++) {
		ttl = (ttl+in[x])%1000;
	}
	
	// Print the sum
	printf("Result: %d\n", ttl);

	return 0;

}

