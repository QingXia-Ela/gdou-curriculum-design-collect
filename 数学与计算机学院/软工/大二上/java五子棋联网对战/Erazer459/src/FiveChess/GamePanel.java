package FiveChess;

import Controller.ConnPool;
import Controller.ControlOp;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.LinkedList;
import java.util.List;

public class GamePanel extends JPanel {
    /**
     * const
     */
    private static final int SPAN = 35;        //棋盘格子宽度
    private static final int MARGIN = 22;      //边界空白
    private static final int DIAMETER = 35;    //直径
    /**
     * variable
     */
    private ControlOp controlOp;
    private boolean color = true;
    private ImageIcon img = new ImageIcon("src/images/board.jpg");
    public List<Chess> list = new LinkedList<Chess>();
    public boolean gameOver = true;         // 默认结束游戏
    public boolean isNetworkPK = false;     //网络对战
    public boolean myChessColor = false;    //记录我方落子的颜色

    public GamePanel(ControlOp controlOp) {
        /**
         * 派生于JPanel，给自己添加鼠标事件
         */
        this.controlOp = controlOp;
        this.addMouseEvent(this);
    }

    /**
     * 重写paint方法
     *
     * @param g 图
     */
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2 = (Graphics2D) g;
        /**
         * 棋盘
         */
        g.drawImage(img.getImage(), 1, 0, null);
        /**
         * 画棋子
         */
        RadialGradientPaint rgp;
        for (int i = 0; i < list.size(); i++) {
            Chess chess = list.get(i);
            int xPos = chess.getX() * SPAN + MARGIN;
            int yPos = chess.getY() * SPAN + MARGIN;    //将真实坐标转换成网格坐标
            g2.setColor(chess.getColors());             //设置画笔颜色
            if (chess.getColors() == Color.BLACK) {
                rgp = new RadialGradientPaint(xPos - DIAMETER / 2 + 26, //
                        yPos - DIAMETER / 2 + 12, 20, new float[]{0.0f, 1.0f}, //
                        new Color[]{Color.WHITE, Color.BLACK});
            } else {
                rgp = new RadialGradientPaint(xPos - DIAMETER / 2 + 25, //
                        yPos - DIAMETER / 2 - 30, 60, new float[]{0f, 1.0f}, //
                        new Color[]{Color.BLACK, Color.WHITE});
            }
            g2.setPaint(rgp);
            //去锯齿
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2.setRenderingHint(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_DEFAULT);
            g2.fillOval(xPos - DIAMETER / 2, yPos - DIAMETER / 2, SPAN - 1, SPAN);
            //画红色矩形
            g2.setColor(Color.RED);
            if (i == list.size() - 1)
                g2.draw3DRect(xPos - DIAMETER / 2 - 1, yPos - DIAMETER / 2 - 1, SPAN, SPAN + 1, true);
        }
    }

    /**
     * 添加鼠标事件
     *
     * @param panel panel
     */
    private void addMouseEvent(JPanel panel) {
        /**
         * 添加鼠标点击事件
         */
        MouseAdapter onPressed = new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                super.mousePressed(e);
                /**
                 * 游戏是否结束
                 */
                if (!gameOver) {
                    /**
                     * 转换鼠标坐标
                     */
                    int x = (e.getX() - MARGIN + SPAN / 2) / SPAN;
                    int y = (e.getY() - MARGIN + SPAN / 2) / SPAN;
                    /**
                     * 是否可以下棋
                     */
                    if (Chess.isValid(list, x, y) && !Chess.isExist(list, x, y)) {
                        /**
                         * 对决为自己或者非对决
                         */
                        if (!isNetworkPK) {
                            Chess.putChess(list, x, y, color);
                            panel.repaint();
                            if (Chess.isWin(list, x, y, color) || list.size() == Chess.ROW * Chess.COL) {
                                gameOver = true;
                                JOptionPane.showMessageDialog(null, "游戏结束！");
                                refurbish();
                            }
                            change();
                        } else if (isNetworkPK && color == myChessColor) {
                            Chess.putChess(list, x, y, color);
                            panel.repaint();
                            /**
                             * 给对方发送下棋的信息
                             */
                            controlOp.sendMsg(x + ":" + y + ":" + color, 2);
                            /**
                             * 判断是否胜利
                             */
                            if (Chess.isWin(list, x, y, color)) {
                                JOptionPane.showMessageDialog(null, "对战胜利！");
                                //发送获胜消息
                                controlOp.sendMsg("#", 5);
                                gameOver = true;
                                isNetworkPK = false;
                                refurbish();
                                ConnPool.setWar(controlOp.getUserID(), 0);
                                controlOp.chessMenu.messagePanel.addMsg("对战胜利！\n", 1);
                            } else if (list.size() == Chess.ROW * Chess.COL) {
                                JOptionPane.showMessageDialog(null, "平局！");
                                //发送平局消息
                                controlOp.sendMsg("#", 6);
                                gameOver = true;
                                isNetworkPK = false;
                                refurbish();
                                ConnPool.setWar(controlOp.getUserID(), 0);
                                controlOp.chessMenu.messagePanel.addMsg("平局！\n", 1);
                            } else {
                                change();
                            }
                        }
                    }
                }
            }
        };
        panel.addMouseListener(onPressed);
        /**
         * 添加鼠标移动变化事件
         */
        MouseAdapter onMove = new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                super.mouseMoved(e);
                if (gameOver)
                    return;
                int x = (e.getX() - MARGIN + SPAN / 2) / SPAN;
                int y = (e.getY() - MARGIN + SPAN / 2) / SPAN;
                if (x < 0 || x >= Chess.ROW || y < 0 || y >= Chess.COL) {
                    return;
                }
                if (Chess.isExist(list, x, y))
                    panel.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
                else
                    panel.setCursor(new Cursor(Cursor.HAND_CURSOR));
            }
        };
        panel.addMouseMotionListener(onMove);
    }

    /**
     * 重画棋盘且游戏结束状态
     */
    public void refurbish() {
        if (!gameOver && isNetworkPK) {
            JOptionPane.showMessageDialog(null, "对战状态无法结束游戏");
        }
        list.clear();
        gameOver = true;
        color = true;
        this.repaint();
    }

    /**
     * 非对决开始
     */
    public void singleStart() {
        if (!isNetworkPK && gameOver) {
            list.clear();
            gameOver = false;
            color = true;
            this.repaint();
        }
    }

    /**
     * 非对决重新开始
     */
    public void restart() {
        if (!isNetworkPK) {
            list.clear();
            gameOver = false;
            color = true;
            this.repaint();
        }
    }

    /**
     * 对决开始
     */
    public void begin(boolean myColor) {
        isNetworkPK = true;
        list.clear();
        gameOver = false;
        color = true;
        myChessColor = myColor;
        this.repaint();
    }

    /**
     * 改变当前的下棋手
     */
    public void change() {
        color = !color;
    }

    /**
     * 处理对方认输的情况
     */
    public void getFail() {
        JOptionPane.showMessageDialog(null, "对方认输");
        gameOver = true;
        isNetworkPK = false;
        refurbish();
    }
}
