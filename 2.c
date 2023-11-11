#include <stdio.h>
#include <unistd.h> 

#define ROWS 20
#define COLS 20

// Функция для печати текущего поколения
void printGeneration(int generation[ROWS][COLS]) {
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
if (generation[i][j] == 0) {
printf("   "); // Неживая клетка
} else {
printf(" * "); // Живая клетка
}
}
printf("\n");
}
}

// Функция для подсчета количества соседей
int countNeighbors(int generation[ROWS][COLS], int row, int col) {
int count = 0;

// Проверка всех восьми соседних клеток
for (int i = row - 1; i <= row + 1; i++) {
for (int j = col - 1; j <= col + 1; j++) {
if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
count += generation[i][j];
}
}
}

return count;
}

// Функция для обновления поколения
void updateGeneration(int generation[ROWS][COLS]) {
int newGeneration[ROWS][COLS];

// Обновление каждой клетки
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
int neighbors = countNeighbors(generation, i, j);

// Логика игры "Жизнь"
if (generation[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
newGeneration[i][j] = 0; // Клетка умирает
} else if (generation[i][j] == 0 && neighbors == 3) {
newGeneration[i][j] = 1; // Клетка рождается
} else {
newGeneration[i][j] = generation[i][j]; // Клетка остается без изменений
}
}
}

// Копирование нового поколения в текущее поколение
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
generation[i][j] = newGeneration[i][j];
}
}
}

int main() {
int generation[ROWS][COLS];

// Инициализация начального поколения
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
generation[i][j] = rand() % 2; // Случайное заполнение клеток
}
}

// Игровой цикл
for (;;) { // Производим 10 поколений
system("clear");
printGeneration(generation);
usleep(1000000); 
printf("\n");
updateGeneration(generation);
}

return 0;
}