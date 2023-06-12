package FiveChess;

import Controller.ConnPool;
import Controller.ControlOp;
import Main.Main;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

public class ChessMenu {
    private static final int width = 772;
    private static final int height = 580;
    private static final int boardWidth = 535;
    private ControlOp controlOp;
    public JFrame chessMenu;
    public GamePanel gamePanel;
    public MessagePanel messagePanel;
    private JMenuBar bar;
    private JMenu Single, Double, Other;
    private JMenuItem start, begin, fail, stop, restart, exit, login;
    private JFrame frame = null;

    public ChessMenu(ControlOp c) {
        controlOp = c;
        chessMenu = new JFrame("五子棋");
        chessMenu.setLayout(null);
        gamePanel = new GamePanel(c);
        gamePanel.setBounds(0, 0, width - (width - boardWidth), height);
        messagePanel = new MessagePanel(c, gamePanel);
        messagePanel.setBounds(width - (width - boardWidth), 0, width - boardWidth, height);
        bar = new JMenuBar();
        Single = new JMenu("单人");
        start = new JMenuItem("开始");
        stop = new JMenuItem("结束");
        restart = new JMenuItem("重新开始");
        Single.add(start);
        Single.add(stop);
        Single.add(restart);
        Double = new JMenu("双人");
        begin = new JMenuItem("开始");
        fail = new JMenuItem("认输");
        Double.add(begin);
        Double.add(fail);
        Other = new JMenu("其他");
        login = new JMenuItem("登陆");
        exit = new JMenuItem("退出");
        Other.add(login);
        Other.add(exit);
        bar.add(Single);
        bar.add(Double);
        bar.add(Other);
        chessMenu.add(messagePanel);
        chessMenu.add(gamePanel);
        chessMenu.setJMenuBar(bar);
        chessMenu.setSize(width, height);
        chessMenu.setResizable(false);
        chessMenu.setVisible(false);
        chessMenu.setLocationRelativeTo(null);
        addEvent();
    }

    /**
     * 给按钮添加事件
     */
    private void addEvent() {
        /**
         * 单人状态下开始游戏
         */
        ActionListener startEvent = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                gamePanel.singleStart();
            }
        };
        /**
         * 双人状态下开始游戏
         */
        ActionListener beginEvent = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    controlOp.beiginPlay();
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
        };
        /**
         * 双人状态下认输
         */
        ActionListener failEvent = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (gamePanel.isNetworkPK && !gamePanel.gameOver) {
                    if (JOptionPane.showConfirmDialog(frame, "确认认输？", "系统提示", JOptionPane.YES_NO_OPTION) == 0) {
                        controlOp.sendMsg("#", 4);
                        controlOp.chessMenu.gamePanel.gameOver = true;
                        controlOp.chessMenu.gamePanel.isNetworkPK = false;
                        controlOp.chessMenu.gamePanel.refurbish();
                        controlOp.chessMenu.messagePanel.addMsg("对战失败！\n", 1);
                        ConnPool.setWar(controlOp.getUserID(), 0);
                    }
                }
            }
        };
        /**
         * 单人状态下停止游戏
         */
        ActionListener stopEvent = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                gamePanel.refurbish();
            }
        };
        /**
         * 单人状态下重新开始游戏
         */
        ActionListener restartEvent = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                gamePanel.restart();
            }
        };
        /**
         * 再次登陆一个用户
         */
        ActionListener loginEvent = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Main.myThread.createThread();
            }
        };
        /**
         * 退出
         */
        ActionListener exitEvent = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controlOp.loginOut();
            }
        };
        /**
         * 将事件加入到菜单中
         */
        start.addActionListener(startEvent);
        begin.addActionListener(beginEvent);
        fail.addActionListener(failEvent);
        stop.addActionListener(stopEvent);
        restart.addActionListener(restartEvent);
        login.addActionListener(loginEvent);
        exit.addActionListener(exitEvent);
    }
}
