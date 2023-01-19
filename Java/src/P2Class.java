import java.util.Arrays;
import java.util.ArrayList;

public class P2Class implements Comparable{
  String name;
  String cn;
  String data;
  public P2Class(String cn, String name, String data){
    this.name=name;
    this.cn=cn;
    this.data=data;
  }
//----------------------------------------------------------
public class Numbers {
    ArrayList<Integer> myList=new ArrayList<Integer>();
    public int sumList(){
      int sum=0;
      for(Integer data: myList){
        sum+=data;
      }
      // System.out.prinln(sum);
      return sum;
    }
  }
//----------------------------------------------------------
  //P2Class
  @Override
    public int compareTo(Object o) {
        P2Class d=(P2Class)o;
        return this.cn.compareTo(d.cn);
    }
//----------------------------------------------------------
  @Override
    public String toString() {
        String msg=cn+" "+name+" ";
        return msg;
    }
//----------------------------------------------------------
  public static void main(String[] args){

    P2Class[] arraynum=new P2Class[5];
    arraynum[0]=new P2Class("201411111","lim js","100");
    arraynum[1]=new P2Class("201811111","kim js","89");
    arraynum[2]=new P2Class("201211111","lee js","65");
    arraynum[3]=new P2Class("201511111","choi js","66");
    arraynum[4]=new P2Class("201311111","park js","80");

    System.out.println("After sorting");
    for(P2Class t:arraynum){
      System.out.println(t.toString());
    // Numbers n=new Numbers();
    // System.out.print("\n"+n.sumList());
    }
  }
}
