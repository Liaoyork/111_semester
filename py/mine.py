import random

# 遊戲設定
board_size = 5
num_mines = 5

# 建立遊戲板
board = [[' ' for _ in range(board_size)] for _ in range(board_size)]
mines = set()

# 放置地雷
while len(mines) < num_mines:
    row = random.randint(0, board_size - 1)
    col = random.randint(0, board_size - 1)
    if (row, col) not in mines:
        mines.add((row, col))

# 遊戲主迴圈
game_over = False
while not game_over:
    # 列印遊戲板
    print("遊戲板:")
    for row in range(board_size):
        for col in range(board_size):
            if (row, col) in mines:
                print(' ', end=' ')
            else:
                print(board[row][col], end=' ')
        print()

    # 讓玩家選擇位置
    row = int(input("選擇行 (0-4): "))
    col = int(input("選擇列 (0-4): "))

    # 檢查選擇的位置是否有地雷
    if (row, col) in mines:
        print("遊戲結束！你踩到地雷！")
        game_over = True
    else:
        print("安全！繼續遊戲。")
        # 計算周圍地雷數量
        count = 0
        for i in range(max(0, row - 1), min(board_size, row + 2)):
            for j in range(max(0, col - 1), min(board_size, col + 2)):
                if (i, j) in mines:
                    count += 1
        # 更新選擇位置的數字
        board[row][col] = str(count)

    # 檢查遊戲是否勝利
    if sum(row.count(' ') for row in board) == num_mines:
        print("恭喜！你贏了遊戲！")
        game_over = True
