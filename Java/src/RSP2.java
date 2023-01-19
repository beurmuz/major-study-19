// enum없는 가위바위보

import java.util.Scanner;
public class RSP2{
  public String whoIsWinner(String a,String b){
    if((a.equals("rock")&&b.equals("sissor"))||(a.equals("sissor")&&b.equals("paper"))||(a.equals("paper")&&b.equals("rock"))){
      return ("\np1 is win!!");
    }
    else if((b.equals("rock")&&a.equals("sissor"))||(b.equals("sissor")&&a.equals("paper"))||(b.equals("paper")&&a.equals("rock"))){
      return ("\np2 is win!!");
    }
    else
      return("\n---same the result---!!");
    }
  public static void main(String[] args){
    RSP2 rsp1=new RSP2();
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter sissor or rock or paper: ");
    System.out.print("p1: ");
    String s1=sc.next();
    System.out.println("\nEnter sissor or rock or paper: ");
    System.out.print("p2: ");
    String s2=sc.next();
    System.out.printf("%s",rsp1.whoIsWinner(s1,s2));
  }
}
