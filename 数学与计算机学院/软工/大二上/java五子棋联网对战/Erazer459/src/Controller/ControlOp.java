package Controller;

import FiveChess.ChessMenu;
import FiveChess.Login;
import FiveChess.Regist;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

public class ControlOp {
    private ControlOp controlOp;    //本类
    public Login loginView;         //注册界面
    public Regist registView;       //登陆界面
    public ChessMenu chessMenu;     //下棋界面

    private String userID;          //用户ID
    private String userName;        //用户名
    private String opponentID;      //对手ID
    private String opponentName;    //对手名字

    private Client client;          //客户端

    /**
     * 初始化ID和名字
     *
     * @param i    用户/对手
     * @param ID   ID
     * @param name 昵称
     */
    public void setInfo(int i, String ID, String name) {
        if (i == 0) {
            userID = ID;
            userName = name;
        } else {
            opponentID = ID;
            opponentName = name;
        }
    }

    /**
     * 初始化
     */
    public ControlOp() {
        loginView = new Login();
        registView = new Regist();
        chessMenu = new ChessMenu(this);
        controlOp = this;
        login();
    }

    /**
     * 登陆、注册
     */
    public void login() {
        /**
         * 点击登陆事件
         */
        ActionListener loginButtonLs = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String admin = loginView.adminText.getText();
                String password = loginView.pwdText.getText();
                try {
                    System.out.println("登陆...用户名: " + admin + " 密码: " + password);
                    String userID = ConnPool.login(admin, password);
                    if (userID == null) {   //登陆失败
                        System.out.println("登陆失败");
                        JOptionPane.showMessageDialog(null, "密码错误或者用户不存在或用户已登录");
                    } else {    //登陆成功
                        loginView.loginFrame.setVisible(false);
                        System.out.println("ID为" + userID + "的用户登陆成功");
                        setInfo(0, userID, admin);
                        printInfo();
                        chessMenu.chessMenu.setVisible(true);
                        chessMenu.messagePanel.setBlackText(userName);
                        chessMenu.messagePanel.setWhiteText(userName);
                        controlOp.chessMenu.messagePanel.addMsg(userName + "，欢迎登陆！\n", 1);
                        System.out.println(userID + "客户端开启");
                        client = new Client(userID, controlOp);
                    }
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
        };

        /**
         * 点击注册事件
         */
        ActionListener registButtion = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                loginView.loginFrame.setVisible(false);
                registView.registFrame.setVisible(true);
            }
        };
        loginView.loginButton.addActionListener(loginButtonLs);
        loginView.registButton.addActionListener(registButtion);

        /**
         * 点击注册事件
         */
        ActionListener registButtonLs = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String admin = registView.getAdmin();
                String password = registView.getPassword();
                if (ConnPool.userExist(admin)) {
                    System.out.println("注册...用户名已存在");
                    JOptionPane.showMessageDialog(null, "用户名已存在");
                } else {
                    if (ConnPool.regist(admin, password)) {
                        System.out.println("注册成功");
                        JOptionPane.showMessageDialog(null, "注册成功");
                        registView.registFrame.setVisible(false);
                        loginView.loginFrame.setVisible(true);
                    } else {
                        System.out.println("注册失败");
                        JOptionPane.showMessageDialog(null, "注册失败");
                    }
                }
            }
        };
        /**
         * 点击返回事件
         */
        ActionListener returnButtonLs = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                registView.registFrame.setVisible(false);
                loginView.loginFrame.setVisible(true);
            }
        };
        registView.registButton.addActionListener(registButtonLs);
        registView.returnButton.addActionListener(returnButtonLs);
    }

    /**
     * 打印成员变量信息，用于调试
     */
    private void printInfo() {
        System.out.println("info:");
        System.out.println(userID);
        System.out.println(userName);
        System.out.println(opponentID);
        System.out.println(opponentName);
    }

    /**
     * 退出登陆
     */
    public void loginOut() {
        //未结束对战
        if (chessMenu.gamePanel.isNetworkPK && !chessMenu.gamePanel.gameOver) {
            JOptionPane.showMessageDialog(null, "请先结束对战！");
            return;
        }
        //用户注销
        ConnPool.loginOut(userID);
        System.out.println("注销...ID为" + userID + "的用户注销");
        //棋盘不可见
        chessMenu.chessMenu.setVisible(false);
        //登陆画面可见
        loginView.loginFrame.setVisible(true);
    }

    /**
     * 请求双人对战
     *
     * @throws SQLException 数据库异常
     */
    public void beiginPlay() throws SQLException {
        String i = ConnPool.findOpponent(userID);
        //查找不到对手
        if (i == null) {
            JOptionPane.showMessageDialog(null, "无匹配对手");
            return;
        }
        //根据查找到对手，根据反馈信息解析对手ID和昵称
        String[] rs = i.split(":");
        opponentID = rs[0];
        opponentName = rs[1];
        System.out.println("请求对战...找到的对手的ID为" + opponentID);
        client.setOppentID(opponentID);
        //发送类别为3内容为#的信息
        client.sendMsg("#", 3);
    }

    public void sendMsg(String msg, int type) {
        client.sendMsg(msg, type);
    }

    /**
     * 获得用户名字
     *
     * @return 用户名
     */
    public String getUserName() {
        return userName;
    }

    /**
     * 获得对手名字
     *
     * @return 对手名
     */
    public String getOpponentName() {
        return opponentName;
    }

    /**
     * 获得ID
     *
     * @return ID
     */
    public String getUserID() {
        return userID;
    }
}
