namespace lmfsnake {

	enum {
		up,
		down,
		left,
		right
	} Direction;

	class Point2D {

		public:

		Point2D(int x, int y);
		void setX(int x);
		void setY(int y);
		int getX(return x_);
		int getY(return y_);

		private:

		int x_;
		int y_;
	};


	class Snake {

		public:
		
		Snake(std::queue<Point2D> points);

		void move(Direction d);

		private:

		std::queue<Point2D> points_;
		size_;
	}

}
