/* SmartSnake.cpp
Algorithm: Perceptual Field
Author: BSS9395
Update: 2019-09-04T01:16 +08 @ ShenZhen +08
*/

#include <Windows.h>
#include <conio.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <queue>
#include <deque>
#include <ctime>

using namespace std;

enum Map {
	HEIGHT = 10,
	WIDTH = 15
};

struct Position {
public:
	int _h;
	int _w;

public:
	Position(int h = 0, int w = 0) {
		_h = h;
		_w = w;
	}

	Position &operator+=(const Position &rhs) {
		_h += rhs._h;
		_w += rhs._w;
		return *this;
	}

	friend bool operator==(const Position &lhs, const Position &rhs) {
		bool con1 = (lhs._h == rhs._h);
		bool con2 = (lhs._w == rhs._w);
		return (con1 && con2);
	}
};

class Scene {
public:
	const char _rep_border = '+';
	const char _rep_background = ' ';
	char _map[HEIGHT][WIDTH];

public:
	static Scene &getScene() {
		static Scene scene;
		return scene;
	}

private:
	Scene() {
		/* init scene */
		for (int h = 0; h < HEIGHT; ++h) {
			for (int w = 0; w < WIDTH; ++w) {
				if (h == 0 || h == HEIGHT - 1 || w == 0 || w == WIDTH - 1) {
					_map[h][w] = _rep_border;
				}
				else {
					_map[h][w] = _rep_background;
				}
			}
		}
	}
	Scene(const Scene &) = delete;
	Scene &operator=(const Scene &) = delete;
};

class Food {
public:
	const char _rep_body = '$';
	Position _body;

public:
	static Food &getFood() {
		static Food food;
		return food;
	}

private:
	Food()
		:_scene(Scene::getScene()) {
		/* init food */
		generateFood();
		_scene._map[_body._h][_body._w] = _rep_body;
	}

	Food(const Food &) = delete;
	Food &operator=(const Food &) = delete;

public:
	void generateFood() {
		Position pos;
		do {
			pos._h = rand() % (HEIGHT - 2) + 1;
			pos._w = rand() % (WIDTH - 2) + 1;
		} while (_scene._map[pos._h][pos._w] != _scene._rep_background);
		_body = pos;
	}

protected:
	Scene &_scene;
};

class Snake {
public:
	enum Status {
		DEAD = 0,
		PAUSE = 1,
		ALIVE = 2
	};

	enum Key {
		SPACE = 32,
		LEFT = 75,
		UP = 72,
		DOWN = 80,
		RIGHT = 77,
		ARROW = 224,
		ESC = 27
	};

	enum Direction {
		STOP = 0,
		LEFTWARD = 1,
		UPWARD = 2,
		DOWNWARD = 3,
		RIGHTWARD = 4,
		ALLWARD = 5
	};
	const char *DIRECTION[ALLWARD] = { "STOP", "LEFT", "UP", "DOWN", "RIGHT" };

	const int dD = +1;
	const int dH[ALLWARD] = { 000, 000, -dD, +dD, 000 };
	const int dW[ALLWARD] = { 000, -dD, 000, 000, +dD };

	const char _rep_head = '@';
	const char _rep_body = '*';
	const char _rep_tail = '#';

	deque<Position> _body;
	Direction _direction;
	double _field[HEIGHT][WIDTH];

	long _speed;
	int _steps;
	Status _status;
	Position _anchor[3];

public:
	static Snake &getSnake() {
		static Snake snake;
		return snake;
	}

private:
	Snake()
		:_scene(Scene::getScene()), _food(Food::getFood()) {
		/* init snake */
		_body.push_back(Position(HEIGHT / 2 + 0, WIDTH / 2));
		_body.push_back(Position(HEIGHT / 2 + 1, WIDTH / 2));
		_body.push_back(Position(HEIGHT / 2 + 2, WIDTH / 2));

		_direction = UPWARD;
		_speed = CLOCKS_PER_SEC;
		_steps = 0;
		_status = ALIVE;

		for (Position &pos : _body) {
			_scene._map[pos._h][pos._w] = _rep_body;
		}
		Position head = _body.front();
		Position tail = _body.back();
		_scene._map[head._h][head._w] = _rep_head;
		_scene._map[tail._h][tail._w] = _rep_tail;
	}

