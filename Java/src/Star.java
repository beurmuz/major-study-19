import ch.aplu.turtle.*;
public class Star{
  private double length;
  private double xpos;
  private double ypos;
  Turtle pen;

  Star(double l,double x, double y){
    length = l;
    xpos = x;
    ypos = y;
    pen=new Turtle();
  }
  public void draw(){
      pen.penUp();
      pen.moveTo(xpos,ypos);
      pen.penDown();
      for (int i=0; i<5;i++){
        pen.forward(length);
        pen.right(216);
      }
  }
  public static void main(String[] args){
    Star s=new Star(100.0,0.0,0.0);
    s.draw();
  }
}
