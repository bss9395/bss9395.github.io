/* SmartSnake.c
Algorithm: Perceptual Field
Platform:  Windows
Author:    BSS9395
Update:    2019-08-03T20:54:00
*/

#include "SmartSnake.h"

Scene  scene;
Snake  snake;
Food   food;
Status status;

void _gotoHW(int h, int w) {
	COORD coord;
	coord.X = w;
	coord.Y = h;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int _iter(int index, int incr, int size) {
	return (index + incr + size) % size;
}

bool _check(Position pos) {
	bool con1 = (scene.map[pos.h][pos.w] == scene.rep_background);
	bool con2 = (scene.map[pos.h][pos.w] == food.rep_body);
	bool con3 = (scene.map[pos.h][pos.w] == snake.rep_tail);

	if (con1 || con2 || con3) {
		return true;
	}
	return false;
}

void _update_field(double field[HEIGHT][WIDTH], Position ori) {
	/* init field */
	for (int h = 0; h < HEIGHT; ++h) {
		for (int w = 0; w < WIDTH; ++w) {
			field[h][w] = INFINITY;
		}
	}

	/* calculate field */
	_init(queue);
	field[ori.h][ori.w] = 0.0;
	_push(queue, ori);

	Position sur;
	while (!_empty(queue)) {
		ori = _pop(queue);
		for (Direction dir = (Direction)(PAUSE + 1); dir < ALLWARD; dir = (Direction)(dir + 1)) {
			sur = ori;
			sur.h += dh[dir];
			sur.w += dw[dir];
			if (_check(sur)) {
				if (field[ori.h][ori.w] + dd < field[sur.h][sur.w]) {
					field[sur.h][sur.w] = field[ori.h][ori.w] + dd;
					_push(queue, sur);
				}
			}
		}
	}
}

void _generate_food() {
	Position pos;
	do {
		pos.h = rand() % (HEIGHT - 2) + 1;
		pos.w = rand() % (WIDTH - 2) + 1;
	} while (scene.map[pos.h][pos.w] != scene.rep_background);
	food.body = pos;
}

void initialize() {
	srand((unsigned)time(NULL));

	/* hide cursor */
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	/* generate scene */
	scene.rep_border = '+';
	scene.rep_background = ' ';

	for (int h = 0; h < HEIGHT; ++h) {
		for (int w = 0; w < WIDTH; ++w) {
			if (h == 0 || h == HEIGHT - 1 || w == 0 || w == WIDTH - 1) {
				scene.map[h][w] = scene.rep_border;
			}
			else {
				scene.map[h][w] = scene.rep_background;
			}
		}
	}

	/* generate snake */
	snake.rep_head = '@';
	snake.rep_body = '*';
	snake.rep_tail = '#';

	snake.size = 3;
	snake.head = 0;
	snake.body[0].h = HEIGHT / 2; snake.body[0].w = WIDTH / 2 + 0;
	snake.body[1].h = HEIGHT / 2; snake.body[1].w = WIDTH / 2 + 1;
	snake.body[2].h = HEIGHT / 2; snake.body[2].w = WIDTH / 2 + 2;
	snake.direction = (Direction)(PAUSE + 1);

	Position *beg = &snake.body[snake.head];
	Position *end = &snake.body[snake.head + snake.size];
	for (Position *it = beg; it < end; ++it) {
		scene.map[it->h][it->w] = snake.rep_body;
		if (it == beg) {
			scene.map[it->h][it->w] = snake.rep_head;
		}
		else if (it == end - 1) {
			scene.map[it->h][it->w] = snake.rep_tail;
		}
	}

	/* init food */
	food.rep_body = '$';
	_generate_food();
	scene.map[food.body.h][food.body.w] = food.rep_body;

	/* init status */
	status.log_file = "snake_log.txt";
	//freopen(status.log_file, "w", stderr);
	status.speed = CLOCKS_PER_SEC / 20;
	status.ongoing = true;
	status.steps = 0;


	/* show scene */
	system("cls");
	for (int h = 0; h < HEIGHT; ++h) {
		for (int w = 0; w < WIDTH; ++w) {
			fputc(scene.map[h][w], stderr);
		}
		fputc('\n', stderr);
	}
	fputc('\n', stderr);
	fflush(stderr);
}

void manual() {
	status.speed = CLOCKS_PER_SEC / 2;

	while (_kbhit()) {
		int kb = _getch();
		if (kb == ARROW) {
			kb = _getch();
		}
		switch (kb) {
		case LEFT: case 'a': case 'A':
			if (snake.direction != RIGHTWARD) {
				snake.direction = LEFTWARD;
			}
			break;
		case UP: case 's': case 'S':
			if (snake.direction != DOWNWARD) {
				snake.direction = UPWARD;
			}
			break;
		case DOWN: case 'd': case 'D':
			if (snake.direction != UPWARD) {
				snake.direction = DOWNWARD;
			}
			break;
		case RIGHT: case 'f': case 'F':
			if (snake.direction != LEFTWARD) {
				snake.direction = RIGHTWARD;
			}
			break;
		case ESC:
			status.ongoing = false;
			break;
		default:
			_gotoHW(HEIGHT + 2, WIDTH + 11);
			fprintf(stderr, "\a""  unknown direction!\n");
			break;
		}
	}

	/* check status */
	Position ahead = snake.body[snake.head];
	ahead.h += dh[snake.direction];
	ahead.w += dw[snake.direction];
	if (!_check(ahead)) {
		status.ongoing = false;
	}
}

void automate() {
	status.speed = CLOCKS_PER_SEC / 20;

	Position head = snake.body[snake.head];
	Position tail = snake.body[_iter(snake.head, -1, snake.size)];

	Direction dir = snake.direction;
	Direction end = dir;
	Direction it = end;
	int dt = (rand() % 2) ? -1 : +1;

	/* if eat food then tail is reachable */
	/* choose shortest path */
	_update_field(snake.field, food.body);
	if (snake.field[tail.h][tail.w] < INFINITY) {
		while (it = (Direction)((it + dt + ALLWARD) % ALLWARD), it != end) {
			if (snake.field[head.h + dh[it]][head.w + dw[it]] < snake.field[head.h + dh[dir]][head.w + dw[dir]]) {
				dir = it;
			}
		}
	}
	/* if eat food then tail is unreachable */
	else {
		/* go after tail */
		/* choose longest path */
		_update_field(snake.field, tail);
		while (it = (Direction)((it + dt + ALLWARD) % ALLWARD), it != end) {
			if (INFINITY <= snake.field[head.h + dh[dir]][head.w + dw[dir]]) {
				dir = it;
			}
			else if (snake.field[head.h + dh[it]][head.w + dw[it]] < INFINITY) {
				if (snake.field[head.h + dh[dir]][head.w + dw[dir]] < snake.field[head.h + dh[it]][head.w + dw[it]]) {
					dir = it;
				}
			}
		}
	}

	/* manually change direction at any time */
	manual();
}

void move_with_eat() {
	Position head = snake.body[snake.head];
	Position ahead = head;
	ahead.h += dh[snake.direction];
	ahead.w += dw[snake.direction];

	/* eat */
	if (scene.map[ahead.h][ahead.w] == food.rep_body) {
		for (int i = snake.size; snake.head < i; --i) {
			snake.body[i] = snake.body[i - 1];
		}
		snake.body[snake.head] = ahead;
		snake.size += 1;

		/* generate food */
		if (snake.size < (HEIGHT - 2)*(WIDTH - 2)) {
			_generate_food();
			scene.map[food.body.h][food.body.w] = food.rep_body;
			_gotoHW(food.body.h, food.body.w);
			putchar(food.rep_body);
		}
		else {
			status.ongoing = false;
		}
	}
	/* move */
	else {
		int back = _iter(snake.head, -1, snake.size);
		int aback = _iter(back, -1, snake.size);
		Position tail = snake.body[back];
		Position atail = snake.body[aback];

		/* deal with tail */
		scene.map[tail.h][tail.w] = scene.rep_background;
		_gotoHW(tail.h, tail.w);
		putchar(scene.rep_background);

		scene.map[atail.h][atail.w] = snake.rep_tail;
		_gotoHW(atail.h, atail.w);
		putchar(snake.rep_tail);

		snake.body[back] = ahead;
		snake.head = back;

		/* check endless loop */
		status.steps += 1;
		if (snake.size * 2 == status.steps) {
			bool con1 = (status.points[0].h == head.h && status.points[0].w == head.w);
			bool con2 = (status.points[1].h == tail.h && status.points[1].w == tail.w);
			bool con3 = (status.points[2].h == food.body.h && status.points[2].w == food.body.w);
			if (con1 && con2 && con3) {
				status.ongoing = false;
			}

			status.steps = 0;
			status.points[0] = head;
			status.points[1] = tail;
			status.points[2] = food.body;
		}
	}

	/* deal with head */
	scene.map[head.h][head.w] = snake.rep_body;
	_gotoHW(head.h, head.w);
	putchar(snake.rep_body);

	scene.map[ahead.h][ahead.w] = snake.rep_head;
	_gotoHW(ahead.h, ahead.w);
	putchar(snake.rep_head);

	/* print field */
	for (int h = 0; h < HEIGHT; ++h) {
		_gotoHW(h, WIDTH + 2);
		for (int w = 0; w < WIDTH; ++w) {
			fprintf(stderr, "%4.0lf", snake.field[h][w]);
		}
		fprintf(stderr, "\n");
	}

	/* print distance */
	_gotoHW(HEIGHT + 0, WIDTH);
	fprintf(stderr, "  STEP""   LEN""   DIR"" PAUSE""  LEFT""    UP""  DOWN"" RIGHT""\n");
	_gotoHW(HEIGHT + 1, WIDTH);
	fprintf(stderr, "%6.0d", status.steps);
	fprintf(stderr, "%6.0d", snake.size);
	fprintf(stderr, "%6.6s", DIRECTION[snake.direction]);
	fprintf(stderr, "%6.0lf", dd + snake.field[head.h + dh[snake.direction]][head.w + dw[snake.direction]]);
	for (Direction dir = (Direction)(PAUSE + 1); dir < ALLWARD; dir = (Direction)(dir + 1)) {
		fprintf(stderr, "%6.0lf", snake.field[head.h + dh[dir]][head.w + dw[dir]]);
	}
	fprintf(stderr, "\n\n");
	fflush(stderr);
}

int main() {
	initialize();
	do {
		Sleep(status.speed);
		// manual();
		automate();
		move_with_eat();
	} while (status.ongoing);
	_gotoHW(HEIGHT + 2, WIDTH);
	printf("  game over!\n");

	system("pause");
	return 0;
}