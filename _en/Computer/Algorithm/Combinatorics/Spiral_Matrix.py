''' Spiral_Matrix.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Spiral Matrix
'''

class Matrix(object):
    @staticmethod
    def _Spiral_Matrix(rank):
        matrix = [[0 for _ in range(rank)] for _ in range(rank)]
        beg_row = 0
        beg_col = 0
        number = 1

        while True:
            if rank <= 0:
                break
            elif rank == 1:
                matrix[beg_row][beg_col] = number
                break

            for col in range(beg_col, beg_col + rank - 1):
                matrix[beg_row][col] = number
                number += 1
            for row in range(beg_row, beg_row + rank - 1):
                matrix[row][beg_col + rank - 1] = number
                number += 1
            for col in range(beg_col + rank - 1, beg_col, -1):
                matrix[beg_row + rank - 1][col] = number
                number += 1
            for row in range(beg_row + rank - 1, beg_row, -1):
                matrix[row][beg_col] = number
                number += 1
            beg_row += 1
            beg_col += 1
            rank -= 2
        return matrix

if __name__ == '__main__':
    rank = 3
    matrix = Matrix._Spiral_Matrix(rank)
    for i in range(rank):
        for j in range(rank):
            print(matrix[i][j], end=' ')
        print()
