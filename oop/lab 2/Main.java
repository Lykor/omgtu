import java.util.regex.Matcher;
import java.util.regex.Pattern;
 
 
public class Main {
    public static void main(String[] args) {
        String string = "e02fd0e4-00fd-090A-ca30-0d00a0038ba0";
        System.out.println(string+" - is correct?");
        Pattern pattern = Pattern.compile("(?i)[a-f\\d]{8}-([a-f\\d]{4}-){3}[a-f\\d]{12}");
        Matcher matcher = pattern.matcher(string);
        if (matcher.find()) System.out.println("Yes");       
        else System.out.println("No");


        string = "e02fd0e400fd090Aca300d00a0038ba0";
        System.out.println(string +" - is correct?");
        matcher = pattern.matcher(string);
        if(matcher.find())System.out.println("Yes");
        else System.out.println("No");
    }
}