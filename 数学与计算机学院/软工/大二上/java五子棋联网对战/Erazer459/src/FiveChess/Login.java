package FiveChess;

import javax.swing.*;
import java.awt.*;

public class Login {
    public JLabel loginLabel;   //登陆页面
    public JFrame loginFrame;   //登陆框架
    public JLabel adminLabel;   //用户
    public JLabel pwdLabel;     //密码
    public JButton loginButton; //登陆按钮
    public JButton registButton;    //注册按钮
    public JTextField adminText;    //用户
    public JPasswordField pwdText;  //密码

    /**
     * 初始化登陆界面
     */
    public Login() {
        Font font = new Font("黑体", Font.PLAIN, 20);
        loginFrame = new JFrame("登陆");
        loginFrame.setSize(450, 400);

        adminLabel = new JLabel("用户名");
        adminLabel.setBounds(20, 50, 60, 50);
        adminLabel.setFont(font);

        pwdLabel = new JLabel("密码");
        pwdLabel.setBounds(20, 120, 60, 50);
        pwdLabel.setFont(font);

        loginButton = new JButton("登陆");
        loginButton.setBounds(90, 250, 100, 50);
        loginButton.setFont(font);

        registButton = new JButton("注册");
        registButton.setBounds(250, 250, 100, 50);
        registButton.setFont(font);

        adminText = new JTextField();
        adminText.setBounds(150, 50, 250, 50);
        adminText.setFont(font);

        pwdText = new JPasswordField();
        pwdText.setBounds(150, 120, 250, 50);
        pwdText.setFont(font);

        loginLabel = new JLabel();
        loginLabel.add(adminText);
        loginLabel.add(pwdText);
        loginLabel.add(adminLabel);
        loginLabel.add(pwdLabel);
        loginLabel.add(loginButton);
        loginLabel.add(registButton);
        loginFrame.add(loginLabel);
        loginFrame.setVisible(true);
        loginFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        loginFrame.setLocationRelativeTo(null);
    }
}
