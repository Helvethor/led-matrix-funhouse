#include <iostream>
#include <chrono>
#include <thread>
#include <boost/filesystem.hpp>
#include <boost/math/special_functions.hpp>
#include <boost/log/trivial.hpp>

#include "optionparser.h"
#include "led-matrix.h"
#include "graphics.h"

#define LOG BOOST_LOG_TRIVIAL(info)
#pragma GCC diagnostic ignored "-Wwrite-strings"


using namespace rgb_matrix;
namespace fs = boost::filesystem;
namespace bm = boost::math;



char* font_file = "/usr/share/fonts/misc/unifont.bdf";
int chains = 2;
int rows = 32;
int delay = 50;
char* message = "Sample message";


int scroll_message(int argc, char** argv) {
	int x, y, message_width, scroll_width, repeat;
	char* chr;
	Font font;

	/*
	if (!optinvoked(&message)) {
		std::cout << "Displaying sample message. Provide one as argument.\n";
	}
	*/

	if (!fs::exists(fs::path(font_file))) {
		std::cout << "Font file " << font_file << " does not exist.\n";
		return 1;
	}

	if (!font.LoadFont(font_file)) {
		std::cout << "Couldn't load font " << font_file << ".\n";
		return 1;
	}

	LOG << "1";
	GPIO io;
	if (!io.Init()) {
		std::cout << "Could not initialize GPIO.\n";
		return 1;
	}
	RGBMatrix canvas(&io, rows, chains);

	LOG << "2";
	for (chr = message; *chr; chr++) {
		message_width += font.CharacterWidth(*chr);
	}
	message_width += font.CharacterWidth(' ');
	repeat = canvas.width() / message_width + 2;
	scroll_width = message_width;
	LOG << "3";

	x = 0;
	y = (canvas.height() - font.height()) / 2 + font.baseline();
	while (true) {

		LOG << "y: " << y << ", x: " << x;
		canvas.Clear();

		for (int i = 0; i < repeat; i++) {
			DrawText(&canvas, font, -x + i * message_width, y,
				{200,25,55}, message);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(delay));

		if (++x >= scroll_width) {
			x = 0;
		}
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
