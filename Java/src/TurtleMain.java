// // 1. 클래스 4개(TurtleMain.java, Turtle, Sea-Turtle, LandTurtle),
// - Turtle 몸무게의 합계를 다형적 함수 get(Weight()를 반복문으로 호출해서 계산함.
// - SeaTurtle 객체로 green 200파운드, leatherback 1000 파운드,
// - LandTurtle 객 체로commonbox700그램,painted500그램 테스트
// - 예시 출력은printf()문을 사용해서 “Total ???kg=??+??+??+??”. 참고: 1파운드=453.59237그램

abstract class Turtle{
  String name;
  double weight;
  public Turtle(String name,double weight){
    this.name=name;
    this.weight=weight;
  }
  abstract public double getWeight();
}//==============================================
class SeaTurtle extends Turtle{
  public SeaTurtle(String name,double weight){
    super(name,weight);
  }
  @Override
  public double getWeight(){
    return weight*453.59237/1000;
  }
}//==============================================
class LandTurtle extends Turtle{
  public LandTurtle(String name,double weight){
    super(name,weight);
  }
  @Override
  public double getWeight(){
    return weight/1000;
  }
}//==============================================
public class TurtleMain{
  public static void main(String[] args){
    Turtle[] t=new Turtle[4];
    t[0]=new SeaTurtle("green",200.0);
    t[1]=new SeaTurtle("leatherback",1000.0);
    t[2]=new LandTurtle("commonbox",700.0);
    t[3]=new LandTurtle("painted",500.0);
    double totalWeight=0;
    for(int i=0;i<t.length;i++){
      totalWeight+=t[i].getWeight();
    }
    System.out.printf("Total %f kg= %f + %f + %f + %f",    totalWeight,t[0].getWeight(),t[1].getWeight(),t[2].getWeight(),t[3].getWeight());
  }
}
