public class Circle{
  public float radius;
  public double result;

  public Circle(float r){
    radius=r;
  }

public double calcArea(){
  result=radius*radius*(float)3.14;
  System.out.printf("Area: %.1f",result);
  return 0;
}

public static void main(String[] args){
  Circle c=new Circle((float)5.0);
  c.calcArea();
}
}
