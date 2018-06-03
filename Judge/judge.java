package Judge;

import java.io.BufferedReader;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

// 需要判别的脚本，可修改：
import Source.Solution;

public class judge {
    private static String base_dir = System.getProperty("user.dir");
    
    // 数据文件所在位置。可修改：
    private static String in_file = base_dir + "/Data/in";
    private static String out_file = base_dir + "/Data/out";
    private static String ans_file = base_dir + "/Data/answer";

    private static int dataCnt;
    private static Solution usrCode = new Solution();
    private static void dataCount() {
        /**
         * Count how many lines in the in_file.
         */
        BufferedReader dataIn = null;
        try {
            dataIn = new BufferedReader(new FileReader(in_file));
        } catch (FileNotFoundException e){
            System.out.println("Cannot Find File: " + e.getMessage());
            System.exit(0);
        }
        String line;
        try {
            while ((line = dataIn.readLine()) != null) {
                ++dataCnt;
            }
            dataIn.close();
        } catch (IOException e) {
            System.out.println("IOException: " + e.getMessage());            
        }
    }

    private static void userRun() {
        /**
         * Redirect data input and user output.
         */
        PrintStream 
            stdOutBackUp = System.out,
            usrOut = null;
        FileInputStream dataIn = null;
        try {
            dataIn = new FileInputStream(in_file);
            usrOut = new PrintStream(out_file);
        } catch (FileNotFoundException e) {
            System.out.println("Cannot Find File: " + e.getMessage());
            System.exit(0);
        }

        System.setIn(dataIn);
        System.setOut(usrOut);

        Scanner input = new Scanner(System.in);

        for (int i = 0; i < dataCnt; ++i) {
            usrCode.solve(input);
        }

        System.setOut(stdOutBackUp);
    }

    private static int judgeAns() {
        /**
         * Open user output ans answer.
         */
        BufferedReader 
            stdAns = null,
            usrAns = null;
        try {
            stdAns = new BufferedReader(new FileReader(ans_file));
            usrAns = new BufferedReader(new FileReader(out_file));
        } catch (FileNotFoundException e) {
            System.out.println("Cannot Find File: " + e.getMessage());
            System.exit(0); 
        }

        String stdLine, usrLine;
        int corCount = 0;
        try {
            for (int i = 0; i < dataCnt; ++i) {
                stdLine = stdAns.readLine();
                usrLine = usrAns.readLine();
                if (stdLine.equals(usrLine)) {
                    ++corCount;
                } else {
                    throw new EOFException("Out At Line " + corCount);
                }
            }
        } catch (EOFException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return (int) Math.floor(100 * corCount / dataCnt);
    }

    public static void main(String[] args) {
        dataCount();
        userRun();
        System.out.println("Pass Rate : " + judgeAns() + " %");
    }
}