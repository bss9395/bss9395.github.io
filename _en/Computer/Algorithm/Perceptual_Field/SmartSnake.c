/* SmartSnake.c
Algorithm: Perceptual Field
Platform:  Windows
Author:    BSS9395
Update:    2019-09-04T10:48:00 +08 @ ShenZhen +08
*/

#ifndef SmartSnake_h
#define SmartSnake_h

#include <Windows.h>
#include <conio.h>

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#ifndef INFINITY
#define INFINITY   ((float)(1e+300 * 1e+300))
#endif

typedef enum {
	HEIGHT = 10,
	WIDTH = 15
} MAP;

typedef enum {
	SPACE = 32,
	LEFT = 75,
	UP = 72,
	DOWN = 80,
	RIGHT = 77,
	ARROW = 224,
	ESC = 27,
} KEY;

typedef enum {
	STOP = 0,
	LEFTWARD = 1,
	UPWARD = 2,
	DOWNWARD = 3,
	RIGHTWARD = 4,
	ALLWARD = 5
} Direction;

typedef enum {
	DEAD = 0,
	PAUSE = 1,
	ALIVE = 2
} Status;

typedef struct {
	int h;
	int w;
} Position;

typedef struct {
	char rep_border;
	char rep_background;
	char map[HEIGHT][WIDTH];
} Scene;

typedef struct {
	char rep_head;
	char rep_body;
	char rep_tail;
	int size;
	int head;
	Position body[HEIGHT * WIDTH];
	Direction direction;
	double field[HEIGHT][WIDTH];

	long speed;
	Status status;
	int steps;
	Position anchor[3];
} Snake;

typedef struct {
	char rep_body;
	Position body;
} Food;

typedef struct {
	const char *log_file;
} Game;

typedef Position Element;
typedef struct {
	int head;
	int tail;
	Element container[HEIGHT * WIDTH];
} Queue;

static Queue _makeQueue() {
	static Queue queue;
	queue.head = 0;
	queue.tail = queue.head;
	return queue;
}

static bool _emptyQueue(Queue *self) {
	return (self->head == self->tail);
}

static void _pushQueue(Queue *self, Element element) {
	self->container[self->tail] = element;
	self->tail++;
}

static Element _popQueue(Queue *self) {
	Element element = self->container[self->head];
	self->head++;
	return element;
}

static const int dD = +1;
static const int dH[ALLWARD] = { 00, 00, -1, +1, 00 };
static const int dW[ALLWARD] = { 00, -1, 00, 00, +1 };
static const char *DIRECTION[ALLWARD] = { "STOP", "LEFT", "UP", "DOWN", "RIGHT" };

#endif // SmartSnake_h

Scene scene;
Snake snake;
Food  food;
Game  game;

