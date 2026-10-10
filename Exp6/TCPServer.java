import java.io.*;
import java.net.*;

public class TCPServer {
    public static void main(String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(5000);
        System.out.println("Server waiting...");

        Socket s = ss.accept();
        BufferedReader in = new BufferedReader(
            new InputStreamReader(s.getInputStream()));
        PrintWriter out = new PrintWriter(
            s.getOutputStream(), true);

        System.out.println("Client: " + in.readLine());
        out.println("Message received");

        s.close();
        ss.close();
    }
}
