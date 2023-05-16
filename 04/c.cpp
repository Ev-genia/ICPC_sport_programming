#include <iostream>

int main() {
  int roomSize;
  int ret = 1;
  int minindexI;
  int minindexJ;
  std::cin >> roomSize;
  int symbol;

  int **data = new int*[roomSize + 2];
  for (int i = 0; i < roomSize + 2; i++) {
    data[i] = new int[roomSize + 2];
    for (int j = 0; j < roomSize + 2; j++) {
      if (i == 0 || j == 0 || i == roomSize + 1 || j == roomSize + 1)
        data[i][j] = -1;
      else {
        std::cin >> symbol;
        if (symbol == 0)
          data[i][j] = -2;
        else
          data[i][j] = -1;
      }
    }
  }

  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  if (data[y1][x1] == -1 || data[y2][x2] == -1) {
    std::cout << 0 << std::endl;
    return (0);
  }
  int dx[4] = {1, 0, -1, 0};   // смещения, соответствующие соседям ячейки
  int dy[4] = {0, 1, 0, -1};   // справа, снизу, слева и сверху
  int d, x, y, k;
  bool stop = false;

  d = 0;
  data[y1][x1] = 0;
  while (!stop && data[y2][x2] == -2) {
    stop = true;
    for (y = 0; y < roomSize + 2; ++y )
      for ( x = 0; x < roomSize + 2; ++x )
        if ( data[y][x] == d )                         // ячейка (x, y) помечена числом d
        {
          for ( k = 0; k < 4; ++k )                    // проходим по всем непомеченным соседям
          {
             int iy=y + dy[k], ix = x + dx[k];
             if ( iy >= 0 && iy < roomSize + 2 && ix >= 0 && ix < roomSize + 2 && data[iy][ix] == -2 )
             {
                stop = false; 
                data[iy][ix] = d + 1;      // распространяем волну
             }
          }
        }
      d++;
  }
  if (data[y2][x2] == -2) {
    std::cout << 0 << std::endl;
    return 0;
  }
  std::cout << data[y2][x2] << std::endl;
}