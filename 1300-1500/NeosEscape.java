import java.io.*;
import java.util.*;

public class NeosEscape{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        while(t-->0){
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<Integer> b = new ArrayList<>(n);
            int prev = -1;
            for(int i=0;i<n;i++){
                int x = Integer.parseInt(st.nextToken());
                if(i==0||x!=prev) b.add(x);
                prev = x;
            }
            int m = b.size(), clones = 0;

            for(int i=0;i<m;i++)
            {
                int left = (i>0?b.get(i-1):0);
                int right = (i+1<m?b.get(i+1):0);
                if(b.get(i)>left&&b.get(i)>right) clones++;
            }
            pw.println(clones);
        }
        pw.flush();
    }
}