import java.lang.Math;
import java.util.Random;

class Dice{
  public int number1;
  public void roll(){
    number1=(int)(Math.random()*6)+1;
  }
  public int getNum(){
    return number1;
  }
}

class Player{
  public String name;
  public int number2;

  public Player(String name){
      this.name = name;
  }
  public void play(){
    Dice d1=new Dice();
    d1.roll();
    this.number2=d1.getNum();
  }
}

class P1Dice{
  Player p1=new Player("A");
  Player p2=new Player("B");
  Dice n=new Dice();
  public int i, sum = 0;
  public void startGame(){

    System.out.printf("A's Score: ");
    for(i=0;i<5;i++){
      n.roll();
      p1.play();
      System.out.printf("%d  ",n.getNum());
      sum+=i;
    }
      System.out.printf("sum:%d\n",sum);

    System.out.printf("B's Score: ");
    for(i=0;i<5;i++){
      n.roll();
      p2.play();
      System.out.printf("%d  ",n.getNum());
      sum+=i;
    }
      System.out.printf("sum:%d\n",sum);


    if(p1.number2>p2.number2)
      System.out.println("the winner is "+ p1.name);
    else if(p1.number2<p2.number2)
      System.out.println("the winner is "+ p2.name);
    else if(p1.number2==p2.number2)
      System.out.println("finish a tie");
    else
      System.out.println("ff");

  }
  public static void main(String []args){

    P1Dice d=new P1Dice();
    System.out.println("\nStart the game");
    d.startGame();
 }
}
