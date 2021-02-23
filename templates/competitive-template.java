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
    Main.output = Main.output.concat("Solution\n");
  }
}

public class Main
{

  public static String output = "";
  public static FastReader fr;

  static final File ip = new File("input.txt");
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
    
  public static void main(String[] args)
  {
    final int cases;
    FastReader fr = new FastReader();

    cases = fr.nextInt();
    Solver solver = new Solver();

    for (int i = 0; i < cases; i++)
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
      br = new BufferedReader(new InputStreamReader(System.in));
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
