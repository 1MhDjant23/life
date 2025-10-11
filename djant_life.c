#include "djant_life.h"

void    ft_free(char **life, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        if (life[i]) {
            free(life[i]);
            life[i] = NULL;
        }
    }
    free(life);
    life = NULL;
}

void    printLife(char **life, int w, int h) {
    for (size_t i = 0; i < h; i++)
    {
        for(size_t j = 0; j < w; j++)
        {
            putchar(life[i][j]);
        }
        putchar('\n');
    }
}



int neighbors(char **grid, int x, int y, int w, int h) {
    int neighbor = 0;

    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dx == 0 && dy == 0)
                continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < w && ny >= 0 && ny < h)
            {
                if (grid[ny][nx] == '0')
                    neighbor++;
            }
        }
    }
    return neighbor;
}

int main(int argc, char const **argv)
{
    if (argc != 4)
    {
        putchar('e');
        return 1;
    }
    int     rByte;
    char    c;
    t_data  data = {0};

    data.width = atoi(argv[1]);
    data.height = atoi(argv[2]);
    data.iterator = atoi(argv[3]);
    data.life = calloc(data.height, sizeof(char*));
    if (!data.life)
    {
        putchar('e');
        return 1;
    }
    
    // char    life[data.width][data.height];
    for (size_t i = 0; i < data.height; i++)
    {
        data.life[i] = calloc(data.width, sizeof(char));
        if (!data.life[i])
        {
            ft_free(data.life, i);
            putchar('e');
            return (1);
        }
        for (size_t j = 0; j < data.width; j++)
        {
            data.life[i][j] = ' ';
        }
    }
    printf("reading ...\n");
    int pen = 0, x = 0, y = 0;
    while ((rByte = read(STREAM, &c, 1)) > 0)
    {

        if (c == 'w' && y - 1 >= 0)
            y--;
        else if (c == 's' && y + 1 < data.height)
            y++;
        else if (c == 'd' && x + 1 < data.width)
            x++;
        else if (c == 'a' && x - 1 >= 0)
            x--;
        else if (c == 'x')
            pen = !pen;
        if (pen)
            data.life[y][x] = '0';
        // putchar(c);
    }
    // start simulation
    int neighbor = 0;
    for (size_t iter = 0; iter < data.iterator; iter++) 
    {
        char **new_grid = copy_grid(data.life, data.width, data.height);
        if (!new_grid)
        {
            ft_free(data.life, data.height);
            putchar('e');
            return 1;
        }
        for (size_t y = 0; y < data.height; y++)
        {
            for (size_t x = 0; x < data.width; x++)
            {
                neighbor = neighbors(new_grid, x, y, data.width, data.height);
                if (new_grid[y][x] == '0' && (neighbor < 2 || neighbor > 3))
                    data.life[y][x] = ' ';
                else if (new_grid[y][x] == ' ' && neighbor == 3)
                    data.life[y][x] = '0';
            }
        }
        ft_free(new_grid, data.height);
    }
    
    printLife(data.life, data.width, data.height);
    return 0;
}

char    **copy_grid(char **source, int w, int h) {
    char    **new_grid = calloc(h, sizeof(char *));
    if (!new_grid)
        return NULL;
    for (size_t n = 0; n < h; n++)
    {
        new_grid[n] = calloc(w, sizeof(char));
        if (!new_grid[n])
        {
            ft_free(new_grid, n);
            return NULL;
        }
        for (size_t i = 0; i < w; i++)
        {
            new_grid[n][i] = source[n][i];
        }
    }
    return new_grid;
}
