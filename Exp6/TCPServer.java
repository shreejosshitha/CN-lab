import java.io.*;
import java.net.*;

public class TCPServer {
    public static void main(String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(5000);
        System.out.println("Waiting for connection...");

        Socket s = ss.accept();
        System.out.println("Connection accepted...");

        BufferedReader in = new BufferedReader(
            new InputStreamReader(s.getInputStream()));
        PrintWriter out = new PrintWriter(
            s.getOutputStream(), true);

        String dir = in.readLine();
        System.out.println("Processing files in " + dir);

        File folder = new File(dir);

        if (folder.isDirectory()) {
            File[] files = folder.listFiles();

            if (files != null) {
                for (File f : files)
                    if (f.isFile())
                        out.println(f.getName());
            }
        } else {
            out.println("Directory not found");
        }

        out.println("END");
        System.out.println("List sent to the client...");

        s.close();
        ss.close();
    }
}
