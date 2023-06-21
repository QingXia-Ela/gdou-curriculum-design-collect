package FiveChess;

import javax.swing.*;
import java.awt.*;

public class Regist {
    public JLabel registLabel;      //注册页面
    public JFrame registFrame;      //注册框架
    public JLabel adminLabel;       //用户
    public JLabel pwdLabel;         //密码
    public JButton registButton;    //注册按钮
    public JButton returnButton;    //返回按钮
    public JTextField adminText;    //用户
    public JPasswordField pwdText;  //密码

    /**
     * 初始化注册界面
     */
    public Regist() {
        Font font = new Font("黑体", Font.PLAIN, 20);
        registFrame = new JFrame("注册");
        registFrame.setSize(450, 400);

        adminLabel = new JLabel("用户名");
        adminLabel.setBounds(20, 50, 60, 50);
        adminLabel.setFont(font);

        pwdLabel = new JLabel("密码");
        pwdLabel.setBounds(20, 120, 60, 50);
        pwdLabel.setFont(font);

        returnButton = new JButton("返回");
        returnButton.setBounds(90, 250, 100, 50);
        returnButton.setFont(font);

        registButton = new JButton("注册");
        registButton.setBounds(250, 250, 100, 50);
        registButton.setFont(font);

        adminText = new JTextField();
        adminText.setBounds(150, 50, 250, 50);
        adminText.setFont(font);

        pwdText = new JPasswordField();
        pwdText.setBounds(150, 120, 250, 50);
        pwdText.setFont(font);

        registLabel = new JLabel();
        registLabel.add(adminText);
        registLabel.add(pwdText);
        registLabel.add(adminLabel);
        registLabel.add(pwdLabel);
        registLabel.add(registButton);
        registFrame.add(returnButton);
        registFrame.add(registLabel);
        registFrame.setVisible(false);
        registFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        registFrame.setLocationRelativeTo(null);

    }

    /**
     * 获得用户名
     *
     * @return 用户名
     */
    public String getAdmin() {
        return adminText.getText();
    }

    /**
     * 获得密码文本
     *
     * @return 密码
     */
    public String getPassword() {
        return pwdText.getText();
    }
}
