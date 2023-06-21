package Server;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;

public class Server {
    private ServerSocket listener;
    private static HashMap<String, Socket> clientMap = new HashMap<>();
    private final short PORT = 8080;

    /**
     * 启动服务器，创建线程
     */
    public Server() {
        try {
            listener = new ServerSocket(PORT);
            System.out.println("服务器socket创建完毕");
            Socket socket = null;
            while (true) {
                socket = listener.accept();
                System.out.println("收到一个socket");
                ServerThread myThread = new ServerThread(socket);
                System.out.println("client host address:" + socket.getInetAddress().getHostAddress());
                myThread.start();
            }
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public static void markID(String ID, Socket s) {
        clientMap.put(ID, s);
    }

    public static Socket getSocket(String ID) {
        return clientMap.get(ID);
    }
}

/**
 * 服务端线程
 */
class ServerThread extends Thread {
    private Socket socket;
    private BufferedReader br;
    private String msg;

    public ServerThread(Socket s) {
        socket = s;
    }

    @Override
    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            while ((msg = br.readLine()) != null) {
                System.out.println(msg);
                String[] message = msg.split(":");
                if (message[0].equals("0")) {
                    Server.markID(message[1], socket);
                } else if (Integer.valueOf(message[0]) > 0 && Integer.valueOf(message[0]) < 6) {
                    /**
                     * 聊天内容：x:(from) userID:(to) userID:[content]
                     * 转发给目标客服端
                     */
                    Socket des = Server.getSocket(message[2]);
                    if (des != null)
                        sendMsg(msg, des);
                } else {
                    System.out.println("收到无归属信息");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    /**
     * 发送信息
     *
     * @param msg         待发送信息
     * @param destination 目的地
     * @throws IOException 异常
     */
    private void sendMsg(String msg, Socket destination) throws IOException {
        PrintWriter pw = new PrintWriter(destination.getOutputStream(), true);
        pw.println(msg);
        pw.flush();
    }
}
