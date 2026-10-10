import java.io.*;
import java.net.*;

public class rarps {
    public static void main(String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(5800);
        System.out.println("RARP server waiting...");

        Socket s = ss.accept();
        BufferedReader in = new BufferedReader(
            new InputStreamReader(s.getInputStream()));
        PrintWriter out = new PrintWriter(
            s.getOutputStream(), true);

        String mac = in.readLine();
        String ip = mac.equals("12.13.24.0.0.3")
                  ? "172.16.5.202" : "IP not found";

        out.println(ip);
        s.close();
        ss.close();
    }
}
