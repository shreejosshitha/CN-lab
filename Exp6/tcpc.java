import java.io.*;
import java.net.*;

public class tcpc {
    public static void main(String[] args) throws Exception {
        Socket s = new Socket("127.0.0.1", 5000);

        BufferedReader in = new BufferedReader(
            new InputStreamReader(s.getInputStream()));
        PrintWriter out = new PrintWriter(
            s.getOutputStream(), true);
        BufferedReader kb = new BufferedReader(
            new InputStreamReader(System.in));

        System.out.print("Enter directory path: ");
        out.println(kb.readLine());

        String file;
        while (!(file = in.readLine()).equals("END"))
            System.out.println(file);

        s.close();
    }
}
