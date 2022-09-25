package socket;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.InetAddress;
import java.net.InterfaceAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {

        ServerSocket  ss = null;
        try {
            ss = new ServerSocket(8000);
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("服务器已启动....");

        Socket socket = null;
        try {
            socket = ss.accept();
        } catch (IOException e) {
            e.printStackTrace();
        }

        InetAddress address = socket.getLocalAddress();
        System.out.println("" + address + "成功连接到服务器！");
        BufferedWriter netOut = null;
        try {
            netOut = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            netOut.write("" + address.getHostName() + "欢迎连接到服务器！\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            netOut.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            netOut.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
