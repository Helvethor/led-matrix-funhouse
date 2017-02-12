#include <iostream>
#include <chrono>
#include <thread>
#include <boost/log/trivial.hpp>

#include "optionparser.h"
#include "led-matrix.h"
#include "graphics.h"

#define LOG BOOST_LOG_TRIVIAL(info)
#pragma GCC diagnostic ignored "-Wwrite-strings"


using namespace rgb_matrix;


char* font_file = "rgbmatrix/fonts/10x20.bdf";
int chains = 2;
int rows = 32;
int delay = 50;
char* message = "Sample message";


int scroll_message(int argc, char** argv) {

	GPIO io;
	if (!io.Init()) {
		std::cout << "Could not initialize GPIO.\n";
		return 1;
	}

	RGBMatrix canvas(&io, rows, chains);

	while (true) {
		canvas.Fill(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	}


	return 0;
}


int main(int argc, char** argv) {

	/*
	OptRegister(&font_file, 'f', "font", "BSF font file");
	OptRegister(&chains, 'c', "chains", "Number of chains (columns / 32)");
	OptRegister(&rows, 'r', "rows", "Number of rows");
	OptRegister(&delay, 'd', "delay","Delay in milliseconds between two frames");
	OptRegister(&message, OPT_FLEXIBLE, "message", "Message to display");

	optVersion("1.0");
	optDisableMenu();
	optMain(scroll_message);
	opt(&argc, &argv);
	*/

	return scroll_message(argc, argv);
}
