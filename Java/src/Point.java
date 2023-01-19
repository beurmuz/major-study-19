public class Point{
  public double x;
  public double y;

  public double distance (Point a, Point b){

    double dis= Math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

    return dis;
  }

  public Point add(Point a, Point b){
    Point p=new Point();
    p.x=(a.x+b.x);
    p.y=(a.y+b.y);

    return p;
}

  public static void main(String [] args){
    Point p1=new Point();
    Point p2=new Point();
    p1.x = 2;
    p1.y = -1;
    p2.x = -2;
    p2.y = 2;
    Point sumPoint=new Point();
    sumPoint=p1.add(p1,p2);


    System.out.printf("distance (%.2f,%.2f) ,(%.2f,%.2f): %.2f \n",p1.x,p1.y,p2.x,p2.y,p1.distance(p1,p2));
    System.out.printf("multi : (%.2f,%.2f)+(%.2f,%.2f)=(%.2f,%.2f)\n",p1.x,p1.y,p2.x,p2.y,sumPoint.x,sumPoint.y);
  }
}
