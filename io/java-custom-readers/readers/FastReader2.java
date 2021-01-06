package readers;

import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;

public class FastReader2 {

    private BufferedReader br;
    private StringTokenizer st;

    public FastReader2()
    {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer("");
    }

    public FastReader2(String fileName) throws IOException
    {
        br = new BufferedReader(new InputStreamReader(new FileInputStream(fileName)));
        st = new StringTokenizer("");
    }

    public String next()
    {
        while (!st.hasMoreTokens())
        {
            try
            {
                String line = br.readLine();
                st = new StringTokenizer(line);
            }
            catch (IOException e) {}
        }

        return st.nextToken();
    }

    public int nextInt()
    {
        return Integer.parseInt(next());
    }

    public long nextLong()
    {
        return Long.parseLong(next());
    }

    public boolean canReadMore()
    {
        if (st.hasMoreTokens())
        {
            return true;
        }

        try
        {
            while(!st.hasMoreTokens())
            {
                String line = br.readLine();
                st = new StringTokenizer(line);
            }
            
            return true;
        }
        catch (Exception e)
        {
            return false;
        }
    }
}