	Snake(const Snake &) = delete;
	Snake &operator=(const Snake &) = delete;

public:
	void manual() {
		_speed = CLOCKS_PER_SEC / 2;

		/* for printing info only */
		Position tail = _body.back();
		_updateField(_food._body);
		if (INFINITY <= _field[tail._h][tail._w]) {
			_updateField(tail);
		}

		/* manually choose direction */
		int kb = '\0';
		while (_kbhit()) {
			kb = _getch();
			if (kb == ARROW) {
				kb = _getch();
			}
		}
		if (kb != '\0') {
			switch (kb) {
			case SPACE:
				_status = (_status == PAUSE) ? ALIVE : PAUSE;
				return;
				break;
			case LEFT: case 'a': case 'A':
				if (_direction != RIGHTWARD) {
					_direction = LEFTWARD;
				}
				break;
			case UP: case 's': case 'S':
				if (_direction != DOWNWARD) {
					_direction = UPWARD;
				}
				break;
			case DOWN: case 'd': case 'D':
				if (_direction != UPWARD) {
					_direction = DOWNWARD;
				}
				break;
			case RIGHT: case 'f': case 'F':
				if (_direction != LEFTWARD) {
					_direction = RIGHTWARD;
				}
				break;
			case ESC:
				_status = DEAD;
				break;
			default:
				_gotoHW(HEIGHT + 2, WIDTH + 11);
				clog << "\a""  unknown direction!" << endl;
				break;
			}
		}

		/* check ahead status */
		Position ahead = _body.front();
		ahead._h += dH[_direction];
		ahead._w += dW[_direction];
		if (!_checkPosition(ahead)) {
			_status = DEAD;
		}
	}

	void automate() {
		_speed = CLOCKS_PER_SEC / 20;

		Position head = _body.front();
		Position tail = _body.back();

		Direction dir = _direction;
		Direction end = dir;
		Direction it = end;
		int dt = (rand() % 2) ? -1 : +1;

		/* if eat food then tail is reachable */
		/* eat food */
		/* choose shortest path */
		_updateField(_food._body);
		if (_field[tail._h][tail._w] < INFINITY) {
			while (it = Direction((it + dt + ALLWARD) % ALLWARD), it != end) {
				if (_field[head._h + dH[it]][head._w + dW[it]] < _field[head._h + dH[dir]][head._w + dW[dir]]) {
					dir = it;
				}
			}
		}
		else {
			/* if eat food then tail is unreachable */
			/* go after tail */
			/* choose longest path */
			_updateField(tail);
			while (it = Direction((it + dt + ALLWARD) % ALLWARD), it != end) {
				if (INFINITY <= _field[head._h + dH[dir]][head._w + dW[dir]]) {
					dir = it;
				}
				else if (_field[head._h + dH[it]][head._w + dW[it]] < INFINITY) {
					if (_field[head._h + dH[dir]][head._w + dW[dir]] < _field[head._h + dH[it]][head._w + dW[it]]) {
						dir = it;
					}
				}
			}
		}
		_direction = dir;

		/* manually change direction at any time */
		manual();
	}

	void move_with_eat() {
		if (_status != ALIVE) {
			return;
		}

		Position head = _body.front();
		Position ahead = head;
		ahead._h += dH[_direction];
		ahead._w += dW[_direction];

		_body.push_front(Position(ahead._h, ahead._w));

		/* eat food */
		if (_scene._map[ahead._h][ahead._w] == _food._rep_body) {
			if (_body.size() < (HEIGHT - 2)*(WIDTH - 2)) {
				_food.generateFood();
				_scene._map[_food._body._h][_food._body._w] = _food._rep_body;
				_gotoHW(_food._body._h, _food._body._w);
				cout << _food._rep_body;
			}
			else {
				_status = DEAD;
			}
		}
		/* move body */
		else {
			Position tail = _body.back();
			_body.pop_back();
			Position atail = _body.back();

			/* deal with tail */
			_scene._map[tail._h][tail._w] = _scene._rep_background;
			_gotoHW(tail._h, tail._w);
			cout << _scene._rep_background;

			/* deal with atail */
			_scene._map[atail._h][atail._w] = _rep_tail;
			_gotoHW(atail._h, atail._w);
			cout << _rep_tail;

			/* check endless loop */
			_steps += 1;
			if (_steps == _body.size() * 2) {
				bool con1 = (_anchor[0] == head);
				bool con2 = (_anchor[1] == tail);
				bool con3 = (_anchor[2] == _food._body);
				if (con1 && con2 && con3) {
					_status = DEAD;
				}

				_steps = 0;
				_anchor[0] = head;
				_anchor[1] = tail;
				_anchor[2] = _food._body;
			}
		}

		/* deal with head */
		_scene._map[head._h][head._w] = _rep_body;
		_gotoHW(head._h, head._w);
		cout << _rep_body;

		/* deal with ahead*/
		_scene._map[ahead._h][ahead._w] = _rep_head;
		_gotoHW(ahead._h, ahead._w);
		cout << _rep_head;
		cout << endl;
	}

