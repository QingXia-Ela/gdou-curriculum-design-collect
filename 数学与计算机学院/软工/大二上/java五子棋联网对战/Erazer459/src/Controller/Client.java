package Controller;

import FiveChess.Chess;

import javax.swing.*;
import java.io.*;
import java.net.Socket;

public class Client {
    private ControlOp controlOp;
    private final String IP = "xxx.example.com";
    private final int PORT = 9898;  //监听9898端口
    private Socket socket;

    private BufferedReader br;
    private PrintWriter pw;

    private String userID;      //用户ID
    private String oppentID;    //对手ID

    /**
     * 初始化客户端
     *
     * @param uID 用户ID
     * @param c   主控
     */
    public Client(String uID, ControlOp c) {
        userID = uID;
        controlOp = c;
        try {
            socket = new Socket(IP, PORT);
            br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            pw = new PrintWriter(socket.getOutputStream(), true);
            pw.println("0:" + userID);    //告知服务器本线程的用户ID
            pw.flush();
            receiveMsg();   //创建接受消息线程
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    /**
     * 客户端接受信息
     */
    public void receiveMsg() {
        Runnable runnable = new Runnable() {
            String msg;

            @Override
            public void run() {
                while (true) {
                    try {
                        if (!((msg = br.readLine()) != null)) break;
                        //打印已收到的信息
                        System.out.println(userID + "收到" + msg);
                        String[] message = msg.split(":");
                        if (message[0].equals("1")) {
                            //收到对方的聊天内容
                            controlOp.chessMenu.messagePanel.addMsg(controlOp.getOpponentName() + ": " + message[3] + "\n", 3);
                        } else if (message[0].equals("2")) {
                            //收到对方下棋的指令
                            Chess.putChess(controlOp.chessMenu.gamePanel.list, Integer.valueOf(message[3]), Integer.valueOf(message[4]), Boolean.valueOf(message[5]));
                            //重画棋盘
                            controlOp.chessMenu.gamePanel.repaint();
                            controlOp.chessMenu.gamePanel.change();
                        } else if (message[0].equals("3")) {
                            //收到有关网络对战的信息
                            switch (message[3]) {
                                case "#":
                                    int n = JOptionPane.showConfirmDialog(null, "接受" + message[1] + "对战?", "对战请求", JOptionPane.YES_NO_OPTION);
                                    oppentID = message[1];
                                    controlOp.setInfo(1, oppentID, ConnPool.getName(oppentID));
                                    if (n == JOptionPane.YES_OPTION) {
                                        //在数据库中更改现在的状态是对战状态
                                        ConnPool.setWar(userID, 1);
                                        controlOp.chessMenu.messagePanel.addMsg("开始对战！\n", 1);
                                        //开启对战标志，接受对战，棋子设为白色
                                        controlOp.chessMenu.gamePanel.begin(false);
                                        //更改数据库，更改当前状态为对战状态
                                        ConnPool.setWar(userID, 1);
                                        //发送接受对战的信息
                                        sendMsg("0", 3);
                                        //设置黑棋白棋归属
                                        controlOp.chessMenu.messagePanel.setBlackText(controlOp.getOpponentName());
                                        controlOp.chessMenu.messagePanel.setWhiteText(controlOp.getUserName());
                                    } else if (n == JOptionPane.NO_OPTION) {
                                        //发送不接受对战邀请的信息
                                        sendMsg("1", 3);
                                    }
                                    break;
                                case "0":
                                    //收到对方同意对战的指令
                                    controlOp.chessMenu.messagePanel.addMsg("开始对战！\n", 1);
                                    //对方接受对战，设置自己的颜色是黑色
                                    controlOp.chessMenu.gamePanel.begin(true);
                                    //设置黑棋白棋归属
                                    controlOp.chessMenu.messagePanel.setBlackText(controlOp.getUserName());
                                    controlOp.chessMenu.messagePanel.setWhiteText(controlOp.getOpponentName());
                                    //设置当前对战状态
                                    ConnPool.setWar(userID, 1);
                                    break;
                                case "1":
                                    //收到对方不同意对战的指令
                                    JOptionPane.showMessageDialog(null, "请稍后再试");
                                    break;
                                default:
                                    System.out.println(userID + "对战内收到无归属信息");
                            }
                        } else if (message[0].equals("4")) {
                            //对方认输
                            controlOp.chessMenu.gamePanel.getFail();
                            ConnPool.setWar(userID, 0);
                            controlOp.chessMenu.messagePanel.addMsg("对战胜利！\n", 1);
                        } else if (message[0].equals("5")) {
                            //对方获胜
                            controlOp.chessMenu.gamePanel.gameOver = true;
                            controlOp.chessMenu.gamePanel.isNetworkPK = false;
                            ConnPool.setWar(userID, 0);
                            JOptionPane.showMessageDialog(null, "对战失败！");
                            controlOp.chessMenu.messagePanel.addMsg("对战失败！\n", 1);
                            controlOp.chessMenu.gamePanel.refurbish();
                        } else if (message[0].equals("6")) {
                            //平局
                            controlOp.chessMenu.gamePanel.getFail();
                            ConnPool.setWar(userID, 0);
                            controlOp.chessMenu.messagePanel.addMsg("平局！\n", 1);
                        } else {
                            System.out.println(userID + "收到无归属信息");
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                }
            }
        };
        /**
         * 开一个线程接受消息
         */
        new Thread(runnable).start();
    }

    /**
     * 发送一条信息
     *
     * @param msg  待发送信息
     * @param type 消息类型
     */
    public void sendMsg(String msg, int type) {
        String message = type + ":" + userID + ":" + oppentID + ":" + msg;
        pw.println(message);    //发送给另一个客户端，需要服务端转发
        pw.flush();
    }

    /**
     * 设置对手ID
     *
     * @param oppentID 对手ID
     */
    public void setOppentID(String oppentID) {
        this.oppentID = oppentID;
    }
}