import array
from operator import truediv
import random

def isSafe(grid, row, col, num):
	return not UsedInRow(grid, row, num) and not UsedInCol(grid, col, num) and not UsedInBox(grid, row - row % 3, col - col % 3, num)

def UsedInRow(grid, row, num):
    for col in range(0,9):
        if grid[row][col] == num:
            return True

    return False;


def UsedInCol(grid, col, num):
    for row in range(0,9):
        if grid[row][col] == num:
            return True

    return False;

def UsedInBox(grid, boxStartRow, boxStartCol, num):
    for row in range(0,3):
        for col in range (0,3):
            if grid[row + boxStartRow][col + boxStartCol] == num:
                return True

    return False

def FindUnassignedLocation(grid, row, col):
    for row in range(0,9):
        for col in range (0,9):
            if grid[row][col] == 0:
                return [row, col]

    return -1

def generateGrid(grid):
    row = 0
    col = 0
    result = FindUnassignedLocation(grid , row, col)
    if result == -1:
        return True
    row = result[0]
    col = result[1]
    array1 = [1,2,3,4,5,6,7,8,9]
    random.shuffle(array1)
    for i in range(len(array1)):
        if isSafe(grid, row, col, array1[i]):
            grid[row][col] = array1[i]
            if generateGrid(grid):
                return True
            grid[row][col] = 0

    return False

def printSudoku(grid):
    for row in range(0,9):
        for col in range (0,9):
            print(grid[row][col], end = " ")
        print("\n")
    
def hideBlocks(emptyGrid):
    array1 = [1,2,3,4,5,6,7,8,9]
    random.shuffle(array1)
    for i in range(0,9):
        for j in range (0,2):
            temp = random.randint(0,8)
            if emptyGrid[i][temp] == 1:
                j = j -1
                continue
            else:
                emptyGrid[i][temp] = 1

def make2DArray():
    grid2 = []
    for i in range(0,9):
        inner = []
        for j in range (0,9):
            inner.append(0)
        grid2.append(inner)
    return grid2


# grid = make2DArray()
# emptyGrid = make2DArray()
# #print("hello")
# generateGrid(grid)
# hideBlocks(emptyGrid)
# printSudoku(grid)