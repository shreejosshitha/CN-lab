import java.io.*;
import java.net.*;

public class arps {
    public static void main(String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(5800);
        System.out.println("ARP server waiting...");

        Socket s = ss.accept();
        BufferedReader in = new BufferedReader(
            new InputStreamReader(s.getInputStream()));
        PrintWriter out = new PrintWriter(
            s.getOutputStream(), true);

        String ip = in.readLine();
        String mac = ip.equals("172.16.5.200")
                   ? "12.13.24.0.0.1" : "MAC not found";

        out.println(mac);
        s.close();
        ss.close();
    }
}
