/* Snake.c
Platform: Windows
Author:   BSS9395
Update:   2019-07-27T20:00:00
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

typedef enum {
	ESC = 27,
	LEFT = 75,
	RIGHT = 77,
	UP = 72,
	DOWN = 80,
	CTRL = 224
} KEY;

typedef enum {
	HEIGHT = 20,
	WIDTH = 60
} MAP;

typedef enum {
	PAUSE = 0,
	UPWARD = 1,
	RIGHTWARD = 2,
	DOWNWARD = 3,
	LEFTWARD = 4,
	ALLWARD = 5
} Direction;

typedef struct {
	int speed;
	bool ongoing;
	bool replay;
} Status;

typedef struct {
	char rep_border;
	char rep_background;
	char map[HEIGHT][WIDTH];
} Scene;

typedef struct {
	int h;
	int w;
} Element;

typedef struct {
	char rep_head;
	char rep_body;
	int size;
	int head;
	Element body[HEIGHT * WIDTH / 2];
	Direction direction;
	int dh[ALLWARD];
	int dw[ALLWARD];
	double distance[ALLWARD];
} Snake;

typedef struct {
	char rep_food;
	Element body;
} Food;

Status status;
Scene scene;
Snake snake;
Food food;

void _gotoHW(int h, int w) {
	COORD coord;
	coord.X = w;
	coord.Y = h;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int _iter(int index, int incr, int size) {
	return (index + incr + size) % size;
}

bool _checkStatus(Element forward) {
	Element tail = snake.body[_iter(snake.head, -1, snake.size)];
	bool con1 = (scene.map[forward.h][forward.w] == scene.rep_background);
	bool con2 = (scene.map[forward.h][forward.w] == food.rep_food);
	bool con3 = (forward.h == tail.h) && (forward.w == tail.w);
	if (con1 || con2 || con3) {
		return true;
	}
	return false;
}

void gen_food() {
	do {
		food.body.h = rand() % (HEIGHT - 2) + 1;
		food.body.w = rand() % (WIDTH - 2) + 1;
	} while (!(scene.map[food.body.h][food.body.w] == scene.rep_background));
}

void initialize() {
	/* hide cursor */
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	srand((unsigned)time(NULL));

	/* init status */
	status.speed = CLOCKS_PER_SEC / 20;

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
	int dh[ALLWARD] = { 00, -1, 00, +1, 00 };  memcpy(snake.dh, dh, ALLWARD * sizeof(*dh));
	int dw[ALLWARD] = { 00, 00, +1, 00, -1 };  memcpy(snake.dw, dw, ALLWARD * sizeof(*dw));

	snake.size = 3;
	snake.head = 0;
	snake.body[0].h = HEIGHT / 2; snake.body[0].w = WIDTH / 2 + 0;
	snake.body[1].h = HEIGHT / 2; snake.body[1].w = WIDTH / 2 + 1;
	snake.body[2].h = HEIGHT / 2; snake.body[2].w = WIDTH / 2 + 2;
	snake.direction = LEFTWARD;

	Element *beg = &snake.body[0];
	Element *end = &snake.body[snake.size];
	for (Element *it = beg; it < end; ++it) {
		if (it == beg) {
			scene.map[it->h][it->w] = snake.rep_head;
		}
		else {
			scene.map[it->h][it->w] = snake.rep_body;
		}
	}

	/* generate food */
	food.rep_food = '$';
	gen_food();
	scene.map[food.body.h][food.body.w] = food.rep_food;

	/* show scene */
	for (int h = 0; h < HEIGHT; ++h) {
		for (int w = 0; w < WIDTH; ++w) {
			putchar(scene.map[h][w]);
		}
		putchar('\n');
	}
}

double _distanceHW(Element dst, Element ori, bool check) {
	if (check) {
		if (!_checkStatus(ori)) {
			return INFINITE;
		}
	}

	double dh = dst.h - ori.h;
	double dw = dst.w - ori.w;
	return fabs(dh) + fabs(dw);
}

