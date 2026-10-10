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
        String ip = "IP not found";

        if (mac.equals("12.13.24.0.0.3"))
            ip = "172.16.5.202";

        out.println(ip);
        s.close();
        ss.close();
    }
}
