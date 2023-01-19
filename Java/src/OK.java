// 최근 컴파일 성공
import java.util.Arrays;
public class P2Class implements Comparable{
  String name;
  String cn;
  String data;
  public P2Class(String cn, String name, String data){
    this.name=name;
    this.cn=cn;
  }

  //P2Class
  @Override
    public int compareTo(Object o) {
        P2Class d=(P2Class)o;
        return this.cn.compareTo(d.cn);
    }

  //@Override
    public String toString() {
        String msg=cn+" "+name;
        return msg;
    }

  public static void main(String[] args){

    P2Class[] arraynum=new P2Class[5];
    arraynum[0]=new P2Class("201411111","lim js");
    arraynum[1]=new P2Class("201811111","kim js");
    arraynum[2]=new P2Class("201211111","lee js");
    arraynum[3]=new P2Class("201511111","choi js");
    arraynum[4]=new P2Class("201311111","park js");

    System.out.println("After sorting");
    for(P2Class t:arraynum){
      System.out.println(t.toString());


    }


  }
}
