// This is a comment in C
// At the top you include files likes this
// #include <stdlib.h> // <> means its a library
// #include "mylib.h" // "" means its your code
#include <stdio.h>
#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"
#include "live/mediaServer/DynamicRTSPServer.hh"

int main( int argc, const char* argv[] )
{
	int i;
	printf("Hello World\n\n");
	for (i = 0; i < argc; i++) {
		printf("Argument %d: %s\n", i, argv[i]);
	}
}
