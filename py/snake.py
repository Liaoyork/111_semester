mport pygame
import random

# 初始化Pygame
pygame.init()

# 視窗大小和顏色
window_width = 800
window_height = 600
window = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption("貪吃蛇遊戲")
window.fill((0, 0, 0))

# 貪吃蛇和食物的顏色和大小
snake_color = (0, 255, 0)
food_color = (255, 0, 0)
block_size = 20

# 貪吃蛇的起始位置和移動速度
snake_x = window_width // 2
snake_y = window_height // 2
snake_speed = 10
snake_x_change = 0
snake_y_change = 0

# 食物的起始位置
food_x = round(random.randrange(0, window_width - block_size) / 10.0) * 10.0
food_y = round(random.randrange(0, window_height - block_size) / 10.0) * 10.0

# 遊戲主迴圈
running = True
while running:
    # 處理事件
        for event in pygame.event.get():
                if event.type == pygame.QUIT:
                            running = False
                                    elif event.type == pygame.KEYDOWN:
                                                if event.key == pygame.K_LEFT:
                                                                snake_x_change = -block_size
                                                                                snake_y_change = 0
                                                                                            elif event.key == pygame.K_RIGHT:
                                                                                                            snake_x_change = block_size
                                                                                                                            snake_y_change = 0
                                                                                                                                        elif event.key == pygame.K_UP:
                                                                                                                                                        snake_y_change = -block_size
                                                                                                                                                                        snake_x_change = 0
                                                                                                                                                                                    elif event.key == pygame.K_DOWN:
                                                                                                                                                                                                    snake_y_change = block_size
                                                                                                                                                                                                                    snake_x_change = 0
                                                                                                                                                                                                                        
                                                                                                                                                                                                                            # 更新貪吃蛇位置
                                                                                                                                                                                                                                snake_x += snake_x_change
                                                                                                                                                                                                                                    snake_y += snake_y_change

                                                                                                                                                                                                                                        # 檢查貪吃蛇是否吃到食物
                                                                                                                                                                                                                                            if snake_x == food_x and snake_y == food_y:
                                                                                                                                                                                                                                                    food_x = round(random.randrange(0, window_width - block_size) / 10.0) * 10.0
                                                                                                                                                                                                                                                            food_y = round(random.randrange(0, window_height - block_size) / 10.0) * 10.0

                                                                                                                                                                                                                                                                # 清空視窗
                                                                                                                                                                                                                                                                    window.fill((0, 0, 0))
                                                                                                                                                                                                                                                                        
                                                                                                                                                                                                                                                                            # 繪製貪吃蛇
                                                                                                                                                                                                                                                                                pygame.draw.rect(window, snake_color, [snake_x, snake_y, block_size, block_size])
                                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                                        # 繪製食物
                                                                                                                                                                                                                                                                                            pygame.draw.rect(window, food_color, [food_x, food_y, block_size, block_size])
                                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                                    # 更新視窗
                                                                                                                                                                                                                                                                                                        pygame.display.update()

                                                                                                                                                                                                                                                                                                        # 關閉遊戲
pygame.quit()
