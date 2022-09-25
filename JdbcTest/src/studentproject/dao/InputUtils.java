package studentproject.dao;
import java.util.Scanner;
public class InputUtils {
    private static Scanner scanner;

    public InputUtils() {
    }

    public static char readMenuSelection() {
        while(true) {
            String str = readKeyBoard(1, false);
            char c = str.charAt(0);
            if (c == '1' || c == '2' || c == '3' || c == '4' ||c=='5') {
                return c;
            }

            System.out.print("选择错误，请重新输入：");
        }
    }

    public static void readReturn() {
        System.out.print("按回车键继续...");
        readKeyBoard(100, true);
    }

    public static int readInt() {
        while(true) {
            String str = readKeyBoard(3, false);

            try {
                int n = Integer.parseInt(str);
                return n;
            } catch (NumberFormatException var3) {
                System.out.print("数字输入错误，请重新输入：");
            }
        }
    }

    public static String readString(){

        while(true) {
            String str = readKeyBoard(3, false);

            return str;
        }


    }

    public static char readConfirmSelection() {
        while(true) {
            String str = readKeyBoard(1, false).toUpperCase();
            char c = str.charAt(0);
            if (c == 'Y' || c == 'N') {
                return c;
            }

            System.out.print("选择错误，请重新输入：");
        }
    }

    private static String readKeyBoard(int limit, boolean blankReturn) {
        String line = "";

        while(scanner.hasNextLine()) {
            line = scanner.nextLine();
            if (line.length() == 0) {
                if (blankReturn) {
                    return line;
                }
            } else {
                if (line.length() >= 1 && line.length() <= limit) {
                    break;
                }

                System.out.print("输入长度（不大于" + limit + "位数"+"）错误，请重新输入：");
            }
        }

        return line;
    }

    static {
        scanner = new Scanner(System.in);
    }

}
