//enum을 이용한 가위바위보 게임 코드

import java.util.Scanner;
public class RSP{
  static enum Enom {sissor, rock, paper};
  public static void main(String[] args) {
    System.out.println("sissor!rock!paper!");
    Scanner sc=new Scanner(System.in);
    System.out.print("player1 write: ");
    String s1=sc.next();
    System.out.print("player2 write: ");
    String s2=sc.next();
    Enom sel1=Enom.valueOf(s1);
    Enom sel2=Enom.valueOf(s2);
    //if(sel1.equals("rock")&&sel2.equals("sissor")){  // enum and String compare.
    if( (sel1==Enom.rock && sel2==Enom.sissor) || (sel1==Enom.paper && sel2==Enom.rock) || (sel1==Enom.sissor && sel2==Enom.paper)) {
      System.out.println("player1 win");
    }
    else if(sel1.equals(sel2)) {
      System.out.println("Same!");
    }
    else {
      System.out.println("player2 win");
    }
  }
}
