public class Player{
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
