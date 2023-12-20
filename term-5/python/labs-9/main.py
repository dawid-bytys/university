import random
import sys

import pygame

# Zaimplementować uproszczoną wersję gry Snake.
# Wąż ma rozmiar jednego kwadratu, porusza się ruchem jednostajnym w kierunku poziomym lub pionowym, zmiana kierunku (skręt) następuje po naciśnięciu kursora.
# Zabroniony jest ruch wstecz (koniec gry).
# Zakładamy, że plansza ma periodyczne warunki brzegowe.


class SnakeGame:
    def __init__(self, width, height, cell_size, fps):
        pygame.init()

        self.width = width
        self.height = height
        self.cell_size = cell_size
        self.fps = fps
        self.directions = {
            "up": (0, -1),
            "down": (0, 1),
            "left": (-1, 0),
            "right": (1, 0),
        }

        self.colors = {
            "white": (255, 255, 255),
            "red": (255, 0, 0),
            "black": (0, 0, 0),
        }
        self.score = 0

        self.screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("Snake Game")
        self.clock = pygame.time.Clock()

        self.snake = [(self.width // 2, self.height // 2)]
        self.direction = self.directions["right"]

        self.snack = self.generate_snack()

    def generate_snack(self):
        while True:
            snack = (
                random.randint(0, (self.width - self.cell_size) // self.cell_size)
                * self.cell_size,
                random.randint(0, (self.height - self.cell_size) // self.cell_size)
                * self.cell_size,
            )
            if snack not in self.snake:
                return snack

    def run(self):
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
                elif event.type == pygame.KEYDOWN:
                    if (
                        event.key == pygame.K_UP
                        and self.direction != self.directions["down"]
                    ):
                        self.direction = self.directions["up"]
                    elif (
                        event.key == pygame.K_DOWN
                        and self.direction != self.directions["up"]
                    ):
                        self.direction = self.directions["down"]
                    elif (
                        event.key == pygame.K_LEFT
                        and self.direction != self.directions["right"]
                    ):
                        self.direction = self.directions["left"]
                    elif (
                        event.key == pygame.K_RIGHT
                        and self.direction != self.directions["left"]
                    ):
                        self.direction = self.directions["right"]

            self.move()
            self.check_collision()
            self.check_snack()

            self.screen.fill(self.colors["black"])
            self.draw_snake()
            self.draw_snack()
            self.draw_score()

            pygame.display.flip()
            self.clock.tick(self.fps)

    def move(self):
        x, y = self.snake[0]
        x += self.direction[0] * self.cell_size
        y += self.direction[1] * self.cell_size

        x %= self.width
        y %= self.height

        self.snake.insert(0, (x, y))
        if len(self.snake) > 1:
            del self.snake[-1]

    def check_collision(self):
        if self.snake[0] in self.snake[1:]:
            pygame.quit()
            print(f"You lose with score {self.score}!")
            sys.exit(1)

    def check_snack(self):
        if self.snake[0] == self.snack:
            self.snake.append((0, 0))
            self.snack = self.generate_snack()
            self.score += 1

    def draw_snake(self):
        for segment in self.snake:
            pygame.draw.rect(
                self.screen,
                self.colors["white"],
                (*segment, self.cell_size, self.cell_size),
            )

    def draw_snack(self):
        pygame.draw.rect(
            self.screen,
            self.colors["red"],
            (*self.snack, self.cell_size, self.cell_size),
        )

    def draw_score(self):
        font = pygame.font.SysFont(None, 25)
        score_text = font.render(f"Score: {self.score}", True, self.colors["white"])
        self.screen.blit(score_text, (10, 10))


if __name__ == "__main__":
    game = SnakeGame(800, 600, 20, 10)
    game.run()

    sys.exit(0)
