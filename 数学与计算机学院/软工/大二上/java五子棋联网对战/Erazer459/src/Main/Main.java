package Main;

import Controller.MyThread;

public class Main {
    public static MyThread myThread;

    public static void main(String[] args) {
        /**
         * 线程创建，界面从登陆开始
         */
        myThread = new MyThread();
        myThread.createThread();
    }
}