	void printInfo() {
		Position head = _body.front();

		/* print field */
		for (int h = 0; h < HEIGHT; ++h) {
			_gotoHW(h, WIDTH + 2);
			for (int w = 0; w < WIDTH; ++w) {
				clog << setw(4) << _field[h][w];
			}
			clog << endl;
		}

		/* print distance */
		_gotoHW(HEIGHT + 0, WIDTH + 2);
		clog << "  TIME""  STEP""   LEN""   DIR"" PAUSE""  LEFT""    UP""  DOWN"" RIGHT" << endl;
		_gotoHW(HEIGHT + 1, WIDTH + 2);
		clog << setw(6) << setprecision(5) << double(clock()) / CLOCKS_PER_SEC;
		clog << setw(6) << _steps;
		clog << setw(6) << _body.size();
		clog << setw(6) << DIRECTION[_direction];
		clog << setw(6) << _field[head._h + dH[_direction]][head._w + dW[_direction]] + dD;
		for (Direction dir = (Direction)(STOP + 1); dir < ALLWARD; dir = (Direction)(dir + 1)) {
			clog << setw(6) << _field[head._h + dH[dir]][head._w + dW[dir]];
		}
		clog << endl << endl;
	}

protected:
	/* move console cursor */
	void _gotoHW(int h, int w) {
		COORD coord;
		coord.X = w;
		coord.Y = h;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	/* tail is the key point */
	bool _checkPosition(Position pos) {
		bool con1 = (_scene._map[pos._h][pos._w] == _scene._rep_background);
		bool con2 = (_scene._map[pos._h][pos._w] == _food._rep_body);
		bool con3 = (_scene._map[pos._h][pos._w] == _rep_tail);

		if (con1 || con2 || con3) {
			return true;
		}
		return false;
	}

	void _updateField(Position ori) {
		/* init field */
		for (int h = 0; h < HEIGHT; ++h) {
			for (int w = 0; w < WIDTH; ++w) {
				_field[h][w] = INFINITY;
			}
		}

		static queue<Position> que;
		_field[ori._h][ori._w] = 0.0;
		que.push(ori);

		/* distance == width steps + height steps */
		Position sur;
		while (!que.empty()) {
			ori = que.front();
			que.pop();
			for (Direction dir = (Direction)(STOP + 1); dir < ALLWARD; dir = (Direction)(dir + 1)) {
				sur = ori;
				sur._h += dH[dir];
				sur._w += dW[dir];
				if (_checkPosition(sur)) {
					if (_field[ori._h][ori._w] + dD < _field[sur._h][sur._w]) {
						_field[sur._h][sur._w] = _field[ori._h][ori._w] + dD;
						que.push(sur);
					}
				}
			}
		}
	}

protected:
	Scene &_scene;
	Food &_food;
};

class Game {
public:
	const char *_log_file = "snake_log.txt";

public:
	static Game &getGame() {
		static Game game;
		return game;
	}

private:
	Game()
		:_scene(Scene::getScene()), _snake(Snake::getSnake()), _food(Food::getFood()) {
		srand((unsigned)time(NULL));

		/* hide cursor */
		CONSOLE_CURSOR_INFO  cci;
		cci.dwSize = sizeof(cci);
		cci.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	}

	Game(const Game &game) = delete;
	Game &operator=(const Game &game) = delete;

public:
	void initialize() {
		static fstream ofs(_log_file, ios::in | ios::out);
		//cout.rdbuf(ofs.rdbuf());
		//clog.rdbuf(cout.rdbuf());

		system("cls");
		for (int h = 0; h < HEIGHT; ++h) {
			for (int w = 0; w < WIDTH; ++w) {
				cout << _scene._map[h][w];
			}
			cout << endl;
		}
		cout << endl;
	}

	bool status() {
		return _snake._status;
	}

	void manual() {
		_snake.printInfo();
		Sleep(_snake._speed);
		_snake.manual();
		_snake.move_with_eat();
	}

	void automate() {
		_snake.printInfo();
		Sleep(_snake._speed);
		_snake.automate();
		_snake.move_with_eat();
	}

protected:
	Scene &_scene;
	Snake &_snake;
	Food &_food;
};

int main() {
	Game &game = Game::getGame();
	game.initialize();

	do {
		//game.manual();
		game.automate();
	} while (game.status());

	system("pause");
	return 0;
}