void automatic() {
	Element head = snake.body[snake.head];
	Element forward;
	snake.distance[PAUSE] = _distanceHW(food.body, head, false);
	for (Direction it = UPWARD; it < ALLWARD; it = (Direction)(it + 1)) {
		forward.h = head.h + snake.dh[it];
		forward.w = head.w + snake.dw[it];
		snake.distance[it] = _distanceHW(food.body, forward, true);
	}

	Direction dir = UPWARD;
	for (Direction it = (Direction)(dir + 1); it < ALLWARD; it = (Direction)(it + 1)) {
		if (snake.distance[it] < snake.distance[dir]) {
			dir = it;
		}
	}

	snake.direction = dir;
	if (snake.distance[dir] == INFINITE) {
		status.ongoing = false;
	}

	_gotoHW(HEIGHT, 0);
	char buf[BUFSIZ] = { '\0' };
	printf(" PAUSE      UP   RIGHT    DOWN    LEFT    \n");
	for (int i = 0; i < ALLWARD; ++i) {
		sprintf(buf, "%6.2lf", snake.distance[i]);
		printf("%6.6s  ", buf);
	}
}

void manual() {
	int kb = '\0';
	while (_kbhit()) {
		kb = _getch();
		if (kb == CTRL) {
			kb = _getch();
		}
		switch (kb) {
		case UP: case 's': case 'S':
			if (snake.direction != DOWNWARD) {
				snake.direction = UPWARD;
			}
			break;
		case RIGHT: case 'f': case 'F':
			if (snake.direction != LEFTWARD) {
				snake.direction = RIGHTWARD;
			}
			break;
		case DOWN: case 'd': case 'D':
			if (snake.direction != UPWARD) {
				snake.direction = DOWNWARD;
			}
			break;
		case LEFT: case 'a': case 'A':
			if (snake.direction != RIGHTWARD) {
				snake.direction = LEFTWARD;
			}
			break;
		case ESC:
			status.ongoing = false;
			break;
		default:
			_gotoHW(HEIGHT, 0);
			fprintf(stderr, "\aunknown direction.\n");
			break;
		}
	}

	Element head = snake.body[snake.head];
	head.h += snake.dh[snake.direction];
	head.w += snake.dw[snake.direction];
	if (!_checkStatus(head)) {
		status.ongoing = false;
	}
}

void move_with_eat() {
	Element head = snake.body[snake.head];
	int back = _iter(snake.head, -1, snake.size);
	Element tail = snake.body[back];

	/* move */
	scene.map[head.h][head.w] = snake.rep_body;
	_gotoHW(head.h, head.w);
	putchar(snake.rep_body);

	head.h += snake.dh[snake.direction];
	head.w += snake.dw[snake.direction];

	scene.map[head.h][head.w] = snake.rep_head;
	_gotoHW(head.h, head.w);
	putchar(snake.rep_head);

	/* eat */
	if (head.h == food.body.h && head.w == food.body.w) {
		for (int i = snake.size; snake.head < i; --i) {
			snake.body[i] = snake.body[i - 1];
		}
		snake.size += 1;
		snake.body[snake.head] = head;

		gen_food();
		scene.map[food.body.h][food.body.w] = food.rep_food;
		_gotoHW(food.body.h, food.body.w);
		putchar(food.rep_food);
		return;
	}

	scene.map[tail.h][tail.w] = scene.rep_background;
	_gotoHW(tail.h, tail.w);
	putchar(scene.rep_background);
	snake.body[back] = head;
	snake.head = back;
}

void play() {
	while (status.ongoing) {
		Sleep(status.speed);
		automatic();
		//manual();
		move_with_eat();
	}
	_gotoHW(HEIGHT + 2, 0);
	printf("game over! ");
}

int main(int argc, char *argv[]) {
	char buf[BUFSIZ] = { '\0' };
	do {
		status.ongoing = true;
		status.replay = true;

		system("cls");
		initialize();
		play();

		printf("replay(Y/N)? ");
		fflush(stdin);
		fgets(buf, BUFSIZ, stdin);
		if (!(buf[0] == 'Y' || buf[0] == 'y')) {
			status.replay = false;
		}
	} while (status.replay);

	return 0;
}