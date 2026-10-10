import java.net.*;
import java.io.*;

public class udps {
    public static void main(String[] args) throws Exception {
        BufferedReader kb = new BufferedReader(
            new InputStreamReader(System.in));

        System.out.print("Enter your port: ");
        int myPort = Integer.parseInt(kb.readLine());

        System.out.print("Enter peer's port: ");
        int peerPort = Integer.parseInt(kb.readLine());

        DatagramSocket ds = new DatagramSocket(myPort);

        String msg = "Hello, I got it from 7000!";
        byte[] data = msg.getBytes();

        DatagramPacket send = new DatagramPacket(
            data, data.length,
            InetAddress.getByName("127.0.0.1"), peerPort);

        ds.send(send);
        System.out.println("You: " + msg);

        byte[] buffer = new byte[1024];
        DatagramPacket receive = new DatagramPacket(
            buffer, buffer.length);

        ds.receive(receive);
        System.out.println("Peer: " +
            new String(receive.getData(), 0,
                       receive.getLength()));

        ds.close();
    }
}
