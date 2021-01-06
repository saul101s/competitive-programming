import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.io.IOException;

import readers.*;

public class Main
{
    final static int TEST_CASES = 500;

    final static File ip = new File("input.txt");
    final static File op = new File("output.txt");

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
        FastReader1 fr1;
        FastReader2 fr2;

        int casesExecuted;
        int numbersRead;
        int numberRead;

        long startTime;
        long endTime;
        double exeTotalTimeSeconds;
        double exeAverageTimeSeconds;

        System.out.println("Reading input.txt " + TEST_CASES + " times per reader");

        /* Fast Reader 1 Test */

        displayTitle("Fast reader 1");

        startTime = System.nanoTime();

        casesExecuted = 0;
        numbersRead = 0;
        numberRead = 0;

        for (; casesExecuted < TEST_CASES; casesExecuted++)
        {
            try
            {
                fr1 = new FastReader1("input.txt");

                while (fr1.canReadMore())
                {
                    fr1.nextInt();
                    numbersRead++;
                }
            }
            catch (Exception e)
            {
                e.printStackTrace();
            }

        }

        endTime = System.nanoTime();

        exeTotalTimeSeconds = (endTime - startTime) / 1000000000.0;
        exeAverageTimeSeconds = exeTotalTimeSeconds / TEST_CASES;

        displayStatistics(exeTotalTimeSeconds, exeAverageTimeSeconds);

        /* Fast Reader 2 Test */

        displayTitle("Fast reader 2");

        startTime = System.nanoTime();

        casesExecuted = 0;
        numbersRead = 0;
        numberRead = 0;

        for (; casesExecuted < TEST_CASES; casesExecuted++)
        {
            try
            {
                fr2 = new FastReader2("input.txt");

                while (fr2.canReadMore())
                {
                    fr2.nextInt();
                    numbersRead++;
                }
            }
            catch (Exception e)
            {
                e.printStackTrace();
            }

        }

        endTime = System.nanoTime();

        exeTotalTimeSeconds = (endTime - startTime) / 1000000000.0;
        exeAverageTimeSeconds = exeTotalTimeSeconds / TEST_CASES;

        displayStatistics(exeTotalTimeSeconds, exeAverageTimeSeconds);
    }

    public static void displayTitle(String title)
    {
        System.out.println("\n====================");
        System.out.println(title);
        System.out.println("====================\n");
    }

    public static void displayStatistics(double totalTime, double averageTime)
    {
        System.out.println("Total execution time: " + totalTime);
        System.out.println("Average execution time: " + averageTime);
    }
}