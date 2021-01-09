/* ASCII.c
Author: BSS9395
Update: 2020-01-09T09:00:00+08@China-Guangdong-Zhanjiang+08
Design: ASCII Table
*/

static char _ASCII[128] = {
#define NUL '\0'
#define SOH 0X01
#define STX 0X02
#define ETX 0X03
#define EOT 0X04
#define ENQ 0X05
#define ACK 0X06
#define BEL '\a'
#define BS  '\b'
#define HT  '\t'
#define LF  '\n'
#define VT  '\v'
#define FF  '\f'
#define CR  '\r'
#define SO  0X0E
#define SI  0X0F
#define DLE 0X10
#define DC1 0X11
#define DC2 0X12
#define DC3 0X13
#define DC4 0X14
#define NAK 0X15
#define SYN 0X16
#define ETB 0X17
#define CAN 0X18
#define EM  0X19
#define SUB 0X1A
#define ESC '\e'
#define FS  0X1C
#define GS  0X1D
#define RS  0X1E
#define US  0X1F
#define SP  0X20
#define DEL 0X7F
     NUL,  SOH,  STX,  ETX,  EOT,  ENQ,  ACK,  BEL,   BS,   HT,   LF,   VT,   FF,   CR,   SO,   SI,
     DLE,  DC1,  DC2,  DC3,  DC4,  NAK,  SYN,  ETB,  CAN,   EM,  SUB,  ESC,   FS,   GS,   RS,   US,
      SP,  '!',  '"',  '#',  '$',  '%',  '&', '\'',  '(',  ')',  '*',  '+',  ',',  '-',  '.',  '/',
     '0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',
     '@',  'A',  'B',  'C',  'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',
     'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z',  '[', '\\',  ']',  '^',  '_',
     '`',  'a',  'b',  'c',  'd',  'e',  'f',  'g',  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
     'p',  'q',  'r',  's',  't',  'u',  'v',  'w',  'x',  'y',  'z',  '{',  '|',  '}',  '~',  DEL
};

