-----
ABOUT
-----
The goal of this project is to study the effect of parallelization on the construction
of images from a Mandelbrot set. mandel uses multi-threading to make each individual
process in creating the image faster whereas mandelmovie uses parallel processing
to run mandel 50 times with higher throughput.

------------ 
INSTRUCTIONS
------------
Included is a Makefile that will compile both mandel and mandelmovie.

 1) The pre-provided mandel.exe constructs an image from the Mandelbrot set given certain parameters.
   - Use the -n flag to specify the number of threads. If not specified, 1 thread will be used.
   - Use the -h flag to see all of its command line options.

 2) Mandelmovie will run mandel 50 times and output 50 .bmp files that can be stitched together to
    create a video using ffmpeg (which is also provided).

To create a .mpg video, perform the following:
	ffmpeg -i mandel%d.bmp mandel.mpg
	ffplay mandel.mpg