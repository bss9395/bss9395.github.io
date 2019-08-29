/* SmartSnake.h
Algorithm: Perceptual Field
Platform:  Windows
Author:    BSS9395
Update:    2019-08-03T20:54:00
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

typedef enum {
	ESC = 27,
	LEFT = 75,
	UP = 72,
	DOWN = 80,
	RIGHT = 77,
	ARROW = 224
} KEY;

typedef enum {
	HEIGHT = 10,
	WIDTH = 15
} MAP;

typedef enum {
	PAUSE = 0,
	LEFTWARD = 1,
	UPWARD = 2,
	DOWNWARD = 3,
	RIGHTWARD = 4,
	ALLWARD = 5
} Direction;

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
} Snake;

typedef struct {
	char rep_body;
	Position body;
} Food;

typedef struct {
	const char *log_file;
	long speed;
	bool ongoing;
	int steps;
	Position points[3];
} Status;

typedef Position Element;
typedef struct {
	int head;
	int tail;
	Element container[HEIGHT * WIDTH];
} Queue;

static void _init(Queue *self) {
	self->head = 0;
	self->tail = self->head;
}

static bool _empty(Queue *self) {
	return (self->head == self->tail);
}

static void _push(Queue *self, Element e) {
	self->container[self->tail] = e;
	self->tail++;
}

static Element _pop(Queue *self) {
	Element ret = self->container[self->head];
	self->head++;
	return ret;
}

static const char *DIRECTION[ALLWARD] = { "PAUSE", "LEFT", "UP", "DOWN", "RIGHT" };
static const int dd = +1;
static const int dh[ALLWARD] = { 00, 00, -1, +1, 00 };
static const int dw[ALLWARD] = { 00, -1, 00, 00, +1 };

static Queue _queue;
static Queue *queue = &_queue;

#endif // SmartSnake_h