void _gotoHW(int h, int w) {
	COORD coord;
	coord.X = w;
	coord.Y = h;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int _iter(int index, int incr, int size) {
	return (index + incr + size) % size;
}

/* tail is the key point */
bool _checkPosition(Position pos) {
	bool con1 = (scene.map[pos.h][pos.w] == scene.rep_background);
	bool con2 = (scene.map[pos.h][pos.w] == food.rep_body);
	bool con3 = (scene.map[pos.h][pos.w] == snake.rep_tail);

	if (con1 || con2 || con3) {
		return true;
	}
	return false;
}

void _updateField(Position ori) {
	/* init field */
	for (int h = 0; h < HEIGHT; ++h) {
		for (int w = 0; w < WIDTH; ++w) {
			snake.field[h][w] = INFINITY;
		}
	}

	Queue queue = _makeQueue();
	snake.field[ori.h][ori.w] = 0.0;
	_pushQueue(&queue, ori);

	/* distance == width steps + height steps */
	Position sur;
	while (!_emptyQueue(&queue)) {
		ori = _popQueue(&queue);
		for (Direction dir = (Direction)(STOP + 1); dir < ALLWARD; dir = (Direction)(dir + 1)) {
			sur = ori;
			sur.h += dH[dir];
			sur.w += dW[dir];
			if (_checkPosition(sur)) {
				if (snake.field[ori.h][ori.w] + dD < snake.field[sur.h][sur.w]) {
					snake.field[sur.h][sur.w] = snake.field[ori.h][ori.w] + dD;
					_pushQueue(&queue, sur);
				}
			}
		}
	}
}

void _generateFood() {
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
	snake.body[0].h = HEIGHT / 2 + 0; snake.body[0].w = WIDTH / 2;
	snake.body[1].h = HEIGHT / 2 + 1; snake.body[1].w = WIDTH / 2;
	snake.body[2].h = HEIGHT / 2 + 2; snake.body[2].w = WIDTH / 2;
	snake.direction = UPWARD;

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

	snake.speed = CLOCKS_PER_SEC / 20;
	snake.status = ALIVE;
	snake.steps = 0;

	/* init food */
	food.rep_body = '$';
	_generateFood();
	scene.map[food.body.h][food.body.w] = food.rep_body;

	/* init status */
	game.log_file = "snake_log.txt";
	//freopen(status.log_file, "w", stderr);

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

void printInfo() {
	Position head = snake.body[snake.head];

	/* print field */
	for (int h = 0; h < HEIGHT; ++h) {
		_gotoHW(h, WIDTH + 2);
		for (int w = 0; w < WIDTH; ++w) {
			fprintf(stderr, "%4.0lf", snake.field[h][w]);
		}
		fprintf(stderr, "\n");
	}

	/* print distance */
	_gotoHW(HEIGHT + 0, WIDTH + 2);
	fprintf(stderr, "  TIME""  STEP""   LEN""   DIR"" PAUSE""  LEFT""    UP""  DOWN"" RIGHT""\n");
	_gotoHW(HEIGHT + 1, WIDTH + 2);
	fprintf(stderr, "%6.2lf", (double)clock() / CLOCKS_PER_SEC);
	fprintf(stderr, "%6.0d", snake.steps);
	fprintf(stderr, "%6.0d", snake.size);
	fprintf(stderr, "%6.6s", DIRECTION[snake.direction]);
	fprintf(stderr, "%6.0lf", dD + snake.field[head.h + dH[snake.direction]][head.w + dW[snake.direction]]);
	for (Direction dir = (Direction)(STOP + 1); dir < ALLWARD; dir = (Direction)(dir + 1)) {
		fprintf(stderr, "%6.0lf", snake.field[head.h + dH[dir]][head.w + dW[dir]]);
	}
	fprintf(stderr, "\n\n");
	fflush(stderr);
}

void manual() {
	snake.speed = CLOCKS_PER_SEC / 2;

	/* for printing info only */
	int back = _iter(snake.head, -1, snake.size);
	Position tail = snake.body[back];
	_updateField(food.body);
	if (INFINITY <= snake.field[tail.h][tail.w]) {
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
			snake.status = (snake.status == PAUSE) ? ALIVE : PAUSE;
			return;
			break;
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
			snake.status = DEAD;
			break;
		default:
			_gotoHW(HEIGHT + 2, WIDTH + 11);
			fprintf(stderr, "\a""  unknown direction!\n");
			break;
		}
	}

	/* check status */
	Position ahead = snake.body[snake.head];
	ahead.h += dH[snake.direction];
	ahead.w += dW[snake.direction];
	if (!_checkPosition(ahead)) {
		snake.status = DEAD;
	}
}

void automate() {
	snake.speed = CLOCKS_PER_SEC / 20;

	Position head = snake.body[snake.head];
	Position tail = snake.body[_iter(snake.head, -1, snake.size)];

	Direction dir = snake.direction;
	Direction end = dir;
	Direction it = end;
	int dt = (rand() % 2) ? -1 : +1;

	/* if eat food then tail is reachable */
	/* eat food */
	/* choose shortest path */
	_updateField(food.body);
	if (snake.field[tail.h][tail.w] < INFINITY) {
		while (it = (Direction)((it + dt + ALLWARD) % ALLWARD), it != end) {
			if (snake.field[head.h + dH[it]][head.w + dW[it]] < snake.field[head.h + dH[dir]][head.w + dW[dir]]) {
				dir = it;
			}
		}
	}
	else {
		/* if eat food then tail is unreachable */
		/* go after tail */
		/* choose longest path */
		_updateField(tail);
		while (it = (Direction)((it + dt + ALLWARD) % ALLWARD), it != end) {
			if (INFINITY <= snake.field[head.h + dH[dir]][head.w + dW[dir]]) {
				dir = it;
			}
			else if (snake.field[head.h + dH[it]][head.w + dW[it]] < INFINITY) {
				if (snake.field[head.h + dH[dir]][head.w + dW[dir]] < snake.field[head.h + dH[it]][head.w + dW[it]]) {
					dir = it;
				}
			}
		}
	}
	snake.direction = dir;

	/* manually change direction */
	manual();
}

void move_with_eat() {
	if (snake.status != ALIVE) {
		return;
	}

	Position head = snake.body[snake.head];
	Position ahead = head;
	ahead.h += dH[snake.direction];
	ahead.w += dW[snake.direction];

	/* eat food */
	if (scene.map[ahead.h][ahead.w] == food.rep_body) {
		for (int i = snake.size; snake.head < i; --i) {
			snake.body[i] = snake.body[i - 1];
		}
		snake.body[snake.head] = ahead;
		snake.size += 1;

		/* generate food */
		if (snake.size < (HEIGHT - 2)*(WIDTH - 2)) {
			_generateFood();
			scene.map[food.body.h][food.body.w] = food.rep_body;
			_gotoHW(food.body.h, food.body.w);
			putchar(food.rep_body);
		}
		else {
			snake.status = DEAD;
		}
	}
	/* move body */
	else {
		int back = _iter(snake.head, -1, snake.size);
		int aback = _iter(back, -1, snake.size);
		Position tail = snake.body[back];
		Position atail = snake.body[aback];

		/* deal with tail */
		scene.map[tail.h][tail.w] = scene.rep_background;
		_gotoHW(tail.h, tail.w);
		putchar(scene.rep_background);

		/* deal with atail */
		scene.map[atail.h][atail.w] = snake.rep_tail;
		_gotoHW(atail.h, atail.w);
		putchar(snake.rep_tail);

		snake.body[back] = ahead;
		snake.head = back;

		/* check endless loop */
		snake.steps += 1;
		if (snake.size * 2 == snake.steps) {
			bool con1 = (snake.anchor[0].h == head.h && snake.anchor[0].w == head.w);
			bool con2 = (snake.anchor[1].h == tail.h && snake.anchor[1].w == tail.w);
			bool con3 = (snake.anchor[2].h == food.body.h && snake.anchor[2].w == food.body.w);
			if (con1 && con2 && con3) {
				snake.status = DEAD;
			}

			snake.steps = 0;
			snake.anchor[0] = head;
			snake.anchor[1] = tail;
			snake.anchor[2] = food.body;
		}
	}

	/* deal with head */
	scene.map[head.h][head.w] = snake.rep_body;
	_gotoHW(head.h, head.w);
	putchar(snake.rep_body);

	/* deal with ahead */
	scene.map[ahead.h][ahead.w] = snake.rep_head;
	_gotoHW(ahead.h, ahead.w);
	putchar(snake.rep_head);
}

int main() {
	initialize();
	do {
		printInfo();
		Sleep(snake.speed);
		//manual();
		automate();
		move_with_eat();
	} while (snake.status);
	printf("game over!\n");

	system("pause");
	return 0;
}