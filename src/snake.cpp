#include <iostream>

#include <boost/log/trivial.hpp>
#define LOG BOOST_LOG_TRIVIAL(info)

#include "snake.hpp"


namespace lmfsnake {

	Point2D::Point2D(int x, int y): x_(x), y_(y) {}

	Point2D::setX(int x) {x_ = x;}
	Point2D::setY(int y) {y_ = y;}


	Snake::Snake(std::queue<Point2D> points):
		points_(points), size_(points.size()) {}

	Snake::move(Direction d) {
		Point2D& front = points_.back();

		switch (d) {
			case up:
				Point2D new_point(front.getX(), front.getY() - 1);
			case down:
				Point2D new_point(front.getX(), front.getY() + 1);
			case left:
				Point2D new_point(front.getX() - 1, front.getY());
			case right:
				Point2D new_point(front.getX() + 1, front.getY());
		}

		points_.push(new_point);

		while (points_.size() > size_) {
			points_.pop();
		}
	}


	int main(int argc, char * argv[]) {
		
		std::queue<Point2D> points(Point2D(0, 0), Point2D(0, 1), Point2D(1, 1));
		Snake snake(points);
	}

}
