package FiveChess;

import java.awt.Color;
import java.util.List;

public class Chess {
    public static final int ROW = 15;          //棋盘行
    public static final int COL = 15;          //棋盘列
    private int x;                              //x坐标
    private int y;                              //y坐标
    private boolean color;                      //棋子颜色

    /**
     * 一个棋子实例
     *
     * @param x       横坐标
     * @param y       纵坐标
     * @param isBlack 颜色
     */
    public Chess(int x, int y, boolean isBlack) {
        this.x = x;
        this.y = y;
        this.color = isBlack;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Color getColors() {
        return color == true ? Color.BLACK : Color.WHITE;
    }


    /**
     * 判断当前位置是否可以落子
     *
     * @param x 横坐标
     * @param y 竖坐标
     * @return true表示可以，false表示不可以
     */
    public static boolean isValid(List<Chess> list, int x, int y) {
        if (x < 0 || x >= ROW || y < 0 || y >= COL) {
            return false;
        }
        if (isExist(list, x, y)) {
            return false;
        }
        return true;
    }

    /**
     * 判断当前位置是否有棋子
     *
     * @param list 棋子集合
     * @param x    横坐标
     * @param y    竖坐标
     * @return true表示存在，false表示不存在
     */
    public static boolean isExist(List<Chess> list, int x, int y) {
        for (Chess c : list) {
            if (c.getX() == x && c.getY() == y)
                return true;
        }
        return false;
    }

    /**
     * 放置棋子
     *
     * @param list  棋子集合
     * @param x     横坐标
     * @param y     竖坐标
     * @param color 颜色
     */
    public static void putChess(List<Chess> list, int x, int y, boolean color) {
        list.add(new Chess(x, y, color));
    }

    /**
     * 查找对应的棋子
     *
     * @param list  棋盘
     * @param x     横坐标
     * @param y     纵坐标
     * @param color 颜色
     * @return Chess的一个实例
     */
    private static boolean getChess(List<Chess> list, int x, int y, boolean color) {
        for (Chess c : list) {
            if (c.getX() == x && c.getY() == y && c.color == color)
                return true;
        }
        return false;
    }

    /**
     * 判断是否胜利
     *
     * @param list  棋子集合
     * @param x     横坐标
     * @param y     竖坐标
     * @param color 颜色
     * @return false
     */
    public static boolean isWin(List<Chess> list, int x, int y, boolean color) {
        //向上下左右查看是否有五子
        int count = 1;
        for (int m = x - 1; m >= 0; m--) {
            if (getChess(list, m, y, color))
                count++;
            else
                break;
        }
        for (int m = x + 1; m <= ROW; m++) {
            if (getChess(list, m, y, color))
                count++;
            else
                break;
        }
        if (count >= 5)
            return true;

        count = 1;
        for (int m = y - 1; m >= 0; m--) {
            if (getChess(list, x, m, color))
                count++;
            else break;
        }
        for (int m = y + 1; m <= COL; m++) {
            if (getChess(list, x, m, color))
                count++;
            else
                break;
        }
        if (count >= 5)
            return true;

        count = 1;
        //向斜方查看是否有五子
        int m, n;
        for (m = x - 1, n = y - 1; m >= 0 && n >= 0; m--, n--) {
            if (getChess(list, m, n, color))
                count++;
            else
                break;
        }
        for (m = x + 1, n = y + 1; m <= ROW && n <= COL; m++, n++) {
            if (getChess(list, m, n, color))
                count++;
            else
                break;
        }
        if (count >= 5)
            return true;

        count = 1;
        for (m = x + 1, n = y - 1; m <= ROW && n >= 0; m++, n--) {
            if (getChess(list, m, n, color))
                count++;
            else
                break;
        }
        for (m = x - 1, n = y + 1; m >= 0 && n <= COL; m--, n++) {
            if (getChess(list, m, n, color))
                count++;
            else
                break;
        }
        if (count >= 5)
            return true;
        return false;
    }
}
