#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_WIDTH 20
#define MIN_HEIGHT 10
#define MAX_WIDTH 100
#define MAX_HEIGHT 50

// 定义地图上的字符表示
#define GRASS ','
#define TREE '|'
#define WASTELAND '*'
#define LAKE '~'
#define RABBIT '#'
#define WOLF '$'

void generateRandomMap(char map[][MAX_WIDTH], int width, int height) {
    int i, j;

    // 初始化地图，用草地填充
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            map[i][j] = GRASS;
        }
    }

    // 随机生成树林
    int maxTrees = (width * height) / 2; // 不超过草地的50%
    int numTrees = rand() % (maxTrees + 1);
    for (i = 0; i < numTrees; i++) {
        int x = rand() % width;
        int y = rand() % height;
        if (map[y][x] == GRASS) {
            map[y][x] = TREE;
        }
    }

    // 随机生成荒地
    int maxWastelands = maxTrees / 2; // 不超过树林的50%
    int numWastelands = rand() % (maxWastelands + 1);
    for (i = 0; i < numWastelands; i++) {
        int x = rand() % width;
        int y = rand() % height;
        if (map[y][x] == GRASS) {
            map[y][x] = WASTELAND;
        }
    }

    // 随机生成湖泊（椭圆形）
    int maxLakes = (width * height) / 2; // 不超过草地的50%
    int numLakes = rand() % (maxLakes + 1);
    numLakes = numLakes > 2 ? 2 : numLakes; // 不超过2个湖泊
    for (i = 0; i < numLakes; i++) {
        int lakeWidth = rand() % (width / 2) + 1; // 湖泊宽度
        int lakeHeight = rand() % (height / 2) + 1; // 湖泊高度
        int x = rand() % (width - lakeWidth);
        int y = rand() % (height - lakeHeight);

        // 在湖泊区域填充~字符
        for (int m = y; m < y + lakeHeight; m++) {
            for (int n = x; n < x + lakeWidth; n++) {
                map[m][n] = LAKE;
            }
        }
    }

    // 随机生成兔子和狼
    int maxRabbits = (width * height) / (MIN_WIDTH * MIN_HEIGHT); // 至少1只兔子/最小面积
    int numRabbits = rand() % (maxRabbits - 1) + 1; // 至少1只兔子
    numRabbits = numRabbits > 3 ? 3 : numRabbits; // 不超过3只兔子
    int maxWolves = 1; // 至少1只狼
    int numWolves = rand() % maxWolves + 1; // 不超过1只狼

    // 分散放置兔子
    for (i = 0; i < numRabbits; i++) {
        int x, y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (map[y][x] != GRASS); // 确保放置在草地上
        map[y][x] = RABBIT;
    }

    // 分散放置狼
    for (i = 0; i < numWolves; i++) {
        int x, y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (map[y][x] != GRASS); // 确保放置在草地上
        map[y][x] = WOLF;
    }
}

int main() {
    srand(time(NULL));

    // 随机生成地图的宽度和高度
    int width = rand() % (MAX_WIDTH - MIN_WIDTH + 1) + MIN_WIDTH;
    int height = rand() % (MAX_HEIGHT - MIN_HEIGHT + 1) + MIN_HEIGHT;

    char map[MAX_HEIGHT][MAX_WIDTH];

    // 生成地图
    generateRandomMap(map, width, height);

    // 打印地图
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
