import ch.aplu.turtle.*;

public class Triangle{
    private double width;
    private double height;
    private double size;
    Turtle pen;

    Triangle(double a, double b, double s){
      width = a;
      height = b;
      size =s; //length
      pen=new Turtle();
    }

    public void draw(){
      pen.penUp();
      pen.moveTo(width,height);
      pen.penDown();
      for (int i=0; i<3; i++){
        pen.forward(size);
        pen.right(120);
      }
    }
    // public float computeArea(){
    //   return (float)(width*height)/2;
    // }
    public static void main(String[] args){
      Triangle t=new Triangle(0.0,0.0,100.0);
      t.draw();
    }
  }
