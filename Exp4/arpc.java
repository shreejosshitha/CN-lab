import java.io.*;
import java.net.*;

public class arpc {
    public static void main(String[] args) throws Exception {
        Socket s = new Socket("127.0.0.1", 5800);

        BufferedReader in = new BufferedReader(
            new InputStreamReader(s.getInputStream()));
        PrintWriter out = new PrintWriter(
            s.getOutputStream(), true);
        BufferedReader kb = new BufferedReader(
            new InputStreamReader(System.in));

        System.out.print("Enter IP address: ");
        out.println(kb.readLine());

        System.out.println("MAC address: " + in.readLine());
        s.close();
    }
}
