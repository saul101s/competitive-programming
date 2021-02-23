import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;

class Solver
{
    public void solve()
    {   
        int maxGain = -1;
        int gain = 0;
        
        int[] A = new int[Main.N];
        
        for (int i = 0; i < Main.N; i++)
        {
          A[i] = Main.fr.nextInt();
        }
        
        for (int i = 0; i < A.length; i++)
        {
          gain += A[i];
          
          if (gain < 0)
          {
            gain = 0;
            continue;
          }
          
          if (gain > maxGain)
          {
            maxGain = gain;
          }
        }
        
        if (maxGain <= 0)
        {
          Main.output += "Losing streak.\n";
        }
        else
        {
          Main.output += "The maximum winning streak is " +
                        Integer.toString(maxGain) + ".\n";
        }
    }
}

public class Main
{

    public static String output = "";
    public static FastReader fr;
    public static int N;

    /* static final File ip = new File("input.txt");
    static final File op = new File("my-output.txt");

    static
    {
        try
        {
            System.setOut(new PrintStream(op));
            System.setIn(new FileInputStream(ip));
        }
        catch(Exception e)
        {}
    }
    */
    
    public static void main(String[] args)
    {
        fr = new FastReader();
        Solver solver = new Solver();

        while((N = fr.nextInt()) != 0)
        { 
          solver.solve();
        }
        
        System.out.print(output);
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}
