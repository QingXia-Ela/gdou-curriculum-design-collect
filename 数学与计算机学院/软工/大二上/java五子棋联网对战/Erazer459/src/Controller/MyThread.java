package Controller;

public class MyThread extends Thread {
    public ControlOp loginOp;

    @Override
    public void run() {
        loginOp = new ControlOp();
    }

    /**
     * 开启一个登陆的线程
     */
    public void createThread() {
        System.out.println("创建一个线程");
        MyThread thread = new MyThread();
        thread.start();
        System.out.println("线程运行结束");
    }
}
