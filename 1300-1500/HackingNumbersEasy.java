import java.io.*;
import java.util.*;

public class HackingNumbersEasy {
    public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out,true);
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0){
            int n = Integer.parseInt(br.readLine().trim());
            pw.println("digit");
            long x = Long.parseLong(br.readLine().trim());
            for(int i=8;i>=1;i>>=1){
                pw.print("add "+(-i));
                x = Long.parseLong(br.readLine().trim());
            }
            pw.println("add "+(n-1));
            x = Long.parseLong(br.readLine().trim());
            pw.println("!");
            int vd = Integer.parseInt(br.readLine().trim());
            if(vd==-1){
                return;
            }
        }

    }
}