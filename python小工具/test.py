import pygame
import random

# 初始化遊戲
pygame.init()

# 設定遊戲視窗大小
window_width = 800
window_height = 600
window = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption('貪吃蛇遊戲')

# 定義顏色
black = pygame.Color(0, 0, 0)
white = pygame.Color(255, 255, 255)
red = pygame.Color(255, 0, 0)
green = pygame.Color(0, 255, 0)

# 設定遊戲參數
snake_position = [100, 50]
snake_body = [[100, 50], [90, 50], [80, 50]]
food_position = [random.randrange(1, (window_width // 10)) * 10,
                 random.randrange(1, (window_height // 10)) * 10]
food_spawn = True
direction = 'RIGHT'
change_to = direction
score = 0

# 設定遊戲時鐘
fps_controller = pygame.time.Clock()

# 定義遊戲結束函數
def game_over():
    font = pygame.font.SysFont('Arial', 36)
    game_over_surface = font.render('遊戲結束', True, red)
    game_over_rect = game_over_surface.get_rect()
    game_over_rect.midtop = (window_width / 2, window_height / 4)
    window.fill(black)
    window.blit(game_over_surface, game_over_rect)
    pygame.display.flip()
    pygame.time.wait(2000)
    pygame.quit()
    quit()

# 遊戲主迴圈
while True:
    # 處理事件
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT or event.key == ord('d'):
                change_to = 'RIGHT'
            if event.key == pygame.K_LEFT or event.key == ord('a'):
                change_to = 'LEFT'
            if event.key == pygame.K_UP or event.key == ord('w'):
                change_to = 'UP'
            if event.key == pygame.K_DOWN or event.key == ord('s'):
                change_to = 'DOWN'

    # 防止貪吃蛇倒退行走
    if change_to == 'RIGHT' and direction != 'LEFT':
        direction = 'RIGHT'
    if change_to == 'LEFT' and direction != 'RIGHT':
        direction = 'LEFT'
    if change_to == 'UP' and direction != 'DOWN':
        direction = 'UP'
    if change_to == 'DOWN' and direction != 'UP':
        direction = 'DOWN'

    # 根據方向移動貪吃蛇的頭部
    if direction == 'RIGHT':
        snake_position[0] += 10
    if direction == 'LEFT':
        snake_position[0] -= 10
    if direction == 'UP':
        snake_position[1] -= 10
    if direction == 'DOWN':
        snake_position[1] += 10

    # 更新貪吃蛇的身體
    snake_body.insert(0, list(snake_position))
    if snake_position[0] == food_position[0] and snake_position[1] == food_position[1]:
        score += 1
        food_spawn = False
    else:
        snake_body.pop()

    # 重新生成食物
    if food_spawn is False:
        food_position = [random.randrange(1, (window_width // 10)) * 10,
                         random.randrange(1, (window_height // 10)) * 10]
    food_spawn = True

    # 繪製遊戲視窗
    window.fill(black)
    for pos in snake_body:
        pygame.draw.rect(window, green, pygame.Rect(
            pos[0], pos[1], 10, 10))
    pygame.draw.rect(window, white, pygame.Rect(
        food_position[0], food_position[1], 10, 10))

    # 檢查碰撞
    if snake_position[0] < 0 or snake_position[0] > window_width-10:
        game_over()
    if snake_position[1] < 0 or snake_position[1] > window_height-10:
        game_over()
    for block in snake_body[1:]:
        if snake_position[0] == block[0] and snake_position[1] == block[1]:
            game_over()

    # 更新遊戲分數
    font = pygame.font.SysFont('Arial', 24)
    score_surface = font.render('分數: ' + str(score), True, white)
    score_rect = score_surface.get_rect()
    score_rect.midtop = (window_width / 10, 15)
    window.blit(score_surface, score_rect)
    pygame.display.flip()

    # 控制遊戲速度
    fps_controller.tick(20)
