package FiveChess;

import Controller.ControlOp;

import javax.swing.*;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class MessagePanel extends JPanel implements KeyListener {
    private ControlOp controlOp;
    private JTextField title, whiteText, blackText;
    private JScrollPane consoleScroll, messageScroll;
    public JLabel whiteLabel, blackLabel;
    private MyTextPane console;     //显示消息的控制台
    private JTextArea message;     //待发送的信息
    public GamePanel chessPanel;   // 棋盘容器
    private ImageIcon bgImg = new ImageIcon("src/images/t1.jpg");

    /**
     * 初始化
     *
     * @param controlOp  本线程的主控
     * @param chessPanel 本线程的棋盘
     */
    public MessagePanel(ControlOp controlOp, GamePanel chessPanel) {
        this.setLayout(null);
        /**
         * initialize
         */
        this.controlOp = controlOp;
        this.chessPanel = chessPanel;
        title = new JTextField("我的聊天室");
        blackText = new JTextField();
        whiteText = new JTextField();
        console = new MyTextPane();
        consoleScroll = new JScrollPane(console);
        message = new JTextArea();
        messageScroll = new JScrollPane(message);
        blackLabel = new JLabel("黑棋：");
        whiteLabel = new JLabel("白棋：");

        title.setBounds(0, 10, 230, 35);
        title.setFont(new Font("楷体", Font.BOLD, 16));
        title.setEditable(false);
        title.setHorizontalAlignment(JTextField.CENTER);
        title.setForeground(Color.BLACK);
        title.setFocusable(false);

        blackLabel.setBounds(17, 50, 85, 35);
        blackLabel.setFont(new Font("楷体", Font.BOLD, 16));

        blackText.setBounds(60, 50, 170, 35);
        blackText.setFont(new Font("楷体", Font.BOLD, 16));
        blackText.setHorizontalAlignment(JTextField.CENTER);
        blackText.setEditable(false);
        blackText.setFocusable(false);

        whiteLabel.setBounds(17, 85, 85, 35);
        whiteLabel.setFont(new Font("楷体", Font.BOLD, 16));

        whiteText.setBounds(60, 85, 170, 35);
        whiteText.setFont(new Font("楷体", Font.BOLD, 16));
        whiteText.setHorizontalAlignment(JTextField.CENTER);
        whiteText.setEditable(false);
        whiteText.setFocusable(false);
        whiteText.setOpaque(false);

        console.setEditable(false);
        console.setFont(new Font("楷体", Font.BOLD, 16));
        console.setFocusable(false);
        console.setOpaque(false);
        consoleScroll.setBounds(0, 120, 230, 380);
        consoleScroll.setOpaque(false);

        message.setFont(new Font("楷体", Font.BOLD, 14));
        message.setFocusable(true);
        message.setLineWrap(true);
        message.setWrapStyleWord(true);
        messageScroll.setBounds(0, 500, 230, 37);

        this.add(title);
        this.add(blackLabel);
        this.add(whiteLabel);
        this.add(blackText);
        this.add(whiteText);
        this.add(consoleScroll);
        this.add(messageScroll);
        message.addKeyListener(this);
    }

    /**
     * 重写键盘相应
     *
     * @param e 按键
     */
    @Override
    public void keyTyped(KeyEvent e) {
        if (e.getKeyChar() == KeyEvent.VK_ENTER) {
            //需要发送的消息
            String sendMsg = message.getText().trim();
            //消息不会空
            if (sendMsg.length() > 0) {
                System.out.println(chessPanel.gameOver);
                if (chessPanel != null && chessPanel.isNetworkPK && !chessPanel.gameOver) {
                    controlOp.sendMsg(sendMsg, 1);
                    //向服务端发送消息
                    addMsg(controlOp.getUserName() + ": " + sendMsg + "\n", 2);
                    message.setText("");
                } else {
                    //不处于对战状态
                    String msg = message.getText();
                    message.setText(msg.substring(0, msg.length() - 1));
                    JOptionPane.showMessageDialog(null, "不是网络对战无法发送信息");
                }
            } else {
                //空消息
                message.setText("");
                JOptionPane.showMessageDialog(null, "不能发送空信息");
            }
        }
    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawImage(bgImg.getImage(), 0, 0, getSize().width, getSize().height, this);// 图片会自动缩放
    }

    public void setWhiteText(String str) {
        whiteText.setText(str);
    }

    public void setBlackText(String str) {
        blackText.setText(str);
    }

    /**
     * 在聊天窗口添加信息
     *
     * @param msg 信息
     */
    public void addMsg(String msg, int type) {
        if (type == 1)
            console.setText(msg, new Font("黑体", Font.ITALIC, 16), Color.WHITE, Color.BLACK);
        else if (type == 2)
            console.setText(msg, new Font("楷体", Font.BOLD, 16), Color.WHITE, Color.BLUE);
        else
            console.setText(msg, new Font("楷体", Font.BOLD, 16), Color.WHITE, Color.GREEN);

    }
}


class MyTextPane extends JTextPane {
    /**
     * 聊天室字体设置
     *
     * @param msg       带插入的文本
     * @param font      字体
     * @param backgroud 背景色
     * @param foregroud 前景色
     */
    public void setText(String msg, Font font, Color backgroud, Color foregroud) {
        try {
            SimpleAttributeSet set = new SimpleAttributeSet();
            StyleConstants.setBackground(set, backgroud);
            StyleConstants.setForeground(set, foregroud);
            StyleConstants.setFontSize(set, font.getSize());
            StyleConstants.setFontFamily(set, font.getFontName());
            if (font.isBold()) {
                StyleConstants.setBold(set, true);
            }
            if (font.isItalic()) {
                StyleConstants.setItalic(set, true);
            }
            this.getDocument().insertString(this.getDocument().getLength(), msg, set